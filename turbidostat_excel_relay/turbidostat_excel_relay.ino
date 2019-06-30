int led = 13; //LED Pin that stays on until threshold is reached for dilution
int M1 = 3; // this is connected to the relay where the motor is connected and powered in parallel


void setup() {
  Serial.begin(9600); //Baud rate: 9600
  Serial.println("CLEARDATA"); //clears up any data left from previous projects this code from CrtSuznik instructable. must has PX-LAB installed and the spreadsheet open

  Serial.println("LABEL,Acolumn,Bcolumn,..."); //always write LABEL, so excel knows the next things will be the names of the columns (instead of Acolumn you could write Time for instance)

  Serial.println("RESETTIMER"); //resets timer to 0

  pinMode(M1, OUTPUT);
}
void loop() {
  int sensorValue = analogRead(A0);// read the input on analog pin 0 this code for DF Robot turbidity sensor
  float voltage = sensorValue * (5.0 / 1024.0); // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  Serial.println(voltage); // print out the value you read:
  
  if (voltage > 2) digitalWrite(led, HIGH);//beginning of loop that determines if culture needs diluted. prototype using voltage - this will need another line of code and OD calibration to compute voltage to OD. This line for LED that should go in tandem
  else digitalWrite(led, LOW);
  if (voltage > 2) digitalWrite(M1, HIGH);//beginning of loop that determines if culture needs diluted. prototype using voltage - this will need another line of code and OD calibration to compute voltage to OD
  else digitalWrite(M1, LOW);
  
  //next lines are from instructable by CrtSuznik for exporting data to excel
  Serial.print("DATA,TIME,TIMER,"); //writes the time in the first column A and the time since the measurements started in column B

  Serial.print(voltage);//be sure to add println to the last command so it knows to go into the next row on the second run
  delay(500);
}
