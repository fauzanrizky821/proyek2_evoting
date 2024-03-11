#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

struct Voter {
    std::string name;
    std::string nim;
    bool hasVoted;  // Menunjukkan apakah pemilih telah melakukan voting atau belum
};