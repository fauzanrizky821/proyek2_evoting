#include "231511077.h"

void HapusLayar() {
    system("cls");
}

void VisiMisi(int calon) {
    clearScreen();
    if (calon == 1) {
        std::cout << "===========================================================================" << std::endl;
        std::cout << "|                             VISI DAN MISI                               |" << std::endl;
        std::cout << "===========================================================================" << std::endl;
        std::cout << "| Calon Ketua Hafiz Muhammad Al Ikhsan                                    |" << std::endl;
        std::cout << "|                                                                         |" << std::endl;
        std::cout << "| Visi:                Mewujudkan kemajuan dan kesejahteraan              |" << std::endl;
        std::cout << "| Misi:             1. Mengembangkan potensi anggota tikus                |" << std::endl;
        std::cout << "|                   2. Menjalin kerjasama yang baik dengan pihak alien    |" << std::endl;
        std::cout << "|                   3. Makan siang gratis                                 |" << std::endl;
        std::cout << "===========================================================================" << std::endl;
    } else if (calon == 2) {
        std::cout << "==============================================================================" << std::endl;
        std::cout << "|                                VISI DAN MISI                               |" << std::endl;
        std::cout << "==============================================================================" << std::endl;
        std::cout << "| Calon Ketua Fauzan Rizky Ramadhan                                          |" << std::endl;
        std::cout << "|                                                                            |" << std::endl;
        std::cout << "| Visi:               Menjadi agen negara                                    |" << std::endl;
        std::cout << "| Misi:            1. Mewujudkan kampus penuh donat                          |" << std::endl;
        std::cout << "|                  2. Membangun hubungan yang kuat dengan masyarakat         |" << std::endl;
        std::cout << "==============================================================================" << std::endl;
    } else if (calon == 3) {
        std::cout << "==============================================================================" << std::endl;
        std::cout << "|                                VISI DAN MISI                               |" << std::endl;
        std::cout << "==============================================================================" << std::endl;
        std::cout << "| Calon Ketua Fauzan Rizky Ramadhan                                          |" << std::endl;
        std::cout << "|                                                                            |" << std::endl;
        std::cout << "| Visi:               Menjadi agen negara                                    |" << std::endl;
        std::cout << "| Misi:            1. Mewujudkan kampus penuh donat                          |" << std::endl;
        std::cout << "|                  2. Membangun hubungan yang kuat dengan masyarakat         |" << std::endl;
        std::cout << "==============================================================================" << std::endl;
    }

    std::cout << "Tekan enter untuk kembali." << std::endl;
    std::cin.ignore();
    std::cin.get();
}

char karakter[] = {
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
    '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '_', '+', '=', '{', '}', '[', ']', '<', '>', '.', ',', ';',
    '"', '\'', '`', '\\', '/', '?', ':', '~', '|',
};

int kunciMatriks[2][2] = {{2, 1}, {3, 4}};

std::string enkripsi(std::string plaintext) 
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

    return ciphertext;
}