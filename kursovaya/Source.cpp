#include <iostream>
#include "Labs.h"

using namespace std;

int main()
{
    setlocale(0, "");
    char input;

    Menu: {
        system("cls");
        cout << "������� ����� ������������ ������, ������� �� ������ ���������:\n"
            "1. ���� ������ � �� ���������� ������������� � ������.\n"
            "2. ���������� ����������� �������.\n"
            "3. ��������� ����������� �������. ���������.\n"
            "4. ��������� ������ ��� ������� ��������.\n"
            "5. ������� ���������.\n";
    }
    cin >> input;

    switch (input) {
    case '1': {
        system("cls");
        Lab1();
        system("pause");
        goto Menu;
    }
    case '2': {
        system("cls");
        Lab2();
        system("pause");
        goto Menu;
    }
    case '3': {
        system("cls");
        Lab3();
        system("pause");
        goto Menu;
    }
    case '4': {
        system("cls");
        Lab4();
        system("pause");
        goto Menu;
    }
    default: {
        goto Menu;
    }
    case '5': {
        exit;
    }
    }
}