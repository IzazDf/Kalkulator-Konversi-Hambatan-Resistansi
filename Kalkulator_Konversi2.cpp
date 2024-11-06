#include <iostream>
#include <cmath>
#include "windows.h"

using namespace std;

void myprint(const wchar_t* str){
        HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
        WriteConsoleW(h, str, wcslen(str), NULL, NULL);
    }

int main (){
    string satuan[]={"Tera ohm", "Giga ohm", "Mega ohm", "kilo ohm", "ohm", "mili ohm", "mikro ohm", "nano ohm", "pico ohm"};
    wstring st [] = {L"TΩ", L"GΩ", L"MΩ", L"kΩ", L"Ω", L"mΩ", L"μΩ", L"nΩ", L"pΩ"};
    int x = 0, y = 0;
    int awal, akhir;
    long double nilai, hasil;
    char pilihan;

    do {

        cout << "Kalkulator konversi satuan Hambatan/Resistansi" << endl;
        cout << "----------------------------------------------" << endl;
        cout << "Pilihan satuan" << endl;
        cout << "1. Tera ohm "; myprint(L"(TΩ)"); cout << endl;
        cout << "2. Giga ohm "; myprint(L"(GΩ)"); cout << endl;
        cout << "3. Mega ohm "; myprint(L"(MΩ)"); cout << endl;
        cout << "4. kilo ohm "; myprint(L"(kΩ)"); cout << endl; 
        cout << "5. ohm "; myprint(L"(Ω)"); cout << endl;
        cout << "6. mili ohm "; myprint(L"(mΩ)"); cout << endl;
        cout << "7. mikro ohm "; myprint(L"(μΩ)"); cout << endl;
        cout << "8. nano ohm "; myprint(L"(nΩ)"); cout << endl;
        cout << "9. pico ohm "; myprint(L"(pΩ)"); cout << endl;

        cout << endl;

        do {
            cout << "Satuan awal (1-9) : ";  cin >> awal;
            if (awal < 1 || awal > 9) {
                cout << "Input tidak valid" << endl;
            } 
        } while (awal < 1 || awal > 9);

        do {
            cout << "Satuan akhir (1-9): ";  cin >> akhir;
            if (akhir < 1 || akhir > 9) {
                cout << "Input tidak valid" << endl;
            }
        } while (akhir < 1 || akhir > 9);

        do {
            cout << "Nilai yang ingin dikonversi : "; cin >> nilai;
            if (nilai <0){
                cout << "Nilai tidak valid" << endl;
            }

        } while (nilai < 0);

            //hasil = 1 supaya perhitungan tidak bertambah setiap iterasi
            hasil = 1;
            long double hasilohm = nilai;

            x = awal;
            y = akhir;

            //fungsi untuk mengubah nilai dalam satuan yang dipilih ke satuan ohm
            if (x > 5){
                int z = x - 5;
                hasilohm /= pow(1000, z);
            } else if (x < 5){
                int z = 5 - x;
                hasilohm *= pow(1000, z);
            }
            
            //fungsi untuk mengubah nilai dalam satuan ohm ke satuan akhir yang dipilih
            if (y > 5){
                int z = y - 5;
                hasil = hasilohm * pow(1000, z);
            } else if (y < 5){
                int z = 5 - y;
                hasil = hasilohm / pow(1000, z);
            } else {
                hasil = hasilohm;
            }
        
            //fungsi untuk mengubah nilai dalam satuan ohm ke mega ohm
            long double hasilmega = hasilohm / pow(1000, 2);
            //fungsi untuk mengubah nilai dalam satuan ohm ke mikro ohm 
            long double hasilmikro = hasilohm * pow(1000, 2);

        cout << endl;
        cout << "hasil konversi" << endl;
        cout << nilai << " " << satuan[awal - 1] << " "; wcout << "("; myprint(st[awal-1].c_str()); wcout << ")"; cout << " = " << hasil << " " << satuan[akhir - 1] << " "; wcout << "("; myprint(st[akhir-1].c_str()); wcout << ")" << endl;
        cout << nilai << " " << satuan[awal - 1] << " "; wcout << "("; myprint(st[awal-1].c_str()); wcout << ")"; cout << " = " << hasilmega << " " << satuan[2] << " "; wcout << "("; myprint(st[2].c_str()); wcout << ")" << endl;
        cout << nilai << " " << satuan[awal - 1] << " "; wcout << "("; myprint(st[awal-1].c_str()); wcout << ")"; cout << " = " << hasilohm << " " << satuan[4] << " "; wcout << "("; myprint(st[4].c_str()); wcout << ")" << endl;
        cout << nilai << " " << satuan[awal - 1] << " "; wcout << "("; myprint(st[awal-1].c_str()); wcout << ")"; cout << " = " << hasilmikro << " " << satuan[6] << " "; wcout << "("; myprint(st[6].c_str()); wcout << ")" << endl;
        
        cout << endl;

        cout << "Ingin kembali melakukan konversi? (y/n): ";
        cin >> pilihan;

        //agar tampilan sebelumnya dihapus saat melakukan perulangan
        system("CLS");

    } while (pilihan == 'y' || pilihan == 'Y');

        cout << "Program selesai" << endl;
        return 0;
    
}