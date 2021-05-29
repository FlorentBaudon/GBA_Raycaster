#pragma once
// Type redifinition (it's just syntactic sugar)
typedef unsigned char      uint8;
typedef unsigned short     uint16;
typedef unsigned long      uint32;

// Registers
#define DISPLAYCONTROL	*((volatile unsigned long*) 	 0x04000000)
#define KEYSTATE		*((volatile unsigned long*) 	 0x04000130)
#define VCOUNT			*((volatile unsigned short*) 	 0x04000006)

// Memory
#define SCREENBUFFER	((volatile unsigned short*)		 0x06000000)
#define PALETTE			((volatile unsigned short*)		 0x05000000)
#define FRONT_BUFFER    ((volatile unsigned short*)      0x06000000)
#define BACK_BUFFER     ((volatile unsigned short*)      0x0600A000)

//Screen size
#define WIDTH	240
#define HEIGHT	160

// Mode definitions
#define MODE0 	0x0000
#define MODE1 	0x0001
#define MODE2 	0x0002
#define MODE3 	0x0003
#define MODE4 	0x0004
#define MODE5	0x0005
#define MODE6	0x0006

// Background definitions
#define BG0		0x0100
#define BG1		0x0200
#define BG2 	0x0400
#define BG3		0x0800
#define OBJ		0x1000

// back buffer
#define SHOW_BACK	0x10;

// Key map
#define KEY_A       1
#define KEY_B       2
#define KEY_SELECT  4
#define KEY_START   8
#define KEY_RIGHT   16
#define KEY_LEFT    32
#define KEY_UP      64
#define KEY_DOWN    128
#define KEY_R       256
#define KEY_L       512
