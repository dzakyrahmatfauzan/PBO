#include "Order.h"
#include <iostream>

// Constructor initializes the order with the provided ID, table, and item
Order::Order(int id, int table, const std::string& item)
    : orderId(id), tableId(table), item(item), isCompleted(false) {}

// Get the completion status of the order
bool Order::getIsCompleted() const {
    return isCompleted;
}

// Mark the order as completed
void Order::completeOrder() {
    isCompleted = true;
}

// Display order details
void Order::displayOrder() const {
    std::cout << "Pesanan ID: " << orderId << ", Meja ID: " << tableId 
              << ", Item: " << item 
              << (isCompleted ? " (Completed)" : " (In Progress)") << std::endl;
}

// Getters for orderId and tableId
int Order::getOrderId() const {
    return orderId;
}

int Order::getTableId() const {
    return tableId;
}
