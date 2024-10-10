#include "Customer.h"

Customer::Customer(int id, int tableId) : customerId(id), tableId(tableId), order(nullptr) {}

int Customer::getCustomerId() const { return customerId; }

int Customer::getTableId() const { return tableId; }

void Customer::setTableId(int tableId) { this->tableId = tableId; }

void Customer::placeOrder(int orderId, const std::string& item) {
    order = new Order(orderId,tableId, item);
    std::cout << "Customer " << customerId << " telah melakukan pemesanan di meja " 
              << tableId << " untuk " << item << "." << std::endl;
}

void Customer::displayOrder() const {
    if (order != nullptr) {
        order->displayOrder();
    } else {
        std::cout << "Tidak ada pemesanan di meja." << std::endl;
    }
}
