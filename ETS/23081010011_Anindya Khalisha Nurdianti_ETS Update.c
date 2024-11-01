#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Mahasiswa {
    char nama[50];
    char gender; 
    struct Mahasiswa *next;
};
typedef struct Mahasiswa Mahasiswa;


Mahasiswa* createNode(char nama[], char gender) {
    Mahasiswa* newNode = (Mahasiswa*)malloc(sizeof(Mahasiswa));
    strcpy(newNode->nama, nama);
    newNode->gender = gender;
    newNode->next = newNode; 
    return newNode;
}


int tambahMahasiswa(Mahasiswa** head, char nama[], char gender) {
    if (gender == 'P' && strcmp(nama, "Cindy") == 0) {
        if (*head != NULL) {
            Mahasiswa* temp = *head;
            do {
                if (temp->gender == 'L') {
                    printf("Cindy tidak mau bergandengan tangan dengan mahasiswa!\n");
                    return 0; 
                }
                temp = temp->next;
            } while (temp != *head);
        }
    }

    Mahasiswa* newNode = createNode(nama, gender);

    if (*head == NULL) {
        *head = newNode;
    } else {
        Mahasiswa* temp = *head;
        int count = 1;

        while (temp->next != *head) {
            temp = temp->next;
            count++;
            if (count >= 20) {
                printf("Lingkaran penuh, tidak dapat menambahkan %s\n", nama);
                free(newNode);
                return 0; 
            }
        }

        if (strcmp(newNode->nama, "Irsyad") == 0 || strcmp(newNode->nama, "Arsyad") == 0) {
            Mahasiswa* check = *head;
            do {
                if (strcmp(check->nama, "Irsyad") == 0 || strcmp(check->nama, "Arsyad") == 0) {
                    if (check->next != newNode) {
                        printf("Irsyad dan Arsyad harus bersama!\n");
                        free(newNode);
                        return 0; 
                    }
                }
                check = check->next;
            } while (check != *head);
        }

        temp->next = newNode;
        newNode->next = *head; 
    }
    return 1; 
}


void hapusMahasiswa(Mahasiswa** head, char nama[], char gender) {
    if (*head == NULL) {
        printf("Lingkaran kosong, tidak ada mahasiswa untuk dihapus.\n");
        return;
    }

    Mahasiswa *current = *head, *prev = NULL;

    do {
        if (strcmp(current->nama, nama) == 0 && current->gender == gender) {
            if (prev != NULL) {
                prev->next = current->next;
            } else { 
                Mahasiswa* temp = *head;
                while (temp->next != *head) {
                    temp = temp->next;
                }
                temp->next = current->next;
                *head = current->next;
            }
            free(current);
            printf("%s (%c) telah dikeluarkan dari lingkaran\n", nama, gender);
            return;
        }
        prev = current;
        current = current->next;
    } while (current != *head);
    
    printf("Mahasiswa bernama %s dengan gender %c tidak ditemukan\n", nama, gender);
}


void printLingkaran(Mahasiswa* head) {
    if (head == NULL) {
        printf("Lingkaran kosong\n");
        return;
    }

    Mahasiswa* temp = head;
    do {
        printf("%s (%c) -> ", temp->nama, temp->gender);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}


void pisahkanLingkaran(Mahasiswa* head, Mahasiswa** mahasiswaLingkaran, Mahasiswa** mahasiswiLingkaran) {
    if (head == NULL) return;

    Mahasiswa* temp = head;
    do {
        if (temp->gender == 'L') {
            tambahMahasiswa(mahasiswaLingkaran, temp->nama, temp->gender);
        } else {
            tambahMahasiswa(mahasiswiLingkaran, temp->nama, temp->gender);
        }
        temp = temp->next;
    } while (temp != head);
}

int main() {
    Mahasiswa* lingkaranBesar = NULL;
    Mahasiswa* lingkaranMahasiswa = NULL;
    Mahasiswa* lingkaranMahasiswi = NULL;

    int pilihan;
    char nama[50];
    char gender;

    while (1) {
        printf("\nMENU:\n");
        printf("1. Tambahkan Mahasiswa\n");
        printf("2. Keluarkan Mahasiswa\n");
        printf("3. Cetak Lingkaran Besar\n");
        printf("4. Pisahkan Lingkaran Besar Menjadi Lingkaran Mahasiswa dan Mahasiswi\n");
        printf("5. Keluar\n");
        printf("PILIHAN ANDA: ");
        scanf("%d", &pilihan);
        getchar(); 

        switch (pilihan) {
            case 1:
                printf("Masukkan nama mahasiswa/i: ");
                fgets(nama, sizeof(nama), stdin);
                nama[strcspn(nama, "\n")] = 0;  
                printf("Masukkan gender (L/P): ");
                scanf(" %c", &gender);
                gender = (gender == 'L' || gender == 'P') ? gender : ' '; 
                if (gender == ' ') {
                    printf("Gender tidak valid, masukkan L untuk laki-laki atau P untuk perempuan.\n");
                } else {
                    if (tambahMahasiswa(&lingkaranBesar, nama, gender)) {
                        printf("%s berhasil ditambahkan.\n", nama);
                    }
                }
                break;
            case 2:
                printf("Masukkan nama mahasiswa/i yang ingin dikeluarkan: ");
                fgets(nama, sizeof(nama), stdin);
                nama[strcspn(nama, "\n")] = 0;

                printf("Masukkan gender (L/P) dari mahasiswa/i: ");
                scanf(" %c", &gender);
                gender = (gender == 'L' || gender == 'P') ? gender : ' '; 

                if (gender == ' ') {
                    printf("Gender tidak valid, masukkan L untuk laki-laki atau P untuk perempuan.\n");
                } else {
                    hapusMahasiswa(&lingkaranBesar, nama, gender);
                }
                break;
            case 3:
                printf("Lingkaran Besar:\n");
                printLingkaran(lingkaranBesar);
                break;
            case 4:
                pisahkanLingkaran(lingkaranBesar, &lingkaranMahasiswa, &lingkaranMahasiswi);
                printf("Lingkaran Mahasiswa:\n");
                printLingkaran(lingkaranMahasiswa);
                printf("Lingkaran Mahasiswi:\n");
                printLingkaran(lingkaranMahasiswi);
                break;
            case 5:
                printf("Keluar dari program.\n");
                return 0;
            default:
                printf("Pilihan tidak valid, coba lagi.\n");
                break;
        }
    }

    return 0;
}
