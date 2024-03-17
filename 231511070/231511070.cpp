// Aulia Putri Ramadhani

#include "231511070.h"

void total_vote(const int hasil_vote[]) {
    std::ofstream file("data/total-vote.txt");
    file << hasil_vote[0] << std::endl;
    file << hasil_vote[1] << std::endl;
    file << hasil_vote[2] << std::endl;
    file.close();
}

void update_status(const std::string& nim) {
    std::ifstream infile("data/data-pengguna.txt");
    std::vector<Pengguna> data_pengguna;

    std::string line;
    while (std::getline(infile, line)) {
        Pengguna pengguna;
        std::istringstream iss(dekripsi(line));
        std::getline(iss, pengguna.nim, ',');
        std::getline(iss, pengguna.password, ',');
        std::getline(iss, pengguna.nama, ',');
        std::getline(iss, pengguna.jurusan, ',');
        std::getline(iss, pengguna.prodi, ',');
        std::getline(iss, pengguna.status, ',');

        if (pengguna.nim == nim) 
        {
            pengguna.status = "1";
        }

        data_pengguna.push_back(pengguna);
    }

    infile.close();

    std::ofstream outfile("data/temp-data-pengguna.txt");
    for (std::vector<Pengguna>::iterator it = data_pengguna.begin(); it != data_pengguna.end(); ++it) {
        Pengguna pengguna = *it;
        std::string dataPengguna;
        dataPengguna = pengguna.nim + ',' + pengguna.password + ',' + pengguna.nama + ',' + pengguna.jurusan + ',' + pengguna.prodi + ',' + pengguna.status + ",";
        outfile << enkripsi(dataPengguna) << std::endl; 
    }
    outfile.close();

    std::remove("data/data-pengguna.txt");
    std::rename("data/temp-data-pengguna.txt", "data/data-pengguna.txt");
}

void  menuVote(Pengguna &pengguna) {
    std::ifstream file("data/total-vote.txt");
    int hasil_vote[3] = {0};

    int i = 0;
    while (i < 3) {
        file >> hasil_vote[i];
        i = i + 1;
    }

    file.close();

    int nomor_calon;

    std::cout << "Calon pasangan ketua BEM dan wakil ketua BEM 2024:" << std::endl;
    std::cout << "=======================================================" << std::endl;
    std::cout << "| No | Calon Pasangan                                 |" << std::endl;
    std::cout << "=======================================================" << std::endl;
    std::cout << "| 1  | Hafiz Muhammad Al Ikhsan & Elsa Monika Sinaga  |" << std::endl;
    std::cout << "|----|------------------------------------------------|" << std::endl;
    std::cout << "| 2  | Fauzan Rizky Ramadhan & Aulia Putri Ramadhani  |" << std::endl;
    std::cout << "|----|------------------------------------------------|" << std::endl;
    std::cout << "| 3  | Abyan Dzaky Pratama & Haikal Hariyanto         |" << std::endl;
    std::cout << "=======================================================" << std::endl;
    std::cout << "Masukkan nomor calon yang ingin Anda pilih (1, 2, atau 3): " ;
    std::cin >> nomor_calon;

    if (nomor_calon >= 1 && nomor_calon <= 3) {
        hasil_vote[nomor_calon - 1] += 1;

        update_status(pengguna.nim);

        total_vote(hasil_vote);

        pengguna.status = "1";

        std::cout << "Vote berhasil ditambahkan." << std::endl;
        getchar();
        getchar();
    } else {
        std::cout << "Nomor calon tidak valid." << std::endl;
        getchar();
        getchar();
        menuVote(pengguna);
    }
}