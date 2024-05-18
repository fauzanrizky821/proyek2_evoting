#include "231511077.h"

string enkripsi(string plaintext)
{
    char karakter[] = {
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
        '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '_', '+', '=', '{', '}', '[', ']', '<', '>', '.', ',', ';',
        '"', '\'', '\\', '/', '?', ':', '~', '|', ' '};

    int kunciMatriks[2][2] = {{2, 1}, {3, 4}};
    int modulus = sizeof(karakter);

    string ciphertext = "";

    if (plaintext.size() % 2 == 1)
    {
        plaintext = plaintext + ' ';
    }

    for (int i = 0; i < plaintext.size(); i = i + 2)
    {
        int x = 0, y = 0;
        for (int j = 0; j < modulus; ++j)
        {
            if (karakter[j] == plaintext[i])
            {
                x = j;
                break;
            }
        }
        for (int j = 0; j < modulus; ++j)
        {
            if (karakter[j] == plaintext[i + 1])
            {
                y = j;
                break;
            }
        }

        int encX = (kunciMatriks[0][0] * x + kunciMatriks[0][1] * y) % modulus;
        int encY = (kunciMatriks[1][0] * x + kunciMatriks[1][1] * y) % modulus;

        ciphertext = ciphertext + karakter[encX];
        ciphertext = ciphertext + karakter[encY];
    }

    return ciphertext;
}

string dekripsi(string ciphertext)
{
    char karakter[] = {
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
        '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '_', '+', '=', '{', '}', '[', ']', '<', '>', '.', ',', ';',
        '"', '\'', '\\', '/', '?', ':', '~', '|', ' '};

    int kunciMatriks[2][2] = {{2, 1}, {3, 4}};
    int modulus = sizeof(karakter);

    string plaintext = "";

    inversMatriks(kunciMatriks, modulus);

    for (int i = 0; i < ciphertext.size(); i = i + 2)
    {
        int x = 0, y = 0;
        for (int j = 0; j < modulus; ++j)
        {
            if (karakter[j] == ciphertext[i])
            {
                x = j;
                break;
            }
        }
        for (int j = 0; j < modulus; ++j)
        {
            if (karakter[j] == ciphertext[i + 1])
            {
                y = j;
                break;
            }
        }

        int encX = (kunciMatriks[0][0] * x + kunciMatriks[0][1] * y) % modulus;
        int encY = (kunciMatriks[1][0] * x + kunciMatriks[1][1] * y) % modulus;

        plaintext = plaintext + karakter[encX];
        plaintext = plaintext + karakter[encY];
    }

    if (plaintext.size() % 2 == 0 && plaintext.back() == ' ')
    {
        return plaintext;
    }
    else if (plaintext.size() % 2 == 1 && plaintext.back() == ' ')
    {
        plaintext.pop_back();
    }

    return plaintext;
}