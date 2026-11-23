#include <iostream>

// Узел дерева
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    TreeNode* root;

    // Рекурсивная вставка
    TreeNode* insertRecursive(TreeNode* node, int value) {
        if (node == nullptr) {
            return new TreeNode(value);
        }

        if (value < node->data) {
            node->left = insertRecursive(node->left, value);
        } else if (value > node->data) {
            node->right = insertRecursive(node->right, value);
        }
        // Если value == node->data, ничего не делаем (дубликаты не добавляем)
        return node;
    }

    // Рекурсивный поиск
    bool searchRecursive(TreeNode* node, int value) {
        // TODO: Если node == nullptr, вернуть false (не найдено).
        // Если value == node->data, вернуть true (нашли).
        // Если value < node->data, искать в левом поддереве.
        // Иначе искать в правом поддереве.
        return false;
    }

    // Симметричный обход (выводит в отсортированном порядке)
    void inorderRecursive(TreeNode* node) {
        if (node != nullptr) {
            inorderRecursive(node->left);
            std::cout << node->data << " ";
            inorderRecursive(node->right);
        }
    }

    // Удаление дерева (освобождение памяти)
    void destroyTree(TreeNode* node) {
        if (node != nullptr) {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }

public:
    BinarySearchTree() : root(nullptr) {}
    ~BinarySearchTree() { destroyTree(root); }

    void insert(int value) {
        root = insertRecursive(root, value);
    }

    bool search(int value) {
        return searchRecursive(root, value);
    }

    void inorder() {
        inorderRecursive(root);
        std::cout << std::endl;
    }
};

int main() {
    BinarySearchTree tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);

    std::cout << "Дерево (in-order): ";
    tree.inorder(); // Ожидается: 20 30 40 50 70

    std::cout << "Поиск 40: " << (tree.search(40) ? "Найдено" : "Не найдено") << std::endl;
    std::cout << "Поиск 90: " << (tree.search(90) ? "Найдено" : "Не найдено") << std::endl;

    return 0;
}