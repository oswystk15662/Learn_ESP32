/*

#include <Arduino.h>
#include <ArduinoEigenDense.h>

using namespace Eigen;

void setup() {
  Serial.begin(9600);
  Serial.println("start");
  delay(2000);

  MatrixXd m(3, 3);
  m <<  1, 2, 3,
        4, 5, 6,
        7, 8, 9;

  //m = (m + Matrix3d::Constant(1.2)) * 50;

  Serial.println("m =");
  Serial.print(m(0, 0));
  Serial.print(" ");
  Serial.print(m(0, 1));
  Serial.print(" ");
  Serial.print(m(0, 2));
  Serial.println();
  Serial.print(m(1, 0));
  Serial.print(" ");
  Serial.print(m(1, 1));
  Serial.print(" ");
  Serial.print(m(1, 2));
  Serial.println();
  Serial.print(m(2, 0));
  Serial.print(" ");
  Serial.print(m(2, 1));
  Serial.print(" ");
  Serial.print(m(2, 2));
  Serial.println();

  Vector3d v(1, 2, 3);
  Vector3d vo = m * v;

  Serial.println("m * v =");
  Serial.print(vo(0));
  Serial.println();
  Serial.print(vo(1));
  Serial.println();
  Serial.print(vo(2));
  Serial.println();
}

void loop() {}

*/