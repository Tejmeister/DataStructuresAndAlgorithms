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

void printVector(vector<int> v){
	vector<int>::iterator i;
	for(i=v.begin(); i!=v.end(); i++){
		cout<<*i<<" ";
	}
	cout<<endl;
} 

void printVector(vector<vector<int> > v){
	
	for(int i=0; i<v.size(); i++){
		for(int j=0; j<v[i].size(); j++){
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
} 
  
/* function to create a new node of tree and  
return pointer */
struct TreeNode* newNode(int key) 
{ 
    struct TreeNode* temp = new TreeNode(key); 
    temp->left = temp->right = NULL; 
    return temp; 
};

// Recursive Inorder Traversal
void inorder(TreeNode *root, vector<int>& v){
	if(root == NULL)
		return;
	inorder(root->left, v);
	v.push_back(root->val);
	inorder(root->right, v);
}

// Iterative Inorder Traversal
vector<int> inorder(TreeNode *root){
	vector<int> result;

	if(root == NULL)
		return result;

	stack<TreeNode*> s;

	TreeNode *temp = root;
	while(!s.empty() || temp!=NULL){
		while(temp != NULL){
			s.push(temp);
			temp = temp->left;
		}

		temp = s.top();
		s.pop();

		result.push_back(temp->val);

		temp = temp->right;
	}

	return result; 
}

// Recursive Preorder Traversal
void preorder(TreeNode *root, vector<int>& v){
	if(root == NULL)
		return;
	v.push_back(root->val);
	preorder(root->left, v);
	preorder(root->right, v);
}

// Iterative Preorder Traversal
vector<int> preorder(TreeNode *root){
	vector<int> result;

	if(root == NULL)
		return result;

	stack<TreeNode*> s;
	s.push(root);
	TreeNode *temp = root;
	while(!s.empty()){
		temp = s.top();
		s.pop();

		result.push_back(temp->val);

		if(temp->right)
			s.push(temp->right);
		if(temp->left)
			s.push(temp->left);

	}

	return result; 
}

// Recursive Postorder Traversal
void postorder(TreeNode *root, vector<int>& v){
	if(root == NULL)
		return;

	postorder(root->left, v);
	postorder(root->right, v);
	v.push_back(root->val);
}

// Iterative Postorder Traversal
vector<int> postorder(TreeNode *root){
	vector<int> result;

	if(root == NULL)
		return result;

	stack<TreeNode*> s;
	s.push(root);
	TreeNode *temp = root;
	while(!s.empty()){
		temp = s.top();
		s.pop();

		result.push_back(temp->val);

		
		if(temp->left)
			s.push(temp->left);
		if(temp->right)
			s.push(temp->right);

	}
	reverse(result.begin(), result.end());
	return result; 
}

// Level Order Traversal (BFS)
vector<int> levelOrder(TreeNode *root){
	vector<int> result;
	if(root == NULL)
		return result;
	queue<TreeNode*> q;
	TreeNode *temp;
	q.push(root);
	while(!q.empty()){
		temp = q.front();
		q.pop();
		result.push_back(temp->val);
		if(temp->left)
			q.push(temp->left);
		if(temp->right)
			q.push(temp->right);
	}

	return result;
}

// Level order level by levl
vector<vector<int> > levelOrderLevel(TreeNode *root){
	vector<vector<int> > result;
	if(root == NULL)
		return result;
	queue<TreeNode*> q;
	TreeNode *temp;
	q.push(root);
	while(!q.empty()){
		vector<int> t;
		int s = q.size();
		for(int i=0; i<s; i++){
			temp = q.front();
			q.pop();
			t.push_back(temp->val);
			//cout<<temp->val<<" ";
			if(temp->left)
				q.push(temp->left);
			if(temp->right)
				q.push(temp->right);
		}
		//cout<<endl;
		result.push_back(t);
	}

	return result;
}

vector<int> zigzagLevelOrder(TreeNode *root){
	vector<int> result;
	if(root == NULL)
		return result;
	queue<TreeNode*> q;
	TreeNode *temp;
	q.push(root);
	
	bool isLevelOdd = false;
	while(!q.empty()){
		vector<int> t;
		int s = q.size();
		for(int i=0; i<s; i++){
			temp = q.front();
			q.pop();
			t.push_back(temp->val);
			//cout<<temp->val<<" ";
			if(temp->left)
				q.push(temp->left);
			if(temp->right)
				q.push(temp->right);
		}
		//cout<<endl;
		if(isLevelOdd){
		    reverse(t.begin(), t.end());
		    
		}
		isLevelOdd = !isLevelOdd;
        result.insert(result.end(), t.begin(), t.end());
	}

	return result;
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
    vector<int> result;
    vector<vector<int> > re;
    result = zigzagLevelOrder(root);
    printVector(result);

	return 0;
}