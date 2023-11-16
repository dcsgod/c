#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#define MAX 5

typedef struct
{
    int bookID;
    char title[40];
    char author[40];
    double price;
    int quantity;
} Book;

// Function prototypes
void listBooks(Book bookshop[], int count);
void addBook(Book bookshop[], int *count);
void removeBook(Book bookshop[], int *count);
void findBook(Book bookshop[], int count);
void updateBook(Book bookshop[], int count);

int main()
{
    Book bookshop[MAX];
    int count = 0;
    int option;

    do
    {
        // Display menu
        printf("\nNTU BOOKSHOP MANAGEMENT PROGRAM:\n");
        printf("1: listBooks()\n");
        printf("2: addBook()\n");
        printf("3: removeBook()\n");
        printf("4: findBook()\n");
        printf("5: updateBook()\n");
        printf("6: quit\n");

        // Get user option
        printf("Enter option: ");
        scanf("%d", &option);

        // Perform corresponding action based on user option
        switch (option)
        {
        case 1:
            listBooks(bookshop, count);
            break;
        case 2:
            addBook(bookshop, &count);
            break;
        case 3:
            removeBook(bookshop, &count);
            break;
        case 4:
            findBook(bookshop, count);
            break;
        case 5:
            updateBook(bookshop, count);
            break;
        case 6:
            printf("Exiting program. Goodbye!\n");
            break;
        default:
            printf("Invalid option. Please try again.\n");
        }
    } while (option != 6);

    return 0;
}

void listBooks(Book bookshop[], int count)
{
    printf("listBooks():\n");

    if (count == 0)
    {
        printf("The bookshop is empty\n");
    }
    else
    {
        for (int i = 0; i < count; i++)
        {
            // Display book information
            printf("Book ID: %d\n", bookshop[i].bookID);
            printf("Title: %s\n", bookshop[i].title);
            printf("Author: %s\n", bookshop[i].author);
            printf("Price: %.2f\n", bookshop[i].price);
            printf("Quantity: %d\n", bookshop[i].quantity);
            printf("\n");
        }
    }
}

void addBook(Book bookshop[], int *count)
{
    printf("addBook():\n");

    if (*count == MAX)
    {
        printf("The bookshop is full! Unable to addBook()\n");
        return;
    }

    Book newBook;
    printf("Enter book id: ");
    scanf("%d", &newBook.bookID);

    printf("Enter book title: ");
    scanf("%s", newBook.title);

    getchar();

    printf("Enter author name: ");
    scanf("%s", newBook.author);

    printf("Enter price: ");
    scanf("%lf", &newBook.price);

    printf("Enter quantity: ");
    scanf("%d", &newBook.quantity);



    // Insert the new book into the bookshop in ascending order based on bookID
    int i = *count - 1;
    while (i >= 0 && bookshop[i].bookID > newBook.bookID)
    {
        bookshop[i + 1] = bookshop[i];
        i--;
    }
    bookshop[i + 1] = newBook;

    (*count)++;
    printf("The book has been added successfully\n");
}

void removeBook(Book bookshop[], int *count)
{
    printf("removeBook():\n");

    if (*count == 0)
    {
        printf("The bookshop is empty\n");
        return;
    }

    char targetTitle[40], targetAuthor[40];
    printf("Enter the target book title: ");
    scanf("%s", targetTitle);
    printf("Enter the target author name: ");
    scanf("%s", targetAuthor);

    // Convert target strings to lowercase for case-insensitive comparison
    for (int i = 0; i < strlen(targetTitle); i++)
    {
        targetTitle[i] = tolower(targetTitle[i]);
    }

    for (int i = 0; i < strlen(targetAuthor); i++)
    {
        targetAuthor[i] = tolower(targetAuthor[i]);
    }

    // Search for the target book
    int i;
    bool found = false;
    for (i = 0; i < *count; i++)
    {
        char currentTitle[40], currentAuthor[40];
        strcpy(currentTitle, bookshop[i].title);
        strcpy(currentAuthor, bookshop[i].author);

        // Convert current strings to lowercase for case-insensitive comparison
        for (int j = 0; j < strlen(currentTitle); j++)
        {
            currentTitle[j] = tolower(currentTitle[j]);
        }

        for (int j = 0; j < strlen(currentAuthor); j++)
        {
            currentAuthor[j] = tolower(currentAuthor[j]);
        }

        // Check if the current book matches the target
        if (strcmp(currentTitle, targetTitle) == 0 && strcmp(currentAuthor, targetAuthor) == 0)
        {
            found = true;
            break;
        }
    }

    if (found)
    {
        printf("The target book is removed\n");
        // Display the contents of the corresponding book
        printf("Book ID: %d\n", bookshop[i].bookID);
        printf("Title: %s\n", bookshop[i].title);
        printf("Author: %s\n", bookshop[i].author);
        printf("Price: %.2f\n", bookshop[i].price);
        printf("Quantity: %d\n", bookshop[i].quantity);
        printf("\n");

        // Remove the target book from the bookshop
        for (int j = i; j < *count - 1; j++)
        {
            bookshop[j] = bookshop[j + 1];
        }

        (*count)--;
    }
    else
    {
        printf("The target book is not in the bookshop\n");
    }
}

void findBook(Book bookshop[], int count)
{
    printf("findBook():\n");

    if (count == 0)
    {
        printf("The bookshop is empty\n");
        return;
    }

    char targetTitle[40], targetAuthor[40];
    printf("Enter the target book title: ");
    scanf("%s", targetTitle);
    printf("Enter the target author name: ");
    scanf("%s", targetAuthor);

    // Convert target strings to lowercase for case-insensitive comparison
    for (int i = 0; i < strlen(targetTitle); i++)
    {
        targetTitle[i] = tolower(targetTitle[i]);
    }

    for (int i = 0; i < strlen(targetAuthor); i++)
    {
        targetAuthor[i] = tolower(targetAuthor[i]);
    }

    // Search for the target book
    int i;
    bool found = false;
    for (i = 0; i < count; i++)
    {
        char currentTitle[40], currentAuthor[40];
        strcpy(currentTitle, bookshop[i].title);
        strcpy(currentAuthor, bookshop[i].author);

        // Convert current strings to lowercase for case-insensitive comparison
        for (int j = 0; j < strlen(currentTitle); j++)
        {
            currentTitle[j] = tolower(currentTitle[j]);
        }

        for (int j = 0; j < strlen(currentAuthor); j++)
        {
            currentAuthor[j] = tolower(currentAuthor[j]);
        }

        // Check if the current book matches the target
        if (strcmp(currentTitle, targetTitle) == 0 && strcmp(currentAuthor, targetAuthor) == 0)
        {
            found = true;
            break;
        }
    }

    if (found)
    {
        printf("The target book is found\n");
        // Display the contents of the corresponding book
        printf("Book ID: %d\n", bookshop[i].bookID);
        printf("Title: %s\n", bookshop[i].title);
        printf("Author: %s\n", bookshop[i].author);
        printf("Price: %.2f\n", bookshop[i].price);
        printf("Quantity: %d\n", bookshop[i].quantity);
        printf("\n");
    }
    else
    {
        printf("The target book is not found\n");
    }
}

void updateBook(Book bookshop[], int count)
{
    printf("updateBook():\n");

    if (count == 0)
    {
        printf("The bookshop is empty\n");
        return;
    }

    char targetTitle[40], targetAuthor[40];
    printf("Enter the target book title: ");
    scanf("%s", targetTitle);
    printf("Enter the target author name: ");
    scanf("%s", targetAuthor);

    // Convert target strings to lowercase for case-insensitive comparison
    for (int i = 0; i < strlen(targetTitle); i++)
    {
        targetTitle[i] = tolower(targetTitle[i]);
    }

    for (int i = 0; i < strlen(targetAuthor); i++)
    {
        targetAuthor[i] = tolower(targetAuthor[i]);
    }

    // Search for the target book
    int i;
    bool found = false;
    for (i = 0; i < count; i++)
    {
        char currentTitle[40], currentAuthor[40];
        strcpy(currentTitle, bookshop[i].title);
        strcpy(currentAuthor, bookshop[i].author);

        // Convert current strings to lowercase for case-insensitive comparison
        for (int j = 0; j < strlen(currentTitle); j++)
        {
            currentTitle[j] = tolower(currentTitle[j]);
        }

        for (int j = 0; j < strlen(currentAuthor); j++)
        {
            currentAuthor[j] = tolower(currentAuthor[j]);
        }

        // Check if the current book matches the target
        if (strcmp(currentTitle, targetTitle) == 0 && strcmp(currentAuthor, targetAuthor) == 0)
        {
            found = true;
            break;
        }
    }

    if (found)
    {
        // Update the target book
        printf("Enter the updated price: ");
        scanf("%lf", &bookshop[i].price);

        printf("Enter the updated quantity: ");
        scanf("%d", &bookshop[i].quantity);

        // Display the updated contents of the corresponding book
        printf("The target book is updated\n");
        printf("Book ID: %d\n", bookshop[i].bookID);
        printf("Title: %s\n", bookshop[i].title);
        printf("Author: %s\n", bookshop[i].author);
        printf("Price: %.2f\n", bookshop[i].price);
        printf("Quantity: %d\n", bookshop[i].quantity);
        printf("\n");
    }
    else
    {
        printf("The target book is not in the bookshop\n");
    }
}
