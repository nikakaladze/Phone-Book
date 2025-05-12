#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 15

typedef struct
{
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
} Contact;

void addContact(Contact phonebook[], int *count)
{
    if (*count >= MAX_CONTACTS)
    {
        printf("Phonebook is full.\n");
        return;
    }

    printf("Enter name: ");
    scanf(" %[^\n]", phonebook[*count].name); 
    printf("Enter phone number: ");
    scanf(" %[^\n]", phonebook[*count].phone);

    (*count)++;
    printf("Contact added successfully.\n");
}

void displayContacts(Contact phonebook[], int count)
{
    if (count == 0)
    {
        printf("No contacts in phonebook.\n");
        return;
    }

    printf("\n--- Phonebook Contacts ---\n");
    for (int i = 0; i < count; i++)
    {
        printf("%d. %s - %s\n", i + 1, phonebook[i].name, phonebook[i].phone);
    }
}

void searchContact(Contact phonebook[], int count)
{
    char searchName[NAME_LENGTH];
    printf("Enter name to search: ");
    scanf(" %[^\n]", searchName);

    int found = 0;
    for (int i = 0; i < count; i++)
    {
        if (strcmp(phonebook[i].name, searchName) == 0)
        {
            printf("Found: %s - %s\n", phonebook[i].name, phonebook[i].phone);
            found = 1;
        }
    }

    if (!found)
    {
        printf("Contact not found.\n");
    }
}

int main()
{
    Contact phonebook[MAX_CONTACTS];
    int contactCount = 0;
    int choice;

    do
    {
        printf("\nPhonebook Menu:\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addContact(phonebook, &contactCount);
            break;
        case 2:
            displayContacts(phonebook, contactCount);
            break;
        case 3:
            searchContact(phonebook, contactCount);
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid option. Try again.\n");
        }

    } while (choice != 4);

    return 0;
}
