#include "book.h"
#include "displayAllBooks.h"
#include <stdio.h>


//*********************************************************************

//this file displays all the books that were input into the library class and not deleted
void displayAllBooks(struct Book* library, int bookCount)
{
    int BK = bookCount;                                         //we take a copy of the bookcount not to disturb the original
    int i;                                                      //we need a loop
    printf("List of all books:\n");

    for (i = 0;i<BK; i++)                                       //this loop prints each book and its element until the bookcount is exhausted
    {
        printf("Book number %d:\n",i+1);
        printf("Title:%s\n",(library+i)->title );
        printf("Author:%s\n",(library+i)->author );
        printf("ISBN:%s\n",(library+i)->ISBN );
        printf("Year of Publication:%d\n",(library+i)->pubYear);
        printf("Available copies:%d\n",(library+i)->availableCopies);
        printf("Total copies:%d\n\n",(library+i)->totalCopies);
    }

    printf("All books have been printed!(if none showed then there is none to show!)");//this will display even if there is no books to be printed
    return;
}//end of displayAllBooks.c