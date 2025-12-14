#include <stdio.h>
#include <stdlib.h>

// Function prototype: Now accepts a "title" string
int selectLocation(char *prompt_message);

int selectLocation(char *prompt_message){
    int user_input;
    
    // Variables for file reading
    int file_count;          
    int location_id;         
    char location_name[100]; 
    int index = 1;           

    int id_map[50]; // Maps index 1 -> ID 100

    // Clear the screen (optional, makes it look cleaner)
    // system("cls"); 

    printf("LARGA: LOCALIZED ALGORITHM for RATES GUIDANCE APPLICATION\n");
    printf("---------------------------------------------------------\n");
    printf("%s\n", prompt_message); // Print "Select Origin" or "Select Destination"
    printf("---------------------------------------------------------\n");

    FILE *fptr;
    fptr = fopen("C:\\Users\\User\\Documents\\PERSONAL PROGRESS(I THINK)\\CMSC18 FINAL PROJECT\\locations.csv", "r");
    
    if (fptr == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }
    
    // Consume first line
    fscanf(fptr, "%d", &file_count);

    // Read file
    while (fscanf(fptr, " %d,%[^\n]", &location_id, location_name) == 2) {
        id_map[index] = location_id;
        printf("[%d] %s\n", index, location_name);
        index++;
    }
    fclose(fptr);

    printf("\nEnter number: ");
    scanf("%d", &user_input);

    // Validate and return ID
    if(user_input > 0 && user_input < index) {
        return id_map[user_input];
    } else {
        printf("Invalid selection.\n");
        return -1;
    }
}

int main()
{
    int origin_id;
    int destination_id;

    // 1. Get Origin
    origin_id = selectLocation("STEP 1: SELECT ORIGIN");
    if (origin_id == -1) return 1; // Stop if invalid

    // 2. Get Destination
    // Note: This will print the list again. 
    destination_id = selectLocation("\nSTEP 2: SELECT DESTINATION");
    if (destination_id == -1) return 1; // Stop if invalid

    // 3. Confirm selections
    printf("\n---------------------------------------------------------\n");
    printf("CALCULATION READY:\n");
    printf("Origin ID:      %d\n", origin_id);
    printf("Destination ID: %d\n", destination_id);
    printf("---------------------------------------------------------\n");

    // Add your Graph/Algorithm logic here...

    return 0;
}