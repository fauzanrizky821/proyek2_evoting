//Abyan Dzaky Pratama
//Modul untuk membaca total hasil vote
#include <iostream>
#include <fstream> // Header file untuk ifstream
using namespace std;

int main() 
{
    int jumlah_vote =0;
    std::ifstream infile("cobain.txt"); // Membuat objek ifstream

    // Memeriksa apakah file berhasil dibuka
    if (!infile) 
    {
        std::cerr << "Cannot open file\n";
        return 1;
    }

    // Membaca file baris per baris
    std::string line;
    while (std::getline(infile, line)) 
    {
        std::cout << line << std::endl; // Menampilkan setiap baris
        jumlah_vote++;
    }
    cout<<endl<< "jumlah vote= " << jumlah_vote <<endl;

    infile.close(); // Menutup file setelah selesai membaca

    return 0;
}
