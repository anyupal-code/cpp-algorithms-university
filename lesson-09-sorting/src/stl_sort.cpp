#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

struct Student {
    std::string name;
    int grade;
};

int main() {
    std::vector<Student> students = {
        {"Иван", 4},
        {"Мария", 5},
        {"Алексей", 4},
        {"Анна", 5},
        {"Петр", 3}
    };

    // Сортируем по убыванию оценки, при равенстве — по имени
    std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        if (a.grade != b.grade) {
            return a.grade > b.grade; // По убыванию
        }
        return a.name < b.name; // По алфавиту
    });

    std::cout << "Студенты (по рейтингу):" << std::endl;
    for (const auto& s : students) {
        std::cout << s.name << " (Оценка: " << s.grade << ")" << std::endl;
    }

    return 0;
}