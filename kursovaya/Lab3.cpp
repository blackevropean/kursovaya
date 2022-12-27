#include "Labs.h"
#include <iostream>
#include <random>
#include <iomanip>
#include <stdio.h>

using namespace std;

void PrintArr(int& Array, int n);
void Zadanie1a(int& Array, int n);
void Zadanie1b(int& Array, int n);
void Zadanie2c(int& Array, int n);
void Zadanie2d(int& Array, int n);
void bubblesort(int& Array, int n);
void swap(int* const, int* const);

void main() {
    setlocale(LC_ALL, "rus");
    int  Next_quest;
    cout << "Задание 1а" << endl;
    const int N = 6;
    int Arr1[N][N] = {};
    Zadanie1a(Arr1[0][0], N);
    cout << endl;
    cout << "Задание 1b" << endl;
    int Arr[N][N] = {};
    Zadanie1b(Arr[0][0], N);
    cout << "Следующее задание ";
    cin >> Next_quest;
    cout << endl;
    cout << "Задание 2c" << endl;
    Zadanie2c(Arr[0][0], N);
    PrintArr(Arr[0][0], N);
    cout << "Следующее задание ";
    cin >> Next_quest;
    cout << endl;
    cout << "Задание 2d" << endl;
    Zadanie2d(Arr[0][0], N);
    PrintArr(Arr[0][0], N);
    cout << "Следующее задание  ";
    cin >> Next_quest;
    cout << endl;
    cout << "Задание 3" << endl;
    bubblesort(Arr[0][0], N);
    PrintArr(Arr[0][0], N);
}
void PrintArr(int& Array, int n)
{
    int* a = &Array;
    for (int i = 0, *Next = a, *End = Next + n * n; Next < End; i++, Next++) {
        cout << setw(4) << *Next;
        if (i % n == n - 1) cout << endl;
    }
    cout << endl;
}
void Zadanie1a(int& Array, int n)
{
    int* Begin = &Array, * End = Begin + n * n - 1;
    for (int i = 0; i < n - 1; Begin++, i++) {
        *Begin = 1 + rand() % (n * n - 1);
        PrintArr(Array, n);
    }
    int temp = n - 1, fl = 1;
    while (temp > 0) {
        for (int i = 0; i < temp; Begin += n * fl, i++) {
            *Begin = 1 + rand() % (n * n - 1);
            PrintArr(Array, n);
        }
        for (int i = 0; i < temp; Begin -= fl, i++) {
            *Begin = 1 + rand() % (n * n - 1);
            PrintArr(Array, n);
        }
        temp--;
        fl = -fl;
    }
    *Begin = 1 + rand() % (n * n - 1);
    PrintArr(Array, n);
}
void Zadanie1b(int& Array, int n)
{
    int* Begin = &Array, * End = Begin + n * n - 1;
    int sign = 1;
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n - 1; Begin += n * sign, i++) {
            *Begin = 1 + rand() % (n * n - 1);
            PrintArr(Array, n);
        }
        *Begin = 1 + rand() % (n * n - 1);
        PrintArr(Array, n);
        Begin++;
        sign = -sign;
    }
}
void Zadanie2c(int& Array, int n)
{
    int* a = &Array, mid = n / 2;
    for (int i = 0, *Begin = a; i < n; i++, Begin += n)
        for (int j = 0; j < mid; j++)
            std::swap(*(Begin + j), *(Begin + mid + j));
}
void Zadanie2d(int& Array, int n)
{
    int* a = &Array, mid = n / 2;
    for (int i = 0, *Begin = a; i < mid * n; i++, Begin++)
        std::swap(*(Begin), *(Begin + mid * n));
}


void swap(int* const elem1Ptr, int* const elem2Ptr)
{
    int hold = *elem1Ptr;
    *elem1Ptr = *elem2Ptr;
    *elem2Ptr = hold;

}
void bubblesort(int& Array, int n) {
    int* l = &Array, * r = &Array + n * n;
    bool b = true;
    while (b) {
        b = false;
        for (int* i = l; i + 1 < r; i++) {
            if (*i > *(i + 1)) {
                swap(*i, *(i + 1));
                b = true;
            }
        }
        r--;
    }
}