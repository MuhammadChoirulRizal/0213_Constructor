#include <iostream>
#include <string>
using namespace std;

class Mahasiswa; // Forward declaration

class Dosen {
private:
    string nama;
    string NIDN;
    string pangkat;
    float gaji;

    friend class Staff;
    friend float lihatGajiStaff(class Staff* s); 
public:
    Dosen(string n, string idn, string p, float g)
        : nama(n), NIDN(idn), pangkat(p), gaji(g) {}

    void beriNilai(Mahasiswa* m, float nilai); 
    void tampil();
};

class Mahasiswa {
private:
    string nama;
    string NIM;
    float nilai;

    friend class Dosen;
public:
    Mahasiswa(string n, string nim) : nama(n), NIM(nim), nilai(0) {}

    void tampil() {
        cout << "Mahasiswa: " << nama << ", NIM: " << NIM << ", Nilai: " << nilai << endl;
    }
};

void Dosen::beriNilai(Mahasiswa* m, float nilai) {
    m->nilai = nilai; // Akses nilai karena Dosen adalah friend
}

void Dosen::tampil() {
    cout << "Dosen: " << nama << ", NIDN: " << NIDN << ", Pangkat: " << pangkat << ", Gaji: " << gaji << endl;
}

class Staff {
private:
    string nama;
    string idStaff;
    float gaji;

public:
    Staff(string n, string id, float g) : nama(n), idStaff(id), gaji(g) {}

    void ubahPangkat(Dosen* d, string pangkatBaru) {
        d->pangkat = pangkatBaru;
    }

    friend float lihatGajiStaff(Staff* s);
};

float lihatGajiStaff(Staff* s) {
    return s->gaji;
}

int main() {
    Mahasiswa m1("Rizal","2022200");
    Dosen d1("Dr. Saifu","88899","Mudir", 100000);
    Staff s1("Bu haya","S01",5000000);

    d1.beriNilai(&m1, 85);
    s1.ubahPangkat(&d1, "Guru Besar");

    m1.tampil();
    d1.tampil();

    cout << "Gaji staff dilihat oleh universitas: " << lihatGajiStaff(&s1) << endl;

    return 0;
}