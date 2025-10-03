/* seaweed.c */

/*   
 *                )
 *               (
 *                )        (
 *    )          (          )
 *   (            )        (
 *    )          (          )
 *   (            )        (   ... 
 */

//////////////
/* Includes */
//////////////
#include "seaweed.h"

/////////////
/* Defines */
/////////////

/* Keep this at an odd number if possible :) */
#define AVG_COLS_PER_SPROUT 9
#define NUM_OF_HEIGHT_VARIANTS 10

/* Max height is actually sum of these values, but I don't want to change the variabe names */
#define MAX_SPROUT_HEIGHT 8
#define MIN_SPROUT_HEIGHT 2

/////////////
/* Globals */
/////////////
int sproutHeight[NUM_OF_HEIGHT_VARIANTS];

/* Just creates the random values for the seaweed heights */
void seaweed_init(){
    
    for( int i = 0; i < NUM_OF_HEIGHT_VARIANTS; i++){
        sproutHeight[i] = (rand() % MAX_SPROUT_HEIGHT) + MIN_SPROUT_HEIGHT;
    }
}


/* Function to re-print the seaweed layer to the screen
 * Called during the background/static layer print function */
void seaweed_print(){

    int index = 0;

    //TODO: add some variance in the spacing between sprouts
    //TODO: Seems that the seaweed does not fill entire length of screen, debug
    for( int i = AVG_COLS_PER_SPROUT; i < (SCREEN_LENGTH - 1); i += AVG_COLS_PER_SPROUT){

        index++;        

        // This loop actually adds the seaweed characters
        for(int j = 0; j < sproutHeight[index]; j++){
            if( (j+i) % 2 == 0){
                /* Adding 1 to the column here, to give a nice wiggle to the seaweed */
                grid[SCREEN_HEIGHT - j - 1][i+1] = ')';
            }
            else{
                grid[SCREEN_HEIGHT - j - 1][i] = '(';
            }
        }
    }

    return;
}

