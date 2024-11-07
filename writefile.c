#include <stdio.h>

int main() {
    char str[100];
    FILE *fp;
    
    // Get input from user safely
    printf("Enter the string: ");
    fgets(str, sizeof(str), stdin);  // safer than gets()
    
    // Open the file for writing
    fp = fopen("file1.dat", "w+");
    if (fp == NULL) {
        printf("Failed to open file.\n");
        return 1;  // Exit if the file cannot be opened
    }
    
    // Write the input string to the file
    fprintf(fp, "%s", str);
    
    // Move file pointer to the beginning for reading
    rewind(fp);
    
    // Read and print the content from the file
    printf("Content of the file: ");
    while (fscanf(fp, "%s", str) != EOF) {
        printf("%s ", str);
    }
    
    // Close the file
    fclose(fp);
    
    return 0;
}
