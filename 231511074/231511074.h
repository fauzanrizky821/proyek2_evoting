#ifndef LIBRARY_231511074_H
#define LIBRARY_231511074_H

#include "../231511077/231511077.h"
#include "../231511065/231511065.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

struct Voter {
    string nim;
    string password;
    string nama;
    string jurusan;
    string Prodi;
    bool status;  
};

// Struktur untuk merepresentasikan matriks 2 dimensi
struct Matrix {
    int rows;
    int cols;
    int **data;
};

// Struktur untuk merepresentasikan node dalam linked list
struct Node {
    Matrix matrix;
    Node* next;
    Node* bottom;
};

void dataPemilih(const Voter& voter);
string melihatHasilVoting();
void lihatDataPemilih();
void menu_pengelola(Pengelola* head, const string& id, const string& nama);
void insertMatrix(Node*& head, Matrix matrix);
void freeLinkedList(Node* head);
Matrix inputMatrix();
#endif