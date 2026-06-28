const int rled = 2;
const int yled = 3;
const int gled = 4;
const int button = 7;

void setup() {
  pinMode(rled, OUTPUT);
  pinMode(yled, OUTPUT);
  pinMode(gled, OUTPUT);

  pinMode(button, INPUT_PULLUP);

  Serial.begin(9600);}

void showred() {
  digitalWrite(rled, HIGH);
  digitalWrite(yled, LOW);
  digitalWrite(gled, LOW);

  Serial.print(millis());
  Serial.println(" ms : RED");}

void showyellow() {
  digitalWrite(rled, LOW);
  digitalWrite(yled, HIGH);
  digitalWrite(gled, LOW);

  Serial.print(millis());
  Serial.println(" ms : YELLOW");}

void showgreen() {
  digitalWrite(rled, LOW);
  digitalWrite(yled, LOW);
  digitalWrite(gled, HIGH);

  Serial.print(millis());
  Serial.println(" ms : GREEN");}

void pedestrian() {
  showred();
  Serial.print(millis());
  Serial.println(" ms : Pedestrian Button Pressed");
  delay(8000);}

void loop() {

  // Check if pedestrian button is pressed
  if (digitalRead(button) == LOW) {
    pedestrian();
    return;}

  showred();
  delay(5000);

  if (digitalRead(button) == LOW) {
    pedestrian();
    return;}

  showyellow();
  delay(2000);

  if (digitalRead(button) == LOW) {
    pedestrian();
    return;}

  showgreen();
  delay(4000);}
