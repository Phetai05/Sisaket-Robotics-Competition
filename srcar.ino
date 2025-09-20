#include <POP32.h>

  int Speed, SlowSpeed, ACCSpeed, BaseSpeed, LeftBaseSpeed, RightBaseSpeed, TurnSpeed, MaxSpeed, SonarSpeed, DistanceRef;
  int Error, PreError, Kp, Kd, Ki, Kt,BackLeftBaseSpeed, BackRightBaseSpeed;
  int KpB,KdB,KtB,KiB;
  int RefL2, RefL1, RefC, RefR1, RefR2, RefBL2, RefBL1, RefBR1, RefBR2, SumError;
  int L2, L1, C, R1, R2, BL2, BL1, BR1, BR2;
  long Timer, Timer2, Timer3;
  int SW_OK_Status,Error99Check=0,digital_sw=0;
  int KnobBase;
  int CanStatus=0;
  
  #define No 0
  #define Yes 1

  #define Mode0 0
  #define Mode1 1
  #define Mode2 2
  #define Mode3 3
  #define Mode4 4

  #define WheelDrive  1   //0:ขับเคลื่อน 2 ล้อ , 1:ขับเคลื่อน 4 ล้อ
  #define SwitchTime  200 //เวลาในการตรวจสอบการกดสวิชในหน่วย ms

  int Mode=Mode0;                

  int FontSensorNumber=5,BackSensorNumber=3;
  int PidStatus=0;    //0:กรณีโค้งน้อยๆ 1:กรณีโค้งเยอะๆ
  int BlackLine=1;    //0:เส้นดำ 1:เส้นขาว

