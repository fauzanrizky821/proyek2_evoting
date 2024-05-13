#include "231511070.h"

int main() {
    addrTable awal = NULL;
    addrTable akhir = NULL;
    char pilihan;
    char karakter;

    do {
        printf("\nMenu Operasi Linked List\n");
        printf("1. Tambah Karakter\n");
        printf("2. Hapus Karakter Terakhir\n");
        printf("3. Tampilkan Linked List\n");
        printf("4. Keluar\n");
        printf("Pilih operasi: ");
        scanf(" %c", &pilihan);

        switch (pilihan) {
            case '1':
                printf("Masukkan karakter yang ingin ditambahkan: ");
                scanf(" %c", &karakter);
                insertChar(karakter, awal, akhir);
                break;
            case '2':
                karakter = deleteChar(awal, akhir);
                if (karakter != '\0') {
                    printf("Karakter '%c' dihapus dari linked list\n", karakter);
                }
                break;
            case '3':
                tampilkanList(awal, akhir);
                break;
            case '4':
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid. Masukkan pilihan 1-4.\n");
                break;
        }

    } while (pilihan != '4');

    // Dealokasi semua node setelah selesai menggunakan linked list
    addrTable current = awal;
    while (current != NULL) {
        addrTable temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}