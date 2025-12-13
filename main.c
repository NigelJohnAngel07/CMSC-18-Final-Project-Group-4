#include "route.h" // Include our custom header file


// --- Main Program Logic ---

int main() {
    int distance = 0;
    int origin_location_ID = 102;
    int origin_index;
    int destination_location_ID = 113;
    char routefile[] = "locations.csv";
    int record_count = 0;

    Data *Route = createArray(routefile,&record_count);
    // Display the list
    displayList(Route, record_count);

    printf("%d",record_count);

    printf("%d",origin_index);

    free(Route);
    Route = NULL;

    return 0;
}
