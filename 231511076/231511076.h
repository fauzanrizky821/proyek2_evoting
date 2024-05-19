#ifndef LOGINRESGIS_H
#define LOGINREGIS_H

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <stdlib.h>

#include "../pengguna.h"
#include "../linkedlist.h"
#include "../231511077/231511077.h"
#include "../231511074/231511074.h"
#include "../231511065/231511065.h"
#include "../231511070/231511070.h"

using namespace std;

void clearScreen();

bool registrasi(addrMatriks matriks, addrMatriks invMatriks,addrTable karakterList, int modulus);

bool loginPengguna(Pengguna &pengguna, addrMatriks invMatriks, addrTable karakterList, int modulus);

void swap(int &a, int &b);

void inversMatriks(int matriks[2][2], int modulus);

addrMatriks inversMatriksKunci(addrMatriks first, int modulus);

#endif