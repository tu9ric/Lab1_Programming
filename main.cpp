#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdint>

using namespace std;

//пишем функцию для перевода числа в другую систему счисления
string binhex(int a, const int base) {
    const char l[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
    string res = "00000000";
    for (int i = 7; i >= 0; i--) {
        res[i] = l[a % base];
        a /= base;
    }
    return res;
}

//функция перевода числа в другую систему счисления (по значению)
string binhexbyzn(int a, int base) {
    string res = "";
    res = binhex(a, base) + res;
    return res;
}

// функция перевода числа в другую систему счисления (по ссылке)
string binhexbysl(int a, int base, string& res) {
    res = "";
    res = binhex(a, base) + res;
    return res;
}
//функция перевода число в другую систему счисления (по указателю)
string binhexbyuk(int a, int base, string* res) {
    *res = "";
    *res = binhex(a, base) + *res;
    return *res;
}


// с помощью арифметики побайтово считываем переменную

void byte_1(uint8_t* a, int len, int base){
    for(int i = len - 1; i >= 0; i--){
        cout << binhex((uint8_t) a[i], base) << "|";
    }
    cout << "\n";
}

//перевод числа в другую систему счисления через рекурсию (4 вариант)
string converttobase(int num, int base) {
    const char l[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
    if (num < base) {
        return string(1, l[num]);
    }
    else {
        return converttobase(num / base, base) + l[num % base];
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");

    // TASK 1
    /*
    int a, base;
    cout << "Введите основание системы счисления: ";
    cin >> base;

    cout << "Введите число в десятичной системе счисления: ";
    cin >> a;

    // по значению
    string res_1 = binhexbyzn(a, base);
    cout << "Результат по значению: " << res_1 << endl;

    //по ссылке
    string res_2;
    res_2 = binhexbysl(a, base, res_2);
    cout << "Результат по ссылке: " << res_2 << endl;

    //через указатель
    string res_3;
    res_3 = binhexbyuk(a, base, &res_3);
    cout << "Результат через указатель: " << res_3 << endl;
    */
    

    // TASK 2
    /*
    float b;
    int a, base;
    cout << "Введите целочисленное число: ";
    cin >> a;
    cout << "Введите систему счисления, в которой нужно вывести число: ";
    cin >> base;
    byte_1((uint8_t*) (&a), sizeof(a), base);
    cout << "Введите число с плавающей точкой: ";
    cin >> b;
    cout << "Введите систему счисления, в которой нужно вывести число: ";
    cin >> base;
    byte_1((uint8_t*)(&b), sizeof(b), base);
    */
    
    // TASK 3
    
    int a, base;
    cout << "Введите число a: ";
    cin >> a;

    cout << "Введите основание системы счисления: ";
    cin >> base;

    string res = converttobase(a, base);
    cout << "Число до перевода: " << a << endl;
    cout << "Число после перевода: " << res << endl;
    
    return 0;
}
