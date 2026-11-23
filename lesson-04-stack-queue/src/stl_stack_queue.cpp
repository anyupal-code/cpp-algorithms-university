#include <iostream>
#include <stack>
#include <queue>
#include <string>

int main() {
    // --- Стек ---
    std::string expression = "{[()]}";
    std::stack<char> brackets;
    bool isValid = true;

    for (char c : expression) {
        if (c == '(' || c == '[' || c == '{') {
            brackets.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (brackets.empty()) {
                isValid = false;
                break;
            }
            char top = brackets.top();
            brackets.pop();
            
            if ((c == ')' && top != '(') || 
                (c == ']' && top != '[') || 
                (c == '}' && top != '{')) {
                isValid = false;
                break;
            }
        }
    }
    
    if (!brackets.empty()) isValid = false;

    std::cout << "Скобки расставлены " << (isValid ? "верно" : "неверно") << std::endl;

    // --- Очередь ---
    std::queue<std::string> printQueue;
    printQueue.push("Документ 1");
    printQueue.push("Документ 2");
    printQueue.push("Документ 3");

    std::cout << "\nПечать документов:" << std::endl;
    while (!printQueue.empty()) {
        std::cout << "Печатается: " << printQueue.front() << std::endl;
        printQueue.pop();
    }

    return 0;
}