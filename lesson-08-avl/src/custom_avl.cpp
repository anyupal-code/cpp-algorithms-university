#include <iostream>
#include <algorithm>

struct Node {
    int data;
    int height;
    Node* left;
    Node* right;

    Node(int value) : data(value), height(1), left(nullptr), right(nullptr) {}
};

class AVLTree {
private:
    Node* root;

    int height(Node* node) {
        return node ? node->height : 0;
    }

    int getBalance(Node* node) {
        return node ? height(node->left) - height(node->right) : 0;
    }

    // Правый поворот
    Node* rotateRight(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        // Поворот
        x->right = y;
        y->left = T2;

        // Обновление высот
        y->height = std::max(height(y->left), height(y->right)) + 1;
        x->height = std::max(height(x->left), height(x->right)) + 1;

        return x;
    }

    // Левый поворот
    Node* rotateLeft(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        // Поворот
        y->left = x;
        x->right = T2;

        // Обновление высот
        x->height = std::max(height(x->left), height(x->right)) + 1;
        y->height = std::max(height(y->left), height(y->right)) + 1;

        return y;
    }

    // Вставка с балансировкой
    Node* insert(Node* node, int value) {
        // 1. Обычная вставка BST
        if (node == nullptr) return new Node(value);

        if (value < node->data) {
            node->left = insert(node->left, value);
        } else if (value > node->data) {
            node->right = insert(node->right, value);
        } else {
            return node; // Дубликаты не добавляем
        }

        // 2. Обновляем высоту текущего узла
        node->height = 1 + std::max(height(node->left), height(node->right));

        // 3. Получаем баланс-фактор
        int balance = getBalance(node);

        // 4. Если узел разбалансирован, выполняем повороты
        // TODO: Реализовать 4 случая (LL, RR, LR, RL)
        
        // Случай LL (левый-левый)
        if (balance > 1 && value < node->left->data) {
            return rotateRight(node);
        }
        // Случай RR (правый-правый)
        if (balance < -1 && value > node->right->data) {
            return rotateLeft(node);
        }
        // Случай LR (левый-правый)
        if (balance > 1 && value > node->left->data) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
        // Случай RL (правый-левый)
        if (balance < -1 && value < node->right->data) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    void inorder(Node* node) {
        if (node) {
            inorder(node->left);
            std::cout << node->data << " ";
            inorder(node->right);
        }
    }

    void destroy(Node* node) {
        if (node) {
            destroy(node->left);
            destroy(node->right);
            delete node;
        }
    }

public:
    AVLTree() : root(nullptr) {}
    ~AVLTree() { destroy(root); }

    void insert(int value) {
        root = insert(root, value);
    }

    void print() {
        inorder(root);
        std::cout << std::endl;
    }
};

int main() {
    AVLTree tree;
    // Вставляем по возрастанию: 10, 20, 30
    // Без балансировки дерево стало бы цепочкой. С балансировкой корнем станет 20.
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);

    std::cout << "Дерево (in-order): ";
    tree.print(); // Ожидается: 10 20 30

    return 0;
}