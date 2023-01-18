

// C++ code
//



// Variables to keep the pin number of the LED and Uv LED.
int lightGroup1Pin = 2;
int lightGroup2Pin = 3;
int uvLightPin = 4;



int lightStatus = 0;
int uvStatus = 0;

void setup()
{
  // Sets up the LED and UV LED pins to output
  pinMode(lightGroup1Pin, OUTPUT);
  pinMode(lightGroup2Pin, OUTPUT);
  pinMode(uvLightPin, OUTPUT);

  // Opens a serial connection
  Serial.begin(9600);
}

void loop()
{
  
  // Calls the method that will receive input from the Light sensor, and pass it to the LED control.
  ControlLightChangeDeviceStatus(lightStatus);
  
  // Calls the method that will receive input from the UV sensor, and pass it to the UV LED control.
  ControlUvChangeDeviceStatus(uvAnalogValue);
  
  delay(1000);
  
}

// This method handles the Light input and output.
void ControlLightChangeDeviceStatus(int oldLightStatus)
{
  int newLightInput = LightUpdateInputStatus(); // Calls the method to receive the light input, and saves the returned value
  int newLightStatus = LightChangeDeviceStatus(newLightInput); // Calls the method to control the LED output, and saves the returned LED output status
  if(newLightStatus != oldLightStatus) // If the LED output status has changed, save the new status.
  {
    lightStatus = newLightStatus;
  }
  // Log the lightstatus to the serial.
    Serial.print("light status: ");
    Serial.println(lightStatus);
}

// This method handles the UV input and output.
void ControlUvChangeDeviceStatus(int oldUvStatus)
{
  int newUvInput = UvUpdateInputStatus(); // Calls the method to receive the temperature input, and saves the returned value
  int newUvStatus = UvChangeDeviceStatus(newUvInput); // Calls the method to control the UV LED output, and saves the returned UV LED output status
  if(newUvStatus != uvStatus) // If the UV LED output status has changed, save the new status.
  {
    uvStatus = newUvStatus;
  }
  // Log the uvstatus to the serial.
    Serial.print("Uv status: ");
    Serial.println(uvStatus);
}




