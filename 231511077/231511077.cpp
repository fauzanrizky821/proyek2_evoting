#include "231511077.h"
#include "../231511076/231511076.h"

void HapusLayar() {
    system("cls");
}

void menuVisiMisi(Pengguna pengguna) {
    int menu;

    std::cout << "==================== "<< "Selamat datang " << pengguna.nama <<" ====================\n" << std::endl;
    std::cout << "Menu Melihat Visi dan Misi Calon" << std::endl;
    std::cout << "\n1. Lihat Visi dan Misi Calon Hafiz Muhammad Al Ikhsan" << std::endl;
    std::cout << "2. Lihat Visi dan Misi Calon Fauzan Rizky Ramadhan" << std::endl;
    std::cout << "3. Lihat Visi dan Misi Calon Abyan Dzaky Pratama" << std::endl;
    std::cout << "4. Kembali ke tampilan utama." << std::endl;

    std::cin >> menu;

    switch (menu) {
        case 1:
            VisiMisi(menu);
            HapusLayar();
            menuVisiMisi(pengguna);
        break;
        case 2:
            VisiMisi(menu);
            HapusLayar();
            menuVisiMisi(pengguna);
        break;
        case 3:
            VisiMisi(menu);
            HapusLayar();
            menuVisiMisi(pengguna);
        break;
        case 4:
            menuUtama(pengguna);
        break;
        default:
            std::cout << "Tolong pilih opsi sesuai dengan yang ditampilkan di atas." << std::endl;
            menuVisiMisi(pengguna);
    }
}

void VisiMisi(int calon) {
    HapusLayar();
    if (calon == 1) {
        std::cout << "==================================================================================================================" << std::endl;
        std::cout << "|                          CALON PASANGAN HAFIZ MUHAMMAD AL IKHSAN & ELSA MONIKA SINAGA                          |" << std::endl;
        std::cout << "------------------------------------------------------------------------------------------------------------------" << std::endl;
        std::cout << "|                                               VISI DAN MISI                                                    |" << std::endl;
        std::cout << "==================================================================================================================" << std::endl;
        std::cout << "|                                                                                                                |" << std::endl;
        std::cout << "| Visi:             Membangun kampus yang berdaya saing tinggi, berbudaya, serta mendorong                       |" << std::endl;
        std::cout << "|                   keterlibatan aktif mahasiswa dalam pembangunan kampus yang berkelanjutan.                    |" << std::endl;
        std::cout << "|                                                                                                                |" << std::endl;
        std::cout << "| Misi:             1. Menjalin komunikasi dan kerjasama dari dalam lingkungan internal dan eksternal Kampus.    |" << std::endl;
        std::cout << "|                   2. Menyelenggarakan program kerja yang solutif bagi mahasiswa.                               |" << std::endl;
        std::cout << "|                   3. Makan siang gratis.                                                                       |" << std::endl;
        std::cout << "==================================================================================================================" << std::endl;
    } else if (calon == 2) {
        std::cout << "===============================================================================================================" << std::endl;
        std::cout << "|                        CALON PASANGAN FAUZAN RIZKY RAMADHAN & AULIA PUTRI RAHMADHANI                        |" << std::endl;
        std::cout << "---------------------------------------------------------------------------------------------------------------" << std::endl;
        std::cout << "|                                              VISI DAN MISI                                                  |" << std::endl;
        std::cout << "===============================================================================================================" << std::endl;
        std::cout << "|                                                                                                             |" << std::endl;
        std::cout << "| Visi:               Menjadi agen negara                                                                     |" << std::endl;
        std::cout << "|                                                                                                             |" << std::endl;
        std::cout << "| Misi:            1. Terlaksananya pelatihan pelatiahan yang meningkatkan kualiatas Sumber Daya Mahasiswa.   |" << std::endl;
        std::cout << "|                  2. Membangun hubungan yang kuat dengan masyarakat.                                         |" << std::endl;
        std::cout << "|                  3. Program berbagi donat gratis untuk seluruh mahasiswa.                                   |" << std::endl;
        std::cout << "===============================================================================================================" << std::endl;
    } else if (calon == 3) {
        std::cout << "================================================================================" << std::endl;
        std::cout << "|               CALON PASANGAN ABYAN DZAKY PRATAMA & UDIN RACING               |" << std::endl;
        std::cout << "--------------------------------------------------------------------------------" << std::endl;
        std::cout << "|                                VISI DAN MISI                                 |" << std::endl;
        std::cout << "================================================================================" << std::endl;
        std::cout << "|                                                                              |" << std::endl;
        std::cout << "| Visi:               Menjadi agen negara                                      |" << std::endl;
        std::cout << "|                                                                              |" << std::endl;
        std::cout << "| Misi:            1. Meningkatnya produktifitas dan kreatifitas mahasiswa.    |" << std::endl;
        std::cout << "|                  2. Membangun hubungan yang kuat dengan masyarakat.          |" << std::endl;
        std::cout << "================================================================================" << std::endl;
    }

    std::cout << "Tekan enter untuk kembali." << std::endl;
    std::cin.ignore();
    std::cin.get();
}

std::string enkripsi(std::string plaintext) 
{
    char karakter[] = {
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
    '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '_', '+', '=', '{', '}', '[', ']', '<', '>', '.', ',', ';',
    '"', '\'', '\\', '/', '?', ':', '~', '|', ' '
    };

    int modulus = sizeof(karakter);
    int kunciMatriks[2][2] = {{2, 1}, {3, 4}};

    std::string ciphertext = "";

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

// std::string decrypt(std::string ciphertext, int kunciMatriks[2][2]) 
// {
//     char karakter[] = {
//     'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
//     'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
//     '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
//     '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '_', '+', '=', '{', '}', '[', ']', '<', '>', '.', ',', ';',
//     '"', '\'', '\\', '/', '?', ':', '~', '|', ' '
//     };

//     std::string plaintext = "";
//     int modulus = sizeof(karakter);

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

//     if(plaintext.back() == ' ')
//     {
//         plaintext.pop_back();
//     }

//     return plaintext;
// }

int main () {
    // int pilihan;

    // Pengguna pengguna;
    // pengguna.nama = "Hafiz";

    // std::cout << "Lihat Visi Misi\n" ;
    // std::cin >> pilihan;

    // menuVisiMisi(pengguna);

    std::string plaintext;
    std::cout << "Masukkan teks yang ingin dienkripsi: ";
    std::getline(std::cin, plaintext);

    std::cout << "Ciphertext: " << enkripsi(plaintext);

}