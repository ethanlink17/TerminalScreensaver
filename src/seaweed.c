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

/////////////
/* Globals */
/////////////
int sproutHeight[NUM_OF_HEIGHT_VARIANTS];
int wiggle = 0;
int toggle = 0;

/* Just creates the random values for the seaweed heights */
void seaweed_init(){
    
    for( int i = 0; i < NUM_OF_HEIGHT_VARIANTS; i++){
        sproutHeight[i] = (rand() % MAX_SPROUT_HEIGHT) + MIN_SPROUT_HEIGHT;
    }

    //Set the whole bottom row to be a seafloor
    //NOTE: It only needs to be done at init, because the Background clear intentionally
    //excludes the bottom row (SCREEN_HEIGHT - 1)
    for(int i = 0; i < SCREEN_LENGTH; i++){
        grid[SCREEN_HEIGHT-1][i] = 'w';
    }
}


/* Function to re-print the seaweed layer to the screen
 * Called during the background/static layer print function */
void seaweed_print(){

    int index = 0;

    /* Code to add some wiggle to the seaweed every WIGGLE_CAL num of frames */
    wiggle = (wiggle + 1) % WIGGLE_CAL;
    if( wiggle == 0){
        toggle = toggle ^ 0x1;
    }

    //TODO: add some variance in the spacing between sprouts
    for( int i = AVG_COLS_PER_SPROUT; i < SCREEN_LENGTH; i += AVG_COLS_PER_SPROUT){

        index = (index + 1) % NUM_OF_HEIGHT_VARIANTS;        

        // This loop adds the seaweed characters
        for(int j = 0; j < sproutHeight[index]; j++){

            //The column i, will alternate between being even and odd every sprout
            //The row j will alternate between being even and odd every character.
            //By adding them, every other character will alternate between even and odd,
            //and every sprout will alternate whether it starts with an even or an odd
            //
            //By adding the toggle in (which alternates between 0 and 1 using an XOR, 
            //we can make this addition give the opposite result of what we would expect
            if( ((j+i+toggle) % 2 == 0)){
                /* Adding 1 to the column here, to give a nice wiggle to the seaweed */
                grid[SCREEN_HEIGHT - j - 2][i+1] = ')';
            }
            else{
                grid[SCREEN_HEIGHT - j - 2][i] = '(';
            }
        }
    }

    return;
}

