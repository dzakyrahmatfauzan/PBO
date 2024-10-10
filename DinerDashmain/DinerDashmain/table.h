#ifndef TABLE_H
#define TABLE_H

class Table {
private:
    bool isOccupied;  // To check if the table is occupied
    int tableId;      // Unique ID for each table

public:
    // Constructor
    Table(int id);

    // Getter and setter for isOccupied
    bool getIsOccupied() const;
    void setIsOccupied(bool occupied);

    // Getter for tableId
    int getTableId() const;
};

#endif
