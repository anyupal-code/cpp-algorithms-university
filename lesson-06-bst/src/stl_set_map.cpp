#include <iostream>
#include <set>
#include <map>
#include <string>
#include <vector>

int main() {
    // --- Задача 1: std::set (уникальные слова в алфавитном порядке) ---
    std::vector<std::string> words = {"яблоко", "банан", "яблоко", "апельсин", "банан"};
    std::set<std::string> uniqueWords(words.begin(), words.end());

    std::cout << "Уникальные слова (в алфавитном порядке):" << std::endl;
    for (const std::string& word : uniqueWords) {
        std::cout << "- " << word << std::endl;
    }

    // --- Задача 2: std::map (оценки студентов по алфавиту) ---
    std::map<std::string, int> grades;
    grades["Иван"] = 5;
    grades["Мария"] = 4;
    grades["Алексей"] = 5;

    std::cout << "\nОценки студентов (в алфавитном порядке):" << std::endl;
    for (const auto& pair : grades) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}