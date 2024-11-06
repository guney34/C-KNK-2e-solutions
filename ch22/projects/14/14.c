#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char filename[FILENAME_MAX];
    printf("Enter name of file to be encrypted: ");
    scanf("%s", filename);
    
    FILE *fp_in = fopen(filename, "rb");
    if (fp_in == NULL) {
        printf("Error: Failed to open %s\n", filename);
        exit(EXIT_FAILURE);
    }

    char output_filename[FILENAME_MAX];
    strcpy(output_filename, filename);
    strcat(output_filename, ".enc");

    FILE *fp_out = fopen(output_filename, "wb");
    if (fp_out == NULL) {
        printf("Error: Failed to open %s\n", output_filename);
        fclose(fp_in);
        exit(EXIT_FAILURE);
    }

    int shift;
    printf("Enter shift amount (1-25): ");
    scanf("%d", &shift);

    int ch;

    while ((ch = fgetc(fp_in)) != EOF) {
        if (ch >= 'A' && ch <= 'Z')
            fputc(((ch - 'A') + shift) % 26 + 'A', fp_out);
        else if (ch >= 'a' && ch <= 'z')
            fputc(((ch - 'a') + shift) % 26 + 'a', fp_out);
        else 
            fputc(ch, fp_out);
    }
    
    fclose(fp_in);
    fclose(fp_out);
}