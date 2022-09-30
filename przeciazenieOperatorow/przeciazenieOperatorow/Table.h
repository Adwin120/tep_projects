#pragma once

#include <iostream>


class Table
{
public:

    Table();
    Table(std::string initialName, int initialTableLen);
    Table(const Table& other);
    ~Table();
    Table(Table&& other);
    Table operator=(Table&& other);
    void setName(std::string newName);
    bool setNewSize(int newTableLen);
    Table* clone();
    std::string getName() const;
    int getTableSize() const;
    int getValueAt(int offset);
    void setValueAt(int offset, int newVal);
    void print();
    Table operator=(Table& other);
    Table operator+(Table& other);
    Table operator<<(int k);
    Table operator>>(int k);
    
private:
    int* table;
    int tableLen;
    std::string name;
    const int defaultTableLen = 10;
    const std::string defaultName = "tablica";
};

