#ifndef ELECTION_COUNT_H
#define ELECTION_COUNT_H

#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>

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
void menu_login_pengelola();
bool login(Pengelola* head, string& id, string& nama);
void deleteList(Pengelola* head);

#endif // ELECTION_COUNT_H
