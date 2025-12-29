/* castle.h */

#ifndef CASTLE_H_
#define CASTLE_H_

//////////////
/* Includes */
//////////////
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "seaweed.h"

/////////////
/* Defines */
/////////////

#define CASTLE_HEIGHT 18
#define CASTLE_LENGTH 65

#define START_CASTLE_COL (SCREEN_LENGTH - CASTLE_LENGTH - 10)

/////////////
/* Globals */
/////////////
extern int SCREEN_HEIGHT;
extern int SCREEN_LENGTH;
extern char** grid;

//////////////////////
/* Function Headers */
//////////////////////

void castle_init(void);
void castle_print(void);

#endif
