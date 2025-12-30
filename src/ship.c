/* ship.c */

/*
     |    |    |
    )_)  )_)  )_)      
   )___))___))___)\
  )____)____)_____)\\
_____|____|____|____\\\__
\                   /

Art from asciiart.eu
 */

//////////////
/* Includes */
//////////////
#include "ship.h"

/////////////
/* Defines */
/////////////

/////////////
/* Globals */
/////////////

ship_t my_ship;

char ship_map[SHIP_HEIGHT][SHIP_LENGTH];
int ship_movement_counter;

void ship_init(){

    ship_movement_counter = 0;

    my_ship.x = SHIP_LENGTH + 1;
    my_ship.facing = RIGHT;
    my_ship.status = ALIVE;

    //Hard-code to initalize the ship
    memcpy(ship_map[5], "     |    |    |         ", SHIP_LENGTH);
    memcpy(ship_map[4], "    )_)  )_)  )_)        ", SHIP_LENGTH);
    memcpy(ship_map[3], "   )___))___))___)\\      ", SHIP_LENGTH);
    memcpy(ship_map[2], "  )____)____)_____)\\\\    ", SHIP_LENGTH);
    memcpy(ship_map[1], "_____|____|____|____\\\\\\__", SHIP_LENGTH);
    memcpy(ship_map[0], "\\                   /    ", SHIP_LENGTH);
}


/* Ship is part of the static layer.
 * TODO: Eventually this should only be included if the size is large enough,
 * or if it is enabled by some other part/command line */
void ship_print(){

    /* Check if the ship X coordinate is in bounds */
    if( ( my_ship.x < 0) || (my_ship.x > SCREEN_LENGTH) ){
        my_ship.status = -SHIP_DEATH_TIMER;
        
        if(my_ship.facing == LEFT){
            my_ship.facing = RIGHT;
            my_ship.x = 0;
        }
        else{
            my_ship.facing = LEFT;
            my_ship.x = SCREEN_LENGTH;
        }
    }

    /* Only draw if it is alive */
    if(my_ship.status == ALIVE){

        /* Move the ship in the direction it is facing */
        ship_movement_counter = (ship_movement_counter + 1) % SHIP_FRAMES_PER_MOVE;
        if( ship_movement_counter == 0){
            my_ship.x = my_ship.x + my_ship.facing;
        }

        for( int j = 0; j < SHIP_HEIGHT; j++){
            for(int i = 0; i < SHIP_LENGTH; i++){

                /* TODO: This needs to move in the x direction */
                grid[TOP_OF_WATER_ROW - j][i + my_ship.x - SHIP_LENGTH] = ship_map[j][i];
            }
        }

    }
    /* Otherwise countdown the death timer */
    else{
        my_ship.status++;
    }
}

