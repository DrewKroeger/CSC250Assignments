#include "book.h"
#include "updateAvailableCopies.h"
#include <stdio.h>
#include <string.h>

//*************************************************************************

//this function/file will take an isbn input and then find the matching book in the catalog, and then ask the user to update the available copies variable
void updateAvailableCopies(struct Book* library, int bookCount)
{
    char matcher[50];                                           //used for user input
    int bookCountCopy = bookCount;
    int bookCountMatch;
    int newCopies;
    printf("Enter ISBN to update available copies:\n");
    scanf("%s", matcher);
    while(bookCountCopy>=0)
    {
        if (strcmp(matcher , ((library+ bookCountCopy)->ISBN)) != 0)
        {
            printf("checking...\n");
        }
        if (strcmp(matcher , ((library+ bookCountCopy)->ISBN)) == 0)
        {
            printf("Book match found!"); 
            bookCountMatch = bookCountCopy;
            break;
        }
        bookCountCopy--;
    }
    if (bookCountCopy < 0)
    {
        printf("No ISBN match!\n");
    }
    printf("Current available copies: %d ", (library+bookCountMatch)->availableCopies);
    int * currentAvailableCopiesPtr= &((library+bookCountMatch)->availableCopies);
    printf("Enter new amount of available copies:");
    scanf("%d",&newCopies);
    int * NCPtr = &newCopies;
    ((library+bookCountMatch)->availableCopies) = *(NCPtr);
    printf("New Current available copies: %d", *(currentAvailableCopiesPtr));
    return;
}