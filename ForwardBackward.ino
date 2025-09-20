void RobotStart() 
{
  ForwardSpeedTime(60,200);
}

void Forward() {
  if(WheelDrive==0) fd2(LeftBaseSpeed, RightBaseSpeed);
  else FD2(LeftBaseSpeed, RightBaseSpeed);
}
void ForwardDelay(int Time) {
  Forward();
  delay(Time);
}
void ForwardSpeedDelay(int Time) {
  int TempSpeed=BaseSpeed;
  BaseSpeed = ACCSpeed;
  InitialSpeed();
  Forward();
  delay(Time);
  BaseSpeed = TempSpeed;
  InitialSpeed();
}
void ForwardSpeedTime(int MotorSpeed, int Time) {
  int TempSpeed=BaseSpeed;
  BaseSpeed = MotorSpeed;
  InitialSpeed();
  Forward();
  delay(Time);
  BaseSpeed = TempSpeed;
  InitialSpeed();
}
void Backward() {
  if(WheelDrive==0) bk2(BackLeftBaseSpeed, BackRightBaseSpeed);
  else BK2(BackLeftBaseSpeed, BackRightBaseSpeed);
}
void BackwardDelay(int Time) {
  Backward();
  delay(Time);
}
void BackwardSpeedTime(int MotorSpeed, int Time) {
  int TempSpeed=BaseSpeed;
  BaseSpeed = MotorSpeed;
  InitialSpeed();
  Backward();
  delay(Time);
  BaseSpeed = TempSpeed;
  InitialSpeed();
}
void MotorStop() {
  OffMotor();
  //delay(10);
}
void OffMotor()
{
  if(WheelDrive==0) ao();   else AO();
}
void ChangeSpeed(int NewSpeed,int NewACCSpeed)
{
  Speed =NewSpeed;
  ACCSpeed =NewACCSpeed;
  BaseSpeed = NewSpeed; 
  TurnSpeed = NewSpeed;
}
