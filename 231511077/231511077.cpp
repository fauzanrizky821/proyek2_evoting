#include "231511077.h"

char karakter[] = {
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
    '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '_', '+', '=', '{', '}', '[', ']', '<', '>', '.', ',', ';',
    '"', '\'', '`', '\\', '/', '?', ':', '~', '|',
};

int kunciMatriks[2][2] = {{2, 1}, {3, 4}};

void enkripsi(std::string plaintext) 
{
    std::string ciphertext = "";

    for (int i = 0; i < plaintext.size(); i = i + 2) 
    {
        int x = 0, y = 0;
        for (int j = 0; j < sizeof(karakter); ++j) 
        {
            if (karakter[j] == plaintext[i]) 
            {
                x = j;
                break;
            }
        }
        for (int j = 0; j < sizeof(karakter); ++j) 
        {
            if (karakter[j] == plaintext[i + 1]) 
            {
                y = j;
                break;
            }
        }

        int encX = (kunciMatriks[0][0] * x + kunciMatriks[0][1] * y) % sizeof(karakter);
        int encY = (kunciMatriks[1][0] * x + kunciMatriks[1][1] * y) % sizeof(karakter);

        ciphertext = ciphertext + karakter[encX];
        ciphertext = ciphertext + karakter[encY];
    }

    std::cout << "Ciphertext: " << ciphertext << std::endl;
}

int main()
{
    std::string plaintext;
    std::cout << "Masukkan teks yang ingin dienkripsi: ";
    std::getline(std::cin, plaintext);
    
    enkripsi(plaintext);
    
    return 0;
}