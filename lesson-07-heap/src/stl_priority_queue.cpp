#include <iostream>
#include <queue>
#include <vector>
#include <string>

// Структура задачи с приоритетом
struct Task {
    std::string name;
    int priority;

    // Для std::priority_queue: чем больше priority, тем выше задача
    bool operator<(const Task& other) const {
        return priority < other.priority; // Max-Heap по приоритету
    }
};

int main() {
    std::priority_queue<Task> tasks;

    tasks.push({"Сделать уроки", 3});
    tasks.push({"Помыть посуду", 1});
    tasks.push({"Написать код", 5});
    tasks.push({"Погулять", 2});

    std::cout << "Задачи по убыванию приоритета:" << std::endl;
    while (!tasks.empty()) {
        Task t = tasks.top();
        tasks.pop();
        std::cout << "Приоритет " << t.priority << ": " << t.name << std::endl;
    }

    return 0;
}