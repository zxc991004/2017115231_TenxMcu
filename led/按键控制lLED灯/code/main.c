#define __main_c
#include "includeAll.h"
//=============================================================================
void main() {
  SysInit();
  VarsInit();
  F_ledOn();
  delayMs(500);
  while (1) {
    //喂狗
    // F_turnOnWDT();         //打开watchdog
    // user coding
    // F_ledOff();            //控制led灯关
    // delayMs(500);          //延迟0.5s
    // F_ledOn();             //控制led灯开
    // delayMs(500);          //延迟0.5s
    GetKeys();
    if (D_keyValue1 == keyValue) {
      F_ledNeg();
    }
    keyValue = D_keyNull;
  }
}
//=============================================================================
void delayMs(uint16_t msCount) {
  uint16_t i, j;
  for (i = 0; i < msCount; i++) {
    for (j = 0; j < 1000; j++) {

    }
  }
}
