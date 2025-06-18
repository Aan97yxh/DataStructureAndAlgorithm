#include <iostream>
#include <conio.h>
#include <stdlib.h>

#define max 20

using namespace std;

struct Stack {
    int data[max];
    int atas;
};

Stack Tumpuk;

int penuh() {
    if (Tumpuk.atas == max - 1)
        return 1;
    else
        return 0;
}

int kosong() {
    return Tumpuk.atas == -1;
}

void input(int data) {
    if (penuh()==1) {
        cout << "Tumpukan Penuh\n";
    } else {
        Tumpuk.atas++;
        Tumpuk.data[Tumpuk.atas] = data;
        cout << "Data " << Tumpuk.data[Tumpuk.atas]
             << " Masuk Ke Stack\n";
    }
}

void hapus() {
    if (kosong()==0) {
        cout << "Data " << Tumpuk.data[Tumpuk.atas] << " Teratas Sudah Terambil\n";
        Tumpuk.atas--;
    } else {
        cout << "Tumpukan Kosong!\n";
    }
}

void tampil() {
    if (kosong()==0) {
        for (int i = Tumpuk.atas; i >= 0; i--) {
            cout << "Tumpukan Ke " << i << " = " << Tumpuk.data[i] << endl;
        }
    } else {
        cout << "Tumpukan Kosong!\n";
    }
}

void bersih() {
    Tumpuk.atas = -1;
    cout << "Tumpukan Kosong!\n";
}

void init() {
    Tumpuk.atas = -1;
}

int main(){
    int pilihan, nilai;
    init();

    do {
        cout << "\n==== MENU STACK ====\n";
        cout << "1. Push (Input)\n";
        cout << "2. Pop (Hapus)\n";
        cout << "3. Tampilkan\n";
        cout << "4. Bersihkan Stack\n";
        cout << "5. Keluar\n";
        cout << "Pilihan Anda: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                if (penuh()) {
                cout << "Tumpukan Penuh\n";
            } 
                else {
                cout << "Masukkan data: ";
                cin >> nilai;
                input(nilai);
            }
            break;

            case 2:
                hapus();
                break;
            case 3:
                tampil();
                break;
            case 4:
                bersih();
                break;
            case 5:
                cout << "Terima kasih. Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
        if (pilihan!=5){
            cout<<"\nTekan apa saja untuk menlanjutkan";
            getch();
            system("cls");
        }

    }while (pilihan != 5);

    return 0;
}