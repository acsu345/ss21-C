#include <stdio.h>

int main() {
    char str[100];
    FILE *file;
    file = fopen("bt01.txt", "a");
    if (file == NULL) {
        printf("Khong the mo file bt01.txt\n");
        return 1;
    }
    printf("Nhap mot chuoi bat ky de ghi them vao file: ");
    fgets(str, sizeof(str), stdin);
    fprintf(file, "%s", str);
    fclose(file);
    printf("Chuoi da duoc ghi them vao file bt01.txt thanh cong.\n");

    return 0;
}

