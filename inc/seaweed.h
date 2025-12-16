/* seaweed.h */

#ifndef SEAWEED_H_
#define SEAWEED_H_

//////////////
/* Includes */
//////////////
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/////////////
/* Defines */
/////////////

/* Keep this at an odd number if possible, makes it so the seaweed alternates which way it faces :) */
/* Probably won't be needed once the distance between the sprouts is randomized */
#define AVG_COLS_PER_SPROUT 9
#define NUM_OF_HEIGHT_VARIANTS 10

/* Max Height is actually sum of these values, but I don't want to change the variable names */
#define MAX_SPROUT_HEIGHT 8
#define MIN_SPROUT_HEIGHT 2

/* How often should the seaweed wiggle? (in # of frames) */
#define WIGGLE_CAL 20

/////////////
/* Globals */
/////////////
extern int SCREEN_HEIGHT;
extern int SCREEN_LENGTH;
extern char** grid;

//////////////////////
/* Function Headers */
//////////////////////

void seaweed_init(void);
void seaweed_print(void);

#endif
