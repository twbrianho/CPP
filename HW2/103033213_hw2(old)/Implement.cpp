#include <iostream>
#include <string>
#include "Implement.h"

using namespace std;

void Implement::InsertBack(int num)
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

void Implement::InsertAfter(int num1, int num2)
{
  Node* tmp = this->head;
  while(tmp != NULL) {
    if(tmp->data != num1){
      tmp = tmp->right;
    }
		else{
      if(tmp->right != NULL){
        Node* nextnode = tmp->right;
        tmp->right = new Node(num2, tmp, nextnode);
        nextnode->left = tmp->right;
      }
      else{
        tmp->right = new Node(num2, tmp, NULL);
      }
      break;
    }
	}
}

void Implement::Delete(int num)
{
  Node* tmp = this->head;
  while(tmp != NULL) {
    if(tmp->data != num){
      tmp = tmp->right;
    }
		else{
      if(tmp->left == NULL){
        Node* rightnode = tmp->right;
        rightnode->left = NULL;
        head = tmp->right;
        delete tmp;
        break;
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

void Implement::DeleteAll(int num)
{
    Node* tmp = this->head;
    while(tmp != NULL) {
        if(tmp->data != num){
            tmp = tmp->right;
        }
        else{
            if(tmp->left == NULL){
                Node* rightnode = tmp->right;
                rightnode->left = NULL;
                head = tmp->right;
                Node* tmp2 = tmp;
                tmp = tmp->right;
                delete tmp2;
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
