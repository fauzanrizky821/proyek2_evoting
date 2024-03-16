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
    Akun akun;

    clearScreen();

    // * Menginput Data diri
    std::cout << "NIM: "; 
    std::cin >> akun.nim;
    clearScreen();

    // * cek jumlah karakter NIM, jika tidak sama dengan 9 maka akan loop terus
    while (akun.nim.length() != 9)
    {
        std::cout << "jumlah NIM harus 9 karakter\n";
        std::cout << "NIM: ";
        std::cin >> akun.nim;
        clearScreen();
    }

    std::cout << "Password: "; 
    std::cin >> akun.password;
    clearScreen();

    std::cout << "Nama: "; 
    std::cin.sync();
    std::getline(std::cin, akun.nama);
    clearScreen();

    std::cout << "Jurusan: "; 
    std::cin.sync();
    std::getline(std::cin, akun.jurusan);
    clearScreen();

    std::cout << "Prodi: "; 
    std::cin.sync();
    std::getline(std::cin, akun.prodi);
    clearScreen();

    std::ofstream inputFile;
    // * Membuka file
    inputFile.open("data-pengguna.txt", std::ios::app);

    if(inputFile.is_open()) { // * Cek apakah file terbuka atau tidak
        // * Menyimpan file
        inputFile << akun.nim << "," << akun.password << "," << akun.nama  << "," << akun.jurusan << "," << akun.prodi << "," << akun.status << std::endl;
        inputFile.close();

        system("cls");
        
        std::cout << "=============================================================" << std::endl;
        std::cout << "|                   REGISTRASI BERHASIL!                    |" << std::endl;
        std::cout << "-------------------------------------------------------------" << std::endl;
        std::cout << "|              Tekan enter untuk melanjutkan..              |" << std::endl;
        std::cout << "=============================================================" << std::endl;
    } else {
        std::cout << "Gagal mengakses data pengguna";
    }
}

bool login(std::string &nim, std::string &nama, std::string &jurusan, std::string &prodi)
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

    readFile.open("data-pengguna.txt");

    if (readFile.is_open()) { // * Cek apakah file terbuka atau tidak

        while (getline(readFile, data) && !cariNim) {
            iss.clear();
            iss.str(data);
            getline(iss, cekNim, ',');

            system("cls");

            if (inputNim == cekNim) { // * mencari nim yang diinputkan dan nim yang ada di dalam file data-pengguna.txt
                cariNim = true; // * jika ketemu nimnya, beri nilai true
                getline(iss, cekPassword, ',');

                if (password == cekPassword) { // * cek apakah password yang diinputkan sama dengan password dalam file
                    nim = inputNim;
                    getline(iss, nama, ',');
                    getline(iss, jurusan, ',');
                    getline(iss, prodi, ',');

                    std::cout << "=============================================================" << std::endl;
                    std::cout << "|                      LOGIN BERHASIL!                      |" << std::endl;
                    std::cout << "-------------------------------------------------------------" << std::endl;
                    std::cout << "|              Tekan enter untuk melanjutkan..              |" << std::endl;
                    std::cout << "=============================================================" << std::endl;

                    return true;
                } else {
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

        if (!cariNim) { // * jika nim tidak ditemukan
            std::cout << "============================================================" << std::endl;
            std::cout << "|                   NIM TIDAK DITEMUKAN!                   |" << std::endl;
            std::cout << "------------------------------------------------------------" << std::endl;
            std::cout << "|             Tekan enter untuk melanjutkan..              |" << std::endl;
            std::cout << "============================================================" << std::endl;

            return false;

            getchar();
        }

        readFile.close();
    } else {
        std::cout << "Gagal mengakses data pengguna";
    }
}