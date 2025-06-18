#include <iostream>
#include <conio.h>
#include <random>
#include <vector>
#include <algorithm>

using namespace std;

void sequentialSearch(const vector<int> &nums, int target) {
    cout << "\n--- Melakukan Sequential Search ---\n";
    cout << "Daftar Angka:\n";

    for (int i = 0; i < nums.size(); ++i) {
        cout << "[" << i + 1 << "] " << nums[i] << " ";
    }
    cout << "\n";

    bool found = false;
    vector<int> found_indices;
    int comparisons = 0;

    for (int i = 0; i < nums.size(); ++i) {
        comparisons++;
        if (nums[i] == target) {
            found = true;
            found_indices.push_back(i + 1);
        }
    }

    if (found) {
        cout << "Angka " << target << " ditemukan!\n";
        cout << "Ditemukan sebanyak " << found_indices.size() << " kali pada urutan: ";
        for (int i = 0; i < found_indices.size(); ++i) {
            cout << found_indices[i];
            if (i < found_indices.size() - 1) cout << ", ";
        }
        cout << "\n";
    } else {
        cout << "Angka " << target << " tidak ditemukan.\n";
    }
    cout << "Jumlah perbandingan: " << comparisons << "\n";
}

void binarySearch(const vector<int> &nums, int target) {
    cout << "\n--- Melakukan Binary Search ---\n";

    vector<int> sorted_nums = nums;
    sort(sorted_nums.begin(), sorted_nums.end());

    cout << "Daftar Angka (terurut):\n";
    for (int i = 0; i < sorted_nums.size(); ++i) {
        cout << "[" << i + 1 << "] " << sorted_nums[i] << " ";
    }
    cout << "\n";

    int left = 0, right = sorted_nums.size() - 1;
    bool found = false;
    int index = -1, comparisons = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        comparisons++;
        if (sorted_nums[mid] == target) {
            found = true;
            index = mid + 1;
            break;
        } else if (sorted_nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (found) {
        cout << "Angka " << target << " ditemukan pada urutan: " << index << ".\n";
    } else {
        cout << "Angka " << target << " tidak ditemukan.\n";
    }
    cout << "Jumlah perbandingan: " << comparisons << "\n";
}

void clearScreen() {
    system("cls");
}

void explain() {
    clearScreen();
    cout << "--- Perbandingan Sequential Search dan Binary Search ---\n\n";

    cout << "1. Sequential Search (Pencarian Linear):\n";
    cout << "   - Menelusuri data satu per satu dari awal sampai akhir.\n";
    cout << "   - Tidak membutuhkan data dalam keadaan terurut.\n";
    cout << "   - Kompleksitas waktu: O(n).\n";
    cout << "   - Kompleksitas ruang: O(1).\n\n";

    cout << "2. Binary Search (Pencarian Biner):\n";
    cout << "   - Membagi data menjadi dua bagian berulang kali.\n";
    cout << "   - Syarat: data harus dalam keadaan terurut.\n";
    cout << "   - Kompleksitas waktu: O(log n).\n";
    cout << "   - Kompleksitas ruang: O(1).\n\n";

    cout << "Kesimpulan:\n";
    cout << "Sequential cocok untuk data acak dan jumlah data sedikit.\n";
    cout << "Binary cocok untuk data besar yang sudah terurut.\n";
}

int main() {
    int opt, target;
    do {
        cout << "Pilih menu \n";
        cout << "1. Sequential Searching\n";
        cout << "2. Binary Searching\n";
        cout << "3. Jelaskan Perbedaan Sequential Searching dan Binary Searching!\n";
        cout << "4. Exit\n";
        cout << "Pilih: ";
        cin >> opt;

        switch (opt) {
            case 1: {
                vector<int> nums(100);
                mt19937_64 rng(random_device{}());
                uniform_int_distribution<int> dist(1, 100);

                for (auto &val : nums) val = dist(rng);

                cout << "\n--- Memulai Sequential Search --- \n";
                for (int i = 0; i < nums.size(); ++i)
                    cout << "[" << i + 1 << "] " << nums[i] << " ";
                cout << "\n";

                cout << "Masukkan angka yang ingin dicari: ";
                cin >> target;

                sequentialSearch(nums, target);
                break;
            }

            case 2: {
                int size;
                cout << "Masukkan ukuran vector: ";
                cin >> size;

                vector<int> nums(size);
                mt19937_64 rng(random_device{}());
                uniform_int_distribution<int> dist(1, 100);

                for (auto &val : nums) val = dist(rng);

                cout << "\n--- Memulai Binary Search --- \n";
                for (int i = 0; i < nums.size(); ++i)
                    cout << "[" << i + 1 << "] " << nums[i] << " ";
                cout << "\n";

                cout << "Masukkan angka yang ingin dicari: ";
                cin >> target;

                binarySearch(nums, target);
                break;
            }

            case 3:
                explain();
                break;

            case 4:
                cout << "\nTERIMA KASIH\n";
                cout << "Program dibuat oleh M.Anshary (2410817310008)\n";
                break;

            default:
                cout << "Opsi tidak valid. Coba lagi.\n";
                break;
        }

        if (opt != 4) {
            cout << "\nTekan sembarang tombol untuk melanjutkan...";
            getch();
            clearScreen();
        }

    } while (opt != 4);

    return 0;
}