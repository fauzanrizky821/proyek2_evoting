#include "231511077.h"

void menuVisiMisi(Pengguna pengguna)
{
    int menu;

    cout << "==================== " << "Selamat datang " << pengguna.nama << " ====================\n"
         << endl;
    cout << "Menu Melihat Visi dan Misi Calon" << endl;
    cout << "\n1. Lihat Visi dan Misi Calon ke-1" << endl;
    cout << "2. Lihat Visi dan Misi Calon ke-2" << endl;
    cout << "3. Lihat Visi dan Misi Calon ke-3" << endl;
    cout << "4. Kembali ke tampilan utama." << endl;
    cout << "Pilihan: ";
    cin >> menu;

    switch (menu)
    {
    case 1:
        VisiMisi(menu);
        system("cls");
        menuVisiMisi(pengguna);
        break;
    case 2:
        VisiMisi(menu);
        system("cls");
        menuVisiMisi(pengguna);
        break;
    case 3:
        VisiMisi(menu);
        system("cls");
        menuVisiMisi(pengguna);
        break;
    case 4:
        system("cls");
        menuUtama(pengguna);
        break;
    default:
        system("cls");
        cout << "=========================================================" << endl;
        cout << "|   Tolong pilih opsi sesuai dengan yang ditampilkan!   |" << endl;
        cout << "=========================================================" << endl
             << endl;
        menuVisiMisi(pengguna);
    }
}

void VisiMisi(int calon)
{
    system("cls");
    if (calon == 1)
    {
        cout << "==================================================================================================================" << endl;
        cout << "|                          CALON PASANGAN HAFIZ MUHAMMAD AL IKHSAN & ELSA MONIKA SINAGA                          |" << endl;
        cout << "------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "|                                              VISI DAN MISI                                                     |" << endl;
        cout << "==================================================================================================================" << endl;
        cout << "|                                                                                                                |" << endl;
        cout << "| Visi:             Membangun kampus yang berdaya saing tinggi, berbudaya, serta mendorong                       |" << endl;
        cout << "|                   keterlibatan aktif mahasiswa dalam pembangunan kampus yang berkelanjutan.                    |" << endl;
        cout << "|                                                                                                                |" << endl;
        cout << "| Misi:             1. Menjalin komunikasi dan kerjasama dari dalam lingkungan internal dan eksternal Kampus.    |" << endl;
        cout << "|                   2. Menyelenggarakan program kerja yang solutif bagi mahasiswa.                               |" << endl;
        cout << "|                   3. Program makan siang gratis.                                                               |" << endl;
        cout << "==================================================================================================================" << endl;
        cout << "|                                        Tekan enter untuk kembali..                                             |" << endl;
        cout << "==================================================================================================================" << endl;
    }
    else if (calon == 2)
    {
        cout << "===============================================================================================================" << endl;
        cout << "|                        CALON PASANGAN FAUZAN RIZKY RAMADHAN & AULIA PUTRI RAHMADHANI                        |" << endl;
        cout << "---------------------------------------------------------------------------------------------------------------" << endl;
        cout << "|                                             VISI DAN MISI                                                   |" << endl;
        cout << "===============================================================================================================" << endl;
        cout << "|                                                                                                             |" << endl;
        cout << "| Visi:            BEM Cerah (Cerdas,Religius, Aktif dan Harmonis)                                            |" << endl;
        cout << "|                                                                                                             |" << endl;
        cout << "| Misi:            1. Terlaksananya pelatihan pelatihan yang meningkatkan kualitas Sumber Daya Mahasiswa.     |" << endl;
        cout << "|                  2. Membangun hubungan yang kuat dengan masyarakat.                                         |" << endl;
        cout << "|                  3. Program berbagi donat gratis untuk seluruh mahasiswa.                                   |" << endl;
        cout << "===============================================================================================================" << endl;
        cout << "|                                       Tekan enter untuk kembali..                                           |" << endl;
        cout << "===============================================================================================================" << endl;
    }
    else if (calon == 3)
    {
        cout << "=================================================================================" << endl;
        cout << "|             CALON PASANGAN ABYAN DZAKY PRATAMA & HAIKAL HARIYANTO             |" << endl;
        cout << "---------------------------------------------------------------------------------" << endl;
        cout << "|                               VISI DAN MISI                                   |" << endl;
        cout << "=================================================================================" << endl;
        cout << "|                                                                               |" << endl;
        cout << "| Visi:            BEM POLBAN sebagai wadah meningkatkan produktifitas dan      |" << endl;
        cout << "|                  kreatifitas mahasiswa yang optimal dalam cakupan Internal    |" << endl;
        cout << "|                  dan eksternal kampus                                         |" << endl;
        cout << "|                                                                               |" << endl;
        cout << "| Misi:            1. Meningkatnya produktifitas dan kreatifitas mahasiswa.     |" << endl;
        cout << "|                  2. Terwujudnya BEM yang Harmonis dan aspiratif.              |" << endl;
        cout << "=================================================================================" << endl;
        cout << "|                         Tekan enter untuk kembali..                           |" << endl;
        cout << "=================================================================================" << endl;
    }
    cin.ignore();
    cin.get();
}

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

addrMatriks MatriksKunci(int nilai)
{
    addrMatriks newNode; 
    newNode = (addrMatriks)malloc(sizeof(matriks));
    if (newNode != NULL)
    {
        newNode->info = nilai;
        newNode->right = NULL;
        newNode->bottom = NULL;
    }
    else
    {
        cout << "Alokasi memori gagal" << endl;
    }
    return newNode;
}

addrMatriks LLKunciMatriks(int Key1, int Key2, int Key3, int Key4)
{

    addrMatriks key1 = MatriksKunci(Key1);
    addrMatriks key2 = MatriksKunci(Key2);
    addrMatriks key3 = MatriksKunci(Key3);
    addrMatriks key4 = MatriksKunci(Key4);

    key1->right = key2;
    key3->right = key4;

    key1->bottom = key3;
    key2->bottom = key4;

    return key1;
}