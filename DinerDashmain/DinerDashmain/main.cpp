#include <iostream>
#include "GameManager.h"
#include "Table.h"
#include "Customer.h"
#include "Kitchen.h"

int main() {
    // Initialize tables and kitchen
    Table table1(1);
    Table table2(2);
    Kitchen kitchen;
    Cucipiring dishwasher;

    // Create GameManager and pass kitchen and tables
    GameManager gameManager(&kitchen, &table1, &table2, &dishwasher);

    // Initialize 5 customers
    Customer customer1(1, -1);
    Customer customer2(2, -1);
    Customer customer3(3, -1);
    Customer customer4(4, -1);
    Customer customer5(5, -1);

    // Add customers to the queue
    gameManager.addCustomerToQueue(&customer1);
    gameManager.addCustomerToQueue(&customer2);
    gameManager.addCustomerToQueue(&customer3);
    gameManager.addCustomerToQueue(&customer4);
    gameManager.addCustomerToQueue(&customer5);

    int choice;
    do {
        std::cout << "===== Menu DinerDash =====\n";
        std::cout << "1. Menempatkan pelanggan\n";
        std::cout << "2. Mengambil pesanan dari meja\n";
        std::cout << "3. Mengambil piring kotor\n";
        std::cout << "4. Keluar\n";
        gameManager.displayQueueSize();  // Display the number of customers in the queue
        std::cout << "===========================\n";
        std::cout << "Pilih salah satu opsi: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                int tableChoice;
                std::cout << "Menugaskan pelanggan ke meja yang mana (1 atau 2)? ";
                std::cin >> tableChoice;

                if (tableChoice == 1) {
                    gameManager.assignCustomerToTable(&table1);
                } else if (tableChoice == 2) {
                    gameManager.assignCustomerToTable(&table2);
                } else {
                    std::cout << "Pilihan meja tidak valid.\n";
                }
                break;
            }
            case 2: {
                int tableChoice;
                std::cout << "Menugaskan pelanggan ke meja yang mana (1 atau 2)? ";
                std::cin >> tableChoice;

                if (tableChoice == 1 && table1.getIsOccupied()) {
                    gameManager.processOrders();  // Process the order in the kitchen
                    gameManager.deliverOrder(table1.getTableId());  // Deliver the order
                } else if (tableChoice == 2 && table2.getIsOccupied()) {
                    gameManager.processOrders();  // Process the order in the kitchen
                    gameManager.deliverOrder(table2.getTableId());  // Deliver the order
                } else {
                    std::cout << "Tidak ada customer di meja " << tableChoice << ".\n";
                }
                break;
            }
            case 3:
            {
                gameManager.takeDirtyPlate(); // Call the method to take dirty plate
                break;
            }
            case 4: {
                std::cout << "Keluar dari permaian.\n";
                break;
            }
            default: {
                std::cout << "Opsi tidak valid. Silakan pilih lagi.\n";
                break;
            }
        }
    } while (choice != 4);

    return 0;
}
