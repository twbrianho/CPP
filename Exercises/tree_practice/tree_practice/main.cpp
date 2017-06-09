#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class Node
{
public:
    int weight; // weight can be negative!
    Node *left, *right;
    Node():weight(0),left(NULL),right(NULL){}
    Node(int d):weight(d),left(NULL),right(NULL){}
};

class MyBinaryTreeOps
{
public:
    // add your code here
    //------------------------------------------------------
    Node* constructTree(Node *root, string InExp, string PreExp)const;
    Node* deleteTree(Node *root)const;
    int treeHeight(const Node *root)const;
    int treeWeight(const Node *root)const;
    int leafNum(const Node *root)const;
    int minPathWeight(const Node *root)const;
    void preorder_print(Node *root);//debug
    void inorder_print(Node *root);//debug
    void postorder_print(Node *root);//debug
    
private:
    void preorder(Node *n);//debug
    void inorder(Node *n);//debug
    void postorder(Node *n);//debug
    //------------------------------------------------------
};

//------------------------------------------------------
// .cpp code here
//------------------------------------------------------
bool IsNumber(char C){
    if(C >= '0' && C <= '9') return true;
    else if(C == '-') return true;
    return false;
}

Node *MyBinaryTreeOps::constructTree(Node *root, string InExp, string PreExp)const{
    int ptr = 1;
    int A[20000] = {0};
    int l = 2;
    
    int sign = 1;
    int root_num = 0;
    while(IsNumber(treeStr[ptr])){
        if(treeStr[ptr] == '-') sign = -1;
        else root_num = root_num * 10 + (treeStr[ptr] - '0');
        ptr++;
    }
    root_num = sign * root_num;
    root = new Node(root_num);
    
    while(true){
        char c = treeStr[ptr];
        if(c == '('){
            ptr++;
            c = treeStr[ptr];
            if(c == ')'){
                Node* tmp = root;
                for(int i = 2; i < l; i++){
                    if(A[i] == 0) tmp = tmp->left;
                    else if(A[i] == 1) tmp = tmp->right;
                }
                if(A[l] == 0) tmp->left = NULL;
                else if(A[l] == 1) tmp->right = NULL;
                continue;
            }
            else if(IsNumber(c)){
                int sign = 1;
                int weight = 0;
                while(IsNumber(treeStr[ptr])){
                    if(treeStr[ptr] == '-') sign = -1;
                    else weight = weight * 10 + (treeStr[ptr] - '0');
                    ptr++;
                }
                weight = sign * weight;
                Node* tmp = root;
                for(int i = 2; i < l; i++){
                    if(A[i] == 0) tmp = tmp->left;
                    else if(A[i] == 1) tmp = tmp->right;
                }
                if(A[l] == 0) tmp->left = new Node(weight);
                else if(A[l] == 1) tmp->right = new Node(weight);
                l++;
                continue;
            }
        }
        else if(c == ')'){
            if(l == 1) break;
            else if(A[l] == 0){
                A[l] = 1;
                ptr++;
                continue;
            }
            else if(A[l] == 1){
                A[l] = 0;
                l--;
                ptr++;
                continue;
            }
        }
    }
    return root;
}

Node *MyBinaryTreeOps::deleteTree(Node *root)const{
    Node* tmp = root;
    if(tmp != NULL){
        deleteTree(tmp->left);
        deleteTree(tmp->right);
        delete tmp;
    }
    return NULL;
}

void Preorder1(const Node *root, stack<int> *s, int *h){
    if(root == NULL) return;
    s->push(root->weight);
    Preorder1(root->left, s, h);
    if(root->left == NULL && root->right == NULL){
        if(s->size() > *h) *h = int(s->size());
    }
    Preorder1(root->right, s, h);
    s->pop();
}

int MyBinaryTreeOps::treeHeight(const Node *root)const{
    int height = 1;
    stack<int> s;
    Preorder1(root, &s, &height);
    return height;
}

void Preorder2(const Node *root, int *w){
    if(root == NULL) return;
    *w += root->weight;
    Preorder2(root->left, w);
    Preorder2(root->right, w);
}

