void TracJCStopBack() 
{  
  InitialSpeed();
  TracSpeedTimeBack(BaseSpeed,5000/BaseSpeed);
  CalErrorBack();
  while(Error<100)
  {
      TracPIDBack();
      StartTimer();
      while((ReadTimer()<KtB)&&(Error<100))
      {
        CalErrorBack();           
      }
  }
}
void TracJCBack() 
{
  TracJCStopBack();
  Backward();
  if(BaseSpeed<=50) delay(9000/BaseSpeed);
  else if(BaseSpeed<=60) delay(7000/BaseSpeed); 
  else if(BaseSpeed<=70) delay(4000/BaseSpeed);
  else if(BaseSpeed<=80) delay(2000/BaseSpeed);
  else if(BaseSpeed<=90) delay(1000/BaseSpeed);
  else if(BaseSpeed<=100) delay(500/BaseSpeed);
}
void TracSpeedTimeBack(int TracSpeed, int TracTime) {
  int TempSpeed=BaseSpeed;
  BaseSpeed = TracSpeed;
  InitialSpeed();
  StartTimer();
  CalErrorBack();
  while(ReadTimer()<TracTime)
  {
    TracPIDBack();
    delay(Kt);
    CalErrorBack();
    if(Error>99) Error=0;
  }
  BaseSpeed = TempSpeed;
  InitialSpeed();
}
void TracJCSpeedTimeBack(int MotorSpeed, int TimeDelay) {
  int TempSpeed=BaseSpeed;
  BaseSpeed = MotorSpeed;
  TracJCStopBack();
  Backward();
  delay(TimeDelay);
  BaseSpeed = TempSpeed;
  InitialSpeed();
}
void TracJCStopBack0()
{
  //TracSpeedTimeBack(ACCSpeed,10000/ACCSpeed);
  if(BaseSpeed>=95) TracJCSpeedTimeBack(95,0);
  else TracJCBack();
}
void TracJCSpeedBack() 
{
  int TempSpeed=BaseSpeed;
  BaseSpeed = ACCSpeed;
  TracJCStopBack();
  Backward();
  while(Error>=100)
  {
    CalError();
  }
  delay(6000/BaseSpeed);
  BaseSpeed = TempSpeed;
  InitialSpeed();
}
