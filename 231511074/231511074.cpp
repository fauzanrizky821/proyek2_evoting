#include "231511074.h"
#include "../231511077/231511077.h"
#include "../231511065/231511065.h"

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

    std::cout << "|=======================================================|" << std::endl;
    std::cout << "|                 HASIL VOTE PEMILIHAN                  |" << std::endl;
    std::cout << "|=======================================================|" << std::endl;

    std::string line;
    int count = 0;
    while (std::getline(voteFile, line)) {
        count ++;
        std::cout << "\t\t   Calon No-" << count << " = " << line << std::endl;
    }
    std::cout << "|=======================================================|" << std::endl;
    voteFile.close();
}

void lihatDataPemilih() {
    std::ifstream filePemilih("data/data-pengguna.txt");

    if (!filePemilih.is_open()){
        std::cerr<< "Gagal membuka file\n";
        return;
    }

    std::string line;
    std::getline(filePemilih, line);
    while (std::getline(filePemilih, line)){
        std::istringstream iss(line);
        Voter voter;

        std::string decryptedLine = line;
        decryptedLine = dekripsi(decryptedLine);
        std::istringstream decryptedStream(decryptedLine);

        if (std::getline(decryptedStream, voter.nim, ',')&&
            std::getline(decryptedStream, voter.password, ',')&&
            std::getline(decryptedStream, voter.nama, ',')&&
            std::getline(decryptedStream,voter.jurusan, ',')&&
            std::getline(decryptedStream, voter.Prodi, ',')){
            std::string statusStr;
            if(std::getline(decryptedStream, statusStr,',')){
                voter.status=(statusStr=="1");
            }else{
                std::cerr << "gagal membaca status" << std::endl;
                continue;
            }
            dataPemilih(voter);
            }else{
                std::cerr << "gagal membaca data" << std::endl;
            }
    }
    filePemilih.close();
}

void menu_pengelola(Pengelola* head, const std::string& id, const std::string& nama){

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
                system("cls");
                melihatHasilVoting();
                std::cout << "Klik enter untuk kembali";
                std::cin.ignore();
                std::cin.get();
                system("cls");
                break;

            case 2:
                system("cls");
                lihatDataPemilih();
                std::cout << "Klik enter untuk kembali";
                std::cin.ignore();
                std::cin.get();
                system("cls");
                break;

            case 3:
                std::cout << "Logout berhasil.\n\n";
                std::cout << "Klik enter untuk kembali";
                std::cin.ignore();
                std::cin.get();
                system("cls");
                menu_login_pengelola();
                break;
            default:
                std::cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }

    } while (choice != 3);

}