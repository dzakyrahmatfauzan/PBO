#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <queue>
#include "Kitchen.h"
#include "Table.h"
#include "Customer.h"
#include "Cucipiring.h"

class GameManager {
private:
    Kitchen* kitchen;
    Table* table1;
    Table* table2;
    Cucipiring* dishwasher;
    std::queue<Customer*> customerQueue;
    int lastOrderId;
public:
    GameManager(Kitchen* kitchen, Table* table1, Table* table2,Cucipiring* dishwasher);

    // Add a customer to the queue
    void addCustomerToQueue(Customer* customer);

    // Check if customer queue is empty
    bool isCustomerQueueEmpty() const;

    // Assign a customer from the queue to a table
    void assignCustomerToTable(Table* table);

    // Display number of customers in the queue
    void displayQueueSize() const; // <-- Add this declaration

    // Process orders and handle them with the kitchen
    int getNextOrderId();
    void orderPlaced(Customer* customer);
    void processOrders();
    void deliverOrder(int tableId);
    void takeDirtyPlate();
    
    // Free a table after order is delivered
    void freeTable(int tableId);
};

#endif
