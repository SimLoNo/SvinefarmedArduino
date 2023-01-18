
int uvSensorPin = A2; // A variable to store the pin for the Temperature sensor.

int UvUpdateInputStatus() // The method that receives the Temperature input from the temperature sensor.
{
  int ClassUvInput = analogRead(uvSensorPin); // Receives the input from the temperature sensor.
  // Prints the Uv input to the serial.
  Serial.print("UV input: ");
  Serial.println(ClassUvInput);
  return ClassUvInput;
}