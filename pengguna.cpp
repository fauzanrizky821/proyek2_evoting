#include <iostream>
#include <string>
#include "231511076/231511076.h"
#include "231511077/231511077.h" 


int main ()
{
    int opsi;
    Akun akun;
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
        cekLogin = login(akun.nim,akun.nama,akun.jurusan,akun.prodi,akun.status);
        getchar();
        getchar();
        system("cls");
        if (cekLogin == true) // cek apakah login berhasil atau tidak, jika berhasil bernilai true
        {
            menuUtama(akun);
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

}