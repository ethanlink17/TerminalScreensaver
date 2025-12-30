/* waves.h */

#ifndef WAVES_H_
#define WAVES_H_

//////////////
/* Includes */
//////////////
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "aquarium.h"

/////////////
/* Defines */
/////////////

/* Note: The top row (0) doesn't actually show on the screen, so this needs to be at least 1 */
/* Define this as SHIP_HEIGHT + 1so that the whole ship will show */
#define TOP_OF_WATER_ROW (SHIP_HEIGHT + 1)

/* Keep in mind, these row values are inclusive! */
#define START_RIPPLES_ROW (TOP_OF_WATER_ROW + 1)
#define END_RIPPLES_ROW (START_RIPPLES_ROW + 2)

/* How often do you want these ripples happen out of 10? */
#define RIPPLE_CAL 5

/////////////
/* Globals */
/////////////
extern int SCREEN_HEIGHT;
extern int SCREEN_LENGTH;
extern int TRUE_SCREEN_LENGTH;
extern char** grid;

//////////////////////
/* Function Headers */
//////////////////////

void waves_init(void);
void waves_print(void);
void waves_free(void);

#endif
