#include <string>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

// node structure
typedef struct node {
    int value;
    struct node *left, *right;
}node;

// Find the index of value in arr[start ... end]
int search(int arr[], int start_idx, int end_idx, int value) {
    int i;
    for(i = start_idx; i <= end_idx; i++) {
        if(arr[i] == value)
            return i;
    }
    return 0;
}

// create a new node
node *getNewNode(int value) {
    node *new_node = new node;
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Inorder traversal of a tree
void inorderTraversal(node *ptr) {
    if(ptr == NULL)
        return;
    else {
        inorderTraversal(ptr->left);
        inorderTraversal(ptr->right);
    }
}

// construct the tree from its inorder and preorder traversals
node* constructTree(int inorder[],int preorder[],int inorder_start,int inorder_end){
    static int preorder_idx = 0;
    if(inorder_start > inorder_end) //bound check
        return NULL;
    
    // create a new node using the value in the current index of the preorder array
    node *tree_node = getNewNode(preorder[preorder_idx++]);
    
    // leaf node (no children)
    if(inorder_start == inorder_end)
        return tree_node;
    
    // Find the index of this node in the inorder array
    int inorder_idx = search(inorder,inorder_start,inorder_end,tree_node->value);
    
    // construct the left and right subtrees of this node
    tree_node->left = constructTree(inorder,preorder,inorder_start,inorder_idx-1);
    tree_node->right = constructTree(inorder,preorder,inorder_idx+1,inorder_end);
    
    return tree_node;
}

void Preorder(const node *root, int *n){
    if(root == NULL) return;
    Preorder(root->left, n);
    if(root->left == NULL && root->right == NULL) *n += 1;
    Preorder(root->right, n);
}

int leafNum(const node *root){
    int num = 0;
    Preorder(root, &num);
    return num;
}

void deleteTree(node *root){
    node* tmp = root;
    if(tmp != NULL){
        deleteTree(tmp->left);
        deleteTree(tmp->right);
        delete tmp;
    }
}

// main
int main() {
    string inorderStr;
    while(getline(cin,inorderStr)){
        int invalues[20000], prevalues[20000];
        string preorderStr;
        getline(cin,preorderStr);
        int i = 0;
        stringstream instream(inorderStr);
        int inn;
        while(instream >> inn){
            invalues[i++]=inn;
        }
        int inorder[i];
        for(int j=0; j<i; j++){
            inorder[j]=invalues[j];
        }
        i = 0;
        stringstream prestream(preorderStr);
        int pren;
        while(prestream >> pren){
            prevalues[i++]=pren;
        }
        int preorder[i];
        for(int j=0; j<i; j++){
            preorder[j]=prevalues[j];
        }
        
        int length = sizeof(inorder)/sizeof(inorder[0]);
        node *root = constructTree(inorder, preorder, 0, length - 1);
        int leaf = leafNum(root);
        cout<<leaf<<endl;
        deleteTree(root);
        root = NULL;
    }
    
    return 0;
}

