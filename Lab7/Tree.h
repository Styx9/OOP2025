#pragma once
#include <iostream>

template<typename T>
class Node {
public:
    T value;
    Node<T>* first_child;
    Node<T>* next_sibling;

    // Constructor
    Node(const T& val) {
        value = val;
        first_child = nullptr;
        next_sibling = nullptr;
    }

    void add_node(Node<T>* parent, Node<T>* new_node) {
        if (parent == nullptr || new_node == nullptr) return;
        if (parent->first_child == nullptr) {
            parent->first_child = new_node;
        }
        else {
            Node<T>* current = parent->first_child;
            while (current->next_sibling != nullptr) {
                current = current->next_sibling;
            }
            current->next_sibling = new_node;
        }
    }

    Node<T>* get_node(Node<T>* parent, size_t index, Node<T>* root) {
        if (parent == nullptr) return root;

        Node<T>* current = parent->first_child;
        size_t count = 0;

        while (current != nullptr && count < index) {
            current = current->next_sibling;
            count++;
        }

        return current;
    }

    void delete_node(Node<T>* node) {
        if (node == nullptr) return;

        Node<T>* child = node->first_child;
        while (child != nullptr) {
            Node<T>* next_child = child->next_sibling;
            delete_node(child);  // Stergem toti copiii in mod recursiv
            child = next_child;
        }

        // Cazul in care vrem sa stergem radacina 
        if (node == this) {
            delete node;
            return;
        }

        // Stergem nodul din lista parintilor
        Node<T>* parent = this;
        Node<T>* current = parent->first_child;
        Node<T>* prev = nullptr;

        while (current != nullptr && current != node) {
            prev = current;
            current = current->next_sibling;
        }

        if (current == node) {
            if (prev == nullptr) {
                parent->first_child = node->next_sibling;
            }
            else {
                prev->next_sibling = node->next_sibling;
            }
        }

        delete node;
    }
    Node<T>* find(Node<T>* node, bool (*compare)(const T&)) {
        if (node == nullptr || compare == nullptr) return nullptr;

        if (compare(node->value)) {
            return node;
        }

        Node<T>* found_in_child = find(node->first_child, compare);
        if (found_in_child != nullptr) {
            return found_in_child;
        }

        return find(node->next_sibling, compare);
    }

    void insert(Node<T>* parent, Node<T>* new_node, size_t index) {
        if (parent == nullptr || new_node == nullptr) return;

        if (index == 0) {
            new_node->next_sibling = parent->first_child;
            parent->first_child = new_node;
            return;
        }

        Node<T>* current = parent->first_child;
        size_t count = 0;

        while (current != nullptr && count < index - 1) {
            current = current->next_sibling;
            count++;
        }

        if (current != nullptr) {
            new_node->next_sibling = current->next_sibling;
            current->next_sibling = new_node;
        }
    }


    void sort(Node<T>* parent, bool (*compare)(const T&, const T&) = nullptr) {
        if (parent == nullptr || parent->first_child == nullptr) return;
        if (compare == nullptr) {
            compare = [](const T& a, const T& b) { return a < b; };
        }

        bool swapped;
        do {
            swapped = false;
            Node<T>* current = parent->first_child;
            Node<T>* prev = nullptr;

            while (current != nullptr && current->next_sibling != nullptr) {
                Node<T>* next = current->next_sibling;

                if (!compare(current->value, next->value)) {
                    if (prev != nullptr) {
                        prev->next_sibling = next;
                    }
                    else {
                        parent->first_child = next;
                    }

                    current->next_sibling = next->next_sibling;
                    next->next_sibling = current;
                    swapped = true;

                    prev = next;  
                }
                else {
                    prev = current;
                    current = current->next_sibling;
                }
            }
        } while (swapped);
    }
    size_t count(Node<T>* node = nullptr) const {
        if (node == nullptr) {
            node = const_cast<Node<T>*>(this);
        }

        size_t total = 1;  
        Node<T>* child = node->first_child;
        while (child != nullptr) {
            total += count(child);
            child = child->next_sibling;
        }

        return total;
    }
};

template<typename T>
class Tree {
public:
    Node<T>* root;

    Tree(const T& rootValue) {
        root = new Node<T>(rootValue);
    }

    ~Tree() {
        if (root != nullptr) {
            root->delete_node(root);
        }
    }

    void print() const {
        printNode(root, 0);
    }

private:
    void printNode(Node<T>* node, int depth) const {
        if (node == nullptr) return;

        for (int i = 0; i < depth; i++) {
            std::cout << "  ";
        }
        std::cout << node->value << std::endl;
        printNode(node->first_child, depth + 1);
        printNode(node->next_sibling, depth);
    }
};

// Functiile de comparatie
bool compareSort(const int& a, const int& b) {
    return a < b;
}

bool compareFind(const int& a) {
    return a == 3;  
}