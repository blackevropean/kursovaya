#include "Labs.h"
#include <iostream>
#include <fstream> 
#include <string>
using namespace std;

string text;

void probel(string txt) {
    for (int i = 0; i < txt.size(); i++) {
        if (txt[i] == ' ' && txt[i + 1] == ' ')
            while (txt[i + 1] == ' ')
                txt.erase((i + 1), 1);
    }
    text = txt;
}

void znaki(string txt) {
    for (int i = 0; i <= txt.size(); i++) {
        if ((txt[i] == '.' || txt[i] == ',' || txt[i] == ';' || txt[i] == ':' || txt[i] == '!' || txt[i] == '?') && (txt[i + 1] == '.' || txt[i + 1] == ',' || txt[i + 1] == ';' || txt[i + 1] == ':' || txt[i + 1] == '!' || txt[i + 1] == '?'))
            if (txt[i] == '.' && txt[i + 1] == '.' && txt[i + 2] == '.' && txt[i + 3] == ' ')
                i += 3;
            else {
                while (txt[i + 1] == '.' || txt[i + 1] == ',' || txt[i + 1] == ';' || txt[i + 1] == ':' || txt[i + 1] == '!' || txt[i + 1] == '?')
                    txt.erase((i + 1), 1);
            }
    }
    text = txt;
}

void registr(string txt) {
    for (int i = 0; i < txt.size(); i++) {
        if (txt[i] == ' ')
            i += 2;
        txt[i] = tolower(txt[i]);
    }
    text = txt;
}

void UpFirst(string txt) {
    txt[0] = toupper(txt[0]);
    for (int i = 0; i < txt.size(); i++) {
        if (txt[i] == ' ')
            txt[i + 1] = toupper(txt[i + 1]);
    }
    text = txt;
}

void main()
{
    setlocale(0, "");
    cout << "Запишите текст\n";
    getline(cin, text);
    cout << "1) Исходная строка: " << text << "\n";

    {
        probel(text);
        znaki(text);
        registr(text);

        cout << "2) Отредактированная строка: " << text << "\n";
    }

    {
        cout << "3) Cтрока в обратном порядке: ";
        int a = 0;
        text += " ";

        for (int i = text.length(); i >= 0; i--) {
            if (text[i] == ' ') {
                for (int k = i + 1; k <= (i + a); k++) {
                    cout << text[k];
                }
                a = 0;
            }
            a++;
        }
        for (int i = 0; i < text.length(); i++) {
            if (text[i] == ' ') break;
            cout << text[i];
        }
    }

    {
        UpFirst(text);

        cout << "\n4) Все слова с заглавной буквы: " << text << "\n";
    }
}