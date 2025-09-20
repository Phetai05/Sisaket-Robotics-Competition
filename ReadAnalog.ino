void Read5Analog() {
  L2 = analog(0);
  L1 = analog(1);
  C = analog(2);
  R1 = analog(3);
  R2 = analog(4);
}
void Read4AnalogBack() {
  BL2 = analog(5); 
  BL1 = analog(6);
  BR1 = analog(7); 
  BR2 = analog(8);
}
int Sonar()
{
  int Sonar;
   
  //Sonar = (analog(8)/40); //ZX-sonar
  Sonar = analog(8);   //infrared
  Sonar -= 1150; 
  if(Sonar<=0) Sonar = 1;
  Sonar = 6000/Sonar;
  return(Sonar);
}
