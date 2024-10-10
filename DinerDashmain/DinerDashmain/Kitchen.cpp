#include "Kitchen.h"
#include <iostream>

// Add an order to the kitchen queue
void Kitchen::takeOrder(Order* order) {
    orderQueue.push(order);
    std::cout << "Pesanan " << order->getOrderId() << " untuk meja " << order->getTableId() 
              << " telah ditambahkan ke antrian dapur." << std::endl;
}

// Simulate cooking the first order in the queue and prompt the user to deliver it
void Kitchen::cookOrder() { // Memasak pesanan dari antrean pesanan dan menandainya sebagai selesai setelah memasak.
    if (!orderQueue.empty()) {
        // Get the current order at the front of the queue
        Order* currentOrder = orderQueue.front();
        
        // Display cooking message for the current order
        std::cout << "Memasak pesanan " << currentOrder->getOrderId() 
                  << " untuk meja " << currentOrder->getTableId() << "..." << std::endl;

        // Mark the order as completed
        currentOrder->completeOrder();
        
        // Remove the order from the queue after it's cooked
        orderQueue.pop();

        // Notify that the order is ready for delivery
        std::cout << "Pesanan " << currentOrder->getOrderId() << " untuk meja " 
                  << currentOrder->getTableId() << " siap untuk dikirim." << std::endl;

        // Clean up memory after cooking the order
        delete currentOrder;
    } else {
        std::cout << "Tidak ada pesanan yang menunggu untuk dimasak." << std::endl;
    }
}

// Check if there are any pending orders in the kitchen
bool Kitchen::hasPendingOrders() const {
    return !orderQueue.empty();
}
