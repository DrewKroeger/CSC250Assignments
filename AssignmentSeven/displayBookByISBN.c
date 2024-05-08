#include "book.h"
#include "displayBookByISBN.h"
#include <stdio.h>
#include <string.h>


//************************************************************************
//this finds and displays a book by an isbn which the user inputs, that isbn is then compared to those already in the catalog

void displayBookByISBN(struct Book* library, int bookCount)
{
    char matcher[50];                                                   //this is used for user input
    int bookCountCopy = bookCount;                                      //this is used so we do not mess up the original bookcount
    printf("Enter ISBN to search:\n");                                  //prompt the user for an isbn
    scanf("%s", matcher);                                               //take that isbn and store it
    while (bookCountCopy >= 0)                                          //this while loop seaches the isbn at each element
    {

        if(strcmp(matcher, ((library+bookCountCopy)->ISBN)) == 0)       //if the user inout and an isbn at an element match it goes here and displays book details
        {
            printf("Book Details:\n");
            printf("Title: %s\n", (library+bookCountCopy)->title);
            printf("Author:%s\n", (library+bookCountCopy)->author);
            printf("ISBN:%s\n", (library+bookCountCopy)->ISBN);
            printf("Year of Publication:%d\n", (library+bookCountCopy)->pubYear);
            printf("Total copies:%d\n", (library+bookCountCopy)->totalCopies);
            printf("Available copies:%d\n", (library+bookCountCopy)->availableCopies);
            return;
        }
        else                                                             //if user input and isbn do not match it will go here
        {
            printf("checking...");
        }
        bookCountCopy--;                                                //decrement this to keep the while loop going
    }//end of while loop

    if (bookCountCopy < 0)                                              //if a match is never found(bookcount copy goes less than zero) it prints this
        {
            printf("No matches found for ISBN number to our catalogue.\n");
        }
    return;
}//end of displayBookbyISBN.c 