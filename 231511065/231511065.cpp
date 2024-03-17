#include "231511065.h"
#include <iostream>
#include <fstream>
#include <sstream>

void hitungJumlahVote(const std::string& nama_file) 
{
    std::map<int, int> jumlah_suara; // Gunakan map untuk menyimpan jumlah suara setiap pasangan calon

    PasanganCalon pasangan_calon[3]; 

    pasangan_calon[0].nama = "Hafiz";
    pasangan_calon[1].nama = "Fauzan";
    pasangan_calon[2].nama = "Abyan";

    pasangan_calon[0].nomor = 1;
    pasangan_calon[1].nomor = 2;
    pasangan_calon[2].nomor = 3;

    std::ifstream infile(nama_file);
    if (!infile) 
    {
        std::cerr << "Cannot open file\n";
        return;
    }

    std::string line;
    int nomor_pasangan = 1; // Nomor pasangan calon untuk mengakses array pasangan_calon
    while (std::getline(infile, line)) 
    {
        std::stringstream ss(line);
        int suara;

        // Menggunakan stringstream untuk membaca suara
        ss >> suara;

        // Mencari pasangan calon yang sesuai dengan nomor pasangan calon
        for (const auto& pasangan : pasangan_calon) 
        {
            if (pasangan.nomor == nomor_pasangan) 
            {
                jumlah_suara[nomor_pasangan] += suara;
                break; // Hentikan pencarian setelah menemukan pasangan calon yang sesuai
            }
        }

        nomor_pasangan++;
    }

    infile.close();
    int i=1;
    std::cout << "=============================================================" << std::endl;
    std::cout << "|                   HASIL TOTAL VOTE                        |" << std::endl;
    std::cout << "-------------------------------------------------------------" << std::endl;
    // Menampilkan total suara untuk setiap pasangan calon
    for (const auto& pasangan : pasangan_calon) 
    {
        std::cout << "                    Pasangan Calon " << i << ": "<< pasangan.nama << std::endl;
        std::cout << "                    Total Suara: " << jumlah_suara[pasangan.nomor]<< std::endl;
        std::cout << "                                                             " << std::endl;
        i++;
    }
    std::cout << "=============================================================" << std::endl;
}
bool login(Pengelola* head, std::string& id, std::string& nama) {
    std::string inputID, password, cekID, cekPassword, data;
    bool cariID = false;

    std::cout << "============================================================" << std::endl;
    std::cout << "|                                                          |" << std::endl;
    std::cout << "|                           LOGIN                          |" << std::endl;
    std::cout << "|                                                          |" << std::endl;
    std::cout << "============================================================" << std::endl;

    std::cout << "ID pengelola: ";
    std::cin >> inputID;
    std::cout << "Password    : ";
    std::cin >> password;

    Pengelola* current = head;
    while (current != nullptr && !cariID) {
        if (current->id == inputID) {
            cariID = true;
            if (current->password == password) {
                id = inputID;
                nama = current->nama;

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

                std::cin.ignore(); // Bersihkan buffer input
                std::cin.get();    // Tunggu pengguna menekan Enter
                return false;
            }
        }
        current = current->next;
    }

    if (!cariID) {
        std::cout << "============================================================" << std::endl;
        std::cout << "|              ID PENGGUNA TIDAK DITEMUKAN!                |" << std::endl;
        std::cout << "------------------------------------------------------------" << std::endl;
        std::cout << "|             Tekan enter untuk melanjutkan..              |" << std::endl;
        std::cout << "============================================================" << std::endl;

        std::cin.ignore(); // Bersihkan buffer input
        std::cin.get();    // Tunggu pengguna menekan Enter
        return false;
    }

    return false; // Jika ada perilaku yang tidak terduga
}

// Fungsi untuk membebaskan memori dari linked list
void deleteList(Pengelola* head) {
    while (head != nullptr) {
        Pengelola* temp = head;
        head = head->next;
        delete temp;
    }
}

// int main()
// {
//     hitungJumlahVote("../data/total-vote.txt");

//     return 0;
// }

void menu_login_pengelola() 
{
    Pengelola* head = nullptr;

    std::ifstream readFile("../data/data-pengelola.txt");
    if (readFile.is_open()) {
        std::string line;
        while (getline(readFile, line)) {
            std::istringstream iss(line);
            std::string id, nama, password;
            getline(iss, id, ',');
            getline(iss, nama, ',');
            getline(iss, password, ',');

            Pengelola* newPengelola = new Pengelola(id, nama, password);
            newPengelola->next = head;
            head = newPengelola;
        }
        readFile.close();
    } else {
        std::cerr << "Gagal membuka file data-pengelola.txt" << std::endl;
        
    }

    std::string id, nama;
    login(head, id, nama);

    // Melakukan operasi sesuai dengan login
    // ...

    // Membersihkan memori
    deleteList(head);

    
}

