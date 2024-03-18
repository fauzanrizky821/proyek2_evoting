#ifndef LIBRARY_231511074_H
#define LIBRARY_231511074_H

#include "../231511077/231511077.h"
#include "../231511065/231511065.h"
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
void menu_pengelola(Pengelola* head, const std::string& id, const std::string& nama);

#endif