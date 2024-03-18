#ifndef LOGINRESGIS_H
#define LOGINREGIS_H

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

#include "../pengguna.h"
#include "../231511077/231511077.h"
#include "../231511070/231511070.h"

void clearScreen();

void registrasi();

bool login(Pengguna &pengguna);

void menuUtama(Pengguna pengguna);

void swap(int &a, int &b);

void inversMatriks(int matriks[2][2], int modulus);

#endif