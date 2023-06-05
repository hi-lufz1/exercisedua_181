#include <iostream>
#include <vector>
using namespace std;

class Pengarang;
class Penerbit {
public:
    string namaPenerbit;
    vector<Pengarang*> daftar_pengarang;

    Penerbit(string Pnama) : namaPenerbit(Pnama) {
    }
    void tambahpengarang(Pengarang*);
    void displaypengarang();

    string getNamaPenerbit() {
        return namaPenerbit;
    }
};
   
class Buku;
class Pengarang{
public:
    string namaPengarang;
    vector<Penerbit*> daftar_penerbit;
    vector<Buku*> daftar_buku;

    Pengarang(string Pnama) : namaPengarang(Pnama) {
    }

    void tambahPenerbit(Penerbit*);
    void tambahbuku(Buku*);

    void displayDaftarPenerbit();

    void displaydaftarbuku();

    string getNamaPengarang() {
        return namaPengarang;
    }


};
class Buku {
public:
    string judulBuku;
    

    Buku(string judul) : judulBuku(judul) {
       
    }
    ~Buku() {
        
    }
    void tambahpengarangg(Pengarang*);
    void displayInfoBuku();

    string getjudulBuku () {
        return judulBuku;
    }
};

void Penerbit::displaypengarang()
{
    cout << "Daftar pengarang pada penerbit \"" << namaPenerbit << "\":" << endl;
    for (Pengarang* pengarang : daftar_pengarang) {
        cout << pengarang->getNamaPengarang() << endl;
    }
}

void Penerbit::tambahpengarang(Pengarang* pengarang) {
    daftar_pengarang.push_back(pengarang);
}

void Pengarang::tambahPenerbit(Penerbit* penerbit) {
    daftar_penerbit.push_back(penerbit);
}

void Pengarang::displayDaftarPenerbit() {
    cout << "Daftar penerbit yang diikuti \"" << namaPengarang << "\": " << endl;
    for (Penerbit* penerbit : daftar_penerbit) {
        cout << penerbit->getNamaPenerbit() << " ";
        cout << endl;
    }
    cout << endl;
}


void Pengarang::tambahbuku(Buku* buku) {
    daftar_buku.push_back(buku);


}

void Pengarang::displaydaftarbuku() {
    cout << "Daftar buku yang dikarang \"" << namaPengarang << "\": " << endl;
    for (Buku* buku : daftar_buku) {
        cout << buku->getjudulBuku() << " ";
        cout << endl;
    }
    cout << endl;
}



int main() {
    Penerbit penerbit1("Gama Press");
    Penerbit penerbit2("Intan Pariwara");

    Pengarang pengarang1("Joko");
    Pengarang pengarang2("Lia");
    Pengarang pengarang3("Giga");
    Pengarang pengarang4("Asroni");

    Buku buku1("Fisika");
    Buku buku2("Algoritma");
    Buku buku3("Basisdata");
    Buku buku4("Dasar Pemrograman");
    Buku buku5("Matematika");
    Buku buku6("Multimedia 1");

    penerbit1.tambahpengarang(&pengarang1);
    penerbit1.tambahpengarang(&pengarang2);
    penerbit1.tambahpengarang(&pengarang3);
    penerbit2.tambahpengarang(&pengarang4);
    penerbit2.tambahpengarang(&pengarang3);

    pengarang1.tambahPenerbit(&penerbit1);
    pengarang1.tambahPenerbit(&penerbit2);
    pengarang2.tambahPenerbit(&penerbit1);
    pengarang3.tambahPenerbit(&penerbit1);
    pengarang3.tambahPenerbit(&penerbit2);
    pengarang4.tambahPenerbit(&penerbit2);

    pengarang1.tambahbuku(&buku1);
    pengarang1.tambahbuku(&buku2);
    pengarang2.tambahbuku(&buku3);
    pengarang4.tambahbuku(&buku4);
    pengarang3.tambahbuku(&buku5);
    pengarang3.tambahbuku(&buku6);

    cout << endl;

    penerbit1.displaypengarang();
    cout << endl;
    penerbit2.displaypengarang();
    cout << endl;

    pengarang3.displayDaftarPenerbit();
    
    pengarang1.displaydaftarbuku();
    pengarang2.displaydaftarbuku();
    pengarang4.displaydaftarbuku();
    pengarang3.displaydaftarbuku();
    
   
    
    return 0;
}


