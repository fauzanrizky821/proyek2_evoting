#ifndef ENKRIPSI_H
#define ENKRIPSI_H

using namespace std;

#include "../pengguna.h"
#include "../231511076/231511076.h"
#include <iostream>
#include <string>

void menuVisiMisi(Pengguna pengguna);

void VisiMisi(int calon);

string enkripsi(string plaintext);

string dekripsi(string plaintext);

addrMatriks MatriksKunci(int nilai);

addrMatriks LLKunciMatriks(int Key1, int Key2, int Key3, int Key4);

bool hapusMatriks(addrMatriks &awal);

#endif