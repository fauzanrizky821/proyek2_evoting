#ifndef ENKRIPSI_H
#define ENKRIPSI_H

#include "../pengguna.h"
#include "../231511076/231511076.h"
#include <iostream>
#include <string>

void HapusLayar();

void menuVisiMisi(Pengguna pengguna);

void VisiMisi(int calon);

std::string enkripsi(std::string plaintext, int kunciMatriks[2][2]);

std::string enkripsi(std::string plaintext, int kunciMatriks[2][2]);

#endif