#ifndef ELECTION_COUNT_H
#define ELECTION_COUNT_H

#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>


struct PasanganCalon {
    std::string nama;
    int nomor;
};

struct Pengelola {
    std::string id;
    std::string nama;
    std::string password;
    Pengelola* next;

    Pengelola(const std::string& id, const std::string& nama, const std::string& password)
        : id(id), nama(nama), password(password), next(nullptr) {}
};

void hitungJumlahVote(const std::string& nama_file);
void menu_login_pengelola();
bool login(Pengelola* head, std::string& id, std::string& nama);
void deleteList(Pengelola* head);

#endif // ELECTION_COUNT_H
