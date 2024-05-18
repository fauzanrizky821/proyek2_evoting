#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>

using namespace std;
              
typedef struct table *addrTable; 
struct table           
{
    char info; 
    addrTable next;  
};

typedef struct matriks *addrMatriks; 
struct matriks           
{
    int info; 
    addrMatriks right;
    addrMatriks bottom;  
};
#endif