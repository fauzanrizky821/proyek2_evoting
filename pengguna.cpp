#include "231511070/231511070.h"
#include "231511076/231511076.h"
#include "231511077/231511077.h" 

int main ()
{
    int opsi;
    Pengguna pengguna;
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
    std::cout << "(3) Keluar Aplikasi\n";
    std::cout << "inputkan pilihan anda: ";
    std::cin >> opsi;

    switch (opsi)
    {
    case 1:
        system("cls");
        cekLogin = login(pengguna);
        getchar();
        getchar();
        system("cls");
        if (cekLogin == true) // cek apakah login berhasil atau tidak, jika berhasil bernilai true
        {
            menuUtama(pengguna);
            main();
        }
        else
        {
            main();
        }
        break;
    case 2:
        registrasi();
        getchar();
        system("cls");
        main();
        break;
    case 3:
        return 0;
        break;

    default:
        std::cout << "Ketikkan salah satu pilihan diatas! \n";
        getchar();
        getchar();
        system("cls");
        main();
        break;
    }
}