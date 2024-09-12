#include <iostream>
#include <string>

using namespace std;

class Order {
public:
    string status;

    Order() {
        status = "Belum Diambil";
    }

    void displayStatus() {
        cout << "Status Pesanan: " << status << endl;
    }

    void setStatus(string newStatus) {
        status = newStatus;
    }

    bool isReady() {
        return status == "Sedang Dimasak";
    }
};

// Kelas Emotion untuk menangani emosi pelanggan
class Emotion {
public:
    int level;

    Emotion() {
        level = 5;
    }

    void displayEmotion() {
        cout << "Emosi Pelanggan: " << level << "/5" << endl;
    }

    void decreaseEmotion() {
        if (level > 1) {
            level--;
        }
    }

    void resetEmotion() {
        level = 5;
    }
};

// Kelas Table untuk menangani meja (menggabungkan pesanan dan emosi)
class Table {
private:
    Order order;
    Emotion emotion;

public:

    void displayStatusAndEmotion() {
        order.displayStatus();
        emotion.displayEmotion();
    }

    void takeOrder() {
        order.setStatus("Sedang dimasak");
        cout << "Pesanan diambil oleh pelayan\n";
    }

    void serveOrder() {
        order.setStatus("Sudah Disajikan");
        emotion.resetEmotion();
        cout << "Pesanan sudah disajikan, pelanggan senangg kembali :D\n";
    }

    void customerWait() {
        emotion.decreaseEmotion();
    }

    bool isOrderReady() {
        return order.isReady();
    }
};

// Kelas Waiter untuk menangani tugas pelayan
class Waiter {
public:
    // Mengambil pesanan dari meja
    void takeOrder(Table& table) {
        table.takeOrder();
    }

    // Mengantar pesanan ke meja
    void deliverOrder(Table& table) {
        if (table.isOrderReady()) {
            table.serveOrder();
        } else {
            cout << "Pesanan belum siap untuk diantar.\n";
        }
    }
};

int main() {
    Table table1;        // Membuat meja
    Waiter waiter;       // Membuat pelayan

    // Menampilkan status awal
    table1.displayStatusAndEmotion();

    // Pelayan mengambil pesanan
    waiter.takeOrder(table1);
    table1.displayStatusAndEmotion();

    // Simulasi pelanggan menunggu, emosi menurun
    for (int i = 0; i < 3; i++) {
        table1.customerWait();
        table1.displayStatusAndEmotion();
    }

    // Pelayan mengantar pesanan
    waiter.deliverOrder(table1);
    table1.displayStatusAndEmotion();

    return 0;
}
