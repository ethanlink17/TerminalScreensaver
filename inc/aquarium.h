/* aquarium.h */

//////////////
/* Includes */
//////////////
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/* Needed to determine size and width of terminal */
#include <sys/ioctl.h>

#include "seaweed.h"

/////////////
/* Defines */
/////////////
/* (Only used when I want to make it static rather than autofit */
//#define SCREEN_LENGTH (10+1)
//#define SCREEN_HEIGHT 10

/* In development, I want to be able to see the characters
 * In production, probably want to change this to whitespace */
#define FILL_CHAR '-'

/////////////
/* Globals */
/////////////

//////////////////////
/* Function Headers */
//////////////////////

void static_layer(void);

