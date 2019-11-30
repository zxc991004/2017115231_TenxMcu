#define __main_c
#include "includeAll.h"
//=============================================================================
void main() {
  SysInit();
  VarsInit();
  //使能看门狗
  F_turnOnWDT();            //打开watchdog
  while (1) {
    //喂狗
    F_clearWDT();
    //业务代码
    TimeProcess();          //时间进程
    TaskSetting();          //设置任务  
    TaskProcess();          //任务进程  
    DisplayProcess();       //显示进程
  }
}
//=============================================================================
void TimeProcess() {
  static uint8_t timer5ms = 0;
  static uint16_t second = 0;

  if (b1ms) {
    // 1ms 执行一次
    b1ms = 0;
    timer5ms++;
    second++;
  }
  if (timer5ms >= D_5ms) {
    // 5ms 执行一次
    timer5ms = 0;
    GetKeys();
  }
  if (second >= D_1000ms) {
    // 1s 执行一次
    second = 0;
  }
}
//=============================================================================
void TaskProcess() {}
//=============================================================================
void TaskSetting() {
  if (D_keyValue1 == keyValue) {
    bLedFlash = ~bLedFlash;
  }
  keyValue = D_keyNull;
}
//=============================================================================
void DisplayProcess() {
  // F_ledOn();
  if (bLedFlash) {
    F_ledOn();        //led灯开
  } else {
    F_ledOff();       //led灯关
  }
}