#ifndef LIBRARY_231511074_H
#define LIBRARY_231511074_H

#include "../231511077/231511077.h"
#include "../231511065/231511065.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

struct Voter {
    string nim;
    string password;
    string nama;
    string jurusan;
    string Prodi;
    bool status;  
};

void dataPemilih(const Voter& voter);
void melihatHasilVoting();
void lihatDataPemilih();
void menu_pengelola(Pengelola* head, const std::string& id, const std::string& nama);

#endif