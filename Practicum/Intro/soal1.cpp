#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

class mahasiswa
{
private:
    float tugas, ets, uas, nilaiAkhir;
public:
    void getNilai(float a, float b, float c){
        tugas = a;
        ets = b; 
        uas = c;
    }
    float nilaiAngka(){
        nilaiAkhir = ((30*tugas/100) + (35*ets/100) + (35*uas/100));
        return nilaiAkhir;
    }
    char nilaiHuruf(){
        if (nilaiAkhir >= 80){
            return 'A';
        }
        if (nilaiAkhir >= 70){
            return 'B';
        }
        if (nilaiAkhir >= 60){
            return 'C';
        }
        if (nilaiAkhir >= 50){
            return 'D';
        }
        else {
            return 'E';
        }
    }

};

int main(){
    int n;
    float a, b, c;
    std::cin >> n;
    mahasiswa mahasiswaArr[n];
    for (int i = 0; i < n; i++){
        std::cin >> a >> b >> c;
        mahasiswaArr[i].getNilai(a, b, c);
    }

    for (int i = 0; i < n; i++){
        std::cout << "Nilai Akhir: " << mahasiswaArr[i].nilaiAngka() << " | Grade: " << mahasiswaArr[i].nilaiHuruf() << std::endl;
    }

    return 0;
}