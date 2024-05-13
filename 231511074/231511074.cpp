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

void lihatDataPemilih() {
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
        decryptedLine = dekripsi(decryptedLine);
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
            Matrix matrix;
            case 1:
                system("cls");
                matrix = inputMatrix();
                cout << "Matriks yang dimasukkan:" << endl;
                printMatrix(matrix);
                break;

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
                menu_login_pengelola();
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }

    } while (choice != 3);

}

// Fungsi untuk menyisipkan matriks ke dalam linked list
void insertMatrix(Node*& head, Matrix matrix) {
    // Buat node baru
    Node* newNode = new Node;
    newNode->matrix = matrix;
    newNode->next = nullptr;
    newNode->bottom = nullptr;

    // Jika linked list kosong, matriks baru akan menjadi head
    if (head == nullptr) {
        head = newNode;
        return;
    }

    // Temukan node terakhir dari linked list pada baris terakhir
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    // Sisipkan node baru di baris terakhir
    temp->next = newNode;

    // Temukan node terakhir dari linked list pada kolom terakhir
    Node* tempCol = head;
    while (tempCol->bottom != nullptr) {
        tempCol = tempCol->bottom;
    }

    // Sisipkan node baru di kolom terakhir
    tempCol->bottom = newNode;
}

Matrix inputMatrix() {
    Matrix matrix;
    cout << "Masukkan jumlah baris matriks: ";
    cin >> matrix.rows;
    cout << "Masukkan jumlah kolom matriks: ";
    cin >> matrix.cols;

    // Alokasikan memori untuk matriks
    matrix.data = new int*[matrix.rows];
    for (int i = 0; i < matrix.rows; ++i) {
        matrix.data[i] = new int[matrix.cols];
        for (int j = 0; j < matrix.cols; ++j) {
            cout << "Masukkan elemen untuk baris " << i + 1 << " kolom " << j + 1 << ": ";
            cin >> matrix.data[i][j];
        }
    }
    return matrix;
}


void freeLinkedList(Node* head) {
    Node* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        // Bebaskan memori untuk matriks dalam node
        for (int i = 0; i < temp->matrix.rows; ++i) {
            delete[] temp->matrix.data[i];
        }
        delete[] temp->matrix.data;
        // Bebaskan memori untuk node
        delete temp;
    }
}

void printMatrix(const Matrix& matrix) {
    cout << "Matriks:\n";
    for (int i = 0; i < matrix.rows; ++i) {
        for (int j = 0; j < matrix.cols; ++j) {
            cout << matrix.data[i][j] << " ";
        }
        cout << endl;
    }
}
