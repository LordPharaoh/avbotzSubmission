
//#include _quadcopter.h_
#define FL 0;
#define FR 1;
#define BR 2;
#define BL 3;
int motors [4] = {127, 127, 127, 127};
int pitch, roll, height;
int main()
{
  while(true)
  {
      motors.fill(127);
      pitch = getPitch();
      roll = getRoll();
      height = getHeight();
      for(int i = 0; i < 4; i++)
      {
          motors[i] = motors[i] - ((height - 127)/2)
      }
      motors[FL] = motors[FL] + (pitch/4);
      motors[FR] = motors[FR] + (pitch/4);
      motors[BR] = motors[BR] - (pitch/4);
      motors[BL] = motors[BL] - (pitch/4);

      motors[FL] = motors[FL] + (roll/4);
      motors[FR] = motors[FR] - (roll/4);
      motors[BR] = motors[BR] - (roll/4);
      motors[BL] = motors[BL] + (roll/4);

      for(int i = 0; i < 4; i++)
	{
		motors[i] = bounds(motors[i])    
	}
	setFR(motors[FR]);
	setFL(motors[FL]);
	setBR(motors[BR]);
	setBL(motors[BL]);
  }
}
int bounds (int input)
{
	if(input < 0) input = 0;
	if(input > 255) input = 255;
}