void setup() {

  DistanceRef = 3;     //0:ไม่เช็คสิ่งกีดขวาง ,>0 เช็คสิ่งกีดขวาง 
  Speed =60;
  ACCSpeed =60;
  SlowSpeed = 30;
  BaseSpeed = Speed; 
  TurnSpeed = Speed;
  SonarSpeed = 55;
  InitialSpeed();
  InitialRef();
  ServoGripUp();
  ServoPut();
  ServoGripUpBack();
  ServoPutBack();
  ServoBoomUp();
  beep(0);
  oled.clear();                 //เคลียร์หน้าจอ
  oled.mode(0);                 //หมุนหน้าจอ 0 องศา
  oled.textSize(1);             //กำหนดขนาดตัวอักษร
  oled.text(0,0,"  Ubon TP Robotics"); //กำหนดข้อความที่จะแสดง
  oled.text(1,0,"Tour Sisaket Robot ");
  oled.text(2,0,"  Kumpang B  ");  
  oled.text(3,0,"     Speed = %d   ",Speed);
  oled.text(4,0,"     ACCSpeed=%d",ACCSpeed);
  oled.text(5,0,"     OK to Start ");
  oled.text(6,0,"Transporter Robot");  
  oled.show();                  //แสดงบนหน้าจอ
  SW_OK_Status = No;
  KnobBase=knob();
  while(SW_OK_Status == No)  {  // waiting "OK" button
      if(Read_sw_OK()) {
        StartTimer();
        Mode=Mode0; 
        SW_OK_Status = Yes;
        beep(1);
        while(Read_sw_OK())  {  //wait unpress OK button
        if(ReadTimer() >= 2000) {
          beep(2);
          delay(100);
          GripDownHalf();
          GripDownHalfBack();
          Grip();
          GripBack();
          ServoBoomDown();
          delay(1000);
          GripDown();
          GripDownBack();
          Put();
          PutBack();
          delay(1000);
          ServoBoomUp();
          ServoGripUp();
          ServoGripUpBack();
          Show8Analog();
          SW_OK_Status = No;
          }
        }
       }
       if(SW_A()) 
       {
          StartTimer();
          beep(1);
          while(SW_A())  {}  //wait unpress SW A button
          if(ReadTimer() >= SwitchTime) Mode=Mode1;
          else  Mode=Mode2;
          SW_OK_Status = Yes;

       }
       if(SW_B()) 
       {
          StartTimer();
          beep(1);
          while(SW_B())  {}  //wait unpress SW A button
          if(ReadTimer() >= SwitchTime) Mode=Mode3;
          else  Mode=Mode4;
          SW_OK_Status = Yes;
       }
  }
  BaseSpeed = Speed;
  oled.clear();
  oled.textSize(2);
  oled.text(0,0,"  Starting   ");
  oled.text(1,0,"  Mode=%d   ",Mode);
  oled.show();
  StartTimer2();
  SelectSpeed();

  //ForwardSpeedTime(BaseSpeed,1500);     //เดินหน้า
  //BackwardSpeedTime(BaseSpeed,1500);    //ถอยหลัง
  //TurnLeft();                           //เลี้ยวซ้าย
  //TurnRight();                          //เลี้ยวขวา
  //UTurnLeft();                          //กลับตัวด้านซ้าย
  //UTurnRight();                         //กลับตัวด้านขวา
  //Left(70,200);                         //เลี้ยวซ้ายแบบหน่วงเวลา
  //Right(70,200);                        //เลี้ยวขวาแบบหน่วงเวลา
  //TracJCStop();                         //เดินเช็ค 1 แยก เจอแยกหยุดทันที
  //TracJC();                             //เดินเช็ค 1 แยก เจอแยกเพื่อเตรียมเลี้ยว
  //TracJCSpeed();                        //เดินเช็ค 1 แยก เจอแยกเพื่อเตรียมตรงไป
  //TracJC99();                           //เดินเช็ค 1 แยก เช็คสิ้นสุดทางด้วย(ขาวล้วนหรือดำล้วน)
  //TracJCStopBack();                     //เดินถอยหลังเช็ค 1 แยก เจอแยกหยุดทันที
  //TracJCBack();                         //เดินถอยหลังเช็ค 1 แยก เจอแยกเพื่อเตรียมเลี้ยว
  //TracJCSpeedBack();                    //เดินถอยหลังเช็ค 1 แยก เจอแยกเพื่อเตรียมถอยตรงไป
  //JC(3);                                //เดินเช็ค 3 แยก เจอแยกเพื่อเตรียมเลี้ยว
  //JCBack(3);                            //เดินถอยหลังเช็ค 3 แยก เจอแยกเพื่อเตรียมเลี้ยว
  //PassHole();                           //ผ่าน ก และ ข
  //TracSonar();                          //เดินตามเส้นเช็ควัตถุใช้ infrared
  //TracSpeedTime(Speed,500);             //เดินตามเส้นแบบหน่วงเวลา
  //TracSpeedTimeBack(Speed,500);         //เดินถอยหลังตามเส้นแบบหน่วงเวลา
  //TracJCSpeedTime(Speed,20);            //เดินตามเส้นเช็คแยกแบบกำหนดความเร็วการเดินและเวลาในการเดินข้ามแยก
  //TracJCSpeedTimeBack(Speed,20);        //เดินถอยหลังตามเส้นเช็คแยกแบบกำหนดความเร็วการเดินและเวลาในการเดินข้ามแยก
  //CurveLeft(70,80);                     //โค้งอ้อมด้านซ้าย
  //CurveRight(70,80);                    //โค้งอ้อมด้านขวา
  //delay(100);                           //หน่วงเวลา
  //Grip();                               //คีบกระป๋องหน้า
  //Put();                                //วางกระป๋องหน้า
  //GripUp();                             //ยกแขนขึ้นหน้า
  //GripDownHalf();                       //ยกแขนขนานกับพื้นหน้า
  //GripDown();                           //ยกแขนลงหน้า
  //GripBack();                           //คีบกระป๋องหลัง
  //PutBack();                            //วางกระป๋องหลัง
  //GripUpBack();                         //ยกแขนขึ้นหลัง
  //GripDownHalfBack();                   //ยกแขนขนานกับพื้นหลัง
  //GripDownBack();                       //ยกแขนลงหลัง
  //BoomBalloon();                        //ตีลูกโป่ง
  //ServoBoomDown();                      //เอาก้านตีลูกโป่งลง
  //ServoBoomDoUp();                      //เอาก้านตีลูกโป่งขึ้น
  //PutBox1_2();                          //วาง Box ก-ข ด้านหน้า
  //PutBox1_2Back();                      //วาง Box ก-ข ด้านหลัง
  //PutBoxAJ();                           //วาง Box A-J ด้านหน้า
  //PutBoxAJBack();                       //วาง Box A-J ด้านหลัง
  //Finish();                             //จบการทำงาน
  
 }

void loop() 
{
  // put your main code here, to run repeatedly:
  Box1_2(); //ข และ ก
  BoxJ_I(); //J&I
  Finish();
}
