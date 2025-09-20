void TracJCStop() 
{  
  InitialSpeed();
  TracSpeedTime(BaseSpeed,3000/BaseSpeed);
  CalError();
  while(Error<99)
  {
    TracPID();
    StartTimer();
    CalError();
    while((ReadTimer()<Kt)&&(Error<99))
    {
      CalError();
    }
  }
}
void TracJC() 
{
  TracJCStop();
  TuneJC();
}
void TuneJC()
{
  Forward();
  if(BaseSpeed<=50) delay(7000/BaseSpeed);
  else if(BaseSpeed<=60) delay(5000/BaseSpeed); 
  else if(BaseSpeed<=70) delay(3000/BaseSpeed);
  else if(BaseSpeed<=80) delay(2000/BaseSpeed);
  else if(BaseSpeed<=90) delay(1000/BaseSpeed);
  else if(BaseSpeed<=100) delay(500/BaseSpeed);
}
void TracJCStraight() 
{
  TracJC();
  ForwardDelay(5000/BaseSpeed);
}
void TracJCSlowStop() 
{
  int TempSpeed=BaseSpeed;
  BaseSpeed = SlowSpeed;
  TracJCStop();
  BaseSpeed = TempSpeed;
  InitialSpeed();
}
void TracJCSlow() {
  TracJCSlowStop();
  Forward();
  while(Error>=100)
  {
    CalError();
  }
}
void TracJCSpeedTime(int MotorSpeed, int TimeDelay) {
  int TempSpeed=BaseSpeed;
  BaseSpeed = MotorSpeed;
  TracJCStop();
  Forward();
  delay(TimeDelay);
  BaseSpeed = TempSpeed;
  InitialSpeed();
}
void TracJCSpeed() 
{
  int TempSpeed=BaseSpeed;
  BaseSpeed = ACCSpeed;
  TracJCStop();
  Forward();
  delay(1000/BaseSpeed);
  while(Error>=100)
  {
    CalError();
  }
  delay(1000/BaseSpeed);
  BaseSpeed = TempSpeed;
  InitialSpeed();
}
void TracSpeedTime(int TracSpeed, int TracTime) {
  int TempSpeed=BaseSpeed;
  BaseSpeed = TracSpeed;
  InitialSpeed();
  StartTimer();
  CalError();
  while(ReadTimer()<TracTime)
  {
    TracPID();
    delay(Kt);
    CalError();
    if(Error>99) Error=0;
  }
  BaseSpeed = TempSpeed;
  InitialSpeed();
}
void TracJCSpeedStop() 
{
  int TempSpeed=BaseSpeed;
  BaseSpeed = ACCSpeed;
  TracJCStop();
  BaseSpeed = TempSpeed;
  InitialSpeed();
}
void TracJCSpeedStop99() 
{
  int TempSpeed=BaseSpeed;
  BaseSpeed = ACCSpeed;
  TracJCStop99();
  BaseSpeed = TempSpeed;
  InitialSpeed();
}
void TracJCStop99() 
{
  InitialSpeed();
  TracSpeedTime(BaseSpeed,5000/BaseSpeed);
  CalError();
  while(Error<99)
  {
    TracPID();
    StartTimer();
    while((ReadTimer()<Kt)&&(Error<99))
    {
      Error99Check = 1;
      CalError();
    }
  }
}
void TracJC99() 
{
  TracJCStop99();
  TuneJC();
}
void TracJCSlowStop99() 
{
  int TempSpeed=BaseSpeed;
  BaseSpeed = SlowSpeed;
  InitialSpeed();
  CalError();
  while(Error<99)
  {
    TracPID();
    StartTimer();
    while((ReadTimer()<Kt)&&(Error<99))
    {
      Error99Check = 1;
      CalError();
    }
  }
  BaseSpeed = TempSpeed;
  InitialSpeed();
}
void TracJCStopLorR() //ใช้เซ็นเซอร์ซ้ายหรือขวาในการเช็คแยก
{  
  InitialSpeed();
  TracSpeedTime(BaseSpeed,10000/BaseSpeed);
  CalError();
  while((L2==1)&&(R2==1))
  {
    TracPID();
    StartTimer();
    CalError();
    while((ReadTimer()<Kt)&&(Error<100))
    {
      CalError();
      if(Error>99) Error=0;
    }
  }
}
void TracJCLorR()     //ใช้เซ็นเซอร์ซ้ายหรือขวาในการเช็คแยก
{
  TracJCStopLorR();
  TuneJC();
}
void TracJCSpeedLorR()  //ใช้เซ็นเซอร์ซ้ายหรือขวาในการเช็คแยก
{
  int TempSpeed=BaseSpeed;
  BaseSpeed = ACCSpeed;
  TracJCStopLorR();
  Forward();
  while(Error>=100)
  {
    CalError();
  }
  delay(3000/BaseSpeed);
  BaseSpeed = TempSpeed;
  InitialSpeed();
}
void TracJCStopL() //ใช้เซ็นเซอร์ซ้ายในการเช็คแยก
{  
  InitialSpeed();
  TracSpeedTime(BaseSpeed,10000/BaseSpeed);
  CalError();
  while((L2==1))
  {
    TracPID();
    StartTimer();
    CalError();
    while((ReadTimer()<Kt)&&(Error<100))
    {
      CalError();
      if(Error>99) Error=0;
    }
  }
}
void TracJCL()     //ใช้เซ็นเซอร์ซ้ายในการเช็คแยก
{
  TracJCStopL();
  TuneJC();
}
void TracJCStopR() //ใช้เซ็นเซอร์ขวาในการเช็คแยก
{  
  InitialSpeed();
  TracSpeedTime(BaseSpeed,10000/BaseSpeed);
  CalError();
  while((R2==1))
  {
    TracPID();
    StartTimer();
    CalError();
    while((ReadTimer()<Kt)&&(Error<100))
    {
      CalError();
      if(Error>99) Error=0;
    }
  }
}
void TracJCR()     //ใช้เซ็นเซอร์ขวาในการเช็คแยก
{
  TracJCStopR();
  TuneJC();
}
