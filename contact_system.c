#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a contact
typedef struct Contact {
    char name[50];
    char phone[20];
    char email[50];
    struct Contact *next;
} Contact;

// Function prototypes
void addContact(Contact **head);
void displayContacts(Contact *head);
void deleteContact(Contact **head, char *name);
Contact *searchContact(Contact *head, char *name);

int main() {
    Contact *head = NULL;
    int choice;
    char name[50];

    do {
        printf("\nContact Management System\n");
        printf("1. Add New Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Delete Contact\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact(&head);
                break;
            case 2:
                displayContacts(head);
                break;
            case 3:
                printf("Enter the name of the contact to delete: ");
                scanf("%s", name);
                deleteContact(&head, name);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 4.\n");
        }
    } while (choice != 4);

    // Free allocated memory for contacts
    while (head != NULL) {
        Contact *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

// Function to add a new contact
void addContact(Contact **head) {
    Contact *newContact = (Contact *)malloc(sizeof(Contact));
    if (newContact == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter Name: ");
    scanf("%s", newContact->name);
    printf("Enter Phone Number: ");
    scanf("%s", newContact->phone);
    printf("Enter Email: ");
    scanf("%s", newContact->email);

    newContact->next = *head;
    *head = newContact;
}

// Function to display all contacts
void displayContacts(Contact *head) {
    printf("\nContacts:\n");
    while (head != NULL) {
        printf("Name: %s\n", head->name);
        printf("Phone: %s\n", head->phone);
        printf("Email: %s\n\n", head->email);
        head = head->next;
    }
}

// Function to delete a contact by name
void deleteContact(Contact **head, char *name) {
    Contact *prev = NULL;
    Contact *current = *head;

    while (current != NULL && strcmp(current->name, name) != 0) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Contact not found.\n");
        return;
    }

    if (prev == NULL) {
        *head = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
    printf("Contact deleted successfully.\n");
}