//Drew Kroeger
//Assingment 6 -CSC250- This code takes in a string(just letters and spaces), and then displays how many 1 letter to 10 letter words there are


#include <stdio.h>
#include <string.h>//needed for stringlength api
#define MAX 50//used for string max size, could be incremented


int main(void)
{
    int numArr[10] = {0};//this is used to store amount of occurences of words, a 7 letter word will be stored at element 7, and 7 will increment by 1
    int * numPtr = numArr;//pointer to numArr
    char string1[MAX];
    char * stringPtr = string1;//pointer to input string


    printf("Enter your string:");
    fgets(string1,sizeof(string1),stdin);//this takes the input of the string
    printf("%s", string1);//prints out all of string1 just as a check


    int i;
    int wordLengthCounter = 0;//used to seperate words

    for (i=0; i<strlen(string1);i++)
    {
        if ((*(stringPtr+i)) == ' ' || (*(stringPtr+i)) == '\0' || (*(stringPtr+i)) == '\n') //if this is a char we know there is a split in words(or end of string)
        {
            (*(numPtr+wordLengthCounter-1))++; 
            wordLengthCounter = 0; //reset char counter
        }
        else //normal letter increments up
        {
            wordLengthCounter++;
        }
    }//end of checking for loop


    printf ("Word Length    Occurence"); //this finally accesses the number array to get instances of amount of i-letter words
    for (i = 0; i<10;i++)
    {
        printf("\n %d \t \t %d  \n", i+1 , *(numPtr+i));
    }//end of print for loop


}//end of Kroeger.c