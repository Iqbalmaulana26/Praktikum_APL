#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Fungsi untuk menghitung jumlah digit ganjil dalam NIM
int countOddDigits(string nim) {
    int count = 0;
    for (char digit : nim) {
        int num = digit - '0';
        if (num % 2 != 0) {
            count++;
        }
    }
    return count;
}

// Metode sorting huruf secara ascending
vector<string> sortingHurufAscending(vector<string> nimList) {
    sort(nimList.begin(), nimList.end());
    return nimList;
}

// Metode sorting angka secara descending
vector<string> sortingAngkaDescending(vector<string> nimList) {
    sort(nimList.begin(), nimList.end(), greater<string>());
    return nimList;
}

// Metode sorting kustom
vector<string> sortingCustom(vector<string> nimList) {
    sort(nimList.begin(), nimList.end(), [](const string& a, const string& b) {
        return countOddDigits(a) < countOddDigits(b);
    });
    return nimList;
}

// Fungsi untuk menampilkan data NIM
void displayNIM(vector<string> nimList) {
    if (nimList.empty()) {
        cout << "Data NIM kosong." << endl;
        return;
    }
    cout << "Data NIM:" << endl;
    for (const string& nim : nimList) {
        cout << nim << endl;
    }
    cout << endl;
}

// Fungsi untuk menambah data NIM
void addNIM(vector<string>& nimList, string nim) {
    nimList.push_back(nim);
    cout << "Data NIM berhasil ditambahkan." << endl << endl;
}

// Fungsi untuk mengubah data NIM
void updateNIM(vector<string>& nimList, int index, string newNIM) {
    if (index >= 0 && index < nimList.size()) {
        nimList[index] = newNIM;
        cout << "Data NIM berhasil diubah." << endl << endl;
    } else {
        cout << "Indeks tidak valid. Data NIM tidak dapat diubah." << endl << endl;
    }
}

// Fungsi untuk menghapus data NIM
void deleteNIM(vector<string>& nimList, int index) {
    if (index >= 0 && index < nimList.size()) {
        nimList.erase(nimList.begin() + index);
        cout << "Data NIM berhasil dihapus." << endl << endl;
    } else {
        cout << "Indeks tidak valid. Data NIM tidak dapat dihapus." << endl << endl;
    }
}

// Fungsi untuk memeriksa login
bool checkLogin(string username, string password) {
    // Contoh implementasi sederhana
    return (username == "admin" && password == "123456");
}

int main() {
    string username, password;
    
    // Meminta input username dan password
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;
    
    // Memeriksa login
    if (!checkLogin(username, password)) {
        cout << "Login gagal. Silakan coba lagi." << endl;
        return 1; // Keluar dari program karena login gagal
    }
    
    cout << "Login berhasil. Selamat datang, " << username << "!" << endl << endl;

    // NIM mahasiswa dengan angka terakhir 103
    vector<string> nimList = {"19010301", "20010302", "21010303", "22010304", "23010305"};

    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Tampilkan Data NIM" << endl;
        cout << "2. Tambah Data NIM" << endl;
        cout << "3. Ubah Data NIM" << endl;
        cout << "4. Hapus Data NIM" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih menu: ";
        
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                displayNIM(nimList);
                break;
            case 2: {
                string nim;
                cout << "Masukkan NIM baru: ";
                cin >> nim;
                addNIM(nimList, nim);
                break;
            }
            case 3: {
                int index;
                string newNIM;
                cout << "Masukkan indeks data yang ingin diubah: ";
                cin >> index;
                cout << "Masukkan NIM baru: ";
                cin >> newNIM;
                updateNIM(nimList, index, newNIM);
                break;
            }
            case 4: {
                int index;
                cout << "Masukkan indeks data yang ingin dihapus: ";
                cin >> index;
                deleteNIM(nimList, index);
                break;
            }
            case 5:
                cout << "Program selesai." << endl;
                return 0;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    }

    return 0;
}
