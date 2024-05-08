//TODO- COMMENTS AND MAKEFILE
//CSC250- ASSIGNMENT7- DREW KROEGER- this assignment creates a library database(100 books), allowing user interface to add and delete books-
//-users can also find and display book details by isbn, display all books, and also update availability for a book via isbn.
#include <stdio.h>
#include <stdlib.h>
#include "book.h"
#include "addBook.h"
#include "displayBookByISBN.h"
#include "updateAvailableCopies.h"
#include "displayAllBooks.h"
#include "deleteBook.h"


int main() 
{
    struct Book* library = (struct Book*)malloc(100 *sizeof(struct Book));
    int bookCount = 0;
        if (library == NULL) 
        {
            printf("Memory allocation failed. Exiting.\n");
            return 1;
        }

    int choice;

    while (1) 
    {
    printf("\nWelcome to the Library Book Record System!\n");
    printf("1. Add a new book\n");
    printf("2. Display book details by ISBN\n");
    printf("3. Display all books\n");
    printf("4. Update available copies\n");
    printf("5. Delete a book\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
        switch (choice) 
        {
            case 1:
            addBook(library, &bookCount);
            break;
            case 2:
            displayBookByISBN(library, bookCount);
            break;
            case 3:
            displayAllBooks(library, bookCount);
            break;
            case 4:
            updateAvailableCopies(library, bookCount);
            break;
            case 5:
            deleteBook(library, &bookCount);
            break;
            case 6:
            free(library);
            printf("Goodbye!\n");
            return 0;
            default:
            printf("Invalid choice. Please enter a valid option. \n");
        }//end of switch
    }//end of while
    return 0;
} //end of main method