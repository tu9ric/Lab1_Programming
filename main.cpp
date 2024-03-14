#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdint>

/**
 * @brief перевод числа из одной системы счисления в другую
 * 
 * @param a  - исходное число
 * @param base - система счисления в которую переводим исходное число 
 * @return std::string - представление числа a в base системе счисления
 */
std::string binhex(int a, const int base) {
    const char l[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
    std::string res = "00000000";
    for (int i = 7; i >= 0; i--) {
        res[i] = l[a % base];
        a /= base;
    }
    return res;
}

/**
 * @brief функция перевода числа в другую систему счисления (по значению)
 * 
 * @param a  - исходное число
 * @param base - система счисления в которую переводим исходное число 
 * @return std::string - представление числа a в base системе счисления
 */
std::string binhexbyzn(int a, int base) {
    std::string res = "";
    res = binhex(a, base) + res;
    return res;
}

/**
 * @brief функция перевода числа в другую систему счисления (по ссылке)
 * 
 * @param a  - исходное число
 * @param base - система счисления в которую переводим исходное число 
 * @param res - переменная для ссылки на переменную с результатом 
 * @return std::string - представление числа a в base системе счисления


 */
std::string binhexbysl(int a, int base, string& res) {
    res = "";
    res = binhex(a, base) + res;
    return res;
}
/**
 * @brief функция перевода число в другую систему счисления (по указателю)
 * 
 * @param a  - исходное число
 * @param base - система счисления в которую переводим исходное число 
 * @param res - переменная для указателя на переменную с результатом 
 * @return std::string - представление числа a в base системе счисления
 */
std::string binhexbyuk(int a, int base, string* res) {
    *res = "";
    *res = binhex(a, base) + *res;
    return *res;
}


/**
 * @brief с помощью арифметики побайтово считываем переменную и выводим на экран её в битовом виде
 * 
 * @param a - исходное число
 * @param len - длина битового представления числа
 * @param base - система счисления в которую переводим число
 */

void byte_1(uint8_t* a, int len, int base){
    for(int i = len - 1; i >= 0; i--){
        std::cout << binhex((uint8_t) a[i], base) << "|";
    }
    std::cout << "\n";
}

/**
 * @brief перевод числа в другую систему счисления через рекурсию (4 вариант)
 * 
 * @param num - исходное число
 * @param base - система счисления в которую нужно перевести число
 * @return std::string -  представление числа a в base системе счисления
 */
std::string converttobase(int num, int base) {
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
    
    int a, base;
    std::cout << "Введите основание системы счисления: ";
    std::cin >> base;

    std::cout << "Введите число в десятичной системе счисления: ";
    std::cin >> a;

    // по значению
    std::string res_1 = binhexbyzn(a, base);
    std::cout << "Результат по значению: " << res_1 << std::endl;

    //по ссылке
    std::string res_2;
    res_2 = binhexbysl(a, base, res_2);
    std::cout << "Результат по ссылке: " << res_2 << std::endl;

    //через указатель
    std::string res_3;
    res_3 = binhexbyuk(a, base, &res_3);
    std::cout << "Результат через указатель: " << res_3 << std::endl;
    
    

    // TASK 2
    /*
    float b;
    int a, base;
    std::cout << "Введите целочисленное число: ";
    std::cin >> a;
    std::cout << "Введите систему счисления, в которой нужно вывести число: ";
    std::cin >> base;
    byte_1((uint8_t*) (&a), sizeof(a), base);
    std::cout << "Введите число с плавающей точкой: ";
    std::cin >> b;
    std::cout << "Введите систему счисления, в которой нужно вывести число: ";
    std::cin >> base;
    byte_1((uint8_t*)(&b), sizeof(b), base);
    */
    
    // TASK 3
    /*
    int a, base;
    std::cout << "Введите число a: ";
    std::cin >> a;

    std::cout << "Введите основание системы счисления: ";
    std::cin >> base;

    std::string res = converttobase(a, base);
    std::cout << "Число до перевода: " << a << std::endl;
    std::cout << "Число после перевода: " << res << std::endl;
    */
    return 0;
}
