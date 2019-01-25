#include <conductivityLib.h>

conductivitySensor mysensor(3, 4, 1);
int myreading;

void setup() {
  // Set upp serial for debugging
  Serial.begin(9600);

  Serial.println("Finished setup");
}

void loop() {
  Serial.println("Start of loop");

  mysensor.measure();
  myreading = mysensor.getValue();

  Serial.print("The value meausred was: ");
  Serial.println(myreading);

  myreading.sleep();

  delay(1000);
}
