#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>


#define MAX_LINE 80 /* The maximum length command */

int main (void){
    char *userInput2 = (char*)malloc(MAX_LINE*sizeof(char*));
    char *userInput = (char*)malloc(MAX_LINE*sizeof(char*));
    int shouldrun = 1; /* flag to determine when to exit program */
    char delim[] = " "; // delimiter for user input
    char **inputTokens = (char**)malloc(10*sizeof(char*));
   
    //allocate space for each string, 50 bytes, which is more than enough for the strings
    for(int i = 0; i < 5; i++){
        inputTokens[i] = (char*)malloc(50*sizeof(char));
    }
    
    while (shouldrun){
        printf("osh> ");
        fflush(stdout); //Echos user command back to them as they type

        fgets(userInput, MAX_LINE, stdin); //Collects user command from new shell
        strcpy(userInput2, userInput);

        //Splits the user entered string into seperate tokens by the whitespace delimiter
	    char *ptr = strtok(userInput2, delim); 

        int count = 0;
	    while(ptr != NULL){
            //saves token as an element in inputTokens
            strcpy(inputTokens[count], ptr);
            ptr = strtok(NULL, delim);
            count ++;
        }

        //remove newline from user input
        int idx = count - 1;

        //strncpy(inputTokens[idx], inputTokens[idx], strlen(inputTokens[idx])-1);
        char* pos = strrchr(inputTokens[idx], '\n');
        if (pos){
            *pos = 0;
        } 

        //sets lats element of inputTokens to NULL
        inputTokens[count] = NULL;

        //child process is forked and executes the command specified by the user
        pid_t pid = fork();
        if (!pid) {
            // child
            int tell = execvp(inputTokens[0], inputTokens);
            if (tell == -1){
                printf("child failed\n");
                printf("Error Number % d\n", errno); 
                _exit(9);
            }
        }

        // parent
        if(strcmp (inputTokens[count-1], "&") == 0){
            wait(&pid);
        }else{
            shouldrun = 0;
        }

    }

return 0;
}