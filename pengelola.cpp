#include <iostream>
#include <string>
#include "231511065/231511065.h"
#include "231511074/231511074.h"
#include "231511076/231511076.h"
#include "231511077/231511077.h"
using namespace std;

int main()
{
    addrTable baca = bacaFile("data/tabel-konversi.txt");
    if (baca == NULL)
    {
        cout << "Gagal membaca file tabel konversi!\n Klik enter untuk melanjutkan!";
        getchar();
        getchar();
        return 0;
    }

    int modulus = mod(baca);
    bool cekLogin;
    int pilihan;
    int Key1 = 2, Key2 = 1, Key3 = 3, Key4 = 4;
    addrMatriks matriksKunci = insertKunciMatriks(Key1, Key2, Key3, Key4);
    addrMatriks invMatriks = inversMatriksKunci(matriksKunci, modulus);

    do
    {
        system("cls");
        cout << "|---------------------------------------------------------|" << endl;
        cout << "|                      Selamat Datang                     |" << endl;
        cout << "|---------------------------------------------------------|" << endl;
        cout << "|                   Di Aplikasi E-Voting                  |" << endl;
        cout << "|---------------------------------------------------------|" << endl
             << endl;

        cout << "\n[1]Login" << endl;
        cout << "[2]Keluar" << endl;
        cout << "Masukkan Pilihan = ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            system("cls");
            if (menu_login_pengelola(invMatriks, baca, modulus))
            {
                int choice;
                do
                {
                    system("cls");
                    // Tampilkan menu
                    cout << "\nMenu Pengelola:\n";
                    cout << "+----+---------------------+\n";
                    cout << "| 1  | Lihat hasil voting  |\n";
                    cout << "| 2  | Lihat Data Pemilih  |\n";
                    cout << "| 3  | Logout              |\n";
                    cout << "+----+---------------------+\n";
                    cout << "Pilih: ";
                    cin >> choice;

                    string hasilVoting;
                    switch (choice)
                    {
                    case 1:
                        system("cls");
                        hasilVoting = melihatHasilVoting(invMatriks, baca, modulus);
                        cout << hasilVoting;
                        cout << "Klik enter untuk kembali";
                        cin.ignore();
                        cin.get();
                        system("cls");
                        break;

                    case 2:
                        system("cls");
                        lihatDataPemilih(invMatriks, baca, modulus);
                        cout << "Klik enter untuk kembali";
                        cin.ignore();
                        cin.get();
                        system("cls");
                        break;

                    case 3:
                        cout << "Logout berhasil.\n\n";
                        cout << "Klik enter untuk kembali";
                        cin.ignore();
                        cin.get();
                        system("cls");
                        break;
                    default:
                        cout << "Pilihan tidak valid. Silakan coba lagi.\n";
                    }

                } while (choice != 3);
                break;
            }

        case 2:
            break;

        default:
            cout << "Input angka sesuai pilihan !" << endl;
            break;
        }

    } while (pilihan != 2);

    bool hapusTabel = deleteTabel(baca);
    bool hapusMat = hapusMatriks(matriksKunci);

    return 0;
}