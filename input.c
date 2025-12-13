#include <stdio.h>
#include <stdlib.h>

void displayMenu();

void displayMenu(){
    int origin_location_id;
    int destination_id;
    int user_input;
    int choice;
    
    printf("LARGA: LOCALIZED ALGORITHM for RATES GUIDANCE APPLICATION\n");
    printf("Select location\n");

    FILE *fptr;
    char ch;
    fptr = fopen("C:\\Users\\User\\Documents\\PERSONAL PROGRESS(I THINK)\\CMSC18 FINAL PROJECT\\CMSC-18-Final-Project-Group-4\\AGIANAN-MINTAL-ROXAS-ROUTE.csv", "r");
    if (fptr == NULL) {
        printf("Error: Could not open file.\\n");
        exit(1);
    }
    
    while ((ch = fgetc(fptr)) != EOF) {
        printf("%c", ch);
    }

    printf("\nSelect Location:");
    scanf("%d", &user_input);

    fclose(fptr);
}

int main()
{
    displayMenu();
    return 0;
}
