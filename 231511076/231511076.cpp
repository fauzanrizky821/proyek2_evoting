#include "231511076.h"
#include "../231511077/231511077.h"

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
    std::string dataPengguna;

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
    inputFile.open("data-pengguna.txt", std::ios::app);

    if(inputFile.is_open()) { // * Cek apakah file terbuka atau tidak
        // * Menyimpan file
        dataPengguna = pengguna.nim + "," + pengguna.password + "," + pengguna.nama  + "," + pengguna.jurusan + "," + pengguna.prodi + "," + pengguna.status + ",";
        inputFile << enkripsi(dataPengguna) << std::endl; // * Mengenkripsi data pengguna lalu menyimpannya ke data-pengguna.txt
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

bool login(std::string &nim, std::string &nama, std::string &jurusan, std::string &prodi, std::string &status)
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
            data = dekripsi(data); // * dekripsi data pengguna
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
                    getline(iss, status, ',');

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

        return false;
    }

    return false;
}

void menuLoginRegister()
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
    std::cout << "inputkan pilihan anda: ";
    std::cin >> opsi;

    switch (opsi)
    {
    case 1:
        system("cls");
        cekLogin = login(pengguna.nim,pengguna.nama,pengguna.jurusan,pengguna.prodi,pengguna.status);
        getchar();
        getchar();
        system("cls");
        if (cekLogin == true) // cek apakah login berhasil atau tidak, jika berhasil bernilai true
        {
            menuUtama(pengguna);
        } else {
            menuLoginRegister();
        }
        break;
    case 2:
        registrasi();
        getchar();
        system("cls");
        menuLoginRegister();
        break;

    default:
        std::cout << "Ketikkan salah satu pilihan diatas! \n" ;
        getchar();
        getchar();
        menuLoginRegister();
        break;
    }
}

void menuUtama(Pengguna pengguna)
{
    int opsi;

    std::cout << "==================== "<< "Selamat datang " << pengguna.nama <<" ====================\n" << std::endl;
    std::cout << "(1) Melakukan voting\n";
    std::cout << "(2) Lihat Visi & Misi\n";
    std::cout << "(3) Logout\n";
    std::cout << "inputkan pilihan anda: ";
    std::cin >> opsi;

    switch (opsi)
    {
    case 1:
        system("cls");
        std::cout << "Halaman voting \n" ;
        getchar();
        getchar();
        menuLoginRegister();
        break;
    case 2:
        system("cls");
        menuVisiMisi(pengguna);
        break;
    case 3:
        system("cls");
        menuLoginRegister();
        break;

    default:
        std::cout << "Ketikkan salah satu pilihan diatas! \n" ;
        getchar();
        getchar();
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

void inversMatriks(int matriks[2][2], int modulus)
{
    int hasilMod, temp, det, hasil, bil;


    det = (matriks[0][0] * matriks[1][1]) - (matriks[0][1] * matriks[1][0]);

    bil = 1;
    while (hasil != 1)
    {
        bil++;
        hasil = (det*bil) % modulus;
    }

    hasilMod = bil;

    swap(matriks[0][0], matriks[1][1]); // swap a dan d
    matriks[0][1] = matriks[0][1] * -1; // mengubah b menjadi -b
    matriks[1][0] = matriks[1][0] * -1; // menugbah c menjadi -c

    for(int i=0;i < 2;i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (matriks[i][j] >= 0) // cek apakah positif
            {
                matriks[i][j] = (matriks[i][j] * hasilMod) % modulus;
            } else {
                matriks[i][j] = (((matriks[i][j] * hasilMod) % modulus) + modulus) % modulus;
            }
        }
    }
}