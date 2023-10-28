/*#include <Arduino.h>
#include <FS.h>
#include <SPIFFS.h>

constexpr bool FORMAT_SPIFFS_IF_FAILED = true;

using namespace fs;

void u_main(){
  Serial.begin(9600);
  Serial.println("start");

  String path = "/hello.txt";
  SPIFFS.begin(FORMAT_SPIFFS_IF_FAILED);

  File fw = SPIFFS.open(path, FILE_WRITE);
  fw.println("Hello world!");
  fw.close();

  File fr = SPIFFS.open(path, FILE_READ);
  while(fr.available()){
    String str = fr.readString();
    Serial.println(str);
    delay(100);
  }
  fr.close();
}

void setup() { u_main(); }
void loop() {}*/