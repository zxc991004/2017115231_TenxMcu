#define __init_c
#include "includeAll.h"
//=============================================================================
void SysInit() {
  //时钟初始化
  CLKCON = 0x02; // Clock div 2
  STPPCK = 0;
  STPFCK = 0;
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  SELFCK = 1;
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  _nop_();
}
// IO 模式初始化
P1MODL = 0xaa;

// IO 状态初始化
F_ledOff();
}
//=============================================================================
void VarsInit() {}