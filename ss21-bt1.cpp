#include <stdio.h>

int main() {
    char str[100];
    FILE *file;
    file = fopen("bt01.txt", "w");
    printf("Nhap mot chuoi bat ky: ");
    fgets(str, sizeof(str), stdin);
    fprintf(file, "%s", str);
    fclose(file);
    printf("Chuoi da duoc ghi vao file bt01.txt thanh cong.\n");

    return 0;
}

