#include <iostream>
#include <conio.h>
#include <stdlib.h>
#define n 20

using namespace std;

int PIL;
char PILIHAN[1], HURUF;

struct Queue {
    char Q[n];
    int F, R;

    void Inisialisasi() {
        F = R = -1;
    }

    void INSERT() {
        if (R == n - 1) {
            cout << "Antrian Penuh!" << endl;
        } else {
            cout << "Masukkan 1 Karakter: ";
            cin >> HURUF;
            if (F == -1) {
                F = 0;
            }
            R++;
            Q[R] = HURUF;
            cout << "Data " << HURUF << " berhasil dimasukkan ke antrian." << endl;
        }
    }

    void DELETE() {
        if (F == -1 || F > R) {
            cout << "Antrian Kosong!" << endl;
        } else {
            cout << "Data " << Q[F] << " dihapus dari antrian." << endl;
            F++;
            if (F > R) {
                F = R = -1;
            }
        }
    }

    void CETAKLAYAR() {
        if (F == -1 || F > R) {
            cout << "Antrian Kosong!" << endl;
        } else {
            cout << "Isi Antrian (Front -> Rear):" << endl;
            for (int i = F; i <= R; i++) {
                cout << "Antrian Ke-" << i << " = [" << Q[i] << "]" << endl;
            }
        }
    }

    void RESET() {
        F = R = -1;
        cout << "Antrian berhasil direset!" << endl;
    }
};

Queue antrian;

int main() {
    antrian.Inisialisasi();

    do {
        cout << "QUEUE" << endl;
        cout << "==============" << endl;
        cout << "1. INSERT" << endl;
        cout << "2. DELETE" << endl;
        cout << "3. CETAK QUEUE" << endl;
        cout << "4. RESET" << endl;
        cout << "5. QUIT" << endl;   
        cout << "PILIHAN : "; cin >> PILIHAN;
        PIL = atoi(PILIHAN);

        switch (PIL) {
            case 1:
                antrian.INSERT();
                break;
            case 2:
                antrian.DELETE();
                break;
            case 3:
                antrian.CETAKLAYAR();
                break;
            case 4:
                antrian.RESET();
                break;
            case 5:
                cout << "TERIMA KASIH" << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
                break;
        }

        if (PIL < 5) {
            cout << "\nPress any key to continue...";
            getch();
            system("cls");
        }

    } while (PIL < 5);

    return 0;
}