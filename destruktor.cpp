#include <iostream>
using namespace std;

class angka
{
private:
    int *arr;
    int panjang;

public:
    angka(int); // Constructor
    ~angka();   // Destructor
    void cetakData();
    void isiData();
};
// Definisi member Function
angka::angka(int i)
{ // Constructor
    panjang = i;
    arr = new int[i];
    isiData();
}

angka::~angka()
{ // Destructor
    cout << endl;
    cetakData();
    delete[] arr;
    cout << "Alamat Array Sudah Dilepaskan" << endl;
}

void angka::cetakData()
{
    for (int i = 1; i < panjang; i++)
    {
        cout << "  = " << arr[i] << endl;
    }
};
