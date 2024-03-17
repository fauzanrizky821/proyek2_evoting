// Aulia Putri Ramadhani

#ifndef VOTE_H
#define VOTE_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "../pengguna.h"
#include "../231511077/231511077.h"

void total_vote(const int hasil_vote[]);
void update_status(const std::string& nim);
void  menuVote(Pengguna &pengguna);

#endif