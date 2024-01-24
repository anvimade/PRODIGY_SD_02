#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a contact
struct Contact {
    char name[50];
    char phone[20];
    char email[50];
};

// Function to add a new contact
void addContact(FILE *file) {
    struct Contact newContact;

    printf("Enter name: ");
    scanf("%s", newContact.name);

    printf("Enter phone number: ");
    scanf("%s", newContact.phone);

    printf("Enter email address: ");
    scanf("%s", newContact.email);

    // Write the new contact to the file
    fwrite(&newContact, sizeof(struct Contact), 1, file);

    printf("Contact added successfully!\n");
}

// Function to view all contacts
void viewContacts(FILE *file) {
    struct Contact contact;

    // Read and display each contact from the file
    rewind(file);  // Move file pointer to the beginning
    while (fread(&contact, sizeof(struct Contact), 1, file) == 1) {
        printf("Name: %s\n", contact.name);
        printf("Phone: %s\n", contact.phone);
        printf("Email: %s\n", contact.email);
        printf("--------------\n");
    }
}

// Function to edit an existing contact
void editContact(FILE *file) {
    struct Contact contact;
    char searchName[50];

    printf("Enter the name of the contact to edit: ");
    scanf("%s", searchName);

    // Search for the contact by name
    fseek(file, 0, SEEK_SET);  // Move file pointer to the beginning
    while (fread(&contact, sizeof(struct Contact), 1, file) == 1) {
        if (strcmp(contact.name, searchName) == 0) {
            printf("Enter new name: ");
            scanf("%s", contact.name);

            printf("Enter new phone number: ");
            scanf("%s", contact.phone);

            printf("Enter new email address: ");
            scanf("%s", contact.email);

            // Update the contact in the file
            fseek(file, -sizeof(struct Contact), SEEK_CUR);
            fwrite(&contact, sizeof(struct Contact), 1, file);

            printf("Contact updated successfully!\n");
            return;
        }
    }

    printf("Contact not found!\n");
}

// Function to delete a contact
void deleteContact(FILE *file) {
    struct Contact contact, tempContact;
    char searchName[50];

    printf("Enter the name of the contact to delete: ");
    scanf("%s", searchName);

    // Create a temporary file to store contacts temporarily
    FILE *tempFile = fopen("temp.dat", "wb");

    // Copy contacts to the temporary file, excluding the one to be deleted
    rewind(file);
    while (fread(&contact, sizeof(struct Contact), 1, file) == 1) {
        if (strcmp(contact.name, searchName) != 0) {
            fwrite(&contact, sizeof(struct Contact), 1, tempFile);
        }
    }

    fclose(file);
    fclose(tempFile);

    // Replace the original file with the temporary file
    remove("contacts.dat");
    rename("temp.dat", "contacts.dat");

    printf("Contact deleted successfully!\n");
}

int main() {
    FILE *file = fopen("contacts.dat", "ab+");

    if (file == NULL) {
        fprintf(stderr, "Error opening file!\n");
        return 1;
    }

    int choice;

    do {
        printf("\nContact Management System\n");
        printf("1. Add Contact\n");
        printf("2. View Contacts\n");
        printf("3. Edit Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact(file);
                break;
            case 2:
                viewContacts(file);
                break;
            case 3:
                editContact(file);
                break;
            case 4:
                deleteContact(file);
                break;
            case 5:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 5);

    fclose(file);

    return 0;
}
