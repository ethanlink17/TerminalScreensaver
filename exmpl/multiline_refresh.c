#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

//Doesn't work
int main(){

	int newPosition = 0;
	int currPosition = 2;

    printf("Multi-line test: \r\n");
    char string1[] = "--O-------";
	char string2[] = "--^-------";
	char string3[] = "--|-------";
	char string4[] = "--^-------";
    while(1)
    {
		newPosition = (currPosition + 1) % 10;
		
        string1[newPosition] = string1[currPosition];
		string1[currPosition] = '-';
		
		string2[newPosition] = string2[currPosition];
		string2[currPosition] = '-';
		
		string3[newPosition] = string3[currPosition];
		string3[currPosition] = '-';
		
		string4[newPosition] = string4[currPosition];
		string4[currPosition] = '-';
		
		currPosition = newPosition;

        //printf("\r%s\r\n%s\r\n%s\r\n%s\r\n", string1, string2, string3, string4);
		
		
		// TODO: Need to figure out when and where to insert necessary ANSI codes
		// Start with a clear console ANSI code, then print?
		// Clear terminal
		printf("\033[2J");
		
		//Print new version of string
		printf("\r%s\r\n%s\r\n%s\r\n%s\r\n", string1, string2, string3, string4);
        fflush( stdout );
        sleep(1);
    }
	printf("\r\n");
}

