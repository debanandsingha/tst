#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int id;
    
    // Create a file with read-write permissions
    id = creat("z.txt", S_IRUSR | S_IWUSR);  // Permission: read/write for owner
    
    if (id == -1) {
        // If file creation fails, print error and exit with failure status
        printf("Cannot create the file\n");
        exit(1);
    } else {
        // If file creation is successful, print confirmation
        printf("File is created\n");
        close(id);  // Close the file descriptor after use
        exit(0);    // Exit with success status
    }
}
