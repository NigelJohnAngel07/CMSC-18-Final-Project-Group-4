#include "route.h"

Data* createArray(char routefile[50], int *count) {
    FILE *file = fopen(routefile, "r");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }

    char line[MAX_LINE_LENGTH];

    // 1. Determine Array Size
    // Usually, the first line of a CSV might contain the count,
    // or you need to count the lines manually first.
    if (!fgets(line, sizeof(line), file)) {
        fclose(file);
        return NULL;
    }
    int array_size = atoi(line); // Assumes first line is the number of entries

    // 2. Allocate Memory
    Data *Route = malloc(array_size * sizeof(Data));
    if (Route == NULL) {
        fclose(file);
        return NULL;
    }

    int lines_read = 0;
    int index;
    while (fgets(line, sizeof(line), file) && lines_read < array_size) {
        char *id_str = strtok(line, ",");
        char *name = strtok(NULL, "\n");

        if (id_str && name) {
            // Cleanup trailing carriage return for Windows compatibility
            size_t len = strlen(name);
            if (len > 0 && name[len - 1] == '\r') name[len - 1] = '\0';

            Route[lines_read].location_ID = atoi(id_str);
            strncpy(Route[lines_read].location_name, name, LOCATION_NAME_MAX - 1);
            Route[lines_read].location_name[LOCATION_NAME_MAX - 1] = '\0';

            lines_read++;
        }
    }

    fclose(file);
    *count = lines_read; // Return the actual number read via pointer
    return Route; // Return the pointer to the array
}

void displayList(Data *Route, int total_records) {
    if (Route == NULL || total_records == 0) {
        printf("The list is empty.\n");
        return;
    }

    printf("\n--- List Contents ---\n");
    printf("| Index | Location ID | Location Name                          |\n");
    printf("|-------|-------------|----------------------------------------|\n");

    for (int i = 0; i < total_records; i++) {
        printf("| %5d | %11d | %-38s |\n",
               i,
               Route[i].location_ID,
               Route[i].location_name);
    }

    printf("----------------------------------------------------------------\n");
}