int MyBinaryTreeOps::treeWeight(const Node *root)const{
    int weight = 0;
    Preorder2(root, &weight);
    return weight;
}

void Preorder3(const Node *root, int *n){
    if(root == NULL) return;
    Preorder3(root->left, n);
    if(root->left == NULL && root->right == NULL) *n += 1;
    Preorder3(root->right, n);
}

int MyBinaryTreeOps::leafNum(const Node *root)const{
    int num = 0;
    Preorder3(root, &num);
    return num;
}

void Preorder4(const Node *root, stack<int> *s, int *m){
    if(root == NULL) return;
    s->push(root->weight);
    Preorder4(root->left, s, m);
    if(root->left == NULL && root->right == NULL){
        stack<int> tmp(*s);
        int weight = 0;
        while(tmp.empty() != true){
            weight += tmp.top();
            tmp.pop();
        }
        if(weight < *m) *m = weight;
    }
    Preorder4(root->right, s, m);
    s->pop();
}

int MyBinaryTreeOps::minPathWeight(const Node *root)const{
    int min = 32767;
    stack<int> s;
    Preorder4(root, &s, &min);
    return min;
}


//------------------------------------------------------
// debug code here
//------------------------------------------------------
void MyBinaryTreeOps::inorder_print(Node *root){
    inorder(root);
    cout << "\n";
}

void MyBinaryTreeOps::inorder(Node *n){
    if(n != NULL){
        inorder_print(n->left);
        cout << n->weight << ",";
        inorder_print(n->right);
    }
}

void MyBinaryTreeOps::preorder_print(Node *root){
    preorder(root);
    cout << "\n";
}

void MyBinaryTreeOps::preorder(Node *n){
    if(n != NULL){
        cout << n->weight << ",";
        inorder_print(n->left);
        inorder_print(n->right);
    }
}

void MyBinaryTreeOps::postorder_print(Node *root){
    postorder(root);
    cout << "\n";
}

void MyBinaryTreeOps::postorder(Node *n){
    if(n != NULL){
        postorder_print(n->left);
        postorder_print(n->right);
        cout << n->weight << ",";
    }
}

/*
 class btree{
 public:
 btree();
 ~btree();
 
 void insert(int key);
 Node *search(int key);
 void destroy_tree();
 void inorder_print();
 void postorder_print();
 void preorder_print();
 
 private:
 void destroy_tree(Node *leaf);
 void insert(int key, Node *leaf);
 Node *search(int key, Node *leaf);
 void inorder_print(Node *leaf);
 void postorder_print(Node *leaf);
 void preorder_print(Node *leaf);
 
 Node *root;
 };
 
 
 btree::btree(){
 root = NULL;
 }
 
 btree::~btree(){
 destroy_tree();
 }
 
 void btree::destroy_tree(Node *leaf){
 if(leaf != NULL){
 destroy_tree(leaf->left);
 destroy_tree(leaf->right);
 delete leaf;
 }
 }
 
 void btree::insert(int key, Node *leaf){
 
 if(key < leaf->weight){
 if(leaf->left != NULL){
 insert(key, leaf->left);
 }else{
 leaf->left = new Node;
 leaf->left->weight = key;
 leaf->left->left = NULL;
 leaf->left->right = NULL;
 }
 }else if(key >= leaf->weight){
 if(leaf->right != NULL){
 insert(key, leaf->right);
 }else{
 leaf->right = new Node;
 leaf->right->weight = key;
 leaf->right->right = NULL;
 leaf->right->left = NULL;
 }
 }
 
 }
 
 void btree::insert(int key){
 if(root != NULL){
 insert(key, root);
 }else{
 root = new Node;
 root->weight = key;
 root->left = NULL;
 root->right = NULL;
 }
 }
 
 Node *btree::search(int key, Node *leaf){
 if(leaf != NULL){
 if(key == leaf->weight){
 return leaf;
 }
 if(key < leaf->weight){
 return search(key, leaf->left);
 }else{
 return search(key, leaf->right);
 }
 }else{
 return NULL;
 }
 }
 
 Node *btree::search(int key){
 return search(key, root);
 }
 
 void btree::destroy_tree(){
 destroy_tree(root);
 }
 
 void btree::inorder_print(){
 inorder_print(root);
 cout << "\n";
 }
 
 void btree::inorder_print(Node *leaf){
 if(leaf != NULL){
 inorder_print(leaf->left);
 cout << leaf->weight << ",";
 inorder_print(leaf->right);
 }
 }
 
 void btree::postorder_print(){
 postorder_print(root);
 cout << "\n";
 }
 
 void btree::postorder_print(Node *leaf){
 if(leaf != NULL){
 inorder_print(leaf->left);
 inorder_print(leaf->right);
 cout << leaf->weight << ",";
 }
 }
 
 void btree::preorder_print(){
 preorder_print(root);
 cout << "\n";
 }
 
 void btree::preorder_print(Node *leaf){
 if(leaf != NULL){
 cout << leaf->weight << ",";
 inorder_print(leaf->left);
 inorder_print(leaf->right);
 }
 }
 */

/* program to construct tree using inorder and preorder traversals */


/* A binary tree node has data, pointer to left child
 and a pointer to right child */
struct node
{
    char data;
    struct node* left;
    struct node* right;
};

/* Prototypes for utility functions */
int search(char arr[], int strt, int end, char value);
struct node* newNode(char data);

/* Recursive function to construct binary of size len from
 Inorder traversal in[] and Preorder traversal pre[].  Initial values
 of inStrt and inEnd should be 0 and len -1.  The function doesn't
 do any error checking for cases where inorder and preorder
 do not form a tree */
struct node* buildTree(char in[], char pre[], int inStrt, int inEnd)
{
    static int preIndex = 0;
    
    if(inStrt > inEnd)
        return NULL;
    
    /* Pick current node from Preorder traversal using preIndex
     and increment preIndex */
    struct node *tNode = newNode(pre[preIndex++]);
    
    /* If this node has no children then return */
    if(inStrt == inEnd)
        return tNode;
    
    /* Else find the index of this node in Inorder traversal */
    int inIndex = search(in, inStrt, inEnd, tNode->data);
    
    /* Using index in Inorder traversal, construct left and
     right subtress */
    tNode->left = buildTree(in, pre, inStrt, inIndex-1);
    tNode->right = buildTree(in, pre, inIndex+1, inEnd);
    
    return tNode;
}

/* UTILITY FUNCTIONS */
/* Function to find index of value in arr[start...end]
 The function assumes that value is present in in[] */
int search(char arr[], int strt, int end, char value)
{
    int i;
    for(i = strt; i <= end; i++)
    {
        if(arr[i] == value)
            return i;
    }
}

/* Helper function that allocates a new node with the
 given data and NULL left and right pointers. */
struct node* newNode(char data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    
    return(node);
}

/* This funtcion is here just to test buildTree() */
void printInorder(struct node* node)
{
    if (node == NULL)
        return;
    
    /* first recur on left child */
    printInorder(node->left);
    
    /* then print the data of node */
    printf("%c ", node->data);
    
    /* now recur on right child */
    printInorder(node->right);
}

/* Driver program to test above functions */
int main()
{
    string lineStr;
    bool in_line=true;
    
    while(getline(cin,lineStr)){
        char in[] = {'D', 'B', 'E', 'A', 'F', 'C'};
        char pre[] = {'A', 'B', 'D', 'E', 'C', 'F'};
        int len = sizeof(in)/sizeof(in[0]);
        struct node *root = buildTree(in, pre, 0, len - 1);
        
        /* Let us test the built tree by printing Insorder traversal */
        printf("Inorder traversal of the constructed tree is \n");
        printInorder(root);
        getchar();
    }
    
}

int main(){
    
    while(true) {
        string InExp, PreExp;
        cin >> InExp;
        cin >> PreExp;
        
        MyBinaryTreeOps mbtops;
        
        Node *root = nullptr;
        
        root = mbtops.constructTree( root, InExp, PreExp );
        
        int leaf_num = mbtops.leafNum( root );
        
        cout << leaf_num << endl;
        
        mbtops.deleteTree( root );
    }

    return 0;
}
