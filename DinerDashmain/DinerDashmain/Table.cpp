#include "Table.h"

// Constructor
Table::Table(int id) : tableId(id), isOccupied(false) {}

// Getter for isOccupied
//Mengatur apakah meja sedang ditempati oleh pelanggan atau tidak.
bool Table::getIsOccupied() const {
    return isOccupied;
}

// Setter for isOccupied
// Mengecek apakah meja sedang ditempati atau kosong.
void Table::setIsOccupied(bool occupied) {
    isOccupied = occupied;
}

// Getter for tableId
//Mengembalikan ID dari meja tersebut.
int Table::getTableId() const {
    return tableId;
}
