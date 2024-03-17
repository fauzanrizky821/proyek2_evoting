#include "231511074.h"

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
    }
    filePemilih.close();
}
