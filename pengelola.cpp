#include <iostream>
#include <string>
#include "231511074/231511074.h"
int main ()
{
   std::cout <<  "|-------------------------------------------------------|" << std::endl;
    std::cout << "|               Selamat Datang                          |" << std::endl;
    std::cout << "|-------------------------------------------------------|" << std::endl;
    std::cout << "|               Silahkan Login                          |" << std::endl;
    std::cout << "|-------------------------------------------------------|" << std::endl;

    
    system("cls");
    int choice;
    do {
        // Tampilkan menu
        std::cout << "\nMenu Pengelola:\n";
        std::cout << "1. Lihat Hasil Voting\n";
        std::cout << "2. Lihat Data Pemilih\n";
        std::cout << "3. Logout\n";
        std::cout << "Pilih: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                melihatHasilVoting();
                break;

            case 2:
                lihatDataPemilih();
                break;

            case 3:
                std::cout << "Logout berhasil.\n";
                break;
            default:
                std::cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }

    } while (choice != 3);


    return 0;
}