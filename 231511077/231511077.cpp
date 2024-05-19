#include "231511077.h"

int mod(addrTable karakterList)
{
    addrTable current = karakterList;
    int mod = 0;
    while (current != NULL)
    {
        current = current->next;
        mod++;
    }
    return mod;
}

addrTable bacaFile(string alamat)
{
    addrTable karakterList = NULL;
    string filename = alamat;
    ifstream file(filename);

    if (!file.is_open())
    {
        cout << "Error membuka file" << endl;
        return NULL;
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

    return karakterList;
}

int konversiKeAngka(addrTable karakterList, char text)
{
    addrTable current = karakterList;
    int bil = 0;
    while (current != NULL)
    {   
        if (current->info == text)
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

string enkripsi(string plaintext, addrMatriks awal, addrTable karakterList, int modulus)
{
    addrMatriks matriksKunci = awal;
    addrTable current = karakterList;
    string ciphertext = "";

    bool ganjil = false;
    if (plaintext.size() % 2 == 1)
    {
        plaintext = plaintext + ' ';
        ganjil = true;
    }


    for (int i = 0; i < plaintext.size(); i = i + 2)
    {
        char x = plaintext[i];
        char y = plaintext[i + 1];

        int indexX = konversiKeAngka(current, x);
        int indexY = konversiKeAngka(current, y);

        int encX = (searchMatriks(matriksKunci, 1, 1)->info * indexX + searchMatriks(matriksKunci, 1, 2)->info * indexY) % modulus;
        int encY = (searchMatriks(matriksKunci, 2, 1)->info * indexX + searchMatriks(matriksKunci, 2, 2)->info * indexY) % modulus;

        char encryptedX = konversiKeKarakter(current, encX);
        char encryptedY = konversiKeKarakter(current, encY);

        ciphertext = ciphertext + encryptedX;
        ciphertext = ciphertext + encryptedY;
    }

    if (ganjil == true)
    {
        ciphertext = ciphertext + '1';
    }

    return ciphertext;
}

string dekripsi(string ciphertext, addrMatriks awal, addrTable karakterList, int modulus)
{
    addrMatriks invMatriks = awal;
    addrTable current = karakterList;
    string plaintext = "";

    bool ganjil = false;
    if (ciphertext.size() % 2 == 1 && ciphertext.back() == '1')
    {
        ciphertext.pop_back();
        ganjil = true;
    }

    for (int i = 0; i < ciphertext.size(); i = i + 2)
    {
        char x = ciphertext[i];
        char y = ciphertext[i + 1];

        int indexX = konversiKeAngka(current, x);
        int indexY = konversiKeAngka(current, y);

        int decX = (searchMatriks(invMatriks, 1, 1)->info * indexX + searchMatriks(invMatriks, 1, 2)->info * indexY) % modulus;
        int decY = (searchMatriks(invMatriks, 2, 1)->info * indexX + searchMatriks(invMatriks, 2, 2)->info * indexY) % modulus;

        char decryptedX = konversiKeKarakter(current, decX);
        char decryptedY = konversiKeKarakter(current, decY);

        plaintext = plaintext + decryptedX;
        plaintext = plaintext + decryptedY;
    }

    if (ganjil == true && plaintext.back() == ' ')
    {
        plaintext.pop_back();
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