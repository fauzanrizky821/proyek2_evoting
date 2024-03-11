// Elsa Monika Sinaga
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

struct Voter {
    std::string name;
    std::string nim;
    bool hasVoted;  // Menunjukkan apakah pemilih telah melakukan voting atau belum
};

void dataPemilih(const Voter& voter) {
    std::cout << "Data Pemilih:\n";
    std::cout <<"Nama : " << voter.name;
    std::cout <<"\tNIM : " << voter.nim;

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