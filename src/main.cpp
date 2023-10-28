// 参考　https://programresource.net/2020/02/25/2994.html

#include <Arduino.h>
#include <ArduinoEigen.h>
#include <FS.h>
#include <SPIFFS.h>

using namespace Eigen;
using namespace fs;

SemaphoreHandle_t xMutex = NULL; 
volatile int intdata = 0;

unsigned int cnt = 0;
 
Vector2d global_pos;
constexpr uint8_t pin_sw = 23;

constexpr bool FORMAT_SPIFFS_IF_FAILED = true;
String path = "/coner_points.txt";

void subProcess(void * pvParameters) {
    File f_cp;

    while (1) {
        if (xSemaphoreTake( xMutex, ( portTickType ) 100 ) == pdTRUE) {
            if(digitalRead(pin_sw) == HIGH){
                f_cp = SPIFFS.open(path, FILE_WRITE);//file coner points
                f_cp.printf("%f,%f, cnt = %d\n", global_pos.x(), global_pos.y(), cnt);
                //Serial.println(f_cp.size());
                f_cp.close();
                cnt++;
            }

            xSemaphoreGive(xMutex);
        }
        delay(1);
    }
}
 
void u_main(){
    pinMode(pin_sw, INPUT_PULLDOWN);

    Serial.begin(9600);
 
    xMutex = xSemaphoreCreateMutex();
    xSemaphoreGive(xMutex);
    xTaskCreatePinnedToCore(subProcess, "subProcess", 4096, NULL, 1, NULL, 0); //Core 0でタスク開始

    SPIFFS.begin(FORMAT_SPIFFS_IF_FAILED);
    File f_cp;

    while(1){
        if (xSemaphoreTake( xMutex, ( portTickType ) 100 ) == pdTRUE) {
            if(Serial.available() == 1){// when there is 1 byte data in buffer.
                switch (Serial.read())
                {
                    case 'w' : global_pos += Vector2d(0.0f, 1.0f); break;
                    case 'a' : global_pos += Vector2d(-1.0f, 0.0f); break;
                    case 's' : global_pos += Vector2d(0.0f, -1.0f); break;
                    case 'd' : global_pos += Vector2d(1.0f, 0.0f); break;
                    
                    case 'f' :
                        f_cp = SPIFFS.open(path, FILE_READ);//file coner points
                        Serial.println(f_cp.readStringUntil('\n'));
                        f_cp.close();
                    break;

                    default: break;
                }
            }

            xSemaphoreGive(xMutex);
        }
        delay(1);
    }
}

void setup() {
    u_main();
}
 
void loop() {}

/*


float global_rot; // -pi ~ pi

void go_forward(){

}

void get_pos{// betsu sureddo

}



*/