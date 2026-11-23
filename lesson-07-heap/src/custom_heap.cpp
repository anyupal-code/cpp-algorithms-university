#include <iostream>
#include <vector>

class MaxHeap {
private:
    std::vector<int> data;

    // Всплытие элемента вверх
    void siftUp(int index) {
        // TODO: Пока элемент больше своего родителя (data[index] > data[parent]),
        // меняем их местами и поднимаемся к родителю (index = parent).
        // parent = (index - 1) / 2
    }

    // Погружение элемента вниз
    void siftDown(int index) {
        // TODO: Найти наибольшего из двух потомков (left и right).
        // Если наибольший потомок больше текущего элемента, поменять их местами
        // и продолжить погружение (index = largest).
        // left = 2 * index + 1, right = 2 * index + 2
    }

public:
    // Добавление элемента
    void push(int value) {
        data.push_back(value);
        // TODO: Вызвать siftUp для последнего элемента (индекс data.size() - 1).
    }

    // Извлечение максимума
    int pop() {
        if (data.empty()) {
            std::cerr << "Ошибка: куча пуста!" << std::endl;
            return -1;
        }
        int maxValue = data[0];
        // TODO: Переместить последний элемент на место корня (data[0] = data.back()).
        // Удалить последний элемент (data.pop_back()).
        // Если куча не пуста, вызвать siftDown для корня (индекс 0).
        return maxValue;
    }

    // Просмотр максимума
    int top() const {
        if (data.empty()) return -1;
        return data[0];
    }

    bool empty() const {
        return data.empty();
    }

    size_t size() const {
        return data.size();
    }
};

int main() {
    MaxHeap heap;
    heap.push(10);
    heap.push(30);
    heap.push(20);
    heap.push(5);
    heap.push(40);

    std::cout << "Извлекаем элементы из кучи:" << std::endl;
    while (!heap.empty()) {
        std::cout << heap.pop() << " ";
    }
    std::cout << std::endl; // Ожидается: 40 30 20 10 5

    return 0;
}