/* castle.h */

#ifndef CASTLE_H_
#define CASTLE_H_

//////////////
/* Includes */
//////////////
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "seaweed.h"

/////////////
/* Defines */
/////////////

/////////////
/* Globals */
/////////////
extern int SCREEN_HEIGHT;
extern int SCREEN_LENGTH;
extern char** grid;

//////////////////////
/* Function Headers */
//////////////////////

void castle_print(void);

#endif
