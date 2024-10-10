#ifndef KITCHEN_H
#define KITCHEN_H

#include <queue>
#include "Order.h"

class Kitchen {
private:
    std::queue<Order*> orderQueue; // Queue to hold the orders

public:
    // Add an order to the kitchen
    void takeOrder(Order* order);

    // Simulate cooking the first order in the queue
    void cookOrder();

    // Check if there are pending orders
    bool hasPendingOrders() const;
};

#endif
