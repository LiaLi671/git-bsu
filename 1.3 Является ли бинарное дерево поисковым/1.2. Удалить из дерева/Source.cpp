#include<iostream>
#include<fstream>
using namespace std;

ofstream out("output.txt");

struct node {
    int data;
    node* left;
    node* right;
    node* parent;
    node(int element) {
        data = element;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }
};



struct BTree {
    node* root;
    BTree() {
        root = nullptr;
    }


    node* add(node* root, int element, node* parent) {
        if (root == nullptr) {
            node* N = new node(element);
            N->parent = parent;
            return N;
        }
        if (element < root->data) {
            root->left = add(root->left, element, root);
        }
        else if (element > root->data) {
            root->right = add(root->right, element, root);
        }
        return root;
    }


    void obhod(node* root) {
        if (root != nullptr) {
            out << root->data << endl;
            obhod(root->left);
            obhod(root->right);
        }
    }


    node* find_min(node* root) {
        while (root->left != nullptr) {
            root = root->left;
        }
        return root;
    }


    node* delete_el(int element, node* root) {
        if (root == nullptr) {
            return root;
        }

        if (element < root->data) {
            root->left = delete_el(element, root->left);
        } else if (element > root->data) {
            root->right = delete_el(element, root->right);
        }

        else if (element == root->data) {

            if (root->left == nullptr and root->right == nullptr) {
                if (root->parent != nullptr) {
                    if (root->parent->left == root) {
                        root->parent->left = nullptr;
                    }
                    else if (root->parent->right == root) {
                        root->parent->right = nullptr;
                    }
                }
                delete root;    
                return nullptr; 
            }

            else if (root->left != nullptr and root->right != nullptr) {
                node* zamena = find_min(root->right);
                root->data = zamena->data;
                root->right = delete_el(zamena->data, root->right);
                return root;   
            }

            else if (root->left != nullptr or root->right != nullptr) {
                node* grand = new node(0);
                if (root->left != nullptr) {
                    grand = root->left;
                }
                else if (root->right != nullptr) {
                    grand = root->right;
                }
                if (root->parent != nullptr) {
                    if (root->parent->left == root) {
                        root->parent->left = grand;
                    }
                    else if (root->parent->right == root) {
                        root->parent->right = grand;
                    }
                }
                grand->parent = root->parent;
                delete root;
                return grand; 
            }
        }
        return root;
    }
};
int main() {
    ifstream in("input.txt");
    BTree* t = new BTree();
    int n, element;
    in >> element;
    while (in >> n) {
        t->root = t->add(t->root, n, nullptr);
    }
    t->root = t->delete_el(element, t->root);
    t->obhod(t->root);
    return 0;
}