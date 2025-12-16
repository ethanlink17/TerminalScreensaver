/* fish.h */

#ifndef FISH_H_
#define FISH_H_

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
#define FISH_HEIGHT 3
#define FISH_LENGTH 9
#define MAX_ENTRIES 4 /* TODO: This should be dynamic, probably */
#define STANDARD_FISH 1 //TODO: Add addtional fish types, move this to an enum
#define MAX_DEATH_TIMER 40

//TODO: When new fish models are introduced, this will need to be updated
#define TOP_LAYER_RIGHT "   _____ "
#define MID_LAYER_RIGHT "|\\/   *_\\"
#define BOT_LAYER_RIGHT "|/\\_____/"

#define TOP_LAYER_LEFT " _____   "
#define MID_LAYER_LEFT "/_*   \\/|"
#define BOT_LAYER_LEFT "\\_____/\\|"

#define LEFT -1
#define RIGHT 1
#define SWIM_SPEED 1
#define ALIVE 1
#define DEAD 0

struct fish_t{
    int facing; //1 for right, -1 for left
    int speed;
    int model;
    int x_coord;
    int y_coord;
    int alive;
    int death_timer;
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

#endif

