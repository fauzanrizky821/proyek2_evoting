#include "231511074.h"

void dataPemilih(const Voter& voter) {
    std::cout <<"NIM : " << voter.nim;
    std::cout <<"\tNama : " << voter.name;

    // pengecekan status voting
    if (voter.hasVoted){
        std::cout << "\tStatus : Telah Melakukan Voting" <<std::endl;
    } else {
        std::cout << "\tStatus : Belum Melakukan Voting" <<std::endl;
    }
}

void melihatHasilVoting() {
    // Buka file untuk dibaca
    std::ifstream voteFile("hasil_vote.txt");

    // Periksa apakah file berhasil dibuka
    if (!voteFile.is_open()) {
        std::cerr << "Gagal membuka file hasil_vote.txt\n";
    }

    std::cout << "Hasil voting: \n";

    // Buat string untuk menyimpan setiap baris dari file
    std::string line;

    // Loop membaca setiap baris dan menampilkannya
    while (std::getline(voteFile, line)) {
        std::cout << line << std::endl;
    }

    // Tutup file setelah selesai membaca
    voteFile.close();
}

void lihatDataPemilih() {
    std::ifstream filePemilih("data_pemilih.txt");

    if (!filePemilih.is_open()){
        std::cerr<< "Gagal membuka file\n";
        return;
    }

    std::string line;

    while (std::getline(filePemilih, line)){
        std::istringstream iss(line);
        Voter voter;
        iss >> voter.nim >> voter.name >> voter.hasVoted;

        dataPemilih(voter);
    }

    filePemilih.close();
}

int main() {
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
