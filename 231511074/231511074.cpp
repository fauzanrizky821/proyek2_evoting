#include "231511074.h"

void dataPemilih(const Voter& voter) {
    std::cout <<"NIM : " << voter.nim;
    std::cout <<"\tNama : " << voter.nama;

    // pengecekan status voting
    if (voter.status){
        std::cout << "\tStatus : Telah Melakukan Voting" <<std::endl;
    } else {
        std::cout << "\tStatus : Belum Melakukan Voting" <<std::endl;
    }
}

void melihatHasilVoting() {
    // Buka file untuk dibaca
    std::ifstream voteFile("total-vote.txt");

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
    std::ifstream filePemilih("data-pengguna.txt");

    if (!filePemilih.is_open()){
        std::cerr<< "Gagal membuka file\n";
        return;
    }

    std::string line;

    while (std::getline(filePemilih, line)){
        std::istringstream iss(line);
        Voter voter;
        iss >> voter.nim >> voter.nama >> voter.status;

        dataPemilih(voter);
    }

    filePemilih.close();
}
