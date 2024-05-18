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

bool registrasi()
{
    Pengguna pengguna;
    istringstream iss;
    string data, dataPengguna, cekNim;
    bool cariNim;

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
            data = dekripsi(data); // * dekripsi data pengguna
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
                inputFile << enkripsi(dataPengguna) << endl; // * Mengenkripsi data pengguna lalu menyimpannya ke data-pengguna.txt
                inputFile.close();

                system("cls");

                cout << "=============================================================" << endl;
                cout << "|                   REGISTRASI BERHASIL!                    |" << endl;
                cout << "-------------------------------------------------------------" << endl;
                cout << "|              Tekan enter untuk melanjutkan..              |" << endl;
                cout << "=============================================================" << endl;

                return true;
            }
            else
            {
                cout << "Gagal mengakses data pengguna";
                return false;
            }
        }
        readFile.close();
    }
    else
    {
        cout << "Gagal mengakses data pengguna";
        return false;
    }
}

bool login(Pengguna &pengguna)
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
            data = dekripsi(data); // * dekripsi data pengguna
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

// void menuUtama(Pengguna pengguna)
// {
//     int opsi;

//     cout << "==================== " << "Selamat datang " << pengguna.nama << " ====================\n" << endl;
//     cout << "(1) Melakukan voting\n";
//     cout << "(2) Lihat Visi & Misi\n";
//     cout << "(3) Logout\n";
//     cout << "inputkan pilihan anda: ";
//     cin >> opsi;

//     switch (opsi)
//     {
//     case 1:
//         if (pengguna.status == "1")
//         {
//             system("cls");
//             cout << "============================================================" << endl;
//             cout << "|                Anda sudah melakukan vote!                |" << endl;
//             cout << "------------------------------------------------------------" << endl;
//             cout << "|             Tekan enter untuk melanjutkan..              |" << endl;
//             cout << "============================================================" << endl;
//             getchar();
//             getchar();
//             system("cls");
//             menuUtama(pengguna);
//         }
//         else
//         {
//             system("cls");
//             menuVote(pengguna);
//             system("cls");
//             menuUtama(pengguna);
//         }
//         break;
//     case 2:
//         system("cls");
//         menuVisiMisi(pengguna);
//         break;
//     case 3:
//         system("cls");
//         break;

//     default:
//         cout << "Ketikkan salah satu pilihan diatas! \n";
//         getchar();
//         getchar();
//         system("cls");
//         menuUtama(pengguna);
//         break;
//     }
// }

void swap(int &a, int &b)
{
    int temp;

    temp = a;
    a = b;
    b = temp;
}

addrMatriks inversMatriks(int matriks[2][2], int modulus)
{
    int hasilMod, temp, det, hasil, bil;

    det = (matriks[0][0] * matriks[1][1]) - (matriks[0][1] * matriks[1][0]); // * cari determinan

    bil = 1;
    while (hasil != 1) // * cari 1/det mod jumlah karakter(94)
    {
        bil++;
        hasil = (det * bil) % modulus;
    }

    hasilMod = bil; // * hasilMod dimasukan nilai dari bil

    swap(matriks[0][0], matriks[1][1]); // * swap a dan d
    matriks[0][1] = matriks[0][1] * -1; // * mengubah b menjadi -b
    matriks[1][0] = matriks[1][0] * -1; // * mengubah c menjadi -c

    for (int i = 0; i < 2; i++) // * matriks kunci dikalikan  dengan hasil Mod
    {
        for (int j = 0; j < 2; j++)
        {
            if (matriks[i][j] >= 0) // * cek apakah positif
            {
                matriks[i][j] = (matriks[i][j] * hasilMod) % modulus;
            }
            else
            {
                matriks[i][j] = (((matriks[i][j] * hasilMod) % modulus) + modulus) % modulus;
            }
        }
    }
}