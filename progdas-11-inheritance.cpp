#include <iostream>

using namespace std;

class bankAccount{
    public:
        int idPelanggan;
        double saldoPelanggan;
        double setoranPelanggan, penarikanPelanggan;


        bankAccount(int idpelanggan, double saldo){
            idPelanggan = idpelanggan;
            saldoPelanggan = saldo;
        }

        double mendapatkanSaldo(){
            return saldoPelanggan;
        }

        int mendapatkanIdPelanggan(){
            return idPelanggan;
        }

        void menetapkanSaldo(double saldo){
            saldoPelanggan = saldo;
        }

        void menetapkanIdPelanggan(int idCustomer){
            idPelanggan = idCustomer;
        }

        void mendapatkanInformasiAkun(){
            cout << "Informasi Akun Anda" << endl;
            cout << "-------------------" << endl;
            cout << "Nomor Akun :" << idPelanggan << endl;
            cout << "Saldo Anda :" << saldoPelanggan << endl;
            cout << endl;
        }

        double menetapkanSetoran(double setoran){
            saldoPelanggan += setoran;
            return saldoPelanggan;
        }

        double mentapkanPenarikan(double penarikan){
            if(saldoPelanggan >= penarikan){
                saldoPelanggan -= penarikan;
            }
            else if(saldoPelanggan < penarikan){
                cout << "Saldo Anda Tidak Mencukupi" << endl;
                cout << "Dimohon Kerja Keras Ya ! Love you 3000" << endl;
            }
            cout << "Saldo Anda Sekarang : ";
            return saldoPelanggan;
        }

};

class checkingAccount:bankAccount{
    public:
        double saldoMinimal = 30000;
        double biayaLayanan = 3000;
        double suku_bunga;

        checkingAccount(int idpelanggan, double saldo, double sukubunga):bankAccount(idpelanggan, saldo){
            suku_bunga = sukubunga; 
        }

        void menetapkanSukuBunga(double sukubunga){
            suku_bunga = sukubunga;
        }
        double mendapatkanSukuBunga(){
            return suku_bunga;
        }
        void menetapkanSaldoMin(double saldo){
            saldoMinimal = saldo;
        }
        double mendapatkanSaldoMin(){
            return saldoMinimal;
        }

        double menetapkanSetoran(double setoran){
            saldoPelanggan += setoran;
            return saldoPelanggan;
        }
        double mendapatkanSaldo(){
            return saldoPelanggan;
        }
        double menetapkanPenarikan(double penarikan){
            if(saldoPelanggan >= penarikan){
                saldoPelanggan -= penarikan;
            }
            else if(saldoPelanggan < penarikan){
                cout << "Saldo Anda Tidak Cukup" << endl;
            }
            cout << "Saldo Anda Sekarang : " << saldoPelanggan << endl;
            return saldoPelanggan;
        }

        int mendapatkanMengenakanBiaya(){
                cout << "Kamu akan dikenakan biaya dikarenakan saldo minimal : Rp " << biayaLayanan << endl;
                cout << "Ini demi meningkatkan keamanan dan kenyamanan Anda" << endl;

                return biayaLayanan;
        }
        void mendapatkanInformasiAkun(){
            cout << "Informasi Akun Anda" << endl;
            cout << "-------------------" << endl;
            cout << "Nomor Akun :" << idPelanggan << endl;
            cout << "Saldo Anda :" << saldoPelanggan << endl;
            cout << endl;
        }
};

class savingAccount:bankAccount{
    double saldoMinimal;
    public:
    savingAccount(int idpelanggan, double saldo):bankAccount(idpelanggan, saldo){
        saldoMinimal = 30000;
    }
    double menetapkanSetoran(double setoran){
        saldoPelanggan += setoran;
        return saldoPelanggan;
    }
    double menetapkanPenarikan(double penarikan){
        if(saldoPelanggan >= penarikan){
            saldoPelanggan -= penarikan;
        }
            else if(saldoPelanggan < penarikan){
                cout << "Saldo Anda Tidak Mencukupi" << endl;
                cout << "Dimohon Kerja Keras Ya ! Love you 3000" << endl;
            }
            cout << "Saldo Anda Sekarang : ";
            return saldoPelanggan;
    }
    void menetapkanMinSaldo(double saldo){
        saldoMinimal = saldo;
    }
    void mendapatkanInformasiAkun(){
            cout << "Informasi Akun Anda" << endl;
            cout << "-------------------" << endl;
            cout << "Nomor Akun :" << idPelanggan << endl;
            cout << "Saldo Anda :" << saldoPelanggan << endl;
            cout << endl;
        }
};

int main(int argc, char const *argv[])
{
    double jumlah;
    int pilihan;

    do{
        cout << "Bikin Akun" << endl;
        cout << "1. Rekening Giro" << endl;
        cout << "2. Akun Tabungan" << endl;
        cout << "3. Keluar" << endl;
        cin >> pilihan;
        cout << endl;

        if(pilihan==1){
            int idPelanggan1, pilihan1;
            double saldo1, sukuBunga1, minimal1;

            cout << "Masukkan ID Akun Anda: ";
                cin >> idPelanggan1;
            cout << "Masukkan Saldo Awal: ";
                cin >> saldo1;
            cout << "Masukkan Suku Bunga: ";
                cin >> sukuBunga1;
            checkingAccount orang1(idPelanggan1, saldo1, sukuBunga1);
            cout << "Masukkan Minimal Saldo: ";
                cin >> minimal1;
            orang1.menetapkanSaldoMin(minimal1);

            do{
                cout << endl;
                cout << "1. Setoran" << endl;
                cout << "2. Penarikan Uang" << endl;
                cout << "3. Informasi Akun" << endl;
                cout << "4. Keluar" << endl;
                cin >> pilihan1;
                cout << endl;
                
                switch (pilihan1)
                {
                case 1:
                    cout << "Masukkan Jumlah: " << endl;
                    cin >> jumlah;
                    cout << "Saldo Anda Sekarang: " << orang1.menetapkanSetoran(jumlah);
                    if(orang1.mendapatkanSaldo() < orang1.mendapatkanSaldoMin()){
                        orang1.mendapatkanMengenakanBiaya();
                    }
                    break;
                case 2:
                    cout << "Masukkan Jumlah : " << endl;
                    cin >> jumlah;
                    cout << orang1.menetapkanPenarikan(jumlah) << endl;
                    if(orang1.mendapatkanSaldo() < orang1.mendapatkanSaldoMin()){
                        orang1.mendapatkanMengenakanBiaya();
                    }
                    else{
                    }
                    break;
                case 3:
                    orang1.mendapatkanInformasiAkun();
                    break;
                default:
                    break;
                }
            }
            while(pilihan1!=4);
        }
        else if (pilihan==2){
            int idPelanggan2, pilihan2;
            double saldo2;
            cout << "Masukkan ID Akun : ";
                cin >> idPelanggan2;
            cout << "Masukkan Saldo Awal Anda : ";
                cin >> saldo2;
            savingAccount orang2(idPelanggan2, saldo2);
            do{
                cout << endl;
                cout << "1. Setoran" << endl;
                cout << "2. Penarikan Uang" << endl;
                cout << "3. Informasi Akun" << endl;
                cout << "4. Keluar" << endl; 
                    cin >> pilihan2;
                cout << endl;
                switch (pilihan2)
                {
                    case 1:
                        cout << "Masukkan Nilai : " << endl;
                            cin >> jumlah;
                        cout << orang2.menetapkanSetoran(jumlah);
                        break;
                    case 2:
                        cout << "Masukkan Nilai : " << endl;
                            cin >> jumlah;
                        cout << orang2.menetapkanPenarikan(jumlah) << endl;
                        break;
                    case 3:
                        orang2.mendapatkanInformasiAkun();
                        break;
                    default:
                        break;
                    
                }
            }
            while(pilihan2!=4);
        }

    }
    while (pilihan!=3);
    return 0;
}
