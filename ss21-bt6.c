#include <stdio.h>

int main() {
    FILE *file1, *file2;
    char c;
    file1 = fopen("bt01.txt", "r");
    if(file1 == NULL) {
        printf("Khong the mo file bt01.txt\n");
        return 1;
    }
    file2 = fopen("bt06.txt", "w");
    if (file2 == NULL) {
        printf("Khong the mo file bt06.txt\n");
        fclose(file1);
        return 1;
    }
    while ((c = fgetc(file1)) != EOF) {
        fputc(c, file2);
    }
    fclose(file1);
    fclose(file2);
    printf("Noi dung da duoc sao chep sang file bt06.txt thanh cong.\n");

    return 0;
}

