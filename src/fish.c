/* fish.c */

/*   
 *      _____
 *   |\/   *_\   <---- Centering point
 *   |/\_____/
 *    
 */

//////////////
/* Includes */
//////////////
#include "fish.h"

/////////////
/* Defines */
/////////////
#define FISH_HEIGHT 3
#define FISH_LENGTH 9
#define MAX_ENTRIES 10 //TODO: This should be done dynamically probably

#define TOP_LAYER "   _____ "
#define MID_LAYER "|\\/   *_\\"
#define BOT_LAYER "|/\\_____/"

/////////////
/* Globals */
/////////////
//fish_t fish_list[MAX_ENTRIES]; //TODO: Make an array of fish entries
struct fish_t fishy;

void fish_init(){
   
    fishy.facing = 1;
    fishy.speed = 1;
    fishy.model = 1;
    fishy.alive = 1;

    //Start at the middle of screen, on left side
    fishy.y_coord = SCREEN_HEIGHT / 2;
    fishy.x_coord = 0;
}


/* Function to print the fish layer to the screen
 *
 * Considering the point of the fish as the main point, 
 * draw the fish to the screen.
 *
 * Need to consider:
 *   -Which way the fish is facing
 *   -Length/Height being within grid range
 *   -Speed it should travel
 *   -Turning?
 *   -Deleting old fish prints (Handled by updated background layer first?)
 */
void fish_print(){
    
    int x_len = 0;
    //int y_len = 0;


    //Take current position, adjust by fish.speed
    if(fishy.facing == 1){

        fishy.x_coord += fishy.speed;

        //Because right now it only swims in X direction,
        //if x bound is out of the picture, then fish is not alive
        if(fishy.x_coord - FISH_LENGTH >= (SCREEN_LENGTH - 1)){
            fishy.alive = 0;
        }
        else{
            //Do bounds checking, determine how much space we can add
            //Then use those bounds to copy
            x_len = (SCREEN_LENGTH - 1) - (fishy.x_coord - FISH_LENGTH);
            if( x_len > FISH_LENGTH ){
                x_len = FISH_LENGTH;
            }
        }
    }
    else{
        fishy.x_coord -= fishy.speed;
        //TODO: Same logic, other direction
    }

    //TODO: Also need to handle y case

    
    //for( int i = 0; i < FISH_HEIGHT; i++){
    //    if(fishy.facing == 1){
    if(fishy.alive == 1){

            //Copying a string into a substring at index
            //strncpy(dest, src + beginIndex, endIndex - beginIndex);
            strncpy(grid[fishy.y_coord - 1] + (fishy.x_coord - FISH_LENGTH), TOP_LAYER, x_len);
            strncpy(grid[fishy.y_coord] + (fishy.x_coord - FISH_LENGTH), MID_LAYER, x_len);
            strncpy(grid[fishy.y_coord + 1] + (fishy.x_coord - FISH_LENGTH), BOT_LAYER, x_len);
    //    }
    //}
    }

    return;
}

