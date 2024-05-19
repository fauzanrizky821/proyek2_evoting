#include "231511077.h"

void insertTabel(addrTable &head, char info)
{
    addrTable newNode, temp;
    newNode = (addrTable)malloc(sizeof(table));
    if (newNode == NULL)
    {
        cout << "Memory Penuh\n";
        return;
    }
    newNode->info = info;
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

bool deleteTabel(addrTable &head)
{
    if (head == NULL)
    {
        return false;
    }
    
    addrTable temp = NULL;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
    return true;
}

void tampilkanMatriks(addrMatriks awal)
{
    addrMatriks row, col;
    row = awal;
    while (row != NULL)
    {
        col = row;
        while (col != NULL)
        {
            cout << col->info << " ";
            col = col->right;
        }
        cout << endl;
        row = row->bottom;
    }
}

int konversiKeAngka(addrTable karakterList, char plaintext)
{
    addrTable current = karakterList;
    int bil = 0;
    while (current != NULL)
    {
        if (current->info == plaintext)
        {
            break;
        }
        current = current->next;
        bil++;
    }
    return bil;
}

char konversiKeKarakter(addrTable karakterList, int hasil)
{
    addrTable current = karakterList;
    char charX;
    for (int j = 0; j < hasil; ++j)
    {
        current = current->next;
    }
    charX = current->info;
    return charX;
}

string enkripsi(string plaintext)
{
    addrTable karakterList = NULL;
    string filename = "../data/tabel-konversi.txt";
    ifstream file(filename);

    if (!file.is_open())
    {
        cout << "Error membuka file" << endl;
        return "";
    }

    char c;
    while (file.get(c))
    {
        if (c != '`')
        {
            insertTabel(karakterList, c);
        }
    }
    file.close();

    int Key1 = 2, Key2 = 1, Key3 = 3, Key4 = 4;
    addrMatriks matriksKunci = insertKunciMatriks(Key1, Key2, Key3, Key4);

    addrTable current = karakterList;
    int modulus = 0;
    while (current != NULL)
    {
        current = current->next;
        modulus++;
    }

    string ciphertext = "";

    if (plaintext.size() % 2 == 1)
    {
        plaintext = plaintext + ' ';
    }

    for (int i = 0; i < plaintext.size(); i = i + 2)
    {
        char x = plaintext[i];
        char y = plaintext[i + 1];

        current = karakterList;
        int indexX = konversiKeAngka(karakterList, x);
        int indexY = konversiKeAngka(karakterList, y);

        int encX = (searchMatriks(matriksKunci, 1, 1)->info * indexX + searchMatriks(matriksKunci, 1, 2)->info * indexY) %modulus;
        int encY = (searchMatriks(matriksKunci, 2, 1)->info * indexX + searchMatriks(matriksKunci, 2, 2)->info * indexY) %modulus;

        char encryptedX = konversiKeKarakter(karakterList, encX);
        char encryptedY = konversiKeKarakter(karakterList, encY);

        ciphertext += encryptedX;
        ciphertext += encryptedY;
    }
    return ciphertext;
}

string dekripsi(string ciphertext)
{
    addrTable karakterList = NULL;
    string filename = "../data/tabel-konversi.txt";
    ifstream file(filename);

    if (!file.is_open())
    {
        cout << "Error membuka file" << endl;
        return "";
    }

    char c;
    while (file.get(c))
    {
        if (c != '`')
        {
            insertTabel(karakterList, c);
        }
    }
    file.close();

    int Key1 = 2, Key2 = 1, Key3 = 3, Key4 = 4;
    addrMatriks matriksKunci = insertKunciMatriks(Key1, Key2, Key3, Key4);

    addrTable current = karakterList;
    int modulus = 0;
    while (current != NULL)
    {
        current = current->next;
        modulus++;
    }

    addrMatriks invMatriks = inversMatriksKunci(matriksKunci, modulus);

    string plaintext = "";

    for (int i = 0; i < ciphertext.size(); i = i + 2)
    {
        char x = ciphertext[i];
        char y = ciphertext[i + 1];

        current = karakterList;
        int indexX = konversiKeAngka(karakterList, x);
        int indexY = konversiKeAngka(karakterList, y);

        int decX = (searchMatriks(invMatriks, 1, 1)->info * indexX + searchMatriks(invMatriks, 1, 2)->info * indexY) % modulus;
        int decY = (searchMatriks(invMatriks, 2, 1)->info * indexX + searchMatriks(invMatriks, 2, 2)->info * indexY) % modulus;

        char decryptedX = konversiKeKarakter(karakterList, decX);
        char decryptedY = konversiKeKarakter(karakterList, decY);

        plaintext = plaintext + decryptedX;
        plaintext = plaintext + decryptedY;
    }

    if (plaintext.back() == ' ')
    {
        return plaintext;
    }
    return plaintext;
}



// string enkripsi(string plaintext)
// {
//     char karakter[] = {
//         'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
//         'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
//         '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
//         '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '_', '+', '=', '{', '}', '[', ']', '<', '>', '.', ',', ';',
//         '"', '\'', '\\', '/', '?', ':', '~', '|', ' '};

//     int kunciMatriks[2][2] = {{2, 1}, {3, 4}};
//     int modulus = sizeof(karakter);

//     string ciphertext = "";

//     if (plaintext.size() % 2 == 1)
//     {
//         plaintext = plaintext + ' ';
//     }

//     for (int i = 0; i < plaintext.size(); i = i + 2)
//     {
//         int x = 0, y = 0;
//         for (int j = 0; j < modulus; ++j)
//         {
//             if (karakter[j] == plaintext[i])
//             {
//                 x = j;
//                 break;
//             }
//         }
//         for (int j = 0; j < modulus; ++j)
//         {
//             if (karakter[j] == plaintext[i + 1])
//             {
//                 y = j;
//                 break;
//             }
//         }

//         int encX = (kunciMatriks[0][0] * x + kunciMatriks[0][1] * y) % modulus;
//         int encY = (kunciMatriks[1][0] * x + kunciMatriks[1][1] * y) % modulus;

//         ciphertext = ciphertext + karakter[encX];
//         ciphertext = ciphertext + karakter[encY];
//     }

//     return ciphertext;
// }

// string dekripsi(string ciphertext)
// {
//     char karakter[] = {
//         'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
//         'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
//         '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
//         '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '_', '+', '=', '{', '}', '[', ']', '<', '>', '.', ',', ';',
//         '"', '\'', '\\', '/', '?', ':', '~', '|', ' '};

//     int kunciMatriks[2][2] = {{2, 1}, {3, 4}};
//     int modulus = sizeof(karakter);

//     string plaintext = "";

//     inversMatriks(kunciMatriks, modulus);

//     for (int i = 0; i < ciphertext.size(); i = i + 2)
//     {
//         int x = 0, y = 0;
//         for (int j = 0; j < modulus; ++j)
//         {
//             if (karakter[j] == ciphertext[i])
//             {
//                 x = j;
//                 break;
//             }
//         }
//         for (int j = 0; j < modulus; ++j)
//         {
//             if (karakter[j] == ciphertext[i + 1])
//             {
//                 y = j;
//                 break;
//             }
//         }

//         int encX = (kunciMatriks[0][0] * x + kunciMatriks[0][1] * y) % modulus;
//         int encY = (kunciMatriks[1][0] * x + kunciMatriks[1][1] * y) % modulus;

//         plaintext = plaintext + karakter[encX];
//         plaintext = plaintext + karakter[encY];
//     }

//     if (plaintext.size() % 2 == 0 && plaintext.back() == ' ')
//     {
//         return plaintext;
//     }
//     else if (plaintext.size() % 2 == 1 && plaintext.back() == ' ')
//     {
//         plaintext.pop_back();
//     }

//     return plaintext;
// }