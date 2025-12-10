#include "list.h" // Include our custom header file

#define MAX_LINE_LENGTH 100

// --- Main Program Logic ---

int main() {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    const char *filename = "locations.csv";
    int lines_read = 0;

    // Open the CSV file for reading
    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        fprintf(stderr, "Please ensure '%s' is in the same directory.\n", filename);
        return 1;
    }

    printf("Reading data from '%s'...\n", filename);

    // Read the CSV file line by line
    while (fgets(line, sizeof(line), file)) {
        char *id_str;
        char *name;
        int id;

        // 1. Get Location ID
        id_str = strtok(line, ",");
        if (id_str == NULL) continue;
        id = atoi(id_str);

        // 2. Get Location Name
        name = strtok(NULL, "\n");
        if (name == NULL) continue;

        // Cleanup trailing carriage return
        size_t len = strlen(name);
        if (len > 0 && name[len - 1] == '\r') {
            name[len - 1] = '\0';
        }

        // 3. Create and insert the node using functions from list.c
        Node* newNode = createNode(id, name);
        insertNode(newNode);
        lines_read++;
    }

    fclose(file);

    printf("Finished processing file. %d record(s) read.\n", lines_read);

    // Display the list
    displayList();

    // Clean up memory
    freeList();

    return 0;
}
