#include "231511074.h"

void dataPemilih(const Voter& voter) {
    cout <<"NIM : " << voter.nim;
    cout <<"\tNama : " << voter.nama;
    cout <<"\tJurusan : " << voter.jurusan;
    cout <<"\tProdi : " << voter.Prodi;
    cout << "\tStatus: " << (voter.status ? "Telah Melakukan Voting" : "Belum Melakukan Voting") << endl;
}

void melihatHasilVoting() {
    ifstream voteFile("data/total-vote.txt");

    if (!voteFile.is_open()) {
        cerr << "Gagal membuka file hasil_vote.txt\n";
    }

    cout << "|=======================================================|" << endl;
    cout << "|                 HASIL VOTE PEMILIHAN                  |" << endl;
    cout << "|=======================================================|" << endl;

    string line;
    int count = 0;
    while (getline(voteFile, line)) {
        count ++;
        cout << "\t\t   Calon No-" << count << " = " << line << endl;
    }
    cout << "|=======================================================|" << endl;
    voteFile.close();
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
        cout << "| 1  | Lihat Hasil Voting  |\n";
        cout << "| 2  | Lihat Data Pemilih  |\n";
        cout << "| 3  | Logout               |\n";
        cout << "+----+---------------------+\n";
        cout << "Pilih: ";
        cin >> choice;

        switch (choice) {
            case 1:
                system("cls");
                melihatHasilVoting();
                cout << "Klik enter untuk kembali";
                cin.ignore();
                cin.get();
                system("cls");
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