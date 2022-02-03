#include <iostream>

void  stani_vulshebno_izrechenie(char da_kriptirash[], int mesto, int vulshebno_chislo);

int main() {
    int num;
    std::cout << "Enter number which you want to move back";
    std::cin >> num;
    int array_size;
    std::cout << "Enter array size";
    std::cin >> array_size;
    char* string = new char[array_size];
    //!!!! Няма cin>>string;
    //!!!! num%=26; ако ти въведат 100
    stani_vulshebno_izrechenie(string, array_size, num);
    return 0;
}

void  stani_vulshebno_izrechenie(char da_kriptirash[], int mesto, int vulshebno_chislo) {

    if (*da_kriptirash == '\0') return;
    *da_kriptirash -= vulshebno_chislo;
    if (*da_kriptirash < 'A') {
        *da_kriptirash += 26;//A - 2 = 63 + 26
    }
    if (*da_kriptirash > 'Z') {
        *da_kriptirash -= 26;//
    }
    stani_vulshebno_izrechenie(da_kriptirash + 1, mesto, vulshebno_chislo);
}

// number = 121



// Цезаровият шифър е един от най-простите и най-стари методи за криптиране на съобщения.
// Първото му известно използване е от Юлий Цезар по време на кампаниите му в Галия, откъдето идва и неговото име.
// Идеята на Цезаровия шифър е проста: вземаме съобщението, което искаме да шифроваме,
// и заместваме всяка от буквите в него с буквата, отместена с определен брой позиции в азбуката.
// Ако буквата трябва да се промени с повече позиции отколкото е азбуката, се започва от началото на азбуката.
// Напишете рекурсивна функция,
// която по даден шифър и число, определящо с колко позиции е преместена всяка буква, разшифрова текста.

// Вход:
// BCTKC
// 2
// Изход:
// ZARIA

// Вход:
// YWFNHMTJRSTLTLTYNS
// 5
// Изход:
// TRAICHOEMNOGOGOTIN
