#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Order.h"
#include <iostream>

class Customer {
private:
    int customerId;
    int tableId;
    Order* order;

public:
    Customer(int id, int tableId);

    int getCustomerId() const;
    int getTableId() const;
    void setTableId(int tableId);

    // Customer places an order (no notification, Game Manager handles it)
    void placeOrder(int orderId, const std::string& item);

    void displayOrder() const;
};

#endif
