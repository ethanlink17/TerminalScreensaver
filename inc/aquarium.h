/* aquarium.h */

//////////////
/* Includes */
//////////////
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/* Needed to determine size and width of terminal */
#include <sys/ioctl.h>

/* Needed for being able to exit cleanly */
#include <signal.h>

#include "seaweed.h"
#include "fish.h"

/////////////
/* Defines */
/////////////
/* (Only used when I want to make it static rather than autofit */
//#define SCREEN_LENGTH (10+1)
//#define SCREEN_HEIGHT 10

/* In development, I want to be able to see the characters
 * In production, probably want to change this to whitespace */
#define FILL_CHAR ' '

/* Uses the usleep() function to sleep between frames based on this value */
#define FRAMES_PER_SEC 4

/////////////
/* Globals */
/////////////

//////////////////////
/* Function Headers */
//////////////////////

void static_layer(void);

