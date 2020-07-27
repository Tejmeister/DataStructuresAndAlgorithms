#include<bits/stdc++.h>

using namespace std;

/* A binary tree node has key, pointer to left  
child and a pointer to right child */
struct Node { 
    int key; 
    struct Node *left, *right; 
}; 
  
/* function to create a new node of tree and  
return pointer */
struct Node* newNode(int key) 
{ 
    struct Node* temp = new Node; 
    temp->key = key; 
    temp->left = temp->right = NULL; 
    return temp; 
};

void inorder(Node *root){
	if(root == NULL)
		return;
	inorder(root->left);
	cout<<root->key<<" ";
	inorder(root->right);
}

int main(){
	struct Node* root = newNode(10); 
    root->left = newNode(11); 
    root->left->left = newNode(7); 
    root->left->right = newNode(12); 
    root->right = newNode(9); 
    root->right->left = newNode(15); 
    root->right->right = newNode(8); 
  
    /*
								10
						11				9
					7		12		15		8
	    */

    cout << "Inorder traversal before deletion : "; 
    inorder(root); 
  
    int key = 11; 
    //root = deletion(root, key); 
  
    cout << endl; 
    cout << "Inorder traversal after deletion : "; 
    inorder(root); 
	return 0;
}