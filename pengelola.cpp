#include <iostream>
#include <string>
#include "231511065/231511065.h"
#include "231511074/231511074.h"
#include "231511076/231511076.h"
#include "231511077/231511077.h"

int main ()
{
    int pilihan;
    do{
    system("cls");
    std::cout << "|---------------------------------------------------------|" << std::endl;
    std::cout << "|                      Selamat Datang                     |" << std::endl;
    std::cout << "|---------------------------------------------------------|" << std::endl;
    std::cout << "|                   Di Aplikasi E-Voting                  |" << std::endl;
    std::cout << "|---------------------------------------------------------|" << std::endl << std::endl;

    std::cout << "\n[1]Login" << std::endl;
    std::cout << "[2]Keluar" << std::endl;
    std::cout << "Masukkan Pilihan = ";
    std::cin >> pilihan;

    switch (pilihan)
    {
    case 1 :
        system("cls");
        menu_login_pengelola();
        break;
    
    case 2 :
        break;

    default:
        std::cout << "Input angka sesuai pilihan !" << std::endl;
        break;
    }

    }while (pilihan!=2);

    return 0;
}