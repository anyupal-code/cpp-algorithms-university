#include <iostream>

class MyVector {
private:
    int* data;       // Указатель на массив в памяти
    size_t size;     // Сколько элементов сейчас в массиве
    size_t capacity; // Сколько элементов может поместиться без перевыделения памяти

public:
    // Конструктор по умолчанию
    MyVector() {
        size = 0;
        capacity = 2; // Начальная вместимость
        data = new int[capacity];
    }

    // Деструктор (освобождает память)
    ~MyVector() {
        delete[] data;
    }

    // Добавление элемента в конец
    void push_back(int value) {
        // TODO 1: Проверить, если size == capacity, значит места нет.
        // Нужно выделить новый массив в 2 раза больше (capacity * 2).
        // Скопировать старые данные в новый массив.
        // Удалить старый массив (delete[]) и обновить указатель.
        // Обновить capacity.
        
        // TODO 2: Добавить элемент в конец массива (data[size] = value).
        // Увеличить size на 1.
    }

    // Получение элемента по индексу
    int& operator[](size_t index) {
        return data[index];
    }

    // Получение текущего размера
    size_t getSize() const {
        return size;
    }

    // Получение вместимости
    size_t getCapacity() const {
        return capacity;
    }
};

int main() {
    MyVector vec;
    
    // Тестируем добавление элементов
    for (int i = 0; i < 10; i++) {
        vec.push_back(i * 10);
        std::cout << "Добавлен: " << i * 10 
                  << " | Размер: " << vec.getSize() 
                  << " | Вместимость: " << vec.getCapacity() << std::endl;
    }

    // Проверяем доступ по индексу
    std::cout << "\nЭлемент с индексом 3: " << vec[3] << std::endl;

    return 0;
}