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

#endif