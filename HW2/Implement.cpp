#include <iostream>
#include <string>
#include "Implement.h"

using namespace std;
//The length of linked list will not exceed 100,000.

void Implement::InsertBack(int num)
{
  Node* tmp = this->head;
	if(tmp == NULL){
		head = new Node(num);
	}
  else{
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
      tmp->right = new Node(num2, tmp, NULL);
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
      Node* leftnode = tmp->left;
      Node* rightnode = tmp->right;
      leftnode->right = rightnode;
      rightnode->left = leftnode;
      delete tmp;
      break;
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
      Node* leftnode = tmp->left;
      Node* rightnode = tmp->right;
      leftnode->right = rightnode;
      rightnode->left = leftnode;
      Node* tmp2 = tmp->right;
      delete tmp;
      Node* tmp = tmp2;
    }
  }
}
