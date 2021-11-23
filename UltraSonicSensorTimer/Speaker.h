#include "tm4c123gh6pm.h"
#include <stdint.h>

void DisableInterrupts(void); // Disable interrupts
void EnableInterrupts(void);  // Enable interrupts
void delay(unsigned long msec);
void DAC_Out(unsigned long data); 
void Delay(void);
void Piano_Sound(void);
void Speakers(void);
void OutSoundMiddle(uint32_t value);
void OutSoundLeft(uint32_t value);
void OutSoundRight(uint32_t value);
void Speaker_Init(void);

void D_Init(void);
void D_Out(unsigned long data);
