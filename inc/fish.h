/* fish.h */

//////////////
/* Includes */
//////////////
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/* Needed for strncpy() */
#include <string.h>

/////////////
/* Defines */
/////////////
struct fish_t{
    int facing; //1 for right, -1 for left
    int speed;
    int model;
    int x_coord;
    int y_coord;
    int alive;
};

/////////////
/* Globals */
/////////////
extern int SCREEN_HEIGHT;
extern int SCREEN_LENGTH;
extern char** grid;

//////////////////////
/* Function Headers */
//////////////////////

void fish_init(void);
void fish_print(void);

