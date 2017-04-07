#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Node
{
    friend class Chain;
public:
    Node *left, *right;
    
    int data;
    
    Node();
    Node(const int e, Node* left=NULL, Node* right=NULL);
    ~Node();
};

class Chain
{
public:
    void InsertBack(int num);
    void InsertAfter(int num1, int num2);
    void Delete(int num);
    void DeleteAll(int num);
    
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
        std::string num = std::to_string(tmp->data);
        result.append(num);
        if(tmp->right != NULL)
            result.append("->");
        tmp = tmp->right;
    }
    return result;
}

string Chain::toStringL()
{
    Node* tmp = this->head;
    string result = "";
    if(tmp == NULL){
        result.append("Empty");
    }
    else {
        while(tmp->right != NULL) {
            tmp = tmp->right;
        }
        
        while(tmp != NULL) {
            std::string num = std::to_string(tmp->data);
            result.append(num);
            if(tmp->left != NULL)
                result.append("->");
            tmp = tmp->left;
        }
    }
    return result;
}

Node::Node()
{
    this->left = NULL;
    this->right = NULL;
}

Node::Node(const int e, Node* left, Node* right)
{
    this->data = e;
    this->left = left;
    this->right = right;
}

Node::~Node()
{
    this->left = NULL;
    this->right = NULL;
}

void Chain::InsertBack(int num)
{
    if(head == NULL){
        head = new Node(num, NULL, NULL);
    }
    else{
        Node* tmp = this->head;
        while(tmp->right != NULL) {
            tmp = tmp->right;
        }
        tmp->right = new Node(num, tmp, NULL);
    }
}

void Chain::Delete(int num)
{
    Node* tmp = this->head;
    while(tmp != NULL) {
        if(tmp->data != num){
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

void Chain::DeleteAll(int num)
{
    Node* tmp = this->head;
    while(tmp != NULL) {
        if(tmp->data != num){
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

int main()
{
    string cmd;
    Chain C;
    while(getline(cin,cmd)){
        size_t last_index = cmd.find_last_not_of("0123456789");
        string numstr = cmd.substr(last_index + 1);
        int num = stoi(numstr);
        if(cmd.substr(0,10) == "InsertBack"){
            C.InsertBack(num);
            string chain_disp = C.toString();
            cout << chain_disp << endl;
            string chain_dispL = C.toStringL();
            cout << chain_dispL << endl;
        }
        else if(cmd.substr(0,9) == "DeleteAll"){
            C.DeleteAll(num);
            string chain_disp = C.toString();
            cout << chain_disp << endl;
            string chain_dispL = C.toStringL();
            cout << chain_dispL << endl;
        }
        else if(cmd.substr(0,6) == "Delete"){
            C.Delete(num);
            /*
            string chain_disp = C.toString();
            cout << chain_disp << endl;
            string chain_dispL = C.toStringL();
            cout << chain_dispL << endl;
            */
        }
    }
    return 0;
}
