int buttonstate = 0;
const int LED = 3;

void setup()
{
  pinMode(2, INPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  buttonstate = digitalRead(2);
  Serial.println(buttonstate);
  if(buttonstate == 1){
    digitalWrite(LED, HIGH);}
  else{
    digitalWrite(LED, LOW);}
  delay(1000);
}
