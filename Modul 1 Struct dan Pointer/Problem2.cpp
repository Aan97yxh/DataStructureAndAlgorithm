#include<iostream>

using namespace std;

struct Kendaraan {
    string platNomor,jenisKendaraan,namaPemilik,alamat,kota;
};

int main(){
    Kendaraan mobil = {
        "DA1234MK",
        "RUSH",
        "Andika Hartanto",
        "Jl. Kayu Tangi 1",
        "Banjarmasin"
    };

    cout << "a. Plat Nomor Kendaraan : " << mobil.platNomor << endl;
    cout << "b. Jenis Kendaraan      : " << mobil.jenisKendaraan << endl;
    cout << "c. Nama Pemilik         : " << mobil.namaPemilik << endl;
    cout << "d. Alamat               : " << mobil.alamat << endl;
    cout << "e. Kota                 : " << mobil.kota << endl;

    return 0;
}