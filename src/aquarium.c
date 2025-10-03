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


/* Function to re-print the static elements to the screen
 * Effectively, the most background layer of the drawing 
 *
 * 
 * For every frame, start at the furthest back layer, and 
 * work yourself forward */
void static_layer(){

    seaweed_print();
    //waves_print();

}

int main(){

    struct winsize win;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &win);

    SCREEN_HEIGHT = win.ws_row;
    SCREEN_LENGTH = win.ws_col;

    //TODO: need to ensure that the screen is of at least a certain size
    //Should add/remove features based on grid size
    //
    //Can grid size update dynamically to a resized terminal screen using realloc?
    //Probably, should experiment with at some point

    // Init
	//int newPosition = 0;
	//int currPosition = 2;
    //char grid[SCREEN_HEIGHT][SCREEN_LENGTH]; //= malloc(SCREEN_LENGTH * sizeof(char) * SCREEN_HEIGHT);
    
    grid = malloc( sizeof(char*) * SCREEN_HEIGHT);

    for( int i = 0; i < SCREEN_HEIGHT; i++){
        grid[i] = malloc( sizeof(char) * SCREEN_LENGTH);
    }

    seaweed_init();
    

    /* Initialize entire screen */
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

    /* Draw initial character placement TODO: This is remnant from the PoC */
    grid[SCREEN_HEIGHT - 4][2] = 'O';
    grid[SCREEN_HEIGHT - 3][2] = '^';
    grid[SCREEN_HEIGHT - 2][2] = '|';
    grid[SCREEN_HEIGHT - 1][2] = '^';

    /* Main loop */
    while(1)
    {

        static_layer();

        /* TODO: Need more dynamic movement, on a per sprite-type basis */
		//newPosition = (currPosition + 1) % (SCREEN_LENGTH - 1);
	
        //for(int i = 0; i < SCREEN_HEIGHT; i++){

        //    grid[i][newPosition] = grid[i][currPosition];
        //    grid[i][currPosition] = FILL_CHAR;

        //}
		//currPosition = newPosition;
        /* TODO: End bad movement */

		// TODO: Need to figure out when and where to insert necessary ANSI codes
        // TODO: Mess with coloring/formatting
		// Start with a clear console ANSI code, then print?
		// Clear terminal
		printf("\033[2J");
		
		//Print new version of string
        for(int i = 0; i < SCREEN_HEIGHT; i++){
		    printf("%s\r\n", grid[i]);
        }
        fflush( stdout );

        // 1 frame per second
        sleep(1);
    }
    return 0;
}

