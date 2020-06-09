#include <iostream>

using namespace std;

// Structure of node
struct node
{
    int key;
    int c = 0;
    struct node *left, *right;
};

// Creating new node
struct node* new_node(int item)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->c = 1;
    temp->left = temp->right = NULL;
    return temp;
}

struct node* insert(struct node* node, int key, int &ma)
{
    
    if(node == NULL){
        if(ma == 0)
            ma = 1;
        return new_node(key);
    }
    if(key < node->key)
        node->left = insert(node->left, key, ma);
    else if(key > node->key)
        node->right = insert(node->right, key, ma);
    else
        node->c++;
    
    ma = max(node->c, ma);
    return node;
}
    
int main (void)
{
    int size;
    cin >> size;
    int ma = 0;

    struct node* root = NULL;
    for(int i = 0, a; i < size; i++){
        cin >> a;
        root = insert(root, a, ma);
    }
    
    if(ma > size / 2)
        cout << 1;
    else
        cout << 0;
    return 0;
}
