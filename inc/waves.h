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
