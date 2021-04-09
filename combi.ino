int smoke=A2; // ouput of smoke sensor
int buzzer=3;// buzzer pin
int sensorThres=188; //sensor threshold value
int PIR_output=10; // output of pir sensor

void setup () {
pinMode(smoke, INPUT) ;// setting smoke sensor output as arduino input
pinMode(buzzer, OUTPUT);//setting buzzer as ouput
pinMode(PIR_output, INPUT);// setting pir output as arduino input
Serial.begin(9600);//serial communication between arduino and pc
digitalWrite(buzzer, HIGH); // setting buzzer OFF
delay(15000); // wait for a 15 second for initialization
}

void loop () {
  //SMOKE SENSOR
int analogSensor=analogRead(smoke);//read data from the smoke sensor
Serial.println("pin A2:");
Serial.println(analogSensor);
delay (500); // delay for half second

//PIR SENSOR
int sensorValue=digitalRead(PIR_output);
Serial.println(sensorValue);
delay (500); // delay for half second

//CHOOSE ACTION HERE BASED ON SENSOR VALUES
if(analogSensor > sensorThres) // if smoke sensor detects smoke
{
 Serial.println("smoke detected");
 digitalWrite(buzzer, LOW);
 delay(1000); // wait for a second
  digitalWrite(buzzer, HIGH); // setting buzzer to OFF
 delay(7000);
}

if(sensorValue == HIGH) // reading the data from the pir sensor
{
 digitalWrite(buzzer, LOW); // setting buzzer to ON
 Serial.println("motion detected");
 delay(1000); // wait for a second 
 digitalWrite(buzzer, HIGH); // setting buzzer to OFF
 delay(7000);
}

else {
 digitalWrite(buzzer, HIGH); // setting buzzer to low
 Serial.println("scanning");
 delay(1000); // wait for second
}

delay(500);
}
