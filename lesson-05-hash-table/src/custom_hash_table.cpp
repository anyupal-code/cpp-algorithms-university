#include <iostream>
#include <list>
#include <vector>
#include <string>

// Реализация хеш-таблицы методом цепочек
class MyHashTable {
private:
    static const int TABLE_SIZE = 10; // Размер таблицы (количество корзин)
    std::vector<std::list<std::pair<std::string, int>>> table;

    // Простая хеш-функция для строки
    int hash(const std::string& key) {
        int sum = 0;
        for (char c : key) {
            sum += c;
        }
        return sum % TABLE_SIZE;
    }

public:
    MyHashTable() {
        table.resize(TABLE_SIZE);
    }

    // Вставка элемента
    void insert(const std::string& key, int value) {
        int index = hash(key);
        // TODO: Проверить, есть ли уже такой ключ в корзине (table[index]).
        // Если есть — обновить значение.
        // Иначе — добавить новую пару (key, value) в конец списка корзины.
    }

    // Поиск элемента по ключу
    int find(const std::string& key) {
        int index = hash(key);
        // TODO: Пройти по списку в корзине (table[index]).
        // Если найти ключ — вернуть значение.
        // Если не найти — вернуть -1.
        return -1;
    }
};

int main() {
    MyHashTable ht;
    ht.insert("Иван", 25);
    ht.insert("Мария", 30);
    ht.insert("Петр", 35);

    std::cout << "Возраст Ивана: " << ht.find("Иван") << std::endl;   // 25
    std::cout << "Возраст Марии: " << ht.find("Мария") << std::endl; // 30

    return 0;
}