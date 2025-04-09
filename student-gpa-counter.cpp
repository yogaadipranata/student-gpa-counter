#include <conio.h>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main(){

    cout << "=====================================================================================\n";
    cout << "\t\t\t Program Menghitung IPK Mahasiswa\n";
    cout << "=====================================================================================\n";

    int jumlah_matkul;
    float total_mutu, total_sks;
    string huruf_mutu, keterangan;

    struct mahasiswa{
        float ipk = 0;
    };

    struct matakuliah{
        string nama_matkul;
        int sks;
        float nilai, ubah_nilai, nilai_mutu;
    };

    mahasiswa mhs;
    matakuliah matkul;

    cout << "Masukkan Jumlah Mata Kuliah yang Akan Dihitung     : ";
    cin >> jumlah_matkul;
    cout << "**********\n";

    for (int a = 0; a < jumlah_matkul; a++) {
        cout << "   " << a + 1 << ". ";
        cout << "Masukkan Nama Mata Kuliah                    : ";
        getline(cin >> ws, matkul.nama_matkul);
        cout << "      Masukkan Jumlah SKS                          : ";
        cin >> matkul.sks;
        cout << "      Masukkan Nilai Mata Kuliah (Rentang 1-100)   : ";
        cin >> matkul.nilai;
        matkul.ubah_nilai = (matkul.nilai/100)* 4;
        cout <<  setprecision(3) << "      Nilai dalam Skala 4                          : " << matkul.ubah_nilai << endl;
        matkul.nilai_mutu = matkul.ubah_nilai * matkul.sks;
        cout <<  setprecision(3) << "      Nilai Mutu                                   : " << matkul.nilai_mutu << endl;
        cout << "-------------------------------------------------------------------------------------\n";

        total_sks += matkul.sks;
        total_mutu += matkul.nilai_mutu;
        }
    cout << "=====================================================================================\n";
    cout << "\t\t\t\tTranskrip Nilai\n";
    cout << "=====================================================================================\n";

    cout << "Total SKS          : " << total_sks << endl;
    cout <<  setprecision(3) << "Total Nilai Mutu   : " << total_mutu <<endl;
    mhs.ipk += total_mutu/total_sks;
    cout <<  setprecision(3) << "IPK                : " << mhs.ipk << endl;
    if (mhs.ipk >= 3.2){
        huruf_mutu = "A";
        keterangan = "Istimewa";
    } else if (mhs.ipk >= 2.84){
        huruf_mutu = "B+";
        keterangan = "Sangat Baik";
    } else if (mhs.ipk >= 2.6){
        huruf_mutu = "B";
        keterangan = "Baik";
    } else if (mhs.ipk >= 2.4){
        huruf_mutu = "C+";
        keterangan = "Cukup Baik";
    } else if (mhs.ipk >= 2.2){
        huruf_mutu = "C";
        keterangan = "Cukup";
    } else if (mhs.ipk >= 2.0){
        huruf_mutu = "D+";
        keterangan = "Kurang Cukup";
    } else if (mhs.ipk <= 1.6){
        huruf_mutu = "D";
        keterangan = "Kurang";
    } else if (mhs.ipk >= 0){
        huruf_mutu = "E";
        keterangan = "Sangat Kurang";
    }
    cout << "Nilai Huruf        : " << huruf_mutu << endl;
    cout << "Keterangan         : " << keterangan << endl;

    cin.get();
    return 0;
        }
