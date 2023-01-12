const int TRIGGER_PIN = 3;
const int ECHO_PIN = 5;

const long MAX = 14;
const long MIN = 2;

void setup() {
  Serial.begin (9600);
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

// functional W
long get_percentage(long x, long minimum, long maximum) {
  return map(constrain(x, minimum, maximum), minimum, maximum, 100, 0);
}

long get_raw_distance() {
  // Requires delay 500 ms before rereading
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2); 
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10); 
  digitalWrite(TRIGGER_PIN, LOW);
  long duration, distance;
  duration = pulseIn(ECHO_PIN, HIGH);
  distance = (duration/2) / 29.1;
  delay(500);
  return distance;
}

void loop() {
    long distance = get_raw_distance();
    long p = get_percentage(distance, MIN, MAX);
    Serial.print(p);
    Serial.println(" %");
}
