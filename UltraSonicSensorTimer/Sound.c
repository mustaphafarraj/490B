// Sound.c

#include "Sound.h"
#include "Speaker.h"
#include "tm4c123gh6pm.h"

unsigned char Index;
const unsigned char SineWave64[64] = {32,35,38,41,44,47,49,52,54,56,58,59,61,
									  62,62,63,63,63,62,62,61,59,58,56,54,52,
									  49,47,44,41,38,35,32,29,26,23,20,17,15,
									  12,10,8,6,5,3,2,2,1,1,1,2,2,3,5,6,8,10,
									  12,15,17,20,23,26,29};
int sound_enable;

void Sound_Init(void){
	Speakers();
	sound_enable=0;
	Index = 0;
	NVIC_ST_CTRL_R = 0;           // disable SysTick during setup
  NVIC_ST_RELOAD_R = C64;    // reload value
  NVIC_ST_CURRENT_R = 0;        // any write to current clears it
  NVIC_SYS_PRI3_R = (NVIC_SYS_PRI3_R&0x00FFFFFF)|0x20000000; // priority 1
  NVIC_ST_CTRL_R = 0x00000007;  // enable with core clock and interrupts
}

void Sound_Tone(unsigned long period){
// this routine sets the RELOAD and starts SysTick
	NVIC_ST_RELOAD_R = period;    // reload value
	sound_enable = 1;
}

void Sound_Off(void){
	sound_enable=0;
	DAC_Out(0x00);
}

void SysTick_Handler(void){
	Index = (Index+1)&0x0F;  
	if(sound_enable) {
		DAC_Out(SineWave64[Index]);
	}
}
