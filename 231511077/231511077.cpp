#include "231511077.h"

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

string enkripsi(string plaintext, addrTable karakterList)
{
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
        int indexX = 0;
        while (current != NULL)
        {
            if (current->info == x)
            {
                break;
            }
            current = current->next;
            indexX++;
        }
        current = karakterList;
        int indexY = 0;
        while (current != NULL)
        {
            if (current->info == y)
            {
                break;
            }
            current = current->next;
            indexY++;
        }

        int encX = (2 * indexX + 1 * indexY) % modulus;
        int encY = (3 * indexX + 4 * indexY) % modulus;

        current = karakterList;
        for (int j = 0; j < encX; ++j)
        {
            current = current->next;
        }
        char encryptedX = current->info;

        current = karakterList;
        for (int j = 0; j < encY; ++j)
        {
            current = current->next;
        }
        char encryptedY = current->info;

        ciphertext += encryptedX;
        ciphertext += encryptedY;
    }
    return ciphertext;
}

string dekripsi(string ciphertext, addrTable karakterList)
{
    addrTable current = karakterList;
    int modulus = 0;
    while (current != NULL)
    {
        current = current->next;
        modulus++;
    }

    string plaintext = "";

    for (int i = 0; i < ciphertext.size(); i = i + 2)
    {
        char x = ciphertext[i];
        char y = ciphertext[i + 1];

        current = karakterList;
        int indexX = 0;
        while (current != NULL)
        {
            if (current->info == x)
            {
                break;
            }
            current = current->next;
            indexX++;
        }
        current = karakterList;
        int indexY = 0;
        while (current != NULL)
        {
            if (current->info == y)
            {
                break;
            }
            current = current->next;
            indexY++;
        }

        int encX = (2 * indexX + 1 * indexY) % modulus;
        int encY = (3 * indexX + 4 * indexY) % modulus;

        current = karakterList;
        for (int j = 0; j < encX; ++j)
        {
            current = current->next;
        }
        char decryptedX = current->info;

        current = karakterList;
        for (int j = 0; j < encY; ++j)
        {
            current = current->next;
        }
        char decryptedY = current->info;

        plaintext += decryptedX;
        plaintext += decryptedY;
    }

    if (plaintext.back() == ' ')
    {
        return plaintext;
    }
    return plaintext;
}