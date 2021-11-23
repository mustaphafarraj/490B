#include "hc-sr04.h"
#include "tm4c123gh6pm.h"
#include "UART.h"
#include "Speaker.h"

// user button connected to PF4 (increment counter on falling edge)


void DisableInterrupts(void); // Disable interrupts
void EnableInterrupts(void);  // Enable interrupts
long StartCritical (void);    // previous I bit, disable interrupts
void EndCritical(long sr);    // restore I bit to previous value
void WaitForInterrupt(void);  // low power mode
void OutCRLF(void)
{
	UART0_OutChar(CR);
	UART0_OutChar(LF);
}


int sprintf(char*, const char*, ...);

//debug code
int main(void){
	
	int32_t dist = 0;
	int32_t left = 0;
	int32_t middle = 0;
	int32_t right = 0;
	char distStr0[20] = "";
	char distStr1[20] = "";
	char distStr2[20] = "";
	//PLL_Init();
	UART0_Init();
	InitRegisters();
	Timer0A_init();
	Timer2A_init(); 
	Timer3A_init();
  while(1){
   
		dist = measureD(0);
		middle = dist;
		OutSignal(dist);
		
	  sprintf(distStr0, "%d middle cm0     ", middle);
		UART_OutString(distStr0);
		//OutSoundMiddle(middle);

	//	delay_Microsecond(3000000);

		
		dist = measureD(1);
		left = dist;
	  OutSignal(dist);
	//	OutSoundLeft(left);
	  sprintf(distStr1, "%d left cm1     ", left);
	  UART_OutString(distStr1);
	//	delay_Microsecond(3000000);
		
		dist = measureD(2);
		right = dist;
	//	OutSoundRight(right);
		OutSignal(dist);
	  sprintf(distStr2, "%d right cm2     ", right);
		
	  UART_OutString(distStr2); 
	//	OutSoundRight(right);
	
		UART0_OutChar(CR);
		UART_OutString("\n");
		
		delay_Microsecond(10000);
	//	delay_Microsecond(3000000);
  }
}
