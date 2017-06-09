#include "MyBinaryTreeOps.h"
#include <string>
#include <stack>

using namespace std;

bool IsNumber(char C){
    if(C >= '0' && C <= '9') return true;
    else if(C == '-') return true;
    return false;
}

Node *MyBinaryTreeOps::constructTree(Node *root, string treeStr)const{
    int ptr = 1;
    int A[10000] = {0};
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
