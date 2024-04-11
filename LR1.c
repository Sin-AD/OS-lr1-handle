#include <windows.h>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <locale.h>
#include <iostream>
int main() {
    HANDLE hin, hout, file;
    DWORD actlen = 0, tlen = 0;
    hout = GetStdHandle(STD_OUTPUT_HANDLE);
    hin = GetStdHandle(STD_INPUT_HANDLE);
    char text[128];
    char butt[1];
    setlocale(0, ".1251");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    printf("Значение handle ввод: %i\nЗначение handle вывод: %i\n", hin, hout);
 
    WriteFile(hout, "Введите текст: ", 15, NULL, NULL);
    ReadFile(hin, text, 128, &actlen, NULL);

    WriteFile(hout, "Введите 1 чтобы записать текст в файл, или 2 - вывести на консоль:\n ", 67, NULL, NULL);
    ReadFile(hin, butt, 1, &tlen, NULL);
    uf (butt[0] == '1') {
        file = CreateFile(L"file.txt", GENERIC_WRITE, 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
        WriteFile(file, text, actlen, NULL, NULL);
        WriteFile(hout, "Ваш текст записан в файл", 26, NULL, NULL);
        ReadFile(file, text, 128, &actlen, NULL);
        WriteFile(hout, text, 10, NULL, NULL);
    }
else {
        WriteFile(hout, "Вы ввели: ", 10, NULL, NULL);
        WriteFile(hout, text, actlen, NULL, NULL);
       }
}
