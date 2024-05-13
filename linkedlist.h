#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>

using namespace std;

struct Pengguna{
    string nim;
    string password;
    string nama;
    string jurusan;
    string prodi;
    string status = "0";
};
              
typedef struct table *addrTable; 
struct table           
{
    char info; 
    addrTable next;  
};

typedef struct matriks *addrMatriks; 
struct matriks           
{
    char info; 
    addrMatriks right;
    addrMatriks buttom;  
};

#endif