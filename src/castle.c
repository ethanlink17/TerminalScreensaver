/* castle.c */

/*   
                                  |>>>
                                  |
                    |>>>      _  _|_  _         |>>>
                    |        |;| |;| |;|        |
                _  _|_  _    \\.    .  /    _  _|
               |;|_|;|_|;|    \\:. ,  /    |;|_|;|_|;|
               \\..      /    ||;   . |    \\.    .  /
                \\.  ,  /     ||:  .  |     \\:  .  /
                 ||:   |_   _ ||_ . _ | _   _||:   |
                 ||:  .|||_|;|_|;|_|;|_|;|_|;||:.  |
                 ||:   ||.    .     .      . ||:  .|
                 ||: . || .     . .   .  ,   ||:   |
                 ||:   ||:  ,  _______   .   ||: , |
                 ||:   || .   /+++++++\    . ||:   |
                 ||:   ||.    |+++++++| .    ||: . |
              __ ||: . ||: ,  |+++++++|.  . _||_   |
     ____--`~    '--~~__|.    |+++++__|----~    ~`---,
-~--~                   ~---__|,--~'                  ~~----_____
Art: "The Gnone Castle" from asciiart.eu
 */

//////////////
/* Includes */
//////////////
#include "castle.h"

/////////////
/* Defines */
/////////////

/////////////
/* Globals */
/////////////

char castle_map[CASTLE_HEIGHT][CASTLE_LENGTH];

void castle_init(){

    //Hard-code to initalize the castle
    memcpy(castle_map[17], "                                  |>>>                           ", CASTLE_LENGTH);
    memcpy(castle_map[16], "                                  |                              ", CASTLE_LENGTH);
    memcpy(castle_map[15], "                    |>>>      _  _|_  _         |>>>             ", CASTLE_LENGTH);
    memcpy(castle_map[14], "                    |        |;| |;| |;|        |                ", CASTLE_LENGTH);
    memcpy(castle_map[13], "                _  _|_  _    \\\\.    .  /    _  _|                ", CASTLE_LENGTH);
    memcpy(castle_map[12], "               |;|_|;|_|;|    \\\\:. ,  /    |;|_|;|_|;|           ", CASTLE_LENGTH);
    memcpy(castle_map[11], "               \\\\..      /    ||;   . |    \\\\.    .  /           ", CASTLE_LENGTH);
    memcpy(castle_map[10], "                \\\\.  ,  /     ||:  .  |     \\\\:  .  /            ", CASTLE_LENGTH);
    memcpy( castle_map[9], "                 ||:   |_   _ ||_ . _ | _   _||:   |             ", CASTLE_LENGTH);
    memcpy( castle_map[8], "                 ||:  .|||_|;|_|;|_|;|_|;|_|;||:.  |             ", CASTLE_LENGTH);
    memcpy( castle_map[7], "                 ||:   ||.    .     .      . ||:  .|             ", CASTLE_LENGTH);
    memcpy( castle_map[6], "                 ||: . || .     . .   .  ,   ||:   |             ", CASTLE_LENGTH);
    memcpy( castle_map[5], "                 ||:   ||:  ,  _______   .   ||: , |             ", CASTLE_LENGTH);
    memcpy( castle_map[4], "                 ||:   || .   /+++++++\\    . ||:   |             ", CASTLE_LENGTH);
    memcpy( castle_map[3], "                 ||:   ||.    |+++++++| .    ||: . |             ", CASTLE_LENGTH);
    memcpy( castle_map[2], "              __ ||: . ||: ,  |+++++++|.  . _||_   |             ", CASTLE_LENGTH);
    memcpy( castle_map[1], "     ____--`~    '--~~__|.    |+++++__|----~    ~`---,           ", CASTLE_LENGTH);
    memcpy( castle_map[0], "-----                   ~---__|,--~'                  ~~---------", CASTLE_LENGTH);
}


/* Castle is part of the static layer.
 * TODO: Eventually this should only be included if the size is large enough,
 * or if it is enabled by some other part/command line */
void castle_print(){

    for( int j = 0; j < CASTLE_HEIGHT; j++){
        for(int i = 0; i < CASTLE_LENGTH; i++){
            grid[SEAFLOOR_ROW - j][i + START_CASTLE_COL] = castle_map[j][i];
        }
    }

}

