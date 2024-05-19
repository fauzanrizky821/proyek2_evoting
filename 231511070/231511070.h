// Aulia Putri Ramadhani

#ifndef VOTE_H
#define VOTE_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "../pengguna.h"
#include "../231511077/231511077.h"
#include "../linkedlist.h"

using namespace std;

void total_vote(const int hasil_vote[]);
void update_status(const std::string& nim);
void  menuVote(Pengguna &pengguna);
void insertTabel(addrTable &head, char info);
bool deleteTabel(addrTable &head);
void tampilkanList(addrTable awal);

#endif