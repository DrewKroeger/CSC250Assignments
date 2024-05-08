#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "book.h"
#include "deleteBook.h"

//*********************************************************

//this is the delete book function/file- it deletes a book from the library database , by matching isbn numbers input to one already in the system
void deleteBook(struct Book* library, int* bookCount)
{
    int bookCountCopy = *(bookCount);                           //we make this so the original bookcount is kept untouched
    char matcher[50];                                           //this is a string
    printf("Enter ISBN to delete:");                            //we want the user to enter an isbn
    scanf("%s", matcher);                                       //we take the user input for a supposed isbn they want to delete
    int bookCountMatch = -1;                                    //this is used when we actually find a isbn matching, this is what book in the struct that actually contains the isbn

    while(bookCountCopy>=0)                                     //this goes from bookcount to zero
    {
        if (strcmp(matcher, (library+bookCountCopy)->ISBN) == 0)//if matcher and an isbn is found then this will equal zero, and we enter the if stmt
        {
            printf("Book match found!"); 
            bookCountMatch = bookCountCopy;                     //bookcountmatch will be greater than zero, and we can use this to actually delete the correct element
            break;
        }
        if (strcmp(matcher, (library + bookCountCopy)->ISBN) != 0)//if matcher and isbn do not match we decrement book count copy and keep looking
        {
            printf("checking...\n");
        }
        bookCountCopy--;                                        //no match, keep looking until bookcount is exhausted
    }


    if (bookCountMatch < 0)                                     //if a match is never found then bookcountmatch stays less than zero(-1) and we know the user input isbn does not match with anything in the catalog
    {
        printf("No ISBN match!\n");
        return;
    }
    else                                                        //if there is a isbn match then we go here to actually delete the book
    {
    printf("Deleting book with ISBN %s from library.\n", (library + bookCountMatch)->ISBN);
    int i;
    for(i = bookCountMatch; i<*bookCount -1; i++)               //we just moved every element above bookcount into bookcount and the respective elements
    {
        *(library +i ) = *(library+i+1);
    }

    (*bookCount)--;                                             //decrement book count               
    printf("Book Deleted!");                                    //let the user know we deleted a book
    }
    return;
}