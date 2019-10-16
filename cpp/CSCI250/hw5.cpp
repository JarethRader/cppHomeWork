#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

struct nodeType{
	int value;
	nodeType* left;
	nodeType* right;
};

int rightLeaves(nodeType* root);

int main(){
	
	nodeType* list1 = new nodeType;
	nodeType* n1 = new nodeType;
	nodeType* n2 = new nodeType;
	nodeType* n3 = new nodeType;
	nodeType* n4 = new nodeType;
	nodeType* n5 = new nodeType;
	list1->value = 5;
	list1->right = n1;
	list1->left = n3;
	n1->value = 15;
	n1->right = n2;
	n2->value = 9;
	n2->left = nullptr;
	n2->right = nullptr;
	n3->value = 7;
	n3->right = n4;
	n3->left = n5;
	n4->value = 21;
	n4->right = nullptr;
	n4->left = nullptr;
	n5->value = 18;
	n5->right = nullptr;
	n5->left = nullptr;
	
	int right = rightLeaves(list1);
	cout << "Count right nodes of List 1: " << right << endl;
	
	nodeType* list2 = nullptr;
	
	int right2 = rightLeaves(list2);
	cout << "Count right nodes of list 2: " << right2 << endl;
	
	cin.get();
	return 0;
}

int rightLeaves(nodeType* root){
	if(root == NULL) return 0;
	else if(root->right == NULL && root->right->left == NULL && root->right->right == NULL) return 1;
	else return rightLeaves(root->left) + rightLeaves(root->right);
}