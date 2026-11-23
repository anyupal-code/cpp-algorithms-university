#include <iostream>
#include <vector>

class MyStack {
private:
    std::vector<int> data; 

public:
    void push(int value) {
        data.push_back(value);
    }

    void pop() {
        // TODO: Проверить, не пуст ли стек. Если пуст — вывести ошибку.
        // Иначе удалить последний элемент (data.pop_back()).
    }

    int top() {
        // TODO: Вернуть последний элемент (data.back()).
        // Если стек пуст — вернуть -1.
        return 0;
    }

    bool empty() const {
        return data.empty();
    }

    size_t size() const {
        return data.size();
    }
};

int main() {
    MyStack stack;
    
    std::cout << "Добавляем: 10, 20, 30" << std::endl;
    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << "Вершина стека: " << stack.top() << std::endl; 
    std::cout << "Размер: " << stack.size() << std::endl;

    std::cout << "Удаляем вершину" << std::endl;
    stack.pop();
    
    std::cout << "Новая вершина: " << stack.top() << std::endl; 

    return 0;
}