#include <stdio.h>
int main()
{
    char str[100];
    FILE *fp;
    fp = fopen("file1.dat", "r");
    if (fp == NULL) {
        printf("File not found!\n");
        return 1; // Exit if the file doesn't open
    }
    while (fscanf(fp, "%s", str) != EOF) {
        printf(" %s ", str);
    } 
    fclose(fp);
}
