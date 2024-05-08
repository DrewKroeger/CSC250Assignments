//CSC300-ASSIGNMENT9-DREW KROEGER
//THIS MAIN FUNCTION TAKES A COMMNAND LINE ARGUMENT(A TXT FILE)- READS THE FILE
//IT THEN COUNTS THE AMOUNT OF LINES- IT ALSO CREATES A NEW FILE AND COPIES THE 
//ORIGINAL CONTENTS INTO THE NEWLY CREATED FILE
//NOTE: the code does not work if there is a file with the same name in the same directory
//      this can be changed with a truncate in the create function, but it was messing me up


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
int main(int argc, char* argv[])
{
    if (argc < 2 || argc >=3)                                //this checks if there is only one extra argument in the command line
    {
        printf("Please put in command line a file you want to read");
    }

    char *file = argv[1];                                     //we read the first command line argument(excluding a.out)
    char buffer[1024];
    int lineCounter = 1;                                      //this starts at 1 because the text editor doesnt count the last line
    
    int openedFile = open(file, O_RDONLY);                    //we open the first argument and only can read from it
    if(openedFile == -1)                                      //if opened file has an error we print that
    {
        perror("File Opening error");
        return -1;
    }

    int readChecker = read(openedFile, buffer, sizeof(buffer));//we read the first command line argument file, and put the contents in the buffer
    if(readChecker == -1)                                      //if there is an error with the read we print that
    {
        perror("Reading input file error");
    }
    
    int i = 0;
    while (buffer[i] != '\0')                                 //this is the line counter, while buffer does not end of string/file it keeps going
    {
        i++;
        if(buffer[i] == '\n')                                 //when we reach end of line, ++ the line counter
        {
            lineCounter++;
        }
    }//end of while


    char * fileName = "output.txt";
    int newFile = creat(fileName, O_RDWR);                    //we create a new file named output.txt, can add more flags here but i did not
    if(newFile == -1)                                         //print error if we get an error
    {
        perror("Error:new file not created successfully");
    }
    else                                                      //no error when creating new file, means we print this
    {
        printf("New file has been created: %s", fileName);
    }

    int writing = write(newFile,buffer,readChecker);          //write the buffer into the new file. readChecker is how many bytes, which is same size as txt amount of bytes, based on read function
    if(writing == -1)                                         //print error if there is one with the write function
    {
        perror("Error: writing to file went wrong");
    }
    else                                                      //no write error means we print the success line
    {
        printf("\n%d lines copied to %s  \n", lineCounter,fileName);
    }


    int checkerOne = close(openedFile);                       //we close the input.txt here/the file we read from
    if (checkerOne == -1)                                     //print error here for file we read from if there is one
    {
        perror("file closing error 1");
    }
    int checkerTwo = close(newFile);                         //we close the output.txt/file we write to
    if (checkerTwo == -1)                                    //print error for closing file we write to if there is one
    {
        perror("file closing error 2");
    }
}//end of main function