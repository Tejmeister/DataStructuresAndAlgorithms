#include<bits/stdc++.h>

using namespace std;

/* A binary tree node has key, pointer to left  
child and a pointer to right child */
struct TreeNode {
	int val;
	TreeNode *left;
  	TreeNode *right;
 	TreeNode() : val(0), left(NULL), right(NULL) {}
 	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
  
/* function to create a new node of tree and  
return pointer */
struct TreeNode* newNode(int key) 
{ 
    struct TreeNode* temp = new TreeNode(key); 
    temp->left = temp->right = NULL; 
    return temp; 
};

void inorder(TreeNode *root){
	if(root == NULL)
		return;
	inorder(root->left);
	cout<<root->val<<" ";
	inorder(root->right);
}

void deleteTree(TreeNode* root){
	if(root == NULL)
		return;
	deleteTree(root->left);
	deleteTree(root->right);
	cout<<"Deleting node: "<<root->val<<endl;
	delete root;
}

TreeNode* deepCopy(TreeNode *root){
	if(root == NULL)
		return root;
	TreeNode *temp = new TreeNode(root->val);
	temp->left = deepCopy(root->left);
	temp->right = deepCopy(root->right);
	return temp;
}

int main(){
	struct TreeNode* root = newNode(10); 
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

    cout<< "\nCloning tree";
    TreeNode *clone = deepCopy(root);
    root->right->right->left = newNode(122); 
	inorder(root);
    cout << "\nTrying to print tree after deletion : "; 
    inorder(clone);
	return 0;
}