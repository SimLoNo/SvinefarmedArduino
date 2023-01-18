int lightSensorPin = A0; // A variable to store the pin for the light sensor.

int LightUpdateInputStatus() // The method that receives input from the light sensor.
{
  int ClassLightInput = analogRead(lightSensorPin); // Receives and stores the light sensor input.
  // Print the light input to the serial.
  Serial.print("light input: ");
  Serial.println(ClassLightInput);
  return ClassLightInput;
}