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
string melihatHasilVoting();
void lihatDataPemilih();
void menu_pengelola(Pengelola* head, const string& id, const string& nama);
void insertMatrix(Node*& head, Matrix matrix);
void freeLinkedList(Node* head);
Matrix inputMatrix();
void printMatrix(const Matrix& matrix);
#endif