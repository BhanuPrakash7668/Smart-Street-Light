unsigned int IR_sensor1_value;
unsigned int IR_sensor2_value;

#define relay 12

void setup()
{
pinMode(relay, OUTPUT);

Serial.begin(9600); //set the baud rate of the serial monitor
}
int Counter=0;
void loop()
{

//IR sensor 1

IR_sensor1_value = analogRead(A0);
/*Serial.print("IR_sensor1_value: ");
Serial.print(IR_sensor1_value);*/
float raw_voltage1 = IR_sensor1_value*0.00488; //convert analog IR_sensor_value to voltage
//Serial.print("  Voltage1: ");
//Serial.println(raw_voltage1);

delay(200);

//IR sensor 2
IR_sensor2_value = analogRead(A1);
//Serial.print("IR_sensor2_value: ");
//Serial.print(IR_sensor2_value);
float raw_voltage2 = IR_sensor2_value*0.00488;
//Serial.print("  Voltage2: ");
//Serial.println(raw_voltage2);
delay(200);

if(IR_sensor1_value >= 500)
{
delay(100);
Counter=Counter+1;
Serial.println("Count"+Counter);
digitalWrite(relay, HIGH);  
Serial.println("IR sensor 1 detected");
}

if(IR_sensor2_value >= 500)
{
delay(100);
Counter=Counter-1;
Serial.println("Count"+Counter);
if(Counter==0)
{
  digitalWrite(relay, LOW);  
  Serial.println("IR sensor 2 detected");
}
}


Serial.println("               ");
delay(200);
}
