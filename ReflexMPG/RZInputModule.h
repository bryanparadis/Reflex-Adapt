/*******************************************************************************
 * Base input module for RetroZord / Reflex-Adapt.
 * By Matheus Fraguas (sonik-br)
 * 
 * Uses a modified version of MPG
 * https://github.com/sonik-br/MPG
 *
*/

#ifndef RETROZORDINPUTMODULE_H_
#define RETROZORDINPUTMODULE_H_

#include "src/MPG/MPG.h"

#define DEFAULT_SLEEP_TIME 200 //micros

class RZInputModule : public MPG {
  public:
    RZInputModule(int debounceMS = 0) : MPG(debounceMS) { }
    static uint8_t totalUsb;
    static uint16_t sleepTime;
    static bool isPS3;
    virtual const char* getUsbId() = 0;
    virtual const uint16_t getUsbVersion() = 0;
    virtual void setup2() = 0;
    
//    #ifdef ENABLE_REFLEX_PAD
//      virtual void displayInputName() = 0;
//    #endif

  protected:
    void resetState(const uint8_t index);
    bool canChangeMode();
    uint16_t convertAnalog(uint8_t value, bool applyDeadzone = true);
    bool canUseAnalogTrigger();
};

#endif
