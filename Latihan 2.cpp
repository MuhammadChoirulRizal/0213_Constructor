#include <iostream>
#include <string>
using namespace std;

// Deklarasi awal
class Dosen;
class Staff;
class Universitas;

class Mahasiswa {
private:
    string nama;
    string NIM;
    float nilai;

public:
    Mahasiswa(string nama, string NIM) : nama(nama), NIM(NIM), nilai(0) {}

    void tampilkan() {
        cout << "Mahasiswa: " << nama << " | NIM: " << NIM << " | Nilai: " << nilai << endl;
    }

    friend class Dosen; // Dosen dapat mengakses nilai
};

class Dosen {
private:
    string nama;
    string NIDN;
    string pangkat;
    float gaji;

public:
    Dosen(string nama, string NIDN, string pangkat, float gaji)
        : nama(nama), NIDN(NIDN), pangkat(pangkat), gaji(gaji) {}

    void beriNilai(Mahasiswa* m, float nilai) {
        m->nilai = nilai;
    }

    friend class Staff; // Staff bisa ubah pangkat dosen
    friend float lihatGajiDosen(Dosen* d); // friend function akses gaji
};

float lihatGajiDosen(Dosen* d) {
    return d->gaji;
}

class Staff {
private:
    string nama;
    string idStaff;
    float gaji;

public:
    Staff(string nama, string id, float gaji)
        : nama(nama), idStaff(id), gaji(gaji) {}

    void ubahPangkat(Dosen* d, string pangkatBaru) {
        d->pangkat = pangkatBaru;
    }

    friend float lihatGajiStaff(Staff* s); // friend function akses gaji
};

float lihatGajiStaff(Staff* s) {
    return s->gaji;
}

class Universitas {
public:
    void tampilkanGajiDosen(Dosen* d) {
        cout << "Gaji Dosen: " << lihatGajiDosen(d) << endl;
    }

    void tampilkanGajiStaff(Staff* s) {
        cout << "Gaji Staff: " << lihatGajiStaff(s) << endl;
    }
};

// ===============================
// Main Program
// ===============================
int main() {
    Mahasiswa* m1 = new Mahasiswa("Andi", "123456");
    Dosen* d1 = new Dosen("Pak Budi", "888999", "Lektor", 12000000);
    Staff* s1 = new Staff("Bu Sari", "STF001", 7000000);
    Universitas* u1 = new Universitas();

    d1->beriNilai(m1, 85.5);
    m1->tampilkan();

    s1->ubahPangkat(d1, "Guru Besar");
    u1->tampilkanGajiDosen(d1);
    u1->tampilkanGajiStaff(s1);

    // Bersihkan memori
    delete m1;
    delete d1;
    delete s1;
    delete u1;

    return 0;
}
