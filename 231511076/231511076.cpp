#include "231511076.h"

void clearScreen()
{
    system("cls");
    cout << "============================================================" << endl;
    cout << "|                                                          |" << endl;
    cout << "|                         REGISTRASI                       |" << endl;
    cout << "|                                                          |" << endl;
    cout << "============================================================" << endl;
    cout << "|                  Masukkan data diri anda                 |" << endl;
    cout << "============================================================" << endl;
}

bool registrasi(addrMatriks matriks, addrMatriks invMatriks,addrTable karakterList, int modulus)
{
    Pengguna pengguna;
    istringstream iss;
    string data, dataPengguna, cekNim;
    bool cariNim, cekRegis;

    clearScreen();

    // * Menginput Data diri
    cout << "NIM: ";
    cin >> pengguna.nim;
    clearScreen();

    // * cek jumlah karakter NIM, jika tidak sama dengan 9 maka akan loop terus
    while (pengguna.nim.length() != 9)
    {
        cout << "jumlah NIM harus 9 karakter\n";
        cout << "NIM: ";
        cin >> pengguna.nim;
        clearScreen();
    }

    ifstream readFile;
    readFile.open("data/data-pengguna.txt");

    if (readFile.is_open())
    { // * Cek apakah file terbuka atau tidak
        while (getline(readFile, data) && !cariNim)
        {
            iss.clear();
            data = dekripsi(data, invMatriks, karakterList, modulus); // * dekripsi data pengguna
            iss.str(data);
            getline(iss, cekNim, ',');

            if (pengguna.nim == cekNim)
            {                   // * mencari nim yang diinputkan dan nim yang ada di dalam file data-pengguna.txt
                cariNim = true; // * jika ketemu nimnya, beri nilai true
                system("cls");
                cout << "============================================================" << endl;
                cout << "|                     NIM SUDAH DIPAKAI                    |" << endl;
                cout << "------------------------------------------------------------" << endl;
                cout << "|             Tekan enter untuk melanjutkan..              |" << endl;
                cout << "============================================================" << endl;

                getchar();
            }
        }

        if (!cariNim)
        { // * jika nim belum dipakai
            cout << "Password: ";
            cin >> pengguna.password;
            clearScreen();

            cout << "Nama: ";
            cin.sync();
            getline(cin, pengguna.nama);
            clearScreen();

            cout << "Jurusan: ";
            cin.sync();
            getline(cin, pengguna.jurusan);
            clearScreen();

            cout << "Prodi: ";
            cin.sync();
            getline(cin, pengguna.prodi);
            clearScreen();

            ofstream inputFile;
            // * Membuka file
            inputFile.open("data/data-pengguna.txt", ios::app);

            if (inputFile.is_open())
            { // * Cek apakah file terbuka atau tidak
                // * Menyimpan file
                dataPengguna = pengguna.nim + "," + pengguna.password + "," + pengguna.nama + "," + pengguna.jurusan + "," + pengguna.prodi + "," + pengguna.status + ",";
                inputFile << enkripsi(dataPengguna, matriks, karakterList, modulus) << endl; // * Mengenkripsi data pengguna lalu menyimpannya ke data-pengguna.txt
                inputFile.close();

                system("cls");

                cout << "=============================================================" << endl;
                cout << "|                   REGISTRASI BERHASIL!                    |" << endl;
                cout << "-------------------------------------------------------------" << endl;
                cout << "|              Tekan enter untuk melanjutkan..              |" << endl;
                cout << "=============================================================" << endl;

                cekRegis = true;
            }
            else
            {
                cout << "Gagal mengakses data pengguna";
                cekRegis = false;
            }
        }
        readFile.close();
    }
    else
    {
        cout << "Gagal mengakses data pengguna";
        cekRegis =  false;
    }

    return cekRegis;
}

bool loginPengguna(Pengguna &pengguna, addrMatriks invMatriks, addrTable karakterList, int modulus)
{
    istringstream iss;
    string data, inputNim, cekNim, password, cekPassword;
    bool cariNim = false;

    cout << "============================================================" << endl;
    cout << "|                                                          |" << endl;
    cout << "|                           LOGIN                          |" << endl;
    cout << "|                                                          |" << endl;
    cout << "============================================================" << endl;

    cout << "NIM     : ";
    cin >> inputNim;
    cout << "Password: ";
    cin >> password;

    ifstream readFile;

    readFile.open("data/data-pengguna.txt");

    if (readFile.is_open())
    { // * Cek apakah file terbuka atau tidak

        while (getline(readFile, data) && !cariNim) // * (istream, string, delimination/pembatasan)
        {
            iss.clear();
            data = dekripsi(data, invMatriks, karakterList, modulus); // * dekripsi data pengguna
            iss.str(data);         // * mendapatkan atau menyetel konten objek perangkat string yang mendasarinya
            getline(iss, cekNim, ',');

            system("cls");

            if (inputNim == cekNim)
            {                   // * mencari nim yang diinputkan dan nim yang ada di dalam file data-pengguna.txt
                cariNim = true; // * jika ketemu nimnya, beri nilai true
                getline(iss, cekPassword, ',');

                if (password == cekPassword)
                { // * cek apakah password yang diinputkan sama dengan password dalam file
                    pengguna.nim = inputNim;
                    pengguna.password = password;
                    getline(iss, pengguna.nama, ',');
                    getline(iss, pengguna.jurusan, ',');
                    getline(iss, pengguna.prodi, ',');
                    getline(iss, pengguna.status, ',');

                    cout << "=============================================================" << endl;
                    cout << "|                      LOGIN BERHASIL!                      |" << endl;
                    cout << "-------------------------------------------------------------" << endl;
                    cout << "|              Tekan enter untuk melanjutkan..              |" << endl;
                    cout << "=============================================================" << endl;

                    return true;
                }
                else
                {
                    cout << "============================================================" << endl;
                    cout << "|                      PASSWORD SALAH!                     |" << endl;
                    cout << "------------------------------------------------------------" << endl;
                    cout << "|             Tekan enter untuk melanjutkan..              |" << endl;
                    cout << "============================================================" << endl;

                    return false;

                    getchar();
                }
            }
        }

        if (!cariNim)
        { // * jika nim tidak ditemukan
            cout << "============================================================" << endl;
            cout << "|                   NIM TIDAK DITEMUKAN!                   |" << endl;
            cout << "------------------------------------------------------------" << endl;
            cout << "|             Tekan enter untuk melanjutkan..              |" << endl;
            cout << "============================================================" << endl;

            return false;

            getchar();
        }

        readFile.close();
    }
    else
    {
        cout << "Gagal mengakses data pengguna";

        return false;
    }

    return false;
}

void swap(int &a, int &b)
{
    int temp;

    temp = a;
    a = b;
    b = temp;
}

int determinan (addrMatriks first)
{
   return (searchMatriks(first,1,1)->info * searchMatriks(first,2,2)->info) - (searchMatriks(first,1,2)->info * searchMatriks(first,2,1)->info);
}

addrMatriks inversMatriksKunci(addrMatriks first, int modulus)
{
    int hasilMod, temp, det, hasil, bil;
    addrMatriks invMatriks = insertKunciMatriks(searchMatriks(first, 1, 1)->info, searchMatriks(first, 1, 2)->info, searchMatriks(first, 2, 1)->info, searchMatriks(first, 2, 2)->info);

    det = determinan(invMatriks); // * cari determinan

    bil = 1;
    while (hasil != 1) // * cari 1/det mod jumlah karakter(94)
    {
        bil++;
        hasil = (det * bil) % modulus;
    }

    hasilMod = bil; // * hasilMod di-assign nilai dari bil

    // * swap a dan d
    temp = searchMatriks(invMatriks, 1, 1)->info;
    searchMatriks(invMatriks, 1, 1)->info = searchMatriks(invMatriks, 2, 2)->info;
    searchMatriks(invMatriks, 2, 2)->info = temp;

    searchMatriks(invMatriks,1,2)->info = searchMatriks(invMatriks,1,2)->info * -1; // * mengubah b menjadi -b
    searchMatriks(invMatriks,2,1)->info = searchMatriks(invMatriks,2,1)->info * -1; // * mengubah c menjadi -c

    for (int i = 1; i <= 2; i++) // * matriks kunci dikalikan  dengan hasil Mod
    {
        for (int j = 1; j <= 2; j++)
        {
            if (searchMatriks(invMatriks,i,j)->info >= 0) // * cek apakah positif
            {
                searchMatriks(invMatriks,i,j)->info = (searchMatriks(invMatriks,i,j)->info * hasilMod) % modulus;
            }
            else
            {
                searchMatriks(invMatriks,i,j)->info = (((searchMatriks(invMatriks,i,j)->info * hasilMod) % modulus) + modulus);
            }
        }
    }

    return invMatriks;
}