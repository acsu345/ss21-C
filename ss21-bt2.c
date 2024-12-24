#include <stdio.h>

int main() {
    char c;
    FILE *f;
    f = fopen("bt01.txt", "r");
    if (f == NULL) {
        printf("Khong the mo file bt01.txt\n");
        return 1;
    }
    c = fgetc(f);
    if (c != EOF) {
        printf("Ky tu dau tien trong file la: %c\n", c);
    } else {
        printf("File rong.\n");
    }
    fclose(f);

    return 0;
}

