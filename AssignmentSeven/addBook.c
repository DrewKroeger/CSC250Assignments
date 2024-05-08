#include "book.h"
#include "addBook.h"
#include <stdio.h>

//******************************************************************************

//this is the add book function/file, it adds the details of a book to the library database

void addBook(struct Book * library, int* bookCount)
{
    
    printf("Input title:");
    scanf("%s", (library + (*bookCount))->title);

    printf("Input Author:");
    scanf("%s", (library + (*bookCount))->author);
    
    printf("Input ISBN:");
    scanf("%s", (library+(*bookCount))->ISBN);
    
    printf("Input Year of publication:");
    scanf("%d", &((library+(*bookCount))->pubYear));

    printf("Input available copies:");
    scanf("%d", &((library+(*bookCount))->availableCopies));

    printf("Input Total copies:");
    scanf("%d", &((library+(*bookCount))->totalCopies));
    
    (*bookCount)++;                                     //must increment the bookcount when we add a book

    printf("Book Added Successfully!");
    return;
}//end of main