#pragma once
#include <iostream>
using namespace std;

template <class T>
class Avl {
private:
    struct Node {
    public:
        Node* father;
        Node* left;
        Node* right;
        int height;
        int balance;
        T* data;
        int key;

        Node(int key, T* data, Node* parent = nullptr)
            : father(parent), left(nullptr), right(nullptr),
            height(0), balance(0), data(data), key(key) {}

        ~Node() {
            delete data;
        }

        void updateHeight() {
            int leftHeight = (left != nullptr) ? left->height : -1;
            int rightHeight = (right != nullptr) ? right->height : -1;
            height = 1 + ((leftHeight > rightHeight) ? leftHeight : rightHeight);
            balance = leftHeight - rightHeight;

        }


        //  names are chosen acording to tutorial 5 slide 5 :
        //this means d , left child of this means b , right subtree of left means c
        Node* LL() {
            Node* b = left;
            Node* c = b->right;

            b->right = this;
            this->left = c;

            if (c)
                c->father = this;

            b->father = this->father;
            this->father = b;

            this->updateHeight();
            b->updateHeight();

            return b;


        }
        //  names are chosen acording to tutorial 5 slide 5 :
        //this means b , right child of this means d , left subtree of right means c
        Node* RR() {
            Node* d = right;
            Node* c = d->left;

            d->left = this;
            this->right = c;

            if (c)
                c->father = this;

            d->father = this->father;
            this->father = d;

            this->updateHeight();
            d->updateHeight();

            return d;


        }

        Node* LR() {
            if (left) left = left->RR();
            return LL();
        }

        Node* RL() {
            if (right) right = right->LL();
            return RR();
        }
    };

    Node* root = nullptr;

    Node* insert(Node* node, int key, T* data, StatusType& status);
    Node* remove(Node* node, int key, StatusType& status);
    Node* find(Node* node, int key);
    void inorder(Node* node);
    void destroy(Node* node);

public:
    Avl() = default;
    ~Avl() { destroy(root); }

    StatusType insert(int key);
    StatusType remove(int key);
    Node* find(int key) { return find(root, key); }
    void inorder() { inorder(root); }
    Node* getRoot() const { return root; }

};


// Insert
template <class T>
typename Avl<T>::Node* Avl<T>::insert(Node* node, int key, T* data, StatusType& status) {
    if (!node) {
        Node* newNode = new(nothrow) Node(key, data);
        if (!newNode) {
            status = StatusType::ALLOCATION_ERROR;
            delete data;
            return nullptr;
        }
        status = StatusType::SUCCESS;
        return newNode;
    }

    if (key < node->key) {
        node->left = insert(node->left, key, data, status);
        if (node->left) node->left->father = node;
    } else if (key > node->key) {
        node->right = insert(node->right, key, data, status);
        if (node->right) node->right->father = node;
    }
    node->updateHeight();

    if (node->balance == 2 && node->left && node->left->balance >= 0)
        return node->LL();
    if (node->balance == -2 && node->right && node->right->balance <= 0)
        return node->RR();
    if (node->balance == 2 && node->left && node->left->balance == -1)
        return node->LR();
    if (node->balance == -2 && node->right && node->right->balance == 1)
        return node->RL();

    return node;
}

template <class T>
StatusType Avl<T>::insert(int key) {
    if (key <= 0)
        return StatusType::INVALID_INPUT;

    if (find(key))
        return StatusType::FAILURE;

    T* data = new(nothrow) T();
    if (!data)
        return StatusType::ALLOCATION_ERROR;

    StatusType status= StatusType::SUCCESS;
    root = insert(root, key, data, status);
    return status;
}




//  Remove

template <class T>
typename Avl<T>::Node* Avl<T>::remove(Node* node, int key, StatusType& status) {
    if (!node) {
        status = StatusType::FAILURE;
        return nullptr;
    }

    if (key < node->key) {
        node->left = remove(node->left, key, status);
        if (node->left) node->left->father = node;
    } else if (key > node->key) {
        node->right = remove(node->right, key, status);
        if (node->right) node->right->father = node;
    } else {
        status = StatusType::SUCCESS;
        if (!node->left || !node->right) {//dont enter only if has 2 sons
            Node* temp = node->left ? node->left : node->right;
            if (temp) temp->father = node->father;
            delete node;
            return temp;
        }
        Node* successor = node->right;
        while (successor->left) successor = successor->left;
        swap(node->key, successor->key);
        swap(node->data, successor->data);
        node->right = remove(node->right, successor->key, status);
        if (node->right) node->right->father = node;
    }

    node->updateHeight();

    if (node->balance == 2 && node->left && node->left->balance >= 0)
        return node->LL();
    if (node->balance == -2 && node->right && node->right->balance <= 0)
        return node->RR();
    if (node->balance == 2 && node->left && node->left->balance == -1)
        return node->LR();
    if (node->balance == -2 && node->right && node->right->balance == 1)
        return node->RL();


    return node;
}

template <class T>
StatusType Avl<T>::remove(int key) {
    if (key <= 0)
        return StatusType::INVALID_INPUT;
    if (!find(key))
        return StatusType::FAILURE;
    StatusType status = StatusType::SUCCESS;
    root = remove(root, key, status);
    return status;
}



template <class T>
typename Avl<T>::Node* Avl<T>::find(Node* node, int key) {
    if (!node) return nullptr;
    if (key < node->key) return find(node->left, key);
    if (key > node->key) return find(node->right, key);
    return node;
}

template <class T>
void Avl<T>::inorder(Node* node) {
    if (!node) return;
    inorder(node->left);
    cout  << node->key << " ";
    inorder(node->right);
}

template <class T>
void Avl<T>::destroy(Node* node) {
    if (!node) return;
    destroy(node->left);
    destroy(node->right);
    delete node;
}
