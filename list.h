#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- Structure Definitions ---

#define LOCATION_NAME_MAX 40

typedef struct Data {
    int location_ID;
    char location_name[LOCATION_NAME_MAX];
} Data;

typedef struct Node {
    Data data;
    struct Node* next;
} Node;

// --- Global Variable (Defined in list.c, Declared here as 'extern') ---

// 'extern' tells the compiler that 'head' is defined in another file (list.c)
extern Node* head;

// --- Function Declarations (Prototypes) ---

Node* createNode(int id, const char* name);
void insertNode(Node* newNode);
void displayList();
void freeList();

#endif // LIST_H_INCLUDED
