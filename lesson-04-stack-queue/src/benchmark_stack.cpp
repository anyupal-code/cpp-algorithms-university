#include <iostream>
#include <vector>
#include <list>
#include <chrono>
#include <iomanip>

int main() {
    const int N = 1000000;
    
    std::vector<int> vec_stack;
    auto start_vec = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < N; i++) vec_stack.push_back(i);
    for (int i = 0; i < N; i++) vec_stack.pop_back();
    auto end_vec = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_vec = end_vec - start_vec;

    std::list<int> list_stack;
    auto start_lst = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < N; i++) list_stack.push_front(i);
    for (int i = 0; i < N; i++) list_stack.pop_front();
    auto end_lst = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_lst = end_lst - start_lst;

    std::cout << std::fixed << std::setprecision(4);
    std::cout << "Стек на " << N << " элементов:\n";
    std::cout << "На основе vector: " << elapsed_vec.count() << " сек.\n";
    std::cout << "На основе list:   " << elapsed_lst.count() << " сек.\n";
    if (elapsed_vec.count() > 0)
        std::cout << "Вектор быстрее в " << (elapsed_lst.count() / elapsed_vec.count()) << " раз.\n";
    return 0;
}