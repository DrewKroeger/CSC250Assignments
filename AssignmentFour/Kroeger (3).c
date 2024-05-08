#include <stdio.h>
#include <string.h>
#define LENGTH 20 //we need to define length and the argc max
#define ARGC 10



void parseCommandLine(char* userInput[],char * args[ARGC][LENGTH])//this must be before main because we call it in the main, the userinput is an array of the input, the other does calculations with that input
{
    int argc = 0; //argc used as a counter
    char* token = strtok(userInput," ");//this tokenizes the input whenver there is a space
    while (token != NULL && argc<ARGC) //while the token isnt the end and argc is not out of the array bounds this continues
    {
        strcpy(args[argc], token);      //copies the input into the argc array
        argc++;                         //counter up
        token = strtok(NULL, " ");      //continues the tokenization(? i think thats what it would be called)
    }    
    printf("Number of commandLine arguments:  %d\n", argc); //when the token reaches the '\o' it finally prints the number of statements
    int i;
    for (i = 0; i<argc; i++)//for loop to print each statement
    {
        printf("argument at %d: %s \n", i , args[i]); //prints the argument stored previously in the strcpy to args 
    }
}//end of parse command line

int main()
{
    char args[ARGC][LENGTH]; //declare args to have 2 dimension of argc(hwo many commands,) or whitespaces, and LENGTH, which is length of each argc )
    char * userInput[200];//this matches up with the length * argc(10x20) which is the max
    printf("Enter command line arguments: \n");// first statement
    fgets(userInput, sizeof(userInput),stdin);//this is like the scanner, it reads what was put after and puts it into the userinput array

    if (strlen(args)> ARGC * LENGTH) //if there is too many chars/arguments we need to do error validation and break
    {
        printf("Number of arguments exceeds capacity of array \n");
        return 1;
    }

    parseCommandLine(userInput, args); //this takes userinput array to the other function
    return 0;//must return an int
}//end of main