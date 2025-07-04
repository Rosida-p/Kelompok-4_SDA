#include<iostream>
#include<map>
#include<queue>
#include<vector>
#include<string>
#include<stack> // Tambahkan ini
using namespace std;

// Struktur utama penyimpanan data mahasiswa
map<string,pair<string,string>>db;

// Stack (LIFO) dan Queue (FIFO)
stack<string>st;
queue<string>qu;

// Tambah data mahasiswa
void create(){
  string npm,nama,jurusan;
  do{
    cout <<"NPM (min 10 digit angka): ";
    cin >>npm;

    // Validasi panjang dan hanya angka
    bool valid = (npm.length()>=10);
    for(char c : npm){
      if(!isdigit(c)){
        valid = false;
        break;
      }
    }

    if (!valid){
      cout << "NPM harus terdiri dari minimal 10 angka.\n";
    } else if (db.count(npm)){ // Perbaiki nim -> npm
      cout << "NPM sudah ada dalam database.\n";
      valid = false;
    }

    if (!valid) continue;
    break;

  }while (true);
  cin.ignore();
  cout << "Nama: ";getline(cin,nama);
  cout << "jurusan: ";getline(cin,jurusan);
  db[npm]=make_pair(nama,jurusan);
  st.push(npm);
  qu.push(npm);
  cout <<"OK\n";
}

// Tampilkan semua data mahasiswa
void listAll(){
  if (db.empty()){
    cout << "Kosong\n";
    return;
  }

  for (auto it = db.begin();it != db.end();++it){
    string npm = it->first;
    string nama = it->second.first;
    string jurusan = it->second.second;
    cout << npm << " ;" <<nama << "(" <<jurusan<< ")\n";
  }
}

// Update data mahasiswa berdasarkan NPM
void updateData() {
    string npm;
    cout << "NPM: ";
    cin >> npm;
    if (!db.count(npm)) { cout << "Tidak ada\n"; return; }
    cin.ignore();
    string n, j;
    cout << "Nama baru (Enter=skip): "; getline(cin, n);
    cout << "Jurusan baru (Enter=skip): "; getline(cin, j);
    if (!n.empty()) db[npm].first = n;
    if (!j.empty()) db[npm].second = j;
    cout << "OK\n";
}

// Hapus data mahasiswa
void deleteData() {
    string npm; cout << "NPM: "; cin >> npm;
    if (!db.erase(npm)) { cout << "Tidak ada\n"; return; }

    // Rebuild stack
    stack<string> s2;
    while (!st.empty()) {
        if (st.top() != npm) s2.push(st.top());
        st.pop();
    }
    // Balik lagi ke urutan semula
    stack<string> s3;
    while (!s2.empty()) {
        s3.push(s2.top());
        s2.pop();
    }
    swap(st, s3);

    // Rebuild queue
    queue<string> q2;
    while (!qu.empty()) {
        if (qu.front() != npm) q2.push(qu.front());
        qu.pop();
    }
    swap(qu, q2);

    cout << "OK\n";
}
   
// Proses FIFO (Queue)
void procQ() {
    if (qu.empty()) {
        cout << "Q kosong\n";
        return;
    }
    string npm = qu.front(); qu.pop();
    cout << "FIFO → " << npm << ": " << db[npm].first << "\n";
}

// Proses LIFO (Stack)
void procS() {
    if (st.empty()) {
        cout << "S kosong\n";
        return;
    }
    string npm = st.top(); st.pop();
    cout << "LIFO → " << npm << ": " << db[npm].first << "\n";
}

// Pencarian berdasarkan NPM atau Nama
void searchData() {
    if (db.empty()) {
        cout << "Data kosong.\n";
        return;
    }

    string keyword;
    cin.ignore();
    cout << "Masukkan NPM atau Nama: ";
    getline(cin, keyword);

    bool found = false;
    for (const auto& entry : db) {
        const string& npm = entry.first;
        const string& nama = entry.second.first;
        const string& jurusan = entry.second.second;

        if (npm == keyword || nama.find(keyword) != string::npos) {
            cout << npm << ": " << nama << " (" << jurusan << ")\n";
            found = true;
        }
    }

    if (!found)
        cout << "Data tidak ditemukan.\n";
}

// Sorting data menggunakan Bubble Sort berdasarkan NPM atau Nama
void bubbleSort() {
    if (db.empty()) {
        cout << "Data kosong.\n";
        return;
    }

    int mode;
    cout << "Urutkan berdasarkan: 1=NPM 2=Nama\n> ";
    cin >> mode;

    // Salin data ke vector untuk diurutkan
    vector<pair<string, pair<string, string>>> data(db.begin(), db.end());

    // Bubble Sort
    for (size_t i = 0; i < data.size(); ++i) {
        for (size_t j = 0; j < data.size() - i - 1; ++j) {
            bool swapNeeded = false;
            if (mode == 1 && data[j].first > data[j + 1].first)
                swapNeeded = true;
            else if (mode == 2 && data[j].second.first > data[j + 1].second.first)
                swapNeeded = true;

            if (swapNeeded)
                swap(data[j], data[j + 1]);
        }
    }

    // Tampilkan hasil sort
    cout << "\nHasil Sort:\n";
    for (const auto& d : data) {
        cout << d.first << ": " << d.second.first << " (" << d.second.second << ")\n";
    }
}

// Menu utama
int main() {
    int p;
    do {
        cout << "\n==============================\n";
        cout << "  MENU UTAMA - DATA MAHASISWA\n";
        cout << "==============================\n";
        cout << " 1. Tambah Data Mahasiswa\n";
        cout << " 2. Tampilkan Semua Data\n";
        cout << " 3. Update Data Mahasiswa\n";
        cout << " 4. Hapus Data Mahasiswa\n";
        cout << " 5. Proses FIFO (Queue)\n";
        cout << " 6. Proses LIFO (Stack)\n";
        cout << " 7. Cari Data Mahasiswa\n";
        cout << " 8. Urutkan Data (Bubble Sort)\n";
        cout << " 0. Keluar Program\n";
        cout << "------------------------------\n";
        cout << "Pilih menu (0-8): ";
        cin >> p;

        switch (p) {
            case 1: create(); break;
            case 2: listAll(); break;
            case 3: updateData(); break;
            case 4: deleteData(); break;
            case 5: procQ(); break;
            case 6: procS(); break;
            case 7: searchData(); break;
            case 8: bubbleSort(); break;
            case 0: cout << "Terima kasih, program selesai.\n"; break;
            default: cout << "Pilihan tidak valid!\n";
        }
    } while (p != 0);
    return 0;
}
