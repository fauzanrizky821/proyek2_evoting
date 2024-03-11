//Abyan Dzaky Pratama
//Modul untuk membaca total hasil vote
#include <iostream>
#include <fstream> // Header file untuk ifstream
using namespace std;

void hitungJumlahVote(const string& nama_file) 
{
    int jumlah_vote = 0;
    std::ifstream infile(nama_file); // Membuat objek ifstream

    // Memeriksa apakah file berhasil dibuka
    if (!infile) 
    {
        std::cerr << "Cannot open file\n";
         // Mengembalikan nilai negatif sebagai indikasi kesalahan
    }

    // Membaca file baris per baris
    std::string line;
    while (std::getline(infile, line)) 
    {
        std::cout << line << std::endl; // Menampilkan setiap baris
        jumlah_vote++;
    }

    infile.close(); // Menutup file setelah selesai membaca

    cout<< "\n" "jumlah vote= " << jumlah_vote;
}
int main(){
    hitungJumlahVote("cobain.txt");
}