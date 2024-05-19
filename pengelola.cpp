#include <iostream>
#include <string>
#include "231511065/231511065.h"
#include "231511074/231511074.h"
#include "231511076/231511076.h"
#include "231511077/231511077.h"
using namespace std;

int main ()
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
    
    int Key1 = 2, Key2 = 1, Key3 = 3, Key4 = 4;
    addrMatriks matriksKunci = insertKunciMatriks(Key1, Key2, Key3, Key4);
    addrMatriks invMatriks = inversMatriksKunci(matriksKunci, modulus);
    
    int pilihan;
    do{
    system("cls");
    cout << "|---------------------------------------------------------|" << endl;
    cout << "|                      Selamat Datang                     |" << endl;
    cout << "|---------------------------------------------------------|" << endl;
    cout << "|                   Di Aplikasi E-Voting                  |" << endl;
    cout << "|---------------------------------------------------------|" << endl << endl;

    cout << "\n[1]Login" << endl;
    cout << "[2]Keluar" << endl;
    cout << "Masukkan Pilihan = ";
    cin >> pilihan;

    switch (pilihan)
    {
    case 1 :
        system("cls");
        menu_login_pengelola();
        break;
    
    case 2 :
        break;

    default:
        cout << "Input angka sesuai pilihan !" << endl;
        break;
    }

    }while (pilihan!=2);

    bool hapusTabel = deleteTabel(baca);
    bool hapusMat = hapusMatriks(matriksKunci);

    return 0;
}