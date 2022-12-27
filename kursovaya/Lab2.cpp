#include "Labs.h"
#include <iostream>
#include <cstdlib>
#include <chrono>
#include <math.h> 

using namespace std;
using namespace std::chrono;


void main() {
    setlocale(LC_ALL, "rus");
    int arr[100];
    cout << "Bubble sort" << endl;
    for (int i = 0; i < 100; i++)
    {
        arr[i] = rand() % 199 - 99;
    }
    cout << "����������������� ������: " << endl;
    for (int i = 0; i < 100; i++) {
        cout << arr[i] << " ";
    }
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 99; j++) {
            if (arr[j] > arr[j + 1]) {
                int b = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = b;
            }
        }
    }
    cout << endl << "��������������� ������: " << endl;
    for (int i = 0; i < 100; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    int max, min, med, x; {
        auto start = chrono::high_resolution_clock::now();
        max = min = arr[0];
        for (int i = 1; i < 100; i++)
        {
            if (max < arr[i]) max = arr[i];
            if (min > arr[i]) min = arr[i];
        }
        cout << "max = " << max << endl;
        cout << "min = " << min << endl;
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<float> duration = end - start;
        cout << "����� ������ Min � Max = " << duration.count() * 1000 << "ms." << endl;
    }
    x = (max + min) / 2;
    med = x;
    int key;
    key = med;
    bool flag = false;
    int l = 0;
    int r = 99;
    int mid;

    while ((l <= r) && (flag != true)) {
        mid = (l + r) / 2;
        if (arr[mid] == key)
            flag = true;
        if (arr[mid] > key)
            r = mid - 1;
        else
            l = mid + 1;
    }

    if (flag)
        cout << "������ �������� " << key << " � ������� �����: " << mid << endl;
    else
        cout << "��� ������ �����";

    int cou = 0, a;
    cout << "������� ����� a ";
    cin >> a;
    for (int i = 0; i < 100; i++)
        if (arr[i] < a)
            cou += 1;
    cout << "���������� ��������� ������ ����� a " << cou << endl;

    int coutn = 0, b;
    cout << "������� ����� a ";
    cin >> b;
    for (int i = 0; i < 100; i++)
        if (arr[i] > b)
            coutn += 1;
    cout << "���������� ��������� ������ ����� b " << coutn << endl;

    int el1, el2; {
        cout << "������� ������ �������� ������� 1 ";
        cin >> el1;
        cout << endl << "������� ������ �������� ������� 2 ";
        cin >> el2;
        {
            auto start = chrono::high_resolution_clock::now();
            swap(arr[el1], arr[el2]);
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<float> duration = end - start;
            cout << "����� ������ = " << duration.count() * 1000 << "ms." << endl;
        }
        cout << endl << arr[el1] << " " << arr[el2] << endl;
    }
}