#include "231511065.h"
#include "../231511074/231511074.h"
#include <iostream>
#include <fstream>
#include <sstream>

void hitungJumlahVote(const string& nama_file) 
{
    map<int, int> jumlah_suara; // Gunakan map untuk menyimpan jumlah suara setiap pasangan calon

    PasanganCalon pasangan_calon[3]; 

    pasangan_calon[0].nama = "Hafiz";
    pasangan_calon[1].nama = "Fauzan";
    pasangan_calon[2].nama = "Abyan";

    pasangan_calon[0].nomor = 1;
    pasangan_calon[1].nomor = 2;
    pasangan_calon[2].nomor = 3;

    ifstream infile(nama_file);
    if (!infile) 
    {
        cerr << "Cannot open file\n";
        return;
    }

    string line;
    int nomor_pasangan = 1; // Nomor pasangan calon untuk mengakses array pasangan_calon
    while (getline(infile, line)) 
    {
        stringstream ss(line);
        int suara;

        // Menggunakan stringstream untuk membaca suara
        ss >> suara;

        // Mencari pasangan calon yang sesuai dengan nomor pasangan calon
        for (const auto& pasangan : pasangan_calon) 
        {
            if (pasangan.nomor == nomor_pasangan) 
            {
                jumlah_suara[nomor_pasangan] += suara;
                break; // Hentikan pencarian setelah menemukan pasangan calon yang sesuai
            }
        }

        nomor_pasangan++;
    }

    infile.close();
    int i=1;
    cout << "=============================================================" << endl;
    cout << "|                   HASIL TOTAL VOTE                        |" << endl;
    cout << "-------------------------------------------------------------" << endl;
    // Menampilkan total suara untuk setiap pasangan calon
    for (const auto& pasangan : pasangan_calon) 
    {
        cout << "                    Pasangan Calon " << i << ": "<< pasangan.nama << endl;
        cout << "                    Total Suara: " << jumlah_suara[pasangan.nomor]<< endl;
        cout << "                                                             " << endl;
        i++;
    }
    cout << "=============================================================" << endl;
}
bool login(Pengelola* head, string& id, string& nama) {
    string inputID, password, cekID, cekPassword, data;
    bool cariID = false;

    cout << "============================================================" << endl;
    cout << "|                                                          |" << endl;
    cout << "|                           LOGIN                          |" << endl;
    cout << "|                                                          |" << endl;
    cout << "============================================================" << endl;

    cout << "ID pengelola: ";
    cin >> inputID;
    cout << "Password    : ";
    cin >> password;

    Pengelola* current = head;
    while (current != nullptr && !cariID) {
        if (current->id == inputID) {
            cariID = true;
            if (current->password == password) {
                id = inputID;
                nama = current->nama;

                cout << "=============================================================" << endl;
                cout << "|                      LOGIN BERHASIL!                      |" << endl;
                cout << "-------------------------------------------------------------" << endl;
                cout << "|              Tekan enter untuk melanjutkan..              |" << endl;
                cout << "=============================================================" << endl;

                return true;
            } else {
                cout << "============================================================" << endl;
                cout << "|                      PASSWORD SALAH!                     |" << endl;
                cout << "------------------------------------------------------------" << endl;
                cout << "|             Tekan enter untuk melanjutkan..              |" << endl;
                cout << "============================================================" << endl;

                cin.ignore(); // Bersihkan buffer input
                cin.get();    // Tunggu pengguna menekan Enter
                return false;
            }
        }
        current = current->next;
    }

    if (!cariID) {
        cout << "============================================================" << endl;
        cout << "|              ID PENGGUNA TIDAK DITEMUKAN!                |" << endl;
        cout << "------------------------------------------------------------" << endl;
        cout << "|             Tekan enter untuk melanjutkan..              |" << endl;
        cout << "============================================================" << endl;

        cin.ignore(); // Bersihkan buffer input
        cin.get();    // Tunggu pengguna menekan Enter
        return false;
    }

    return false; // Jika ada perilaku yang tidak terduga
}

// Fungsi untuk membebaskan memori dari linked list
void deleteList(Pengelola* head) {
    while (head != nullptr) {
        Pengelola* temp = head;
        head = head->next;
        delete temp;
    }
}



void menu_login_pengelola(addrMatriks invMatriks, addrTable karakterList, int modulus) 
{
    Pengelola* head = nullptr;

    ifstream readFile("data/data-pengelola.txt");
    if (readFile.is_open()) 
    {
        string data;
        while (getline(readFile, data)) 
        {
            string line = dekripsi(data, invMatriks, karakterList, modulus);
            istringstream iss(line);
            string id, nama, password;
            getline(iss, id, ',');
            getline(iss, nama, ',');
            getline(iss, password, ',');

            Pengelola* newPengelola = new Pengelola(id, nama, password);
            newPengelola->next = head;
            head = newPengelola;
        }
        readFile.close();
    } 
    else 
    {
        cerr << "Gagal membuka file data-pengelola.txt" << endl;
        
    }

    string id, nama;
    if (login(head, id, nama)) // Periksa hasil login sebelum memanggil menu
    {
        cin.ignore();
        cin.get();
        system("cls");
        menu_pengelola(head, id, nama); // Panggil menu_pengelola jika login berhasil
    }
    else
    {
        cerr << "Login gagal. Tidak dapat memanggil menu pengelola." << endl;
    }

    // Membersihkan memori
    deleteList(head);

    
}

// Fungsi untuk menghapus semua matriks dari linked list dan membebaskan memori
void deleteMatriks(Node*& head, Node*& akhir) 
{
    if (head == nullptr) 
    {
        return;
    }
    Node* current = head;
    Node* nextNode;

    // Iterasi melalui setiap node di linked list
    while (current != nullptr) 
    {
        nextNode = current->next;
        // Hapus data matriks dari setiap node
        for (int i = 0; i < current->matrix.rows; ++i) 
        {
            delete[] current->matrix.data[i];
        }
        delete[] current->matrix.data;
        // Hapus node saat ini
        delete current;
        current = nextNode;
    }
    // Set head dan akhir linked list ke nullptr karena linked list sekarang kosong
    head = nullptr;
    akhir = nullptr;
}

// Fungsi untuk mencari elemen matriks berdasarkan baris dan kolom
addrMatriks searchMatriks(addrMatriks first, int row, int col)
{
    addrMatriks point = first;
    for (int i = 1; i < row; i++)
    {
        point = point->bottom;
    }

    for (int i = 1; i < col; i++)
    {
        point = point->right;
    }
    return point;
}

bool hapusMatriks(addrMatriks &awal)
{
    addrMatriks tempRow, tempCol;

    if (awal == NULL)
    {
        return false;
    }
    
    while (awal != NULL)
    {
        tempRow = awal;
        while (tempRow != NULL)
        {
            tempCol = tempRow;
            tempRow = tempRow->bottom;
            delete tempCol;
        }
        awal = awal->right;
    }
    return true;
}