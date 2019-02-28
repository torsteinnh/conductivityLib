#include <conductivityLib.h>

conductivitySensor mysensor(3, 4, 1);
int myreading;
int resistance;

void setup() {
  // Set upp serial for debugging
  Serial.begin(9600);

  Serial.println("Finished setup");
}

void loop() {
  Serial.println("Start of loop");

  mysensor.measure();
  myreading = mysensor.getValue();
  resistance = mysensor.resistance();

  Serial.print("The value meausred was: ");
  Serial.print(myreading);
  Serial.print("\tThe resistance in the sensor was: ");
  Serial.println(resistance);

  myreading.noCurrent();

  delay(1000);
}
