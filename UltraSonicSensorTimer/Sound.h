// Sound.h

#define C64 2982 		// 50Mhz/(262*64)-1 = 2982
#define D64 2657		// 50Mhz/(294*64)-1 = 2657
#define E64 2368		// 50Mhz/(330*64)-1 = 2368
#define F64 2239		// 50Mhz/(349*64)-1 = 2239
#define G64 1993		// 50Mhz/(392*64)-1 = 1993
#define A64 1776		// 50Mhz/(440*64)-1 = 1776
#define B64 1582		// 50Mhz/(494*64)-1 = 1582

void Sound_Init(void);
void Sound_Tone(unsigned long period);
void Sound_Off(void);

