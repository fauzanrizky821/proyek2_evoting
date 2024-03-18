#include "231511076.h"

void clearScreen()
{
    system("cls");

    std::cout << "============================================================" << std::endl;
    std::cout << "|                                                          |" << std::endl;
    std::cout << "|                         REGISTRASI                       |" << std::endl;
    std::cout << "|                                                          |" << std::endl;
    std::cout << "============================================================" << std::endl;
    std::cout << "|                  Masukkan data diri anda                 |" << std::endl;
    std::cout << "============================================================" << std::endl;
}

void registrasi()
{
    Pengguna pengguna;
    std::istringstream iss;
    std::string data, dataPengguna, cekNim;
    bool cariNim;

    clearScreen();

    // * Menginput Data diri
    std::cout << "NIM: ";
    std::cin >> pengguna.nim;
    clearScreen();

    // * cek jumlah karakter NIM, jika tidak sama dengan 9 maka akan loop terus
    while (pengguna.nim.length() != 9)
    {
        std::cout << "jumlah NIM harus 9 karakter\n";
        std::cout << "NIM: ";
        std::cin >> pengguna.nim;
        clearScreen();
    }

    std::ifstream readFile;
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
                std::cout << "============================================================" << std::endl;
                std::cout << "|                     NIM SUDAH DIPAKAI                    |" << std::endl;
                std::cout << "------------------------------------------------------------" << std::endl;
                std::cout << "|             Tekan enter untuk melanjutkan..              |" << std::endl;
                std::cout << "============================================================" << std::endl;

                getchar();
            }
        }

        if (!cariNim)
        { // * jika nim belum dipakai
            std::cout << "Password: ";
            std::cin >> pengguna.password;
            clearScreen();

            std::cout << "Nama: ";
            std::cin.sync();
            std::getline(std::cin, pengguna.nama);
            clearScreen();

            std::cout << "Jurusan: ";
            std::cin.sync();
            std::getline(std::cin, pengguna.jurusan);
            clearScreen();

            std::cout << "Prodi: ";
            std::cin.sync();
            std::getline(std::cin, pengguna.prodi);
            clearScreen();

            std::ofstream inputFile;
            // * Membuka file
            inputFile.open("data/data-pengguna.txt", std::ios::app);

            if (inputFile.is_open())
            { // * Cek apakah file terbuka atau tidak
                // * Menyimpan file
                dataPengguna = pengguna.nim + "," + pengguna.password + "," + pengguna.nama + "," + pengguna.jurusan + "," + pengguna.prodi + "," + pengguna.status + ",";
                inputFile << enkripsi(dataPengguna) << std::endl; // * Mengenkripsi data pengguna lalu menyimpannya ke data-pengguna.txt
                inputFile.close();

                system("cls");

                std::cout << "=============================================================" << std::endl;
                std::cout << "|                   REGISTRASI BERHASIL!                    |" << std::endl;
                std::cout << "-------------------------------------------------------------" << std::endl;
                std::cout << "|              Tekan enter untuk melanjutkan..              |" << std::endl;
                std::cout << "=============================================================" << std::endl;
            }
            else
            {
                std::cout << "Gagal mengakses data pengguna";
            }
        }
    }
    else
    {
        std::cout << "Gagal mengakses data pengguna";
    }
}

bool login(Pengguna &pengguna)
{
    std::istringstream iss;
    std::string data, inputNim, cekNim, password, cekPassword;
    bool cariNim = false;

    std::cout << "============================================================" << std::endl;
    std::cout << "|                                                          |" << std::endl;
    std::cout << "|                           LOGIN                          |" << std::endl;
    std::cout << "|                                                          |" << std::endl;
    std::cout << "============================================================" << std::endl;

    std::cout << "NIM     : ";
    std::cin >> inputNim;
    std::cout << "Password: ";
    std::cin >> password;

    std::ifstream readFile;

    readFile.open("data/data-pengguna.txt");

    if (readFile.is_open())
    { // * Cek apakah file terbuka atau tidak

        while (getline(readFile, data) && !cariNim)
        {
            iss.clear();
            data = dekripsi(data); // * dekripsi data pengguna
            iss.str(data);
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

                    std::cout << "=============================================================" << std::endl;
                    std::cout << "|                      LOGIN BERHASIL!                      |" << std::endl;
                    std::cout << "-------------------------------------------------------------" << std::endl;
                    std::cout << "|              Tekan enter untuk melanjutkan..              |" << std::endl;
                    std::cout << "=============================================================" << std::endl;

                    return true;
                }
                else
                {
                    std::cout << "============================================================" << std::endl;
                    std::cout << "|                      PASSWORD SALAH!                     |" << std::endl;
                    std::cout << "------------------------------------------------------------" << std::endl;
                    std::cout << "|             Tekan enter untuk melanjutkan..              |" << std::endl;
                    std::cout << "============================================================" << std::endl;

                    return false;

                    getchar();
                }
            }
        }

        if (!cariNim)
        { // * jika nim tidak ditemukan
            std::cout << "============================================================" << std::endl;
            std::cout << "|                   NIM TIDAK DITEMUKAN!                   |" << std::endl;
            std::cout << "------------------------------------------------------------" << std::endl;
            std::cout << "|             Tekan enter untuk melanjutkan..              |" << std::endl;
            std::cout << "============================================================" << std::endl;

            return false;

            getchar();
        }

        readFile.close();
    }
    else
    {
        std::cout << "Gagal mengakses data pengguna";

        return false;
    }

    return false;
}

void menuUtama(Pengguna pengguna)
{
    int opsi;

    std::cout << "==================== " << "Selamat datang " << pengguna.nama << " ====================\n" << std::endl;
    std::cout << "(1) Melakukan voting\n";
    std::cout << "(2) Lihat Visi & Misi\n";
    std::cout << "(3) Logout\n";
    std::cout << "inputkan pilihan anda: ";
    std::cin >> opsi;

    switch (opsi)
    {
    case 1:
        if (pengguna.status == "1")
        {
            system("cls");
            std::cout << "============================================================" << std::endl;
            std::cout << "|                Anda sudah melakukan vote!                |" << std::endl;
            std::cout << "------------------------------------------------------------" << std::endl;
            std::cout << "|             Tekan enter untuk melanjutkan..              |" << std::endl;
            std::cout << "============================================================" << std::endl;
            getchar();
            getchar();
            system("cls");
            menuUtama(pengguna);
        }
        else
        {
            system("cls");
            menuVote(pengguna);
            system("cls");
            menuUtama(pengguna);
        }
        break;
    case 2:
        system("cls");
        menuVisiMisi(pengguna);
        break;
    case 3:
        system("cls");
        break;

    default:
        std::cout << "Ketikkan salah satu pilihan diatas! \n";
        getchar();
        getchar();
        system("cls");
        menuUtama(pengguna);
        break;
    }
}

void swap(int &a, int &b)
{
    int temp;

    temp = a;
    a = b;
    b = temp;
}

int inversMatriks(int matriks[2][2], int modulus)
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
    matriks[1][0] = matriks[1][0] * -1; // * menugbah c menjadi -c

    for (int i = 0; i < 2; i++) // * matriks kunci dikalikan  dengan hasiMod
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

    return matriks[2][2];
}