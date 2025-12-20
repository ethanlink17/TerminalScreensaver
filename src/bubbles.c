/* bubbles.c */

/*   
 *   O 
 *                  O
 *          O
 *   
 *                      ...
 */

//////////////
/* Includes */
//////////////
#include "bubbles.h"

/////////////
/* Defines */
/////////////

/////////////
/* Globals */
/////////////

bubble_t bubble_list[MAX_BUBBLES];

/* Function for initializing a bubble */
static void create_bubble(){

    //Find the first empty spot in the list
    for(int i = 0; i < MAX_BUBBLES; i++){

        if( bubble_list[i].status == FALSE ){
            bubble_list[i].x = (rand() % BUBBLE_X_MAX) + BUBBLE_X_MIN;
            bubble_list[i].y = (rand() % BUBBLE_Y_MAX) + BUBBLE_Y_MIN;
            bubble_list[i].status = TRUE;
            break;
        }
    }
}

/* Function for destorying a bubble instance */
static void pop_bubble(bubble_t* bub){

    bub->x = 0;
    bub->y = 0;
    bub->status = FALSE;
}

/* Initialize bubble array */
void bubbles_init(){

    for(int i = 0; i < MAX_BUBBLES; i++){
        bubble_list[i].x = 0;
        bubble_list[i].y = 0;
        bubble_list[i].status = FALSE;
    }
}

/* Function to re-print the seaweed layer to the screen
 * Called during the background/static layer print function */
void bubbles_print(){
    
    int temp = rand() % BUBBLE_CAL;

    if(temp == 0){
        create_bubble();
    }

    for( int i = 0; i < MAX_BUBBLES; i++){

        if(bubble_list[i].status == TRUE){

            // Add some wiggle to the bubble as it rises
            if((bubble_list[i].y % 2) == 0){
                grid[bubble_list[i].y][bubble_list[i].x + 1] = BUBBLE_CHAR;
            }
            else{
                grid[bubble_list[i].y][bubble_list[i].x] = BUBBLE_CHAR;
            }

            //Decrement the y-value so that the bubble rises
            bubble_list[i].y--;

            //Check bounds after, so that we don't print on the next frame
            if( bubble_list[i].y <= TOP_OF_WATER_ROW){
                pop_bubble( &bubble_list[i] );
            }
        }
    }
}

