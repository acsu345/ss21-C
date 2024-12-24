#include <stdio.h>

int main() {
    char line[100];
    FILE *file;
    file = fopen("bt01.txt", "r");
    if (file == NULL) {
        printf("Khong the mo file bt01.txt\n");
        return 1;
    }
    if (fgets(line, sizeof(line), file) != NULL) {
        printf("Dong dau tien trong file la: %s", line);
    } else {
        printf("Khong the doc dong dau tien hoac file rong.\n");
    }
    fclose(file);

    return 0;
}

