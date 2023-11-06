#include <iostream>
#include <string>
#include <array>
#include <chrono>
#include <thread>
using namespace std;

const int KAT_SAYISI = 5;
const int PARK_YERI_SAYISI = 10;

array<array<string, PARK_YERI_SAYISI>, KAT_SAYISI> aracListesi;

void girisYap() {  // Giris fonksiyonu , kullanıcı adi ve sifremiz "Admin" olarak belirledik ikisi de dogru mu onu kontrol ediyoruz , 3 haktan sonra program kendini kapatiyor
    int girisHakki = 3;
    string kullaniciAdi, sifre;

    while (girisHakki > 0) {
        cout << "Kullanici Adi: ";
        cin >> kullaniciAdi;
        cout << "Sifre: ";
        cin >> sifre;

        if (kullaniciAdi == "Admin" && sifre == "Admin") {
            cout << "Hos geldiniz, " << kullaniciAdi << endl;
            return;
        }
        else {
            girisHakki--;
            cout << "Hatali kullanici adi veya sifre. Kalan giris hakki: " << girisHakki << endl;
            if (girisHakki == 0) {
                this_thread::sleep_for(chrono::seconds(1));
                system("CLS");
                cout << "Cok fazla yanlıs giris yaptiniz. Program kapatiliyor." << endl;
                return;
            }
        }
    }
}

void listele() { // Burada iç içe for ile bütün "kat" ve bütün "parkYeri" nde bulunan plakalari (Park halindeki araclari) getiren fonksiyon çalisir
    cout << "Park Halindeki Araclar" << endl;
    for (int kat = 0; kat < KAT_SAYISI; ++kat) {
        for (int parkYeri = 0; parkYeri < PARK_YERI_SAYISI; ++parkYeri) {
            if (!aracListesi[kat][parkYeri].empty()) {
                cout << "Kat " << kat + 1 << ". Numarali Park Yerinde " << parkYeri + 1 << ". Numarali Park Alaninda " << aracListesi[kat][parkYeri] << " Park Halinde." << endl;
            }
        }
    }
}

void aracCikisi() {
    // Burada araç çıkışı işlemleri yapılacak
    
}

void yeniAracGirisi() { // Park etmek icin kat numarasi (5 katli bir otopark olarak ayarladik) ve park yeri(10 park yeri olarak ayarladik) ve bunlari listeye koyduk
    int secilenKat, secilenParkYeri;
    cout << "Kat numarasini girin (1-5): ";
    cin >> secilenKat;

    if (secilenKat < 1 || secilenKat > KAT_SAYISI) {
        cout << "Gecersiz kat numarasi!" << endl;
        return;
    }

    cout << "Park yeri numarasini girin (1-10): ";
    cin >> secilenParkYeri;

    if (secilenParkYeri < 1 || secilenParkYeri > PARK_YERI_SAYISI) {
        cout << "Gecersiz park yeri numarasi!" << endl;
        return;
    }

    if (!aracListesi[secilenKat - 1][secilenParkYeri - 1].empty()) {
        cout << "Secilen park yeri dolu!" << endl;
    }
    else {
        string plaka;
        cout << "Plaka: ";
        cin >> plaka;
        

        aracListesi[secilenKat - 1][secilenParkYeri - 1] = plaka;
        cout << "Arac park edildi." << endl;
    }
}

int main() { //Baslangicta hos geldiniz yaizi 1 saniye bekleyerek programi baslatir , do-while dongusu icerisine secimlerimizi yaptigimiz menuyu getiririz
    //

    cout << "Hos geldiniz!" << endl;
    this_thread::sleep_for(chrono::seconds(1)); // 1 saniye bekleme

    girisYap();

    int secim;

    do {
        cout << "\n-- Ana Menu --" << endl;
        cout << "1. Park Halindeki Araclarin Listesi" << endl;
        cout << "2. Park Halindeki Arac Cikisi" << endl;
        cout << "3. Yeni Aracin Girisi" << endl;
        cout << "4. Cikis" << endl;
        cout << "Seciminizi yapin: ";
        cin >> secim;

        switch (secim) {
        case 1:
            listele();
            break;
        case 2:
            aracCikisi();
            break;
        case 3:
            yeniAracGirisi();
            break;
        case 4:
            cout << "Programdan cikiliyor." << endl;
            return 0;
        default:
            cout << "Gecersiz secim. Lutfen tekrar deneyin." << endl;
            break;
        }
    } while (secim != 4);

    return 0;
}
