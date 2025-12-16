/* waves.c */

/*   
 *   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *   ^^^    ^^^^          ^^^^
 *     ^^   ^^     ^^^^^^
 *   ^^^^^^    ^^^^^       ^^^^
 *   
 */

//////////////
/* Includes */
//////////////
#include "waves.h"

/////////////
/* Defines */
/////////////

/////////////
/* Globals */
/////////////

//NOTE: Be careful with the indexing here. ripple_grid[0] will map the grid[START_RIPPLES_GRID], they
//do not use the same row value!
char** ripple_grid;

/* Todo: probably need a strategy for randomly generating the ^'s above */
void waves_init(){

    int test;

    ripple_grid = malloc( sizeof(char*) * (END_RIPPLES_ROW - START_RIPPLES_ROW + 1));

    for( int i = 0; i < (END_RIPPLES_ROW - START_RIPPLES_ROW + 1); i++){
        ripple_grid[i] = malloc( sizeof(char) * TRUE_SCREEN_LENGTH);
    }

    /* For now, just add the tildes across the top */
    for(int j = 0; j < (END_RIPPLES_ROW - START_RIPPLES_ROW + 1); j++){
        for( int i = 0; i < TRUE_SCREEN_LENGTH; i++){

            /* Handling the string termination */
            if(i == (TRUE_SCREEN_LENGTH - 1)){
                ripple_grid[j][i] = '\0';
            }

            test = rand() % 10;
            if(test > RIPPLE_CAL){
                ripple_grid[j][i] = '^';
            }
            else{
                ripple_grid[j][i] = FILL_CHAR;;
            }
        }
    }
}


/* Function to re-print the seaweed layer to the screen
 * Called during the background/static layer print function */
void waves_print(){


    /* TODO: Is there a better way to handle reassigning these ripples values than iterating through 
     * several rows of the screen? */
    /* TODO: Should the ripples move/update at some frequency? */
    for( int i = 0; i < SCREEN_LENGTH; i++){

        grid[TOP_OF_WATER_ROW][i] = '~';

        for(int j = START_RIPPLES_ROW; j < (END_RIPPLES_ROW + 1); j++){
            grid[j][i] = ripple_grid[j - START_RIPPLES_ROW][i];
        }
    }

    return;
}

/* Free the memory we allocated */
void waves_free(){
    for( int i = 0; i < SCREEN_HEIGHT; i++){
        free(ripple_grid[i]);
    }
    free(ripple_grid);
}

