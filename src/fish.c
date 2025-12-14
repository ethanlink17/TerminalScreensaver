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
#define MAX_ENTRIES 4 //TODO: This should be done dynamically probably
#define STANDARD_FISH 1 //TODO: Add additional Fish types 

//TODO: When new fish models are introduced, these should be added into fish struct
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

/////////////
/* Globals */
/////////////
struct fish_t fish_list[MAX_ENTRIES];

/* Function to randomly initialize the list of fish at the start of the program
 *
 * Main difference between this function and the spawn_fish() function
 * is that this function can initialize fish in the middle of the screen (in terms of X coordinate),
 * wheras the spawn_function() can only add them such that they enter the screen from LEFT or RIGHT
 */
void fish_init(){
 
    /* Initialize fish list with some base values */
    for(int i = 0; i < MAX_ENTRIES; i++){
        //We want to use -1 and 1 as LEFT and RIGHT to make use of a positive/negative speed
        //Let's us commonize our code a bit, but because of that we can't just use a modulo
        if( (rand() % 2) == 0 ){
            fish_list[i].facing = RIGHT;
        }
        else{
            fish_list[i].facing = LEFT;
        }
        fish_list[i].speed = SWIM_SPEED;
        fish_list[i].model = STANDARD_FISH;

        //TODO: Start fish dynamically at different points in the screen
        //based on the size of the screen

        fish_list[i].x_coord = (rand() % SCREEN_LENGTH) - 10;
        fish_list[i].y_coord = (rand() % (SCREEN_HEIGHT - 2)) + 2;

        fish_list[i].alive = ALIVE;
    }
}

/* Function to randomly initialize the list of fish at the start of the program
 *
 * Like noted in the function description of the fish_init() function, the 
 * main difference between this function and fish_init
 * is that fish_init() can initialize fish in the middle of the screen (in terms of X coordinate),
 * wheras this function can only add them such that they enter the screen from LEFT or RIGHT
 */
void spawn_fish(){

    for(int i = 0; i < MAX_ENTRIES; i++){
        
        // For any DEAD fish, create some new ones coming onto the screen
        // TODO: Maybe there should be a DEATH_TIMER field such that it isn't so clear that 
        // there is always the same amount of fish on the screen
        if( fish_list[i].alive == DEAD ){

            if( (rand() % 2) == 0 ){
                fish_list[i].facing = RIGHT;
            }
            else{
                fish_list[i].facing = LEFT;
            }
            fish_list[i].speed = SWIM_SPEED;
            fish_list[i].model = STANDARD_FISH;

            //TODO: Start fish dynamically at different points in the screen
            //based on the size of the screen

            if( fish_list[i].facing == LEFT){
                fish_list[i].x_coord = SCREEN_LENGTH;
                fish_list[i].y_coord = (rand() % (SCREEN_HEIGHT - 2)) + 2;
            }
            else{
                fish_list[i].x_coord = 0;
                fish_list[i].y_coord = (rand() % (SCREEN_HEIGHT - 2)) + 2;
            }

            fish_list[i].alive = ALIVE;
        }
    }

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
 *   -The alive/dead status of the fish
 */
void fish_print(){

    struct fish_t* fishy;
    int beg_idx, end_idx;
    //int y_len = 0;

    //For any fish that are DEAD, create some new ones to enter the screen
    spawn_fish();

    for( int i = 0; i < MAX_ENTRIES; i++){

        fishy = &fish_list[i];  
        beg_idx = 0;
        end_idx = FISH_LENGTH - 1;

        // Only recalculate the position of any fish that are ALIVE
        if( fishy->alive == ALIVE){

            //Take current position, adjust by fish.speed
            fishy->x_coord += fishy->speed * fishy->facing;

            //To commonize some of the printing code, we want to determine the beginning and end
            //indexes of where we should start printing the strings from. Ideally, this will handle
            //for us the logic of how much the string should be shorted on either end when entering
            //or exiting the screen
            if(fishy->facing == RIGHT){

                //Check the X bounds, determine how much we have to shorten our string when we print
                //if x bound is out of the picture, then fish is not alive, don't print it
                
                if(fishy->x_coord - FISH_LENGTH >= SCREEN_LENGTH){
                    fishy->alive = DEAD;
                    break;
                }
                else if( fishy->x_coord - FISH_LENGTH < 0 ){
                    beg_idx = (FISH_LENGTH-1) - fishy->x_coord;
                }
                else{
                    end_idx = SCREEN_LENGTH - (fishy->x_coord - FISH_LENGTH) - 1;
                    if( end_idx > (FISH_LENGTH - 1) ){
                        end_idx = FISH_LENGTH - 1;
                    }
                }
            }
            else{

                //Check the X bounds, determine how much we have to shorten our string when we print
                //if x bound is out of the picture, then fish is not alive, don't print it
                if( (fishy->x_coord + FISH_LENGTH) < 0){
                    fishy->alive = DEAD;
                    break;
                }
                else if( (fishy->x_coord + FISH_LENGTH) > SCREEN_LENGTH ){
                    end_idx = SCREEN_LENGTH - fishy->x_coord;
                }
                else{
                    //Do bounds checking, determine how much space we have
                    //Then use those bounds to copy
                    beg_idx =  0 - fishy->x_coord;
                    if( beg_idx < 0 ){
                        beg_idx = 0;
                    }
                }
            }

            //printf("Beginning index: %d\r\n", beg_idx);
            //printf("Ending index: %d\r\n", end_idx);

            //TODO: Should fish also swim in Y-direction?

            //Copying a string into a substring at index using string copy fn:
            //strncpy(dest, src + beginIndex, endIndex - beginIndex);

            //There are some interesting cases that need to be handled, based on when the fish is facing
            //LEFT or RIGHT, and whether it is entering the screen or leaving. For example, when a fish is 
            //facing RIGHT and entering the screen, it should enter nose first (on the LEFT side of the screen), 
            //meaning we need to print only a substring based on the end of the string, adding characters 
            //until the entire fish string fits on the screen. 
            //
            //However, when that same fish exits the screen (on the RIGHT side of the screen), we need to do
            //the opposite, printing only a subset of the fish model string starting from the beginning
            //and cutting characters off of the end. 
            //
            //For a LEFT facing fish, this logic is basically flipped. There may be a clever way to 
            //commonize this code, but at least for now it's easier to maintain the separate behaviors
            //by handling the situations with if-conditions.
            if( fishy->facing == LEFT){

                strncpy(grid[fishy->y_coord - 1] + fishy->x_coord + beg_idx, (char*)(TOP_LAYER_LEFT + beg_idx), (end_idx - beg_idx) + 1);
                strncpy(grid[fishy->y_coord] + fishy->x_coord + beg_idx, (char*)(MID_LAYER_LEFT + beg_idx), (end_idx - beg_idx) + 1);
                strncpy(grid[fishy->y_coord + 1] + fishy->x_coord + beg_idx, (char*)(BOT_LAYER_LEFT + beg_idx), (end_idx - beg_idx) + 1);
            }
            else{

                strncpy(grid[fishy->y_coord - 1] + fishy->x_coord - FISH_LENGTH + beg_idx + 1, (char*)(TOP_LAYER_RIGHT + beg_idx), (end_idx - beg_idx) + 1);
                strncpy(grid[fishy->y_coord] + fishy->x_coord - FISH_LENGTH + beg_idx + 1, (char*)(MID_LAYER_RIGHT + beg_idx), (end_idx - beg_idx) + 1);
                strncpy(grid[fishy->y_coord + 1] + fishy->x_coord - FISH_LENGTH + beg_idx + 1, (char*)(BOT_LAYER_RIGHT + beg_idx), (end_idx - beg_idx) + 1);
            }
            
            //TODO: Above should be done dynamically based on the FISH_HEIGHT
            //for( int i = 0; i < FISH_HEIGHT; i++){
            //
            //}
        }

    }

    return;
}

