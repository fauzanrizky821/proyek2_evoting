#include "231511065/231511065.h"
#include "231511070/231511070.h"
#include "231511074/231511074.h"
#include "231511076/231511076.h"
#include "231511077/231511077.h"

int main()
{
    int opsi, menu;
    Pengguna pengguna;
    bool cekLogin;

    addrTable baca = bacaFile("data/tabel-konversi.txt");
    if (baca == NULL)
    {
        cout << "Gagal membaca file tabel konversi!\n Klik enter untuk melanjutkan!";
        getchar();
        getchar();
        return 0;
    }

    int modulus = mod(baca);
    
    int Key1 = 2, Key2 = 1, Key3 = 3, Key4 = 4;
    addrMatriks matriksKunci = insertKunciMatriks(Key1, Key2, Key3, Key4);
    addrMatriks invMatriks = inversMatriksKunci(matriksKunci, modulus);

    do
    {
        std::cout << "============================================================" << std::endl;
        std::cout << "|                      APLIKASI E-VOTING                   |" << std::endl;
        std::cout << "============================================================" << std::endl;
        std::cout << "|                                                          |" << std::endl;
        std::cout << "|                       SELAMAT DATANG                     |" << std::endl;
        std::cout << "|                                                          |" << std::endl;
        std::cout << "============================================================" << std::endl;
        std::cout << "(1) Login\n";
        std::cout << "(2) Registrasi\n";
        std::cout << "(0) Keluar Aplikasi\n";
        std::cout << "inputkan pilihan anda: ";
        std::cin >> opsi;

        switch (opsi)
        {
        case 1:
            system("cls");
            cekLogin = loginPengguna(pengguna, invMatriks, baca, modulus);
            getchar();
            getchar();
            system("cls");
            if (cekLogin == true) // cek apakah login berhasil atau tidak, jika berhasil bernilai true
            {
                do
                {
                    cout << "==================== " << "Selamat datang " << pengguna.nama << " ====================\n"
                         << endl;
                    cout << "(1) Melakukan voting\n";
                    cout << "(2) Lihat Visi & Misi\n";
                    cout << "(0) Logout\n";
                    cout << "inputkan pilihan anda: ";
                    cin >> opsi;

                    switch (opsi)
                    {
                    case 1:
                        if (pengguna.status == "1")
                        {
                            system("cls");
                            cout << "============================================================" << endl;
                            cout << "|                Anda sudah melakukan vote!                |" << endl;
                            cout << "------------------------------------------------------------" << endl;
                            cout << "|             Tekan enter untuk melanjutkan..              |" << endl;
                            cout << "============================================================" << endl;
                            getchar();
                            getchar();
                            system("cls");
                        }
                        else
                        {
                            system("cls");
                            menuVote(pengguna, matriksKunci, invMatriks, baca, modulus);
                            system("cls");
                        }
                        break;
                    case 2:
                        system("cls");
                        do
                        {
                            cout << "==================== " << "Selamat datang " << pengguna.nama << " ====================\n" << endl;
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
                                getchar();
                                getchar();
                                system("cls");
                                break;
                            case 2:
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
                                getchar();
                                getchar();
                                system("cls");
                                break;
                            case 3:
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
                                getchar();
                                getchar();
                                system("cls");
                                break;
                            case 4:
                                getchar();
                                system("cls");
                                break;
                            default:
                                system("cls");
                                cout << "=========================================================" << endl;
                                cout << "|   Tolong pilih opsi sesuai dengan yang ditampilkan!   |" << endl;
                                cout << "=========================================================" << endl
                                    << endl;
                                break;
                            }
                        } while (menu != 4);
                        break;
                    case 0:
                        system("cls");
                        break;

                    default:
                        cout << "Ketikkan salah satu pilihan diatas! \n";
                        getchar();
                        getchar();
                        system("cls");
                        break;
                    }
                } while (opsi != 0);
                main();
            }
            break;
        case 2:
            registrasi(matriksKunci, invMatriks, baca, modulus);
            getchar();
            system("cls");
            break;
        case 0:
            system("cls");
            break;

        default:
            std::cout << "Ketikkan salah satu pilihan diatas! \n";
            getchar();
            getchar();
            system("cls");
            break;
        }
    } while (opsi != 0);

    bool hapusTabel = deleteTabel(baca);
    bool hapusMat = hapusMatriks(matriksKunci);
    
    return 0;
}