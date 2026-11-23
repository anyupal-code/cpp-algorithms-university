#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec;
    
    // В std::vector вместимость увеличивается автоматически
    for (int i = 0; i < 10; i++) {
        vec.push_back(i * 10);
        std::cout << "Добавлен: " << i * 10 
                  << " | Размер: " << vec.size() 
                  << " | Вместимость: " << vec.capacity() << std::endl;
    }

    return 0;
}