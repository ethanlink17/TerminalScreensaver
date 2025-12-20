/* bubbles.h */

#ifndef BUBBLES_H_
#define BUBBLES_H_

//////////////
/* Includes */
//////////////
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "aquarium.h"
#include "waves.h"

/////////////
/* Defines */
/////////////

#define MAX_BUBBLES 10
#define BUBBLE_CAL 30
#define BUBBLE_CHAR 'o'

/* Keep in mind, these row values are inclusive! */
/* NOTE: The actual max X value you will see is BUBBLE_X_MAX + BUBBLE_X_MIN, but I like the naming 
 * of these macros so I'm not going to change it */
#define BUBBLE_X_MIN 10
#define BUBBLE_X_MAX (SCREEN_LENGTH-10-BUBBLE_X_MIN)

//Bubbles should go up to the waterline, I think
//Similarly as above, Y max is actually TOP_OF_WATER_ROW
#define BUBBLE_Y_MIN TOP_OF_WATER_ROW
#define BUBBLE_Y_MAX (SCREEN_HEIGHT - 10 - TOP_OF_WATER_ROW)

typedef struct{
    int x;
    int y;
    int status;
} bubble_t;

/////////////
/* Globals */
/////////////
extern int SCREEN_HEIGHT;
extern int SCREEN_LENGTH;
extern char** grid;

//////////////////////
/* Function Headers */
//////////////////////

void bubbles_init(void);
void bubbles_print(void);

#endif
