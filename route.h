#ifndef ROUTE_H_INCLUDED
#define ROUTE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants for buffer sizes
#define MAX_LINE_LENGTH 256
#define LOCATION_NAME_MAX 100

// Define the structure once here
typedef struct {
    int location_ID;
    char location_name[LOCATION_NAME_MAX];
} Data;

// Function Prototypes (Declarations)
// These tell the compiler what the functions look like
Data* createArray(char routefile[50], int *count);
void displayList(Data *Route, int total_records);

#endif // ARRAY_H_INCLUDED
