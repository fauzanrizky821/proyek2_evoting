#ifndef ENKRIPSI_H
#define ENKRIPSI_H

#include <iostream>
#include <string>

#include "../pengguna.h"
#include "../linkedlist.h"
#include "../231511065/231511065.h"
#include "../231511074/231511074.h"
#include "../231511076/231511076.h"

using namespace std;

string enkripsi(string plaintext);

string dekripsi(string plaintext);

void insertTabel(addrTable &head, char info);

bool deleteTabel(addrTable &head);

#endif