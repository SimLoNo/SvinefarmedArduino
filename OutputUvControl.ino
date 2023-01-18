
int uvOnLimit = 150; // A variable to store the limit of the UV LED being off.

int UvChangeDeviceStatus(int input) // The method that controls the UV LED output.
{
  int classUvStatus; // A variable to store the output status.
  if(input > uvOnLimit) // If the input is above the limit for it to be turned off, turn the UV LED on.
  {
    digitalWrite(uvLightPin, HIGH);
    classUvStatus = 1;
  }
  else // Else turn the UV LED off.
  {
    digitalWrite(uvLightPin, LOW);
    classUvStatus = 0;
  }
  return classUvStatus;
}