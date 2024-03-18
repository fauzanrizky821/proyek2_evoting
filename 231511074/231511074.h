#ifndef LIBRARY_231511074_H
#define LIBRARY_231511074_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

struct Voter {
    std::string nim;
    std::string password;
    std::string nama;
    std::string jurusan;
    std::string Prodi;
    bool status;  
};

void dataPemilih(const Voter& voter);
void melihatHasilVoting();
void lihatDataPemilih();

#endif