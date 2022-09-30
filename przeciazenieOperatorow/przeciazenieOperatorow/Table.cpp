#include "Table.h"

Table::Table()
{
    name = defaultName;
    tableLen = defaultTableLen;
    table = new int[tableLen];
    //std::cout << "bezp: " << name << std::endl;
}

Table::Table(std::string initialName, int initialTableLen)
{
    name = initialName;
    tableLen = initialTableLen;
    table = new int[tableLen];
    //std::cout << "parametr: " << name << std::endl;
}

Table::Table(const Table& other)
{
    name = other.getName() + "_copy";
    tableLen = other.getTableSize();
    table = new int[tableLen];
    for (int i = 0; i < tableLen; i++)
    {
        table[i] = other.table[i];
    }
    std::cout << "kopiuj: " << name << "-----------lllllllllllllllllllll" << std::endl;
}

Table::~Table()
{
    if(table != NULL) delete[] table;
    //std::cout << "usuwam: " << name << std::endl;
}

Table::Table(Table&& other)
{
    table = other.table;
    tableLen = other.tableLen;
    name = other.name;

    other.table = NULL;
    std::cout << "MOVE " << std::endl;
}

Table Table::operator=(Table&& other)
{
    if (table == other.table)
    {
        return *this;
    }
    if (table != NULL) delete[] table;

    table = other.table;
    tableLen = other.tableLen;
    name = other.name;

    other.table = NULL;

    return *this;
}

void Table::setName(std::string newName)
{
    name = newName;
}

bool Table::setNewSize(int newTableLen)
{
    if (newTableLen <= 0) {
        return false;
    }

    int* newTable = new int[newTableLen];
    int smallerLen = (tableLen < newTableLen) ? tableLen : newTableLen;

    for (int i = 0; i < smallerLen; i++)
    {
        newTable[i] = table[i];
    }
    tableLen = newTableLen;
    delete[] table;
    table = newTable;
    return true;
}

Table* Table::clone()
{
    Table clonedTable(*this);
    return &clonedTable;
}

std::string Table::getName() const
{
    return name;
}

int Table::getTableSize() const
{
    return tableLen;
}

int Table::getValueAt(int offset)
{
    return table[offset];
}

void Table::setValueAt(int offset, int newVal)
{
    if (offset < tableLen)
    {
        table[offset] = newVal;
    }
}

void Table::print()
{
    std::cout << name << ": ";
    for (int i = 0; i < tableLen; i++)
    {
        std::cout << table[i] << " ";
    }
    std::cout << std::endl;
}

Table Table::operator=(Table& other)
{
    if (table == other.table)
    {
        return *this;
    }
    if (table != NULL) delete[] table;

    name = other.getName() + "_copy";
    tableLen = other.getTableSize();
    table = new int[tableLen];
    for (int i = 0; i < tableLen; i++)
    {
        table[i] = other.table[i];
    }
    std::cout << "kopiuj: " << name << "-----------lllllllllllllllllllll" << std::endl;
    return *this;
}

Table Table::operator+(Table& other)
{
    Table resultTable("(" + name + "+" + other.getName() + ")", tableLen + other.getTableSize());
    for (int i = 0; i < tableLen; i++)
    {
        resultTable.setValueAt(i, table[i]);
    }
    for (int i = 0; i < other.getTableSize(); i++)
    {
        resultTable.setValueAt(i + tableLen, other.table[i]);
    }
    return resultTable;
}

Table Table::operator<<(int k)
{
    if (k < 0)
    {
        return (*this) >> (-k);
    }
    else
    {
        k = k % tableLen;
        Table resultTable(name, tableLen);
        for (int i = 0; (k + i) < tableLen; i++)
        {
            resultTable.setValueAt(i, table[k + i]);
        }
        for (int i = 0; i < k; i++)
        {
            //std::cout << tableLen - k << std::endl;
            resultTable.setValueAt(tableLen - k + i, table[i]);
        }
        return resultTable;
    }
}

Table Table::operator>>(int k)
{
    Table resultTable(name, tableLen);
    if (k < 0)
    {
        return (*this) << (-k);
    }
    else
    {
        k = k % tableLen;
        Table resultTable(name, tableLen);
        for (int i = 0; i < k; i++)
        {
            resultTable.setValueAt(i, table[tableLen - k + i]);
        }
        for (int i = k; i < tableLen; i++)
        {
            resultTable.setValueAt(i, table[i-k]);
        }
        return resultTable;
    }
}
