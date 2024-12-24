#include <stdio.h>

int main() {
    int soDong;
    char line[100];
    FILE *file;
    file = fopen("bt05.txt", "w");
    if (file == NULL) {
        printf("Khong the mo file bt05.txt\n");
        return 1;
    }
    printf("Nhap so dong: ");
    scanf("%d", &soDong);
    for (int i = 0; i < soDong; i++) {
        printf("Nhap noi dung dong thu %d: ", i + 1);
        fgets(line, sizeof(line), stdin);
        fprintf(file, "%s", line);
    }
    fclose(file);
    file = fopen("bt05.txt", "r");
    if (file == NULL) {
        printf("Khong the mo file bt05.txt\n");
        return 1;
    }
    printf("\nNoi dung file bt05.txt:\n");
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }
    fclose(file);

    return 0;
}

