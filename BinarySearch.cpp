#include <iostream>
#include <string>
using namespace std;

class Node{
    public:
        string info;
        Node* leftchild;
        Node* rightchild;

        //Constructor for the node class
        Node(string i, Node* l, Node* r)
        {
            info = i;
            leftchild = l;
            rightchild = r;
        }
};

class BinaryTree{
    public:
        Node* ROOT;

        BinaryTree(){
            ROOT = nullptr; //Initializing ROOT to null
        }

        void insert(string element){ //insert a node in the binary search tree
            Node* newNode = new Node(element, nullptr, nullptr); // allocate memory for the new node
            newNode->info = element; // assign value to the data field of the new node
            newNode->leftchild = nullptr; // make the left child of the new node point to null
            newNode->rightchild = nullptr; // make the right child of the new node point to null

            Node* parent = nullptr;
            Node* currentNode = nullptr;
            search(element, parent, currentNode); // locate the node which will be the parent of the node to be insert

            if (parent == nullptr) // if the parent is NULL (Tree is empty)
            {
                ROOT = newNode; // mark the new node as ROOT
                return; // exit
            }
            
            if (element < parent->info) // if the value in the data field of the new node is less than that of the
            {
                parent->leftchild = newNode; // make the left child of the parent point to the new node
            }
            else if (element > parent->info) // if the value in the data field of the new node is greater than that
            {
                parent->rightchild = newNode; //make the right child of the parent point to the new node
            }
        }
};