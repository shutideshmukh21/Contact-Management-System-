# Contact Management System
Welcome to our Contact Management System! This system helps you organize your contacts efficiently. Here's what you can do:
## Features:
### 1. Add New Contact
   - Easily add new contacts to your list.
   - Enter name, phone number, and email for each contact.
### 2. Display Contacts
   - View all your contacts at a glance.
   - Names, phone numbers, and emails are neatly displayed.
### 3. Delete Contact
   - Remove unwanted contacts quickly.
   - Just enter the name of the contact you want to delete.
### 4. Exit
   - Close the program when you're done managing your contacts.
## Instructions:
- Choose the corresponding number for the action you want to perform.
- Follow the prompts to add, view, or delete contacts.
- Enjoy a streamlined contact management experience!
## Code Overview:
The system is implemented in C language and consists of the following components:
### Structure:
- **Contact:** Represents a contact with name, phone number, email, and a pointer to the next contact.
### Functions:
1. **addContact:** Add a new contact by dynamically allocating memory and storing user input.
2. **displayContacts:** Display all contacts in the system.
3. **deleteContact:** Delete a contact by name.
4. **searchContact:** Search for a contact by name.
## Sample Usage:
```c
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
    // Main function as described in the code
}
