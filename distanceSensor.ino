#define DISTSENSOR A0

int distanceReading(){
  int dist = analogRead(DISTSENSOR-14);
  Serial.println(dist);
  return dist;
}
