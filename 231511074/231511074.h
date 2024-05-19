#ifndef LIBRARY_231511074_H
#define LIBRARY_231511074_H

#include "../linkedlist.h"
#include "../231511077/231511077.h"
#include "../231511065/231511065.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

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
string melihatHasilVoting(addrMatriks invMatriks, addrTable karakterList, int modulus);
void lihatDataPemilih(addrMatriks invMatriks, addrTable karakterList, int modulus);
addrMatriks insertMatriks(int nilai);
addrMatriks insertKunciMatriks(int Key1, int Key2, int Key3, int Key4);
void freeMatrix(addrMatriks head);
void printMatrix(addrMatriks head);
#endif