#ifndef LOGINRESGIS_H
#define LOGINREGIS_H

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

struct Akun{
    std::string nim;
    std::string password;
    std::string nama;
    std::string jurusan;
    std::string prodi;
    std::string status = "0";
};

void registrasi();

bool login(std::string &nim, std::string &nama, std::string &jurusan, std::string &prodi, std::string &status);

void menuUtama(Akun akun);

#endif