#ifndef ORDER_H
#define ORDER_H

#include <string>

class Order {
private:
    int orderId;         // Unique ID for each order, will match the table ID in this case
    int tableId;         // Table associated with the order
    bool isCompleted;    // Whether the order is completed
    std::string item;    // The single item ordered by the customer

public:
    // Constructor
    Order(int id, int table, const std::string& item);

    // Getter for order completion status
    bool getIsCompleted() const;
    
    // Mark the order as completed
    void completeOrder();

    // Display order details
    void displayOrder() const;

    // Getter for orderId and tableId
    int getOrderId() const;
    int getTableId() const;
};

#endif
