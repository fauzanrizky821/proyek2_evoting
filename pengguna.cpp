#include "231511070/231511070.h"
#include "231511076/231511076.h"
#include "231511077/231511077.h"

int main()
{
    int opsi;
    Pengguna pengguna;
    bool cekLogin;

    do
    {
        std::cout << "============================================================" << std::endl;
        std::cout << "|                      APLIKASI E-VOTING                   |" << std::endl;
        std::cout << "============================================================" << std::endl;
        std::cout << "|                                                          |" << std::endl;
        std::cout << "|                       SELAMAT DATANG                     |" << std::endl;
        std::cout << "|                                                          |" << std::endl;
        std::cout << "============================================================" << std::endl;
        std::cout << "(1) Login\n";
        std::cout << "(2) Registrasi\n";
        std::cout << "(0) Keluar Aplikasi\n";
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
                do
                {
                    cout << "==================== " << "Selamat datang " << pengguna.nama << " ====================\n"
                         << endl;
                    cout << "(1) Melakukan voting\n";
                    cout << "(2) Lihat Visi & Misi\n";
                    cout << "(0) Logout\n";
                    cout << "inputkan pilihan anda: ";
                    cin >> opsi;

                    switch (opsi)
                    {
                    case 1:
                        if (pengguna.status == "1")
                        {
                            system("cls");
                            cout << "============================================================" << endl;
                            cout << "|                Anda sudah melakukan vote!                |" << endl;
                            cout << "------------------------------------------------------------" << endl;
                            cout << "|             Tekan enter untuk melanjutkan..              |" << endl;
                            cout << "============================================================" << endl;
                            getchar();
                            getchar();
                            system("cls");
                        }
                        else
                        {
                            system("cls");
                            menuVote(pengguna);
                            system("cls");
                        }
                        break;
                    case 2:
                        system("cls");
                        menuVisiMisi(pengguna);
                        break;
                    case 0:
                        system("cls");
                        break;

                    default:
                        cout << "Ketikkan salah satu pilihan diatas! \n";
                        getchar();
                        getchar();
                        system("cls");
                        break;
                    }
                } while (opsi != 0);
                main();
            }
            break;
        case 2:
            registrasi();
            getchar();
            system("cls");
            break;
        case 0:
            system("cls");
            break;

        default:
            std::cout << "Ketikkan salah satu pilihan diatas! \n";
            getchar();
            getchar();
            system("cls");
            break;
        }
    } while (opsi != 0);
    return 0;
}