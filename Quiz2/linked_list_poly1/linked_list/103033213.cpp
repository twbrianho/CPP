#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class Node
{
    friend class Chain;
public:
    Node *left, *right;
    
    int pow;
    int coeff;
    
    Node();
    Node(const int pow, const int coeff, Node* left=NULL, Node* right=NULL);
    ~Node();
};

class Chain
{
public:
    void InsertBack(int pow, int coeff);
    void Delete(int pow);
    void DeleteAll(int pow);
    int Find(int pow);
    
    string toString();
    string toStringL();
    
    Node* head = NULL;
};

string Chain::toString()
{
    Node* tmp = this->head;
    string result = "";
    if(tmp == NULL){
        result.append("Empty");
    }
    while(tmp != NULL) {
        string num = to_string(tmp->coeff);
        result.append(num);
        if(tmp->right != NULL)
            result.append("->");
        tmp = tmp->right;
    }
    return result;
}

Node::Node()
{
    this->left = NULL;
    this->right = NULL;
}

Node::Node(const int pow, const int coeff, Node* left, Node* right)
{
    this->pow = pow;
    this->coeff = coeff;
    this->left = left;
    this->right = right;
}

Node::~Node()
{
    this->left = NULL;
    this->right = NULL;
}

void Chain::InsertBack(int pow, int coeff)
{
    if(head == NULL){
        head = new Node(pow, coeff, NULL, NULL);
    }
    else{
        Node* tmp = this->head;
        while(tmp->right != NULL) {
            tmp = tmp->right;
        }
        tmp->right = new Node(pow, coeff, tmp, NULL);
    }
}

void Chain::Delete(int pow)
{
    Node* tmp = this->head;
    while(tmp != NULL) {
        if(tmp->pow != pow){
            tmp = tmp->right;
        }
        else{
            if(tmp->left == NULL){
                if(tmp->right != NULL){
                    Node* rightnode = tmp->right;
                    rightnode->left = NULL;
                    head = tmp->right;
                    delete tmp;
                    break;
                }
                else{
                    head = NULL;
                    delete tmp;
                    break;
                }
            }
            else if(tmp->right == NULL){
                Node* leftnode = tmp->left;
                leftnode->right = NULL;
                delete tmp;
                break;
            }
            else{
                Node* leftnode = tmp->left;
                Node* rightnode = tmp->right;
                leftnode->right = rightnode;
                rightnode->left = leftnode;
                delete tmp;
                break;
            }
        }
    }
}

void Chain::DeleteAll(int coeff)
{
    Node* tmp = this->head;
    while(tmp != NULL) {
        if(tmp->coeff != coeff){
            tmp = tmp->right;
        }
        else{
            if(tmp->left == NULL){
                if(tmp->right != NULL){
                    Node* rightnode = tmp->right;
                    rightnode->left = NULL;
                    head = tmp->right;
                    Node* tmp2 = tmp;
                    tmp = tmp->right;
                    delete tmp2;
                }
                else{
                    head = NULL;
                    delete tmp;
                    break;
                }
            }
            else if(tmp->right == NULL){
                Node* leftnode = tmp->left;
                leftnode->right = NULL;
                delete tmp;
                break;
            }
            else{
                Node* leftnode = tmp->left;
                Node* rightnode = tmp->right;
                leftnode->right = rightnode;
                rightnode->left = leftnode;
                Node* tmp2 = tmp;
                tmp = tmp->right;
                delete tmp2;
            }
        }
    }
}

int Chain::Find(int pow)
{
    Node* tmp = this->head;
    while(tmp != NULL) {
        if(tmp->pow != pow){
            tmp = tmp->right;
        }
        else if(tmp->pow == pow){
            int coeff = tmp->coeff;
            return coeff;
        }
    }
    return 0;
}

int main()
{
    string nums;
    Chain C;
    bool first = true;
    while(getline(cin,nums)){
        istringstream iss(nums);
        int coeff, pow;
        while(iss >> coeff >> pow){
            if(first)C.InsertBack(pow, coeff);
            else{
                int C_coeff = C.Find(pow);
                if(C_coeff == 0){
                    C.InsertBack(pow, coeff);
                }
                else{
                    int new_coeff = C_coeff + coeff;
                    C.Delete(pow);
                    C.InsertBack(pow, new_coeff);
                }
                C.DeleteAll(0);
            }
        }
        first = false;
    }
    bool all_zero = true;
    for(int i = 1000; i > -1000; i--){
        int co = C.Find(i);
        if(co != 0){
            if(all_zero == false)cout << " ";
            all_zero = false;
            cout << co << " " << i;
        }
    }
    if(all_zero)cout << "0 0" << endl;
    else cout << endl;
    return 0;
}




