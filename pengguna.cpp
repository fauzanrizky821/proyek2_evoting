#include <iostream>
#include <string>
#include "231511076/231511076.h"

int main ()
{
    int opsi;
    std::string nim,nama,jurusan,prodi;
    bool cekLogin;

    std::cout << "============================================================" << std::endl;
    std::cout << "|                      APLIKASI E-VOTING                   |" << std::endl;
    std::cout << "============================================================" << std::endl;
    std::cout << "|                                                          |" << std::endl;
    std::cout << "|                       SELAMAT DATANG                     |" << std::endl;
    std::cout << "|                                                          |" << std::endl;
    std::cout << "============================================================" << std::endl;
    std::cout << "(1) Login\n";
    std::cout << "(2) Registrasi\n";
    std::cout << "inputkan pilihan anda: ";
    std::cin >> opsi;

    switch (opsi)
    {
    case 1:
        system("cls");
        cekLogin = login(nim,nama,jurusan,prodi);
        getchar();
        getchar();
        system("cls");
        if (cekLogin == true)
        {
            break;
        } else {
            main();
        }
    case 2:
        registrasi();
        getchar();
        system("cls");
        main();

    default:
        std::cout << "Ketikkan salah satu pilihan diatas! \n" ;
        getchar();
        getchar();
        main();
    }

    
    std::cout << "==================== "<< "Selamat datang " << nama <<" ====================\n" << std::endl;
    std::cout << "(1) Voting\n";
    std::cout << "(2) Logout\n";
    std::cout << "inputkan pilihan anda: ";
    std::cin >> opsi;

    switch (opsi)
    {
    case 1:
        system("cls");
        std::cout << "Halaman voting \n" ;
        getchar();
        getchar();
    case 2:
        system("cls");
        main();
    default:
        std::cout << "Ketikkan salah satu pilihan diatas! \n" ;
        getchar();
        getchar();
        main();
    }
}