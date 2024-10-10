#include "GameManager.h"
#include <iostream>


// Constructor initializes the kitchen and tables
GameManager::GameManager(Kitchen* kitchen, Table* table1, Table* table2, Cucipiring* dishwasher) 
    : kitchen(kitchen), table1(table1), table2(table2), dishwasher(dishwasher), lastOrderId(0) {}

// Add a customer to the queue
void GameManager::addCustomerToQueue(Customer* customer) {
    if (customerQueue.size() < 5) { // Limit to 5 customers
        customerQueue.push(customer);
    } else {
        std::cout << "Customer dalam antrian sudah penuh! (max 5 customers).\n";
    }
}

// Check if customer queue is empty
bool GameManager::isCustomerQueueEmpty() const {
    return customerQueue.empty();
}

// Assign a customer from the queue to a table
void GameManager::assignCustomerToTable(Table* table) {
    if (!table->getIsOccupied() && !customerQueue.empty()) {
        Customer* customer = customerQueue.front(); // Get the first customer in the queue
        customerQueue.pop();                         // Remove the customer from the queue
        customer->setTableId(table->getTableId());
        table->setIsOccupied(true);

        std::cout << "Customer " << customer->getCustomerId() 
                  << " telah ditetapkan ke meja " << table->getTableId() << std::endl;
        // Automatically place an order for the customer
        orderPlaced(customer);                       
    } else {
        if (table->getIsOccupied()) {
            std::cout << "Neja " << table->getTableId() << " sudah terisi penuh." << std::endl;
        } else {
            std::cout << "Tidak ada customer dalam antrian." << std::endl;
        }
    }
}
int GameManager::getNextOrderId() {
    return ++lastOrderId; // Increment and return the next order ID
}
// Notify the kitchen when a customer places an order
void GameManager::orderPlaced(Customer* customer) {
    std::string orderItem = "Makanan";  // Automatically assign the order to "Food"
    // Create the order with the orderId matching tableId
     int orderId = getNextOrderId(); // Get the next order ID
    customer->placeOrder(orderId, orderItem);  
    kitchen->takeOrder(new Order(orderId, customer->getTableId(), orderItem));  

    std::cout << "Pesanan untuk " << orderItem << " ditempatkan di atas meja " 
              << customer->getTableId() << "." << std::endl;
}

// Process orders in the kitchen (cooking all pending orders)
void GameManager::processOrders() {
    while (kitchen->hasPendingOrders()) {
        kitchen->cookOrder();  // Cook one order at a time
    }
}

// Handle delivering orders to the correct table
void GameManager::deliverOrder(int tableId) {
    int deliveryTable;
    std::cout << "Masukkan nomor meja untuk mengantarkan pesanan: ";
    std::cin >> deliveryTable;

    if (deliveryTable == tableId) {
        std::cout << "Pesanan berhasil dikirim ke meja " << tableId << "." << std::endl;
    } else {
        std::cout << "Meja yang salah! Pesanan tidak terkirim." << std::endl;
    }
}
void GameManager::takeDirtyPlate() 
{
    if (table1->getIsOccupied() && table1->getIsOccupied()) {
        std::cout << "Mengambil piring kotor dari meja " << table1->getTableId() << " ke mesin pencuci piring " << std::endl;
        dishwasher->washPlate();
        freeTable(table1->getTableId()); // Free the table after washing
    } else if (table2->getIsOccupied()) {
        std::cout << "Mengambil piring kotor dari meja" << table2->getTableId() << " ke mesin pencuci piring" << std::endl;
        dishwasher->washPlate();
        freeTable(table2->getTableId()); // Free the table after washing
    } else {
        std::cout << "Tidak ada pesanan yang telah selesai dicuci." << std::endl;
    }
}
void GameManager::freeTable(int tableId) {
    if (tableId == 1) {
        table1->setIsOccupied(false); // Free table 1
        std::cout << "Meja 1 sudah kosong." << std::endl;
    } else if (tableId == 2) {
        table2->setIsOccupied(false); // Free table 2
        std::cout << "Meja 2 sudah kosong." << std::endl;
    } else {
        std::cout << "ID tabel tidak valid." << std::endl;
    }
}
void GameManager::displayQueueSize() const {
    std::cout << "Customers dalam antrian: " << customerQueue.size() << std::endl;
}
