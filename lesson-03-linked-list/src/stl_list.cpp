#include <iostream>
#include <list>
#include <string>

int main() {
    // Создаем список задач
    std::list<std::string> tasks = {
        "Помыть посуду", 
        "Сделать уроки", 
        "Погулять", 
        "Почитать книгу"
    };

    // 1. Вывод всех задач
    std::cout << "Текущий список задач:" << std::endl;
    for (const std::string& task : tasks) {
        std::cout << "- " << task << std::endl;
    }

    // 2. Добавление в конец
    tasks.push_back("Купить хлеб");
    std::cout << "\nПосле добавления 'Купить хлеб':" << std::endl;
    for (const std::string& task : tasks) {
        std::cout << "- " << task << std::endl;
    }

    // 3. Удаление задачи "Погулять"
    tasks.remove("Погулять");
    std::cout << "\nПосле удаления 'Погулять':" << std::endl;
    for (const std::string& task : tasks) {
        std::cout << "- " << task << std::endl;
    }

    return 0;
}