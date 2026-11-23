#include <iostream>
#include <unordered_map>
#include <sstream>
#include <string>

int main() {
    std::string text = "яблоко банан яблоко апельсин яблоко";
    std::unordered_map<std::string, int> wordCount;
    std::stringstream ss(text);
    std::string word;

    // Разбиваем текст на слова и считаем частоту
    while (ss >> word) {
        wordCount[word]++; // Если слова нет, оно создастся со значением 0 и сразу увеличится
    }

    // Выводим результат
    std::cout << "Частота слов:" << std::endl;
    for (const auto& pair : wordCount) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}