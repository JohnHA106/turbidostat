int led = 13;

void setup() {
  Serial.begin(9600); //Baud rate: 9600
  Serial.println("CLEARDATA"); //clears up any data left from previous projects

  Serial.println("LABEL,Acolumn,Bcolumn,..."); //always write LABEL, so excel knows the next things will be the names of the columns (instead of Acolumn you could write Time for instance)

  Serial.println("RESETTIMER"); //resets timer to 0
}
void loop() {
  int sensorValue = analogRead(A0);// read the input on analog pin 0:
  float voltage = sensorValue * (5.0 / 1024.0); // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  Serial.println(voltage); // print out the value you read:
  if (voltage > 2) digitalWrite(led, HIGH);
  else digitalWrite(led, LOW);
  //next lines are from instructable by CrtSuznik for exporting data to excel
  Serial.print("DATA,TIME,TIMER,"); //writes the time in the first column A and the time since the measurements started in column B

  Serial.print(voltage);//be sure to add println to the last command so it knows to go into the next row on the second run
  delay(500);
}
