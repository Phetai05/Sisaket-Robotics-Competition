void ServoGrip()
{
  servo(1,5);
}
void ServoPut()
{
  servo(1,40);
}
void ServoGripUp()
{
  servo(2,5);
}
void ServoGripDownHalf()
{
  servo(2,300);
}
void ServoGripDown()
{
  servo(2,120);
}
void ServoGripBack()
{
  servo(3,60);
}
void ServoPutBack()
{
  servo(3,115);
}
void ServoGripUpBack()
{
  servo(4,20);
}
void ServoGripDownHalfBack()
{
  servo(4,125);
}
void ServoGripDownBack()
{
  servo(4,145);
}
void Grip()
{
  OffMotor();
  ServoGrip();
  delay(150); 
}
void Put()
{
  OffMotor();
  ServoPut();
  delay(100);   
}
void GripUp()
{
  OffMotor(); 
  ServoGripUp();
  delay(300);
}
void GripDownHalf()
{
  OffMotor(); 
  ServoGripDownHalf();
  delay(200);
}
void GripDown()
{
  OffMotor(); 
  ServoGripDown();
  delay(300);
}
void GripBack()
{
  OffMotor();
  ServoGripBack();
  delay(150); 
}
void PutBack()
{
  OffMotor();
  ServoPutBack();
  delay(100);   
}
void GripUpBack()
{
  OffMotor(); 
  ServoGripUpBack();
  delay(200);
}
void GripDownHalfBack()
{
  OffMotor(); 
  ServoGripDownHalfBack();
  delay(200);
}
void GripDownBack()
{
  OffMotor(); 
  ServoGripDownBack();
  delay(50);
}
void ServoBoomDown()
{
  servo(6,140);
}
void ServoBoomUp()
{
  servo(6,90);
}
void BoomBalloon()  //ตีลูกโป่ง
{
  int BoomCount = 3;
  //MotorStop();
  ForwardSpeedTime(10,1);
  for(int i=1; i<=BoomCount; i++)
  {
    ServoBoomDown();
    delay(300);
    ServoBoomUp();
    if(i<BoomCount) delay(300);
  }
}
