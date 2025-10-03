/* seaweed.h */

//////////////
/* Includes */
//////////////
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

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

void seaweed_init(void);
void seaweed_print(void);

