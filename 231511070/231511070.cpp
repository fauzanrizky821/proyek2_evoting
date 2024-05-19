// Aulia Putri Ramadhani

#include "231511070.h"

void total_vote(const int hasil_vote[]) {
    ofstream file("data/total-vote.txt");
    file << hasil_vote[0] << endl;
    file << hasil_vote[1] << endl;
    file << hasil_vote[2] << endl;
    file.close();
}

void update_status(const string &nim) {
    ifstream infile("data/data-pengguna.txt");
    vector<Pengguna> data_pengguna;

    string line;
    while (getline(infile, line)) {
        Pengguna pengguna;
        istringstream iss(dekripsi(line));
        getline(iss, pengguna.nim, ',');
        getline(iss, pengguna.password, ',');
        getline(iss, pengguna.nama, ',');
        getline(iss, pengguna.jurusan, ',');
        getline(iss, pengguna.prodi, ',');
        getline(iss, pengguna.status, ',');

        if (pengguna.nim == nim) {
            pengguna.status = "1";
        }

        data_pengguna.push_back(pengguna);
    }

    infile.close();

    ofstream outfile("data/temp-data-pengguna.txt");
    for (vector<Pengguna>::iterator it = data_pengguna.begin(); it != data_pengguna.end(); ++it) {
        Pengguna pengguna = *it;
        string dataPengguna;
        dataPengguna = pengguna.nim + ',' + pengguna.password + ',' + pengguna.nama + ',' + pengguna.jurusan + ',' + pengguna.prodi + ',' + pengguna.status + ",";
        outfile << enkripsi(dataPengguna) << endl;
    }
    outfile.close();

    remove("data/data-pengguna.txt");
    rename("data/temp-data-pengguna.txt", "data/data-pengguna.txt");
}

void menuVote(Pengguna &pengguna) {
    ifstream file("data/total-vote.txt");
    int hasil_vote[3] = {0};

    int i = 0;
    while (i < 3) {
        file >> hasil_vote[i];
        i = i + 1;
    }

    file.close();

    int nomor_calon;

    cout << "Calon pasangan ketua BEM dan wakil ketua BEM 2024:" << endl;
    cout << "=======================================================" << endl;
    cout << "| No | Calon Pasangan                                 |" << endl;
    cout << "=======================================================" << endl;
    cout << "| 1  | Hafiz Muhammad Al Ikhsan & Elsa Monika Sinaga  |" << endl;
    cout << "|----|------------------------------------------------|" << endl;
    cout << "| 2  | Fauzan Rizky Ramadhan & Aulia Putri Ramadhani  |" << endl;
    cout << "|----|------------------------------------------------|" << endl;
    cout << "| 3  | Abyan Dzaky Pratama & Haikal Hariyanto         |" << endl;
    cout << "=======================================================" << endl;
    cout << "Masukkan nomor calon yang ingin Anda pilih (1, 2, atau 3): ";
    cin >> nomor_calon;

    if (nomor_calon >= 1 && nomor_calon <= 3) {
        hasil_vote[nomor_calon - 1] += 1;

        update_status(pengguna.nim);

        total_vote(hasil_vote);

        pengguna.status = "1";

        cout << "Vote berhasil ditambahkan." << endl;
        getchar();
        getchar();
    } else {
        cout << "Nomor calon tidak valid." << endl;
        getchar();
        getchar();
        menuVote(pengguna);
    }
}

void insertTabel(addrTable &head, char info) {
    addrTable newNode, temp;
    newNode = (addrTable)malloc(sizeof(table));
    if (newNode == NULL) {
        cout << "Memory Penuh\n";
        return;
    }
    newNode->info = info;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

bool deleteTabel(addrTable &head) {
    if (head == NULL) {
        return false;
    }

    addrTable temp = NULL;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
    return true;
}

void tampilkanList(addrTable awal, addrTable akhir) {
    addrTable p;
    p = awal;
    int i;

    printf("\nLinked List: \n");

    i = 1;
    while (p != NULL) {
        printf("(%d) %d \n", i, p->info);
        p = next(p);
        i++;
    }
}