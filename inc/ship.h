/* ship.h */

#ifndef SHIP_H_
#define SHIP_H_

//////////////
/* Includes */
//////////////
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "waves.h"
#include "aquarium.h"

/////////////
/* Defines */
/////////////

#define SHIP_HEIGHT 6
#define SHIP_LENGTH 24

/* 30 second death timer */
/* TODO: Probably should go through and tie all frame-related macros to the frame rate macro */
#define SHIP_DEATH_TIMER (30 * FRAMES_PER_SEC)

/* Ship moves slow, want it to move >1 block per frame */
#define SHIP_FRAMES_PER_MOVE (2 * FRAMES_PER_SEC)

/////////////
/* Globals */
/////////////
extern int SCREEN_HEIGHT;
extern int SCREEN_LENGTH;
extern char** grid;

typedef struct{
    int x;
    int status;
    int facing;
} ship_t;

//////////////////////
/* Function Headers */
//////////////////////

void ship_init(void);
void ship_print(void);

#endif
