#include <iostream>
#include <string>
#include "231511074/231511074.h"
#include "231511077/231511077.h"

void dataPemilih(const Voter& voter) {
    std::cout <<"NIM : " << voter.nim;
    std::cout <<"\tNama : " << voter.nama;
    std::cout <<"\tJurusan : " << voter.jurusan;
    std::cout <<"\tProdi : " << voter.Prodi;
    std::cout << "\tStatus: " << (voter.status ? "Telah Melakukan Voting" : "Belum Melakukan Voting") << std::endl;
}

void melihatHasilVoting() {
    std::ifstream voteFile("data/total-vote.txt");

    if (!voteFile.is_open()) {
        std::cerr << "Gagal membuka file hasil_vote.txt\n";
    }

    std::cout << "Hasil voting: \n";

    std::string line;

    while (std::getline(voteFile, line)) {
        std::cout << line << std::endl;
    }

    voteFile.close();
}

void lihatDataPemilih() {
    std::ifstream filePemilih("data/data-pengguna.txt");

    if (!filePemilih.is_open()){
        std::cerr<< "Gagal membuka file\n";
        return;
    }

    std::string line;

    while (std::getline(filePemilih, line)){
        std::istringstream iss(line);
        Voter voter;
    
        if (std::getline(iss, voter.nim, ',')&&
            std::getline(iss, voter.password, ',')&&
            std::getline(iss, voter.nama, ',')&&
            std::getline(iss,voter.jurusan, ',')&&
            std::getline(iss, voter.Prodi, ',')){
            std::string statusStr;
            if(std::getline(iss, statusStr,',')){
                voter.status=(statusStr=="1");
            }else{
                std::cerr << "gagal membaca status" << std::endl;
                continue;
            }
            dataPemilih(voter);
            }else{
                std::cerr << "gagal membaca data" << std::endl;
            }
    filePemilih.close();
}
}

int main ()
{
   std::cout <<  "|-------------------------------------------------------|" << std::endl;
    std::cout << "|               Selamat Datang                          |" << std::endl;
    std::cout << "|-------------------------------------------------------|" << std::endl;
    std::cout << "|               Silahkan Login                          |" << std::endl;
    std::cout << "|-------------------------------------------------------|" << std::endl;

    
    system("cls");
    int choice;
    do {
        // Tampilkan menu
        std::cout << "\nMenu Pengelola:\n";
        std::cout << "1. Lihat Hasil Voting\n";
        std::cout << "2. Lihat Data Pemilih\n";
        std::cout << "3. Logout\n";
        std::cout << "Pilih: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                melihatHasilVoting();
                break;

            case 2:
                lihatDataPemilih();
                break;

            case 3:
                std::cout << "Logout berhasil.\n";
                break;
            default:
                std::cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }

    } while (choice != 3);


    return 0;
}