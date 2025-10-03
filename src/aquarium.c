#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/* Needed to determine size and width of terminal */
#include <sys/ioctl.h>

/* Defines for ASCII grid size
 * TODO: Make dynamic in future, autofit to terminal size? */
//#define SCREEN_LENGTH (10+1)
//#define SCREEN_HEIGHT 10

#define FILL_CHAR '-'

/* Overall pseudo-code of program:
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
//void static_layer(){
//
//    //TODO
//
//}

int main(){

    struct winsize win;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &win);

    int SCREEN_HEIGHT = win.ws_row;
    int SCREEN_LENGTH = win.ws_col;

    printf("Lines: %d\n", SCREEN_HEIGHT);

    // Init
	int newPosition = 0;
	int currPosition = 2;

    char grid[SCREEN_HEIGHT][SCREEN_LENGTH]; //= malloc(SCREEN_LENGTH * sizeof(char) * SCREEN_HEIGHT);

    printf("Multi-line test: \r\n");
    
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

    /* Draw initial character placement */
    grid[SCREEN_HEIGHT - 4][currPosition] = 'O';
    grid[SCREEN_HEIGHT - 3][currPosition] = '^';
    grid[SCREEN_HEIGHT - 2][currPosition] = '|';
    grid[SCREEN_HEIGHT - 1][currPosition] = '^';

    /* Main loop */
    while(1)
    {
		newPosition = (currPosition + 1) % (SCREEN_LENGTH - 1);
		
        for(int i = 0; i < SCREEN_HEIGHT; i++){

            grid[i][newPosition] = grid[i][currPosition];
            grid[i][currPosition] = FILL_CHAR;

        }
		
		currPosition = newPosition;

		// TODO: Need to figure out when and where to insert necessary ANSI codes
        // TODO: Mess with coloring/formatting
		// Start with a clear console ANSI code, then print?
		// Clear terminal
		printf("\033[2J");
		
		//Print new version of string
		//printf("\r%s\r\n%s\r\n%s\r\n%s\r\n", grid[0], grid[1], grid[2], grid[3]);
        for(int i = 0; i < SCREEN_HEIGHT; i++){
		    printf("%s\r\n", grid[i]);
        }
        fflush( stdout );

        // 1 frame per second
        sleep(1);
    }
    return 0;
}

