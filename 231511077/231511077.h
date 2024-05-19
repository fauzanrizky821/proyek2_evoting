#ifndef ENKRIPSI_H
#define ENKRIPSI_H

#include <iostream>
#include <string>

#include "../pengguna.h"
#include "../linkedlist.h"
#include "../231511065/231511065.h"
#include "../231511070/231511070.h"
#include "../231511074/231511074.h"
#include "../231511076/231511076.h"

using namespace std;

int mod(addrTable karakterList);

addrTable bacaFile(string alamat);

int konversiKeAngka(addrTable karakterList, char plaintext);

char konversiKeKarakter(addrTable karakterList, int hasil);

string enkripsi(string plaintext, addrMatriks awal, addrTable karakterList, int modulus);

string dekripsi(string ciphertext, addrMatriks invMatriks, addrTable karakterList, int modulus);

#endif