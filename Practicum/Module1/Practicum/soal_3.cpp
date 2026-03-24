#include <iostream>
#include <string>

class Sesi {
    protected:
        int nomorSesi;
        std::string nama;
        int durasi;
        bool status;
    public:
        //Constructor
        Sesi(int a, std::string b, int c, bool d) : nomorSesi(a), nama(b), durasi(c), status(d){}

        //Setter & Getter
        void setNomorSesi(int a) {nomorSesi = a;}
        void setNama(std::string a) {nama = a;}
        void setDurasi(int a) {durasi = a;}
        void setStatus(bool a) {status = a;}
        int getNomorSesi() {return nomorSesi;}
        std::string getNama() {return nama;}
        int getDurasi() {return durasi;}
        std::string getStatus() {if (status == true) return "Berlangsung"; else return "Selesai";}

        //Methods
        void updateStatus(){
            setStatus(false);
        }
        virtual double hitungBiaya() = 0;
        virtual void tampilkanInfo() {
            std::cout << "[#" << getNomorSesi() << "] | ";
            std::cout << getNama();
            std::cout << " | " << getDurasi() << "jam | ";
            std::cout << getStatus() << " | ";
        }
        ~Sesi() {
            std::cout << "Sesi " << getNomorSesi() <<" terhapus";
        }
};

class SesiReguler : public Sesi {
    private:
        int nomorPS;
        double harga;
        std::string label;
    public:
        //Constructor
        SesiReguler(int a, std::string b, int c, bool d, int e, double f) : Sesi(a, b, c, d){
            nomorPS = e;
            harga = f;
            label = "Reguler";
        }

        //Setter & Getter
        void setNomorPS(int a) {nomorPS = a;}
        void setHarga(double a) {harga = a;}
        int getNomorPS() {return nomorPS;}
        double getHarga() {return harga;}
        std::string getLabel() {return label;}

        //Methods
        double hitungBiaya() override {
            return harga*durasi;
        }
        void tampilkanInfo() override {
            Sesi::tampilkanInfo();
            std::cout << getLabel();
            std::cout << " | PS#" << getNomorPS() << " | " << "Rp. " << hitungBiaya() << std::endl;
        }

};

class SesiVIP : public Sesi {
    private:
        std::string label;
        double harga;
        double hargaRuangan;
    public:
        //Constructor
        SesiVIP(int a, std::string b, int c, bool d, double e, double f) : Sesi(a, b, c, d) {
            harga = e;
            hargaRuangan = f;
            label = "VIP";
        }

        //Setter & Getter
        void setHarga(double a) {harga = a;}
        void setHargaRuangan(double a) {hargaRuangan = a;}
        double getHarga() {return harga;}
        double getHargaRuangan() {return hargaRuangan;}
        std::string getLabel() {return label;}

        //Methods
        double hitungBiaya() override {
            return (harga*durasi)+hargaRuangan;
        }
        void tampilkanInfo() override {
            Sesi::tampilkanInfo();
            std::cout << getLabel() << " | " << "Rp. " << hitungBiaya() << std::endl;
        }
};

class RentalPS {
    private:
        Sesi* pDaftarSesi[100];
        int total;
        int nomorUrut;
        double pendapatan;
    public:
        //Setter & Getter
        double getPendapatan() {
            return pendapatan;
        }

        //Constructor
        RentalPS() {
            total = 0;
            pendapatan = 0;
            nomorUrut = 1;
            for (int i = 0; i < 100; i++){
                pDaftarSesi[i] = nullptr;
            }
        }

        //Methods
        void tambahSesi(){
            int slot;
            std::string nama;
            int durasi;
            int label;
            for (int i = 0; i < 100; i++){
                if (pDaftarSesi[i] == nullptr){
                    slot = i;
                }
                else {
                    std::cout << "Tidak ditemukan slot kosong\n";
                    return;
                }
            }
            std::cout << "Masukkan Nama (1 Kata)\n>>"; std::cin >> nama;
            std::cout << "Masukkan Durasi\n>>"; std::cin >> durasi;
            std::cout << "1. Reguler 2. VIP\n>>"; std::cin >> label;
            if(label == 1) {
                int nomorPS;
                double harga;
                std::cout << "Masukkan Harga\n>>"; std::cin >> harga;
                std::cout << "Masukkan Nomor PS\n>>"; std::cin >> nomorPS;
                Sesi* pNewSesi = new SesiReguler(nomorUrut, nama, durasi, "Berlangsung", nomorPS, harga);
                pDaftarSesi[slot] = pNewSesi;
                total++;
                nomorUrut++;
                pendapatan += harga;
            }
            if(label == 2) {
                int hargaRuangan;
                double harga;
                std::cout << "Masukkan Harga\n>>"; std::cin >> harga;
                std::cout << "Masukkan Harga Ruangan\n>>"; std::cin >> hargaRuangan;
                Sesi* pNewSesi = new SesiVIP(nomorUrut, nama, durasi, "Berlangsung", harga, hargaRuangan);
                pDaftarSesi[slot] = pNewSesi;
                total++;
                nomorUrut++;
                pendapatan += harga;
            }
            
        }
        void tampilSemuaSesi(){
            for (int i = 0; i < 100; i++){
                if (pDaftarSesi[i] != nullptr){
                    pDaftarSesi[i]->tampilkanInfo();
                }
            }
        }
        void selesaikanSesi(){
            int nomor;
            std::cout << "Masukkan Nomor Sesi\n>>"; std::cin >> nomor;
            for (int i = 0; i < 100; i++){
                if (pDaftarSesi[i] != nullptr && pDaftarSesi[i]->getNomorSesi() == nomor){
                    pDaftarSesi[i]->updateStatus();
                }
            }
        }
        void hapusSesi(){
            int nomor;
            std::cout << "Masukkan Nomor Sesi\n>>"; std::cin >> nomor;
            for (int i = 0; i < 100; i++){
                if (pDaftarSesi[i] != nullptr && pDaftarSesi[i]->getNomorSesi() == nomor){
                    delete pDaftarSesi[i];
                    pDaftarSesi[i] = nullptr;
                    total--;
                }
            }
        }
        void totalPendapatan() {
            std::cout << "Pendapatan: Rp. " << getPendapatan();
        }

        //Destructor
        ~RentalPS(){
            for (int i = 0; i < 100; i++){
                delete pDaftarSesi[i];
            }
        }
};

int main(){
    int input;
    RentalPS* pManager = new RentalPS();
    while(true){
        std::cout << "1. Daftarkan Sesi\n2. Lihat Sesi\n3. Tandai Sesi Selesai\n4. Hapus Sesi\n5. Total Pendapatan\n6. Keluar\n>>";
        std::cin >> input;
        if (input == 1) pManager->tambahSesi();
        if (input == 2) pManager->tampilSemuaSesi();
        if (input == 3) pManager->selesaikanSesi();
        if (input == 4) pManager->hapusSesi();
        if (input == 5) pManager->totalPendapatan();
        if (input == 6) {
            delete pManager;
            break;
        }

    }

    return 0;
}