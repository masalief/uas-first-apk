#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

// Struktur untuk menyimpan data pengeluaran
struct Pengeluaran {
    string kategori;
    int jumlah;
};

// Fungsi untuk menampilkan menu utama
void tampilkanMenu() {
    cout << "\nMenu Utama:" << endl;
    cout << "1. Tambah Pengeluaran" << endl;
    cout << "2. Tampilkan Total Pengeluaran" << endl;
    cout << "3. Tampilkan Sisa Saldo" << endl;
    cout << "4. Keluar" << endl;
    cout << "\nPilih opsi (1-4): ";
}

int main() {
    int saldoAwal;
    vector<Pengeluaran> daftarPengeluaran;
    int totalPengeluaran = 0;
    int pilihan;

    // Selamat datang dan input saldo awal
    cout << "Selamat datang di Aplikasi Keuangan Harian!" << endl;
    cout << "Masukkan saldo awal Anda: ";
    cin >> saldoAwal;

    do {
        tampilkanMenu();
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                // Tambah pengeluaran
                Pengeluaran pengeluaranBaru;
                cout << "\nMasukkan nama kategori pengeluaran: ";
                cin.ignore(); // Membersihkan buffer input
                getline(cin, pengeluaranBaru.kategori);
                cout << "Masukkan jumlah pengeluaran: ";
                cin >> pengeluaranBaru.jumlah;

                daftarPengeluaran.push_back(pengeluaranBaru);
                totalPengeluaran += pengeluaranBaru.jumlah;
                cout << "Pengeluaran berhasil ditambahkan!\n";
                break;
            }
            case 2: {
                // Tampilkan total pengeluaran
                cout << "\nDaftar Pengeluaran Anda:" << endl;
                cout << left << setw(20) << "Kategori" << "Jumlah" << endl;
                cout << string(30, '-') << endl;
                for (const auto& pengeluaran : daftarPengeluaran) {
                    cout << left << setw(20) << pengeluaran.kategori << pengeluaran.jumlah << endl;
                }
                cout << "\nTotal pengeluaran Anda: " << totalPengeluaran << "\n";
                break;
            }
            case 3: {
                // Tampilkan sisa saldo
                cout << "\nSisa saldo Anda: " << saldoAwal - totalPengeluaran << "\n";
                break;
            }
            case 4: {
                // Keluar
                cout << "\nTerima kasih telah menggunakan Aplikasi Keuangan Harian!\n";
                break;
            }
            default: {
                cout << "\nPilihan tidak valid. Silakan coba lagi.\n";
            }
        }
    } while (pilihan != 4);

    return 0;
}