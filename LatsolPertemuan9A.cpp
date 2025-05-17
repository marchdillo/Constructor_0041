#include <iostream>
#include <string>
using namespace std;

class Dosen; // Forward declaration
class Staff;

class Mahasiswa
{
private:
    string nama;
    string NIM;
    float nilai;

public:
    Mahasiswa(string n, string nim, float nil) : nama(n), NIM(nim), nilai(nil) {}

    void tampilkanInfo()
    {
        cout << "Mahasiswa: " << nama << ", NIM: " << NIM << ", Nilai: " << nilai << endl;
    }

    friend class Dosen; // Dosen dapat mengakses nilai
};

class Dosen
{
private:
    string nama;
    string NIDN;
    string pangkat;
    float gaji;

public:
    Dosen(string n, string nidn, string p, float g) : nama(n), NIDN(nidn), pangkat(p), gaji(g) {}

    void beriNilai(Mahasiswa *m, float nilaiBaru)
    {
        m->nilai = nilaiBaru;
    }

    void tampilkanInfo()
    {
        cout << "Dosen: " << nama << ", NIDN: " << NIDN << ", Pangkat: " << pangkat << endl;
    }

    friend void ubahPangkat(Dosen *d, string pangkatBaru); // Staff bisa ubah pangkat
    friend float lihatGajiDosen(const Dosen *d);           // Universitas bisa lihat gaji
};

class Staff
{
private:
    string nama;
    string IDStaff;
    float gaji;

public:
    Staff(string n, string id, float g) : nama(n), IDStaff(id), gaji(g) {}

    void tampilkanInfo()
    {
        cout << "Staff: " << nama << ", ID: " << IDStaff << endl;
    }

    friend void ubahPangkat(Dosen *d, string pangkatBaru);
    friend float lihatGajiStaff(const Staff *s); // hanya Universitas bisa akses
};

// Friend Function: di luar class
void ubahPangkat(Dosen *d, string pangkatBaru)
{
    d->pangkat = pangkatBaru;
}

float lihatGajiDosen(const Dosen *d)
{
    return d->gaji;
}

float lihatGajiStaff(const Staff *s)
{
    return s->gaji;
}

int main()
{
    Mahasiswa mhs("Rina", "2301103", 70); // NIM ganjil
    Dosen dosen("Dr. Budi", "001122", "Lektor", 9000000);
    Staff staff("Ani", "ST123", 5000000);

    dosen.beriNilai(&mhs, 85);         // Dosen mengubah nilai Mahasiswa
    ubahPangkat(&dosen, "Guru Besar"); // Staff mengubah pangkat dosen

    mhs.tampilkanInfo();
    dosen.tampilkanInfo();
    staff.tampilkanInfo();

    cout << "Gaji Dosen dilihat oleh Universitas: " << lihatGajiDosen(&dosen) << endl;
    cout << "Gaji Staff dilihat oleh Universitas: " << lihatGajiStaff(&staff) << endl;

    return 0;
}