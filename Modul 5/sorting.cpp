#include <iostream>
#include <string>
#include <functional>
#include <chrono>
#include <conio.h>

using namespace std;

void timeSort(const function<void()>& sortFunc, const string& sortName) {
    auto start = chrono::high_resolution_clock::now();
    sortFunc();
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    cout << fixed;
    cout.precision(10); 
    cout << sortName << " took " << duration.count() << " seconds\n";
}

void printString(const string& str) {
    cout << str << endl;
}

void insertionSort(string& str) {
    for (int i = 1; i < str.length(); ++i) {
        char key = str[i];
        int j = i - 1;
        while (j >= 0 && str[j] > key) {
            str[j + 1] = str[j];
            --j;
        }
        str[j + 1] = key;
    }
}

void merge(string& str, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    string L = str.substr(left, n1);
    string R = str.substr(mid + 1, n2);

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            str[k++] = L[i++];
        } else {
            str[k++] = R[j++];
        }
    }

    while (i < n1) str[k++] = L[i++];
    while (j < n2) str[k++] = R[j++];
}

void mergeSort(string& str, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(str, left, mid);
    mergeSort(str, mid + 1, right);
    merge(str, left, mid, right);
}

void shellSort(string& str) {
    int n = str.length();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            char temp = str[i];
            int j;
            for (j = i; j >= gap && str[j - gap] > temp; j -= gap)
                str[j] = str[j - gap];
            str[j] = temp;
        }
    }
}

void bubbleSort(string& str) {
    int n = str.length();
    bool swapped;
    for (int i = 0; i < n - 1; ++i) {
        swapped = false;
        for (int j = 0; j < n - i - 1; ++j) {
            if (str[j] > str[j + 1]) {
                swap(str[j], str[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

int partition(string& str, int low, int high) {
    char pivot = str[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (str[j] < pivot) {
            ++i;
            swap(str[i], str[j]);
        }
    }
    swap(str[i + 1], str[high]);
    return i + 1;
}

void quickSort(string& str, int low, int high) {
    if (low < high) {
        int pi = partition(str, low, high);
        quickSort(str, low, pi - 1);
        quickSort(str, pi + 1, high);
    }
}

void selectionSort(string& str) {
    int n = str.length();
    for (int i = 0; i < n - 1; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < n; ++j) {
            if (str[j] < str[min_idx]) {
                min_idx = j;
            }
        }
        swap(str[i], str[min_idx]);
    }
}

int main() {
    int pilihan;

    do {
        cout << "\n---------------------\n";
        cout << "|      Sorting      |\n";
        cout << "---------------------\n";
        cout << "1. Insertion Sort\n";
        cout << "2. Merge Sort\n";
        cout << "3. Shell Sort\n";
        cout << "4. Quick Sort\n";
        cout << "5. Bubble Sort\n";
        cout << "6. Selection Sort\n";
        cout << "7. Exit\n";
        cout << "---------------------\n";
        cout << "Masukkan Pilihan: ";
        cin >> pilihan;

        if (pilihan == 7) {
            cout << "\nProgram selesai.\n";
            cout << "Program was made by M.Anshary (2410817310008).\n" << endl;
            return 0;
        }

        if (pilihan < 1 || pilihan > 7) {
            cout << "Pilihan tidak valid.\n";
            cout << "\npress any key to continue..." << endl;
            getch();
            system("cls");
            continue;
        }

        string data;
        cout << "Masukkan Nama/NIM: ";
        cin >> data;

        switch (pilihan) {
            case 1:
                timeSort([&]() { insertionSort(data); }, "Insertion Sort");
                break;
            case 2:
                timeSort([&]() { mergeSort(data, 0, data.length() - 1); }, "Merge Sort");
                break;
            case 3:
                timeSort([&]() { shellSort(data); }, "Shell Sort");
                break;
            case 4:
                timeSort([&]() { quickSort(data, 0, data.length() - 1); }, "Quick Sort");
                break;
            case 5:
                timeSort([&]() { bubbleSort(data); }, "Bubble Sort");
                break;
            case 6:
                timeSort([&]() { selectionSort(data); }, "Selection Sort");
                break;
        }

        cout << "Setelah di sorting: ";
        printString(data);
        cout << "\npress any key to continue..." << endl;
        getch();
        system("cls");

    } while (true);

    return 0;
}