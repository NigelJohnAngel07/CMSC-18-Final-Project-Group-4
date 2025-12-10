#include "list.h"

// --- Global Variable Definition ---

// This is the actual definition of the head pointer, visible only in list.c
Node* head = NULL;

// --- Function Definitions ---

Node* createNode(int id, const char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    newNode->data.location_ID = id;
    strncpy(newNode->data.location_name, name, LOCATION_NAME_MAX - 1);
    newNode->data.location_name[LOCATION_NAME_MAX - 1] = '\0';

    newNode->next = NULL;
    return newNode;
}

void insertNode(Node* newNode) {
    if (head == NULL) {
        // List is empty
        head = newNode;
        head->next = head;
    } else {
        // Traverse to the last node
        Node* current = head;
        while (current->next != head) {
            current = current->next;
        }
        // Insert new node between the last node and the head
        current->next = newNode;
        newNode->next = head;
    }
}

void displayList() {
    if (head == NULL) {
        printf("The circular list is empty.\n");
        return;
    }

    Node* current = head;
    int count = 0;

    printf("\n--- Circular Linked List Contents ---\n");
    printf("| Index | Location ID | Location Name                          |\n");
    printf("|-------|-------------|----------------------------------------|\n");

    do {
        printf("| %5d | %11d | %-38s |\n",
               count,
               current->data.location_ID,
               current->data.location_name);
        current = current->next;
        count++;
    } while (current != head);

    printf("-------------------------------------\n");
}

void freeList() {
    if (head == NULL) return;

    Node* current = head->next;
    Node* temp;

    while (current != head) {
        temp = current;
        current = current->next;
        free(temp);
    }
    free(head);
    head = NULL;
    printf("\nList memory freed successfully.\n");
}
