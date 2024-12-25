#include <stdio.h>
#include <string.h>

struct Book {
    char id[20];
    char name[50];
    char author[50];
    float price;
    char genre[30];
};

struct Book books[100];
int currentLength = 0;

void nhapThongTinSach() {
    printf("Nhap so luong sach: ");
    int soLuong;
    scanf("%d", &soLuong);
    fflush(stdin);
    for (int i = 0; i < soLuong; i++) {
        printf("Nhap thong tin sach thu %d:\n", currentLength + 1);
        printf("ID: ");
        fgets(books[currentLength].id, 20, stdin);
        printf("Ten sach: ");
        fgets(books[currentLength].name, 50, stdin);
        printf("Tac gia: ");
        fgets(books[currentLength].author, 50, stdin);
        printf("Gia tien: ");
        scanf("%f", &books[currentLength].price);
        fflush(stdin);
        printf("The loai: ");
        fgets(books[currentLength].genre, 30, stdin);
        currentLength++;
    }
}

void luuThongTinSach() {
    FILE *file = fopen("books.dat", "wb");
    if (file != NULL) {
        fwrite(&currentLength, sizeof(int), 1, file);
        fwrite(books, sizeof(struct Book), currentLength, file);
        fclose(file);
        printf("Da luu thong tin sach vao file.\n");
    } else {
        printf("Khong the mo file de ghi thong tin sach.\n");
    }
}

void layThongTinSach() {
    FILE *file = fopen("books.dat", "rb");
    if (file != NULL) {
        fread(&currentLength, sizeof(int), 1, file);
        fread(books, sizeof(struct Book), currentLength, file);
        fclose(file);
        printf("Da lay thong tin sach tu file.\n");
    } else {
        printf("Khong the mo file de doc thong tin sach.\n");
    }
}

void hienThiThongTinSach() {
    printf("\nThong tin cac cuon sach:\n");
    for (int i = 0; i < currentLength; i++) {
        printf("Ma sach: %s\n", books[i].id);
        printf("Ten sach: %s\n", books[i].name);
        printf("Tac gia: %s\n", books[i].author);
        printf("Gia tien: %.2f\n", books[i].price);
        printf("The loai: %s\n\n", books[i].genre);
    }
}

int main() {
    int choice;
    do {
        printf("\nMENU\n");
        printf("1. Nhap so luong va thong tin sach\n");
        printf("2. Luu thong tin sach vao file\n");
        printf("3. Lay thong tin sach tu file\n");
        printf("4. Hien thi thong tin sach\n");
        printf("5. Thoat\n");
        printf("\nLua chon cua ban: ");
        scanf("%d", &choice);
        fflush(stdin);

        switch (choice) {
            case 1:
                nhapThongTinSach();
                break;
            case 2:
                luuThongTinSach();
                break;
            case 3:
                layThongTinSach();
                break;
            case 4:
                hienThiThongTinSach();
                break;
            case 5:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (choice != 5);

    return 0;
}

