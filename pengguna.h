#ifndef PENGGUNA_H
#define PENGGUNA_H

#include <string>

struct Pengguna{
    std::string nim;
    std::string password;
    std::string nama;
    std::string jurusan;
    std::string prodi;
    std::string status = "0";
};

#endif