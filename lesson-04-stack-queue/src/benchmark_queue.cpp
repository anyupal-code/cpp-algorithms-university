#include <iostream>
#include <vector>
#include <deque>
#include <chrono>
#include <iomanip>

int main() {
    const int N = 100000; 
    
    std::deque<int> deque_queue;
    auto start_deque = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < N; i++) deque_queue.push_back(i);
    for (int i = 0; i < N; i++) deque_queue.pop_front();
    auto end_deque = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_deque = end_deque - start_deque;

    std::vector<int> vec_queue;
    auto start_vec = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < N; i++) vec_queue.push_back(i);
    for (int i = 0; i < N; i++) vec_queue.erase(vec_queue.begin()); 
    auto end_vec = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_vec = end_vec - start_vec;

    std::cout << std::fixed << std::setprecision(4);
    std::cout << "Очередь на " << N << " элементов:\n";
    std::cout << "На основе deque: " << elapsed_deque.count() << " сек.\n";
    std::cout << "На основе vector: " << elapsed_vec.count() << " сек.\n";
    if (elapsed_deque.count() > 0)
        std::cout << "Deque быстрее в " << (elapsed_vec.count() / elapsed_deque.count()) << " раз.\n";
    return 0;
}