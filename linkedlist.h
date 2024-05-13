#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>
#include <stdlib.h>

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
    char info; 
    addrMatriks right;
    addrMatriks buttom;  
};

// Struktur untuk merepresentasikan matriks 2 dimensi
struct Matrix {
    int rows;
    int cols;
    int **data;
};

// Struktur untuk merepresentasikan node dalam linked list
struct Node {
    Matrix matrix;
    Node* next;
    Node* bottom;
};
#endif