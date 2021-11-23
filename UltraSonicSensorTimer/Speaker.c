#include "Tm4c123gh6pm.h"
#include "Sound.h"
#include "Speaker.h"
#include "PLL.h"
#include "hc-sr04.h"
#define TONE_DURATION 8
#define NUM_VALS 64

unsigned long left;
unsigned long right;
unsigned long front;

struct Note{
	
	unsigned long tone_index;
	unsigned char delay;
};

typedef const struct Note NTyp;
// basic functions defined at end of startup.s
const unsigned long tonetab[] =
// C, D, E, F, G, A, B
// 1, 2, 3, 4, 5, 6, 7

{47778,42566,37921,35793,31888,28409,25310,
	23889,21283,18961,17897,15944,14205,12655,
	11945,10641,9480,8948,7972,7102,6328,
	11345,10641,9480,8948,7972,7102,6328};

void Speaker_Init(void) { volatile unsigned long delay;
	
	SYSCTL_RCGC2_R |= 0x08;
	delay = SYSCTL_RCGC2_R;
	
	GPIO_PORTD_AMSEL_R &= ~0x03;
	GPIO_PORTD_PCTL_R &= ~0x000000FF;
	GPIO_PORTD_DIR_R |= 0x03;
	GPIO_PORTD_AFSEL_R &= ~0x03;
	GPIO_PORTD_DEN_R |= 0x03;
}

void DAC_Out(unsigned long data){
GPIO_PORTD_DATA_R = (GPIO_PORTD_DATA_R & 0x0F) | (data & 0x0F);
}

void Speakers(void)
{
	/*
	direction of the speakers right, left, or front.
	right and left and front can be played together
	front will play both speakers
	while the left and right will play their corresponding speakers
	speakers and sensors work together
	
	*/
}

void OutSoundMiddle(uint32_t distance) {
	GPIO_PORTD_DATA_R &= ~(0x03);
  if(distance < 50) { 
    GPIO_PORTD_DATA_R |= (0x03);// open port D0-1
		
		// display sound B
	  delay_Microsecond(2000000);// delay 2 second
	
		GPIO_PORTD_DATA_R &= ~(0x03);// close D0-1
	}
  else if (distance < 100) {
   GPIO_PORTD_DATA_R |= (0x03);// open port D0-1
		
		// display sound A
	  delay_Microsecond(2000000);// delay 2 second
	
		GPIO_PORTD_DATA_R &= ~(0x03);// close D0-1
	}
	else if (distance < 150) {
		GPIO_PORTD_DATA_R |= (0x03);// open port D0-1
		
		// display sound G 
	  delay_Microsecond(2000000);// delay 2 second
	
		GPIO_PORTD_DATA_R &= ~(0x03);// close D0-1
	}
	else if (distance < 200) {
		GPIO_PORTD_DATA_R |= (0x03);// open port D0-1
		
		// display sound F
	  delay_Microsecond(2000000);// delay 2 second
	
		GPIO_PORTD_DATA_R &= ~(0x03);// close D0-1
	}
	else if (distance < 250) {
		GPIO_PORTD_DATA_R |= (0x03);// open port D0-1
		
		// display sound E
	  delay_Microsecond(2000000);// delay 2 second
	
		GPIO_PORTD_DATA_R &= ~(0x03);// close D0-1
	}
	else if (distance < 300) {
		GPIO_PORTD_DATA_R |= (0x03);// open port D0-1
		
		// display sound D
	  delay_Microsecond(2000000);// delay 2 second
	
		GPIO_PORTD_DATA_R &= ~(0x03);// close D0-1
	}
	else if (distance < 400) {
		GPIO_PORTD_DATA_R |= (0x03);// open port D0-1
		
		// display sound C
		
	  delay_Microsecond(2000000);// delay 2 second
	
		GPIO_PORTD_DATA_R &= ~(0x03);// close D0-1
	}
	else {
		GPIO_PORTD_DATA_R &= ~(0x03);// sound off D0-1
	}
}

void OutSoundLeft(uint32_t distance) {
	GPIO_PORTD_DATA_R &= ~(0x03);
  if(distance < 50) {
	GPIO_PORTD_DATA_R |= (0x01);// open port D0
		
		// display sound B
	  delay_Microsecond(2000000);// delay 2 second
	
		GPIO_PORTD_DATA_R &= ~(0x01);// close D0		
  
	}
  else if (distance < 100) {
   
			GPIO_PORTD_DATA_R |= (0x01);// open port D0
		
		// port D0 earphones A
	  delay_Microsecond(2000000);// delay 2 second
	
		GPIO_PORTD_DATA_R &= ~(0x01);// close D0	
	}
	else if (distance < 150) {
		
				GPIO_PORTD_DATA_R |= (0x01);// open port D0
		
		// port D0 earphones G
	  delay_Microsecond(2000000);// delay 2 second
	
		GPIO_PORTD_DATA_R &= ~(0x01);// close D0	
	}
	else if (distance < 200) {
		
				GPIO_PORTD_DATA_R |= (0x01);// open port D0
		
		// port D0 earphones F
	  delay_Microsecond(2000000);// delay 2 second
	
		GPIO_PORTD_DATA_R &= ~(0x01);// close D0	
	}
	else if (distance < 250) {
		
		GPIO_PORTD_DATA_R |= (0x01);// open port D0
		
		// port D0 earphones E
	  delay_Microsecond(2000000);// delay 2 second
	
		GPIO_PORTD_DATA_R &= ~(0x01);// close D0	
	}
	else if (distance < 300) {
	
				GPIO_PORTD_DATA_R |= (0x01);// open port D0
		
		// port D0 earphones D
	  delay_Microsecond(2000000);// delay 2 second
	
		GPIO_PORTD_DATA_R &= ~(0x01);// close D0	
	}
	else if (distance < 400) {
	
				GPIO_PORTD_DATA_R |= (0x01);// open port D0
		
		// port D0 earphones C
	  delay_Microsecond(2000000);// delay 2 second
	
		GPIO_PORTD_DATA_R &= ~(0x01);// close D0	
	}
	else {
		GPIO_PORTD_DATA_R &= ~(0x03);// sound off D0-1
		
	}
}

void OutSoundRight(uint32_t distance) {
	GPIO_PORTD_DATA_R &= ~(0x03);
  if(distance < 50) { 
		GPIO_PORTD_DATA_R |= (0x02);// open port D0
		
		// port D1 earphones B
	  delay_Microsecond(2000000);// delay 2 second
	
		GPIO_PORTD_DATA_R &= ~(0x02);// close D0	
    
		
	}
  else if (distance < 100) {
  
				GPIO_PORTD_DATA_R |= (0x02);// open port D0
		
		 // port D1 earphones A
	  delay_Microsecond(2000000);// delay 2 second
	
		GPIO_PORTD_DATA_R &= ~(0x02);// close D0
	}
	else if (distance < 150) {
		
		GPIO_PORTD_DATA_R |= (0x02);// open port D0
		
		 // port D1 earphones G
	  delay_Microsecond(2000000);// delay 2 second
	
		GPIO_PORTD_DATA_R &= ~(0x02);// close D0
	}
	else if (distance < 200) {
		
		GPIO_PORTD_DATA_R |= (0x02);// open port D0
		
		 // port D1 earphones F
	  delay_Microsecond(2000000);// delay 2 second
	
		GPIO_PORTD_DATA_R &= ~(0x02);// close D0
	}
	else if (distance < 250) {
		
		GPIO_PORTD_DATA_R |= (0x02);// open port D0
		
		 // port D1 earphones E
	  delay_Microsecond(2000000);// delay 2 second
	
		GPIO_PORTD_DATA_R &= ~(0x02);// close D0
	}
	else if (distance < 300) {
	
		GPIO_PORTD_DATA_R |= (0x02);// open port D0
		
		 // port D1 earphones D
	  delay_Microsecond(2000000);// delay 2 second
	
		GPIO_PORTD_DATA_R &= ~(0x02);// close D0
	}
	else if (distance < 400) {
	
		GPIO_PORTD_DATA_R |= (0x02);// open port D0
		
		 // port D1 earphones C
	  delay_Microsecond(2000000);// delay 2 second
	
		GPIO_PORTD_DATA_R &= ~(0x02);// close D0
	}
	else {
		GPIO_PORTD_DATA_R &= ~(0x03);// sound off D0-1
	}
}

