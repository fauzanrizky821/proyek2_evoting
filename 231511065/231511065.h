#ifndef ELECTION_COUNT_H
#define ELECTION_COUNT_H

#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include "../linkedlist.h"
using namespace std;

struct PasanganCalon {
    string nama;
    int nomor;
};

struct Pengelola {
    string id;
    string nama;
    string password;
    Pengelola* next;

    Pengelola(const string& id, const string& nama, const string& password)
        : id(id), nama(nama), password(password), next(nullptr) {}
};

void hitungJumlahVote(const string& nama_file);
bool menu_login_pengelola(addrMatriks invMatriks, addrTable karakterList, int modulus);
bool login(Pengelola* head, string& id, string& nama);
void deleteList(Pengelola* head);


struct Matrix {
    int rows;
    int cols;
    int** data;
};

struct Node {
    Matrix matrix;
    Node* next;
    Node* bottom;
};

// Fungsi untuk menghapus semua matriks dari linked list dan membebaskan memori
void deleteMatriks(Node*& head, Node*& akhir);


// Fungsi untuk mencari elemen matriks berdasarkan baris dan kolom
addrMatriks searchMatriks(addrMatriks first, int row, int col);

bool hapusMatriks(addrMatriks &awal);

#endif // ELECTION_COUNT_H
