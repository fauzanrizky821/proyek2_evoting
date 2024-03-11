// Aulia Putri Ramadhani
// Menjumlahkan Total Hasil Voting

#include "231511070.h"

void total_vote(int hasil_vote[])
{
    std::ofstream file("total_vote.txt");
    file << hasil_vote[0] << std::endl;
    file << hasil_vote[1] << std::endl;
    file << hasil_vote[2] << std::endl;
    file.close();
}

void tambah_vote()
{
    // membaca total vote dari file txt
    std::ifstream file("total_vote.txt");
    int hasil_vote[3] = {0};

    int i = 0;
    while(i < 3)
    {
        file >> hasil_vote[i];

        i = i + 1;
    }

    file.close();


    // menginput vote dari user
    int nomor_calon;
    std::cout << "Calon Presiden 2024:\n";
    std::cout << "1. Anies\n" << "2. Prabowo\n" << "3. Ganjar\n";
    std::cout << "Masukkan nomor calon yang ingin Anda vote (1, 2, atau 3): ";
    std::cin >> nomor_calon;


    // menambah total vote ke file txt
    if (nomor_calon >= 1 && nomor_calon <= 3)
    {
        hasil_vote[nomor_calon - 1]+= 1;
        std::cout << "Vote berhasil ditambahkan." << std::endl;

        total_vote(hasil_vote);
    }
    else
    {
        std::cout << "Nomor calon tidak valid." << std::endl;
    }

}
