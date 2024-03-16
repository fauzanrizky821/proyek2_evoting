#ifndef LOGINRESGIS_H
#define LOGINREGIS_H

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

#include "../pengguna.h"

void registrasi();

bool login(std::string &nim, std::string &nama, std::string &jurusan, std::string &prodi, std::string &status);

void menuUtama(Pengguna pengguna);

#endif