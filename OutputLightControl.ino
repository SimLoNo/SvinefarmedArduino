
int lightDarkLimit = 70; // The input limit for it to be dark.
int lightOvercastLimit = 200; // The input limit for it to be overcast


int LightChangeDeviceStatus(int input) // The method that controls the LED output
{
  int classLightStatus; // A variable that stores the LED output status.
  if(input > lightOvercastLimit) // If the input is higher than overcast, it is light
  {
    digitalWrite(lightGroup1Pin, HIGH);
    digitalWrite(lightGroup2Pin, HIGH);
    classLightStatus = 2;
  }
  else if(input > lightDarkLimit) // Else if the input is higher than dark, it is overcast.
  { 
    digitalWrite(lightGroup1Pin, HIGH);
    digitalWrite(lightGroup2Pin, LOW);
    classLightStatus = 1;
  }
  else // If nothing else, it is dark.
  {
    digitalWrite(lightGroup1Pin, LOW);
    digitalWrite(lightGroup2Pin, LOW);
    classLightStatus = 0;
  }
  return classLightStatus;
}