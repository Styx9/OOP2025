#include <iostream>
#include "Tree.h"
#include "temperature_literals.h"

int main() {
    float a = 300.0_Kelvin;
    float b = 120.0_Fahrenheit;
    std::cout << a << " " << b << std::endl;

    Tree<int> tree(1);
    Node<int>* child1 = new Node<int>(2);
    Node<int>* child2 = new Node<int>(3);
    Node<int>* child3 = new Node<int>(4);
    tree.root->add_node(tree.root, child1);
    tree.root->add_node(tree.root, child2);
    tree.root->add_node(tree.root, child3);

    //Adaugam copii pentru nodul 2
    Node<int>* child1_1 = new Node<int>(5);
    Node<int>* child1_2 = new Node<int>(6);
    child1->add_node(child1, child1_1);
    child1->add_node(child1, child1_2);
    //Adaugam copii pentru nodul 3
    Node<int>* child2_1 = new Node<int>(7);
    child2->add_node(child2, child2_1);

    std::cout << "Initial Tree Structure:" << std::endl;
    tree.print();
    std::cout << "Total nodes: " << tree.root->count() << std::endl;

    Node<int>* foundNode = tree.root->find(tree.root, compareFind);
    if (foundNode != nullptr) {
        std::cout << "Found node with value: " << foundNode->value << std::endl;
    }

    Node<int>* newNode = new Node<int>(8);
    tree.root->insert(tree.root, newNode, 1);
    std::cout << "\nAfter inserting 8 at position 1:" << std::endl;
    tree.print();

    tree.root->sort(tree.root, compareSort);
    std::cout << "\nAfter sorting siblings:" << std::endl;
    tree.print();

    tree.root->delete_node(child1);
    std::cout << "\nAfter deleting node with value 2 and its children:" << std::endl;
    tree.print();

    return 0;
}