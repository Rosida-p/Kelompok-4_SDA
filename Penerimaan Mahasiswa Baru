Kelompok 4; (Sistem penerimaan mahasiswa baru ilmu komputer)
QORINA QISTHI KAMAL (2407051028)
ROSIDA PURNALA SARI (2407051011)
ILHAM KHOIRUL SAPUTRA (2407051007)
MUHAMMAD IQBAL FADHILAH AB (2407051019) 






























































































//Rebuild stack
 stack<string> s2;
    while (!st.empty()) {
        if (st.top() != nim) s2.push(st.top());
        st.pop();
    }
    swap(st, s2);

 // Rebuild queue
    queue<string> q2;
    while (!qu.empty()) {
        if (qu.front() != nim) q2.push(qu.front());
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
    string nim = qu.front(); qu.pop();
    cout << "FIFO → " << nim << ": " << db[nim].first << "\n";
}

// Proses LIFO (Stack)
void procS() {
    if (st.empty()) {
        cout << "S kosong\n";
        return;
    }
    string nim = st.top(); st.pop();
    cout << "LIFO → " << nim << ": " << db[nim].first << "\n";
}















































// Menu utama
int main() {
    int p;
    do {
        cout << "\n==============================\n";
        cout << "  MENU UTAMA - DATA MAHASISWA\n";
        cout << "==============================\n";
        cout << " 1. ➕ Tambah Data Mahasiswa\n";
        cout << " 2. 📄 Tampilkan Semua Data\n";
        cout << " 3. ✏  Update Data Mahasiswa\n";
        cout << " 4. ❌ Hapus Data Mahasiswa\n";
        cout << " 5. 🔁 Proses FIFO (Queue)\n";
        cout << " 6. 🔂 Proses LIFO (Stack)\n";
        cout << " 7. 🔍 Cari Data Mahasiswa\n";
        cout << " 8. 📊 Urutkan Data (Bubble Sort)\n";
        cout << " 0. 🚪 Keluar Program\n";
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
            default: cout << "❗ Pilihan tidak valid!\n";
        }
    } while (p != 0);
    return 0;
}
