#include <iostream>

using namespace std;

struct Karyawan {
    string nama;
    string umur;
    string posisi;
};

const int MAX_KARYAWAN = 100;
Karyawan karyawan[MAX_KARYAWAN];
int jumlahKaryawan = 0;

void bacaKaryawan() {
    cout << "Daftar karyawan:" << endl;
    for (int i = 0; i < jumlahKaryawan; ++i) {
        cout << i+1 << ". Nama: " << karyawan[i].nama << "\n   Umur: " << karyawan[i].umur << "\n   Posisi: " << karyawan[i].posisi << endl;
    }
}

void buatKaryawan() {
    bacaKaryawan();
    if (jumlahKaryawan < MAX_KARYAWAN) {
        cout << "Masukkan nama karyawan: ";
        cin >> karyawan[jumlahKaryawan].nama;
        cout << "Masukkan umur karyawan: ";
        cin >> karyawan[jumlahKaryawan].umur;
        cout << "Masukkan posisi karyawan: ";
        cin >> karyawan[jumlahKaryawan].posisi;
        jumlahKaryawan++;
        cout << "Karyawan berhasil ditambahkan!" << endl;
    } else {
        cout << "Tidak dapat menambahkan karyawan. Batas maksimum telah tercapai." << endl;
    }
}

void perbaruiKaryawan() {
    int nomorKaryawan;
    bacaKaryawan();
    cout << "Masukkan Nomor karyawan yang ingin diperbarui: ";
    cin >> nomorKaryawan;
    int indeks = nomorKaryawan - 1;
    if (indeks >= 0 && indeks < jumlahKaryawan) {
        cout << "Masukkan nama karyawan baru: ";
        cin >> karyawan[indeks].nama;
        cout << "Masukkan umur karyawan baru: ";
        cin >> karyawan[indeks].umur;
        cout << "Masukkan posisi karyawan baru: ";
        cin >> karyawan[indeks].posisi;
        cout << "Karyawan berhasil diperbarui!" << endl;
    } else {
        cout << "Nomor tidak valid!" << endl;
    }
}

void hapusKaryawan() {
    int nomorKaryawan;
    bacaKaryawan();
    cout << "Masukkan Nomor karyawan yang ingin dihapus: ";
    cin >> nomorKaryawan;
    int indeks = nomorKaryawan - 1;
    if (indeks >= 0 && indeks < jumlahKaryawan) {
        for (int i = indeks; i < jumlahKaryawan - 1; ++i) {
            karyawan[i] = karyawan[i + 1];
        }
        jumlahKaryawan--;
        cout << "Karyawan berhasil dihapus!" << endl;
    } else {
        cout << "Nomor tidak valid!" << endl;
    }
}

void login() {
    string user, password;
    int coba = 0;
    do {
        cout << "Masukkan ID: ";
        getline(cin, user);
        cout << "Masukkan Password: ";
        getline(cin, password);
        if (user == "Maulana iqbal hidayah" && password == "2309106103") {
            break;
        } else {
            coba++;
            if (coba == 3) {
                cout << "Percobaan Terlalu Banyak. Silahkan Coba Lagi Nanti" << endl;
                exit(0);
            } else {
                cout << "ID atau Password Salah" << endl;
            }
        }
    } while (coba < 3);
}

int main() {
    login();
    char pilihan;
    do {
        cout << "\nSistem Pengelolaan Karyawan\n";
        cout << "1. Tambah Karyawan\n";
        cout << "2. Lihat Karyawan\n";
        cout << "3. Perbarui Karyawan\n";
        cout << "4. Hapus Karyawan\n";
        cout << "5. Keluar\n";
        cout << "Masukkan pilihan Anda: ";
        cin >> pilihan;

        switch (pilihan) {
            case '1':
                buatKaryawan();
                break;
            case '2':
                bacaKaryawan();
                break;
            case '3':
                perbaruiKaryawan();
                break;
            case '4':
                hapusKaryawan();
                break;
            case '5':
                cout << "Keluar dari program..." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (pilihan != '5');

    return 0;
}
