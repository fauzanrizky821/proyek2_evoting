#include "231511074.h"
#include <iostream>
using namespace std;

void dataPemilih(const Voter& voter) {
    cout <<"NIM : " << voter.nim;
    cout <<"\tNama : " << voter.nama;
    cout <<"\tJurusan : " << voter.jurusan;
    cout <<"\tProdi : " << voter.Prodi;
    cout << "\tStatus: " << (voter.status ? "Telah Melakukan Voting" : "Belum Melakukan Voting") << endl;
}

string melihatHasilVoting() {
    std::ifstream voteFile("data/total-vote.txt");
    std::string hasilVoting;

    if (!voteFile.is_open()) {
        std::cerr << "Gagal membuka file hasil_vote.txt\n";
        return hasilVoting;
    }

    hasilVoting += "|=======================================================|\n";
    hasilVoting += "|                 HASIL VOTE PEMILIHAN                  |\n";
    hasilVoting += "|=======================================================|\n";

    string line;
    int count = 0;
    while (std::getline(voteFile, line)) {
        count++;
        hasilVoting += "\t\t   Calon No-" + std::to_string(count) + " = " + line + "\n";
    }

    hasilVoting += "|=======================================================|\n";
    voteFile.close();

    return hasilVoting;
}

void lihatDataPemilih(addrMatriks invMatriks, addrTable karakterList, int modulus) {
    ifstream filePemilih("data/data-pengguna.txt");

    if (!filePemilih.is_open()){
        cerr<< "Gagal membuka file\n";
        return;
    }

    string line;
    getline(filePemilih, line);
    while (getline(filePemilih, line)){
        istringstream iss(line);
        Voter voter;

        string decryptedLine = line;
        decryptedLine = dekripsi(decryptedLine, invMatriks, karakterList, modulus);
        istringstream decryptedStream(decryptedLine);

        if (getline(decryptedStream, voter.nim, ',')&&
            getline(decryptedStream, voter.password, ',')&&
            getline(decryptedStream, voter.nama, ',')&&
            getline(decryptedStream,voter.jurusan, ',')&&
            getline(decryptedStream, voter.Prodi, ',')){
            string statusStr;
            if(getline(decryptedStream, statusStr,',')){
                voter.status=(statusStr=="1");
            }else{
                cerr << "gagal membaca status" << endl;
                continue;
            }
            dataPemilih(voter);
            }else{
                cerr << "gagal membaca data" << endl;
            }
    }
    filePemilih.close();
}

void menu_pengelola(Pengelola* head, const string& id, const string& nama){

    int choice;
    do {
        // Tampilkan menu
        cout << "\nMenu Pengelola:\n";
        cout << "+----+---------------------+\n";
        cout << "| 1  | input matriks  |\n";
        cout << "| 2  | Lihat Data Pemilih  |\n";
        cout << "| 3  | Logout               |\n";
        cout << "+----+---------------------+\n";
        cout << "Pilih: ";
        cin >> choice;

        
        string hasilVoting;
        switch (choice) {
            // case 1:
            //     system("cls");
            //     hasilVoting = melihatHasilVoting();
            //     cout << hasilVoting;
            //     cout << "Klik enter untuk kembali";
            //     cin.ignore();
            //     cin.get();
            //     system("cls");
            //     break;
            case 1: {
                // Panggil fungsi untuk input matriks disini
                int Key1, Key2, Key3, Key4;
                cout << "Masukkan kunci 1: ";
                cin >> Key1;
                cout << "Masukkan kunci 2: ";
                cin >> Key2;
                cout << "Masukkan kunci 3: ";
                cin >> Key3;
                cout << "Masukkan kunci 4: ";
                cin >> Key4;

                addrMatriks matrixHead = insertKunciMatriks(Key1, Key2, Key3, Key4);

                cout << "\n2x2 Matrix in the linked list:\n";
                printMatrix(matrixHead);

                // Free the matrix after printing
                freeMatrix(matrixHead);
                break;
            }

            case 2:
                system("cls");
                lihatDataPemilih();
                cout << "Klik enter untuk kembali";
                cin.ignore();
                cin.get();
                system("cls");
                break;

            case 3:
                cout << "Logout berhasil.\n\n";
                cout << "Klik enter untuk kembali";
                cin.ignore();
                cin.get();
                system("cls");
                break;
                default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }

    } while (choice != 3);

}

addrMatriks insertMatriks(int nilai)
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

addrMatriks insertKunciMatriks(int Key1, int Key2, int Key3, int Key4)
{

    addrMatriks key1 = insertMatriks(Key1);
    addrMatriks key2 = insertMatriks(Key2);
    addrMatriks key3 = insertMatriks(Key3);
    addrMatriks key4 = insertMatriks(Key4);

    key1->right = key2;
    key3->right = key4;

    key1->bottom = key3;
    key2->bottom = key4;

    return key1;
}

void printMatrix(addrMatriks head) {
    addrMatriks row = head;
    while (row != NULL) {
        addrMatriks col = row;
        while (col != NULL) {
            cout << col->info << " ";
            col = col->right;
        }
        cout << endl;
        row = row->bottom;
    }
}

void freeMatrix(addrMatriks head) {
    addrMatriks row = head;
    while (row != NULL) {
        addrMatriks col = row;
        while (col != NULL) {
            addrMatriks temp = col;
            col = col->right;
            free(temp);
        }
        addrMatriks tempRow = row;
        row = row->bottom;
        free(tempRow);
    }
}
