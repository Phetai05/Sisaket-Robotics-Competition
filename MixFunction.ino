void PassHole()
{
  TracJC99();
  ForwardSpeedTime(60,80);
}
void JC(int Count)  //เดินข้ามแยก
{
  while(Count>1)
  {
    TracJCSpeed();
    Count--;
  }
  TracJC();
}
void JCBack(int Count)  //เดินถอยหลังข้ามแยก
{
  while(Count>1)
  {
    TracJCSpeedBack();
    Count--;
  }
  TracJCBack();
}
void PutBox1_2()
{
  TracSpeedTime(SonarSpeed,270);
  GripDown();
  Put();
  ServoGripUp();
}
void PutBox1_2Back()
{
  TracSpeedTimeBack(SonarSpeed,290);
  GripDownBack();
  PutBack();
  ServoGripUpBack();
}
void PutBoxAJ()
{
  TracSpeedTime(SonarSpeed,380);
  GripDown();
  Put();
  ServoGripUp();
}
void PutBoxAJBack()
{
  TracSpeedTimeBack(SonarSpeed,380);
  GripDownBack();
  PutBack();
  ServoGripUpBack();
}
