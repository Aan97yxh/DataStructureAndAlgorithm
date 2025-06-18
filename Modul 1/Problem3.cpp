#include<iostream>

using namespace std;

int main(){
    char huruf;
    string kata;
    int angka;

    //Input
    cout << "a. Masukkan sebuah huruf = ";
    cin >> huruf;
    cin.ignore();

    cout << "b. Masukkan sebuah kata = ";
    getline(cin, kata);

    cout << "c. Masukkan Angka = ";
    cin >> angka;

    //Output
    cout << "d. Huruf yang Anda masukkan adalah " << huruf << endl;
    cout << "e. Kata yang Anda masukkan adalah " << kata << endl;
    cout << "f. Angka yang Anda masukkan adalah " << angka << endl;

    return 0;
}