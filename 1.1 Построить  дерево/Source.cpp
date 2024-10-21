#include<iostream>
#include<fstream>
using namespace std;
ofstream out("output.txt");
struct node {
    int data;
    node* left;
    node* right;
    node(int element) {
        data = element;
        left = nullptr;
        right = nullptr;
    }
};
struct BTree {
    node* root;
    BTree(){
        root = nullptr;
    }
    node* add(node* root, int element) {
        if (root == nullptr) {
            return new node(element);
        }
        if (root->data == element) {
            return root;
        }
        if (element < root->data) {
            root->left = add(root->left, element);
        }
        else if (element > root->data) {
            root->right = add(root->right, element);
        }
        return root;
    }
    void obhod(node*root) {
        if (root != nullptr) {
            out << root->data << endl;
            obhod(root->left);
            obhod(root->right);
        }
    }
};
int main() {
    ifstream in("input.txt");
    BTree* t = new BTree();
    int n;
    while(in >> n){
        t->root = t->add(t->root, n);
    }
    t->obhod(t->root);
    return 0;
}