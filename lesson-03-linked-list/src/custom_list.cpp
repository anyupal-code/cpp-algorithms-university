#include <iostream>

// Узел списка
struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class MyLinkedList {
private:
    Node* head; // Указатель на первый элемент

public:
    MyLinkedList() : head(nullptr) {}

    // Деструктор (освобождает память)
    ~MyLinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Добавление в начало
    void push_front(int value) {
        // TODO: Создать новый узел. Указать его next на текущую head.
        // Сделать новый узел головой (head).
    }

    // Добавление в конец
    void push_back(int value) {
        // TODO: Создать новый узел.
        // Если список пуст, сделать его головой.
        // Иначе пройти до последнего узла (у которого next == nullptr)
        // и привязать к нему новый узел.
    }

    // Удаление первого элемента
    void pop_front() {
        // TODO: Если список пуст, ничего не делать.
        // Иначе сохранить указатель на второй узел,
        // удалить текущую голову и сделать головой второй узел.
    }

    // Вывод списка
    void print() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    MyLinkedList list;
    
    std::cout << "Добавляем в конец: 10, 20, 30" << std::endl;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    list.print();

    std::cout << "Добавляем в начало: 5" << std::endl;
    list.push_front(5);
    list.print();

    std::cout << "Удаляем первый элемент" << std::endl;
    list.pop_front();
    list.print();

    return 0;
}