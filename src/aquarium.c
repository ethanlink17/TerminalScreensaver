/* aquarium.c */

//////////////
/* Includes */
//////////////
#include "aquarium.h"

/////////////
/* Defines */
/////////////

/////////////
/* Globals */
/////////////
int SCREEN_HEIGHT = 0;
int SCREEN_LENGTH = 0;
int interrupt = 0;

char** grid;


/* Overall pseudo-code of program: (WIP)
 *
 * Initialize variables and screen
 *
 * Draw starting positions for ASCII sprites
 *
 * On  every frame:
 *     -Update current position of all sprites on screen 
 *         -If sprite exits screen, remove it from active list
 *     -Decide if new sprites should be added
 *     
 *    
 *     -Re-add static elements in background layers
 *     -Update sprite location from further back to front
 *     
 *     -Print updated grid to screen
 */

void sigint_handler(int sig_num){
    interrupt = 1;  
}

void background_clear(void){

    /* Blank entire screen */
    for( int i = 0; i < SCREEN_HEIGHT; i++){
        for( int j = 0; j < SCREEN_LENGTH; j++){

            /* Handle case for string termination */
            if( j == SCREEN_LENGTH - 1){
                grid[i][j] = '\0';
            }
            else{
                grid[i][j] = FILL_CHAR;
            }
        }
    }

}

/* Function to re-print the static elements to the screen
 * Effectively, the most background layer of the drawing 
 *
 * 
 * For every frame, start at the furthest back layer, and 
 * work yourself forward */
void static_layer(){

    background_clear();
    seaweed_print();
    //waves_print();
}

void movement_layer(){
    fish_print();
}

int main(){

    struct winsize win;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &win);

    SCREEN_HEIGHT = win.ws_row;
    SCREEN_LENGTH = win.ws_col;

    /* Initialize catching the Ctrl-C signal in order to clean up nicely */
    signal(SIGINT, sigint_handler);

    //TODO: need to ensure that the screen is of at least a certain size
    //Should add/remove features based on grid size
    //
    //Can grid size update dynamically to a resized terminal screen using realloc?
    //Probably, should experiment with at some point

    grid = malloc( sizeof(char*) * SCREEN_HEIGHT);

    for( int i = 0; i < SCREEN_HEIGHT; i++){
        grid[i] = malloc( sizeof(char) * SCREEN_LENGTH);
    }

    seaweed_init();
    fish_init();

    //Hide the Cursor
    printf("\033[?25l");
        
    /* Main loop */
    while(!interrupt)
    {

        static_layer();
        movement_layer();

        // TODO: Mess with coloring/formatting

        // Started with using ANSI codes to clear terminal and reset cursor to top left
        // Learned that the tput utility in linux is simpler
        // Then learned that we don't even need to clear the terminal, and can ovewrite instead
        // Clearing terminal actually caused "flickering", not clearing improves visual quality significantly
        // TODO: for even better performance, can use something "double buffering"
        


		//printf("\033[2J");
        //system("tput clear");
        system("tput home");
        fflush( stdout );
		
		//Print new version of string
        for(int i = 0; i < SCREEN_HEIGHT; i++){
		    printf("%s\r\n", grid[i]);
        }

        usleep(1000000 / FRAMES_PER_SEC );

        
    }

    //Bring cursor back
    printf("\033[?25h");

    /* Free malloc'ed space */
    for( int i = 0; i < SCREEN_HEIGHT; i++){
        free(grid[i]);
    }

    free(grid);


    return 0;
}

