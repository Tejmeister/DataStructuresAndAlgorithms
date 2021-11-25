#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;

/* A binary tree node has key, pointer to left  
child and a pointer to right child */
class TreeNode {
	public:
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode() : val(0), left(NULL), right(NULL) {}
		TreeNode(int x) : val(x), left(NULL), right(NULL) {}
		TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

 class TreeNodeWithDistance
 {
	public:
		TreeNode *node;
		int hd;
		TreeNodeWithDistance() : hd(0), node(NULL) {}
		TreeNodeWithDistance(int x) : hd(x) {}
		TreeNodeWithDistance(TreeNode *n, int x) : node(n), hd(x) {}
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
TreeNode* newNode(int key) 
{ 
	TreeNode* temp = new TreeNode(key); 
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

// Zig zag level order traversal
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

// Left side view (BFS)
vector<int> leftSideView(TreeNode *root){
	vector<int> result;
	if(root == NULL)
		return result;
	queue<TreeNode*> q;
	TreeNode *temp;
	q.push(root);

	while(!q.empty()){
		result.push_back(q.front()->val);
		int s = q.size();
		for(int i=0; i<s; i++){
			temp = q.front();
			q.pop();
			if(temp->left)
				q.push(temp->left);
			if(temp->right)
				q.push(temp->right);
		}
	}

	return result;
}

// Right side view (BFS)
vector<int> rightSideView(TreeNode *root){
	vector<int> result;
	if(root == NULL)
		return result;
	queue<TreeNode*> q;
	TreeNode *temp;
	q.push(root);

	while(!q.empty()){
		result.push_back(q.front()->val);
		int s = q.size();
		for(int i=0; i<s; i++){
			temp = q.front();
			q.pop();
			if(temp->right)
				q.push(temp->right);
			if(temp->left)
				q.push(temp->left);
		}
	}
	return result;
}

// leftSide traversal for boundary
void leftSideTraversal(TreeNode *root, vector<int>& result){
	if(root == NULL)
		return;
	if(root->left){
		result.push_back(root->val);
		leftSideTraversal(root->left, result);
	}
	else if(root->right){
		result.push_back(root->val);
		leftSideTraversal(root->right, result);
	}
	// do nothing if it is a leaf node, this way we avoid
    // duplicates in output
}

// rightSide traversal for boundary
void rightSideTraversal(TreeNode *root, vector<int>& result){
	if(root == NULL)
		return;
	// since we want the right side traversal in reverse order we first call the function recursively
	// and then push in result vector
	if(root->right){
		rightSideTraversal(root->right, result);
		result.push_back(root->val);
	}
	else if(root->left){
		rightSideTraversal(root->left, result);
		result.push_back(root->val);
	}
	// do nothing if it is a leaf node, this way we avoid
    // duplicates in output
}

// leaves traversal
void leavesTraversal(TreeNode *root, vector<int>& result){
	if(root == NULL)
		return;
	leavesTraversal(root->left, result);
	if(root->left == NULL && root->right == NULL)
		result.push_back(root->val);
	leavesTraversal(root->right, result);
}

// Boundary traversal
vector<int> boundaryTraversal(TreeNode *root){
	vector<int> result;
	if(root == NULL)
		return result;

	result.push_back(root->val);

	leftSideTraversal(root->left, result);
	leavesTraversal(root->left, result);
	leavesTraversal(root->right, result);
	rightSideTraversal(root->right, result);

	return result;
}

// Bottom View
vector<int> bottomView(TreeNode *root){
	vector<int> result;
	if(root == NULL)
		return result;
	queue<TreeNodeWithDistance*> q;

	// horizontal distance -> node.val
	unordered_map<int, int> m;
	TreeNodeWithDistance *temp = new TreeNodeWithDistance(root, 0);

	q.push(temp);

	while(!q.empty()){
		temp = q.front();
		q.pop();

		m[temp->hd] = temp->node->val;

		if(temp->node->left){
			q.push(new TreeNodeWithDistance(temp->node->left, temp->hd - 1));
		}
		if(temp->node->right){
			q.push(new TreeNodeWithDistance(temp->node->right, temp->hd + 1));
		}
	}

	unordered_map<int,int>::iterator i;
	for(i=m.begin(); i!=m.end(); i++){
		//cout<<i->first<<" "<<i->second<<endl;
		result.push_back(i->second);
	}

	return result;
}

// Top View
vector<int> topView(TreeNode *root){
	vector<int> result;
	if(root == NULL)
		return result;
	queue<TreeNodeWithDistance*> q;
	unordered_map<int, int> m;
	TreeNodeWithDistance *temp = new TreeNodeWithDistance(root, 0);

	q.push(temp);

	while(!q.empty()){
		temp = q.front();
		q.pop();
		if(m.find(temp->hd) == m.end())
			m[temp->hd] = temp->node->val;

		if(temp->node->left){
			q.push(new TreeNodeWithDistance(temp->node->left, temp->hd - 1));
		}
		if(temp->node->right){
			q.push(new TreeNodeWithDistance(temp->node->right, temp->hd + 1));
		}
	}

	unordered_map<int,int>::iterator i;
	for(i=m.begin(); i!=m.end(); i++){
		cout<<i->first<<" "<<i->second<<endl;
		result.push_back(i->second);
	}

	return result;
}

// Diagonal traversal
void diagonalTraversalUtil(TreeNode *root, int d, unordered_map<int, vector<int> > &diagonalPrint){
	if(root == NULL)
		return;

	diagonalPrint[d].push_back(root->val);

	diagonalTraversalUtil(root->left, d+1, diagonalPrint);
	diagonalTraversalUtil(root->right, d, diagonalPrint);
}

vector<vector<int> > diagonalTraversal(TreeNode *root){
	unordered_map<int, vector<int> > m;
	diagonalTraversalUtil(root, 0, m);

	vector<vector<int> > result;

	for (auto it :m)
    {
        result.push_back(it.second);
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

int getHeight(TreeNode *root){
	if(root == NULL)
		return 0;
	if(root->left == NULL && root->right == NULL)
		return 1;
	return 1 + max(getHeight(root->left), getHeight(root->right));
}

int diameter(TreeNode *root){
	if(root == NULL)
		return 0;
	int leftHeight = getHeight(root->left);
	int rightHeight = getHeight(root->right);

	int leftDiameter = diameter(root->left);
	int rightDiameter = diameter(root->right);

	return max(leftHeight + rightHeight + 1, max(leftDiameter, rightDiameter));
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	// if current node is same as P or Q then return
	if(root == p || root == q)
		return root;
	// if current node is leaf node return NULL
	if(root->left == NULL && root->right == NULL)
		return NULL;
	
	TreeNode *leftParent = NULL, *rightParent = NULL;
	
	// if left node present then search in left
	if(root->left)
		leftParent = lowestCommonAncestor(root->left, p, q);
	// if right node present then search in right
	if(root->right)
		rightParent = lowestCommonAncestor(root->right, p, q);
	
	// if both parents are present then that element is your LCA
	if(leftParent && rightParent)
		return root;
	
	// else non null parent is the LCA
	return leftParent ? leftParent : rightParent;
}

bool isMirror(TreeNode* root1, TreeNode* root2){
	if(root1 == NULL && root2 == NULL)
		return true;
	if(root1 == NULL || root2 == NULL)
		return false;
	
	return root1->val == root2->val && isMirror(root1->left, root2->right) && isMirror(root1->right, root2->left);
}
    
bool isSymmetric(TreeNode* root) {
	return isMirror(root, root);
}

TreeNode* buildTreeHelperPre(vector<int>& preorder, vector<int>& inorder, int& rootIndex, unordered_map<int, int>& mp, int start, int end){
	if(start > end)
		return NULL;
	
	int rootValue = preorder[rootIndex++];
	TreeNode *root = new TreeNode(rootValue);
	
	root->left = buildTreeHelperPre(preorder, inorder, rootIndex, mp, start, mp[rootValue]-1);
	root->right = buildTreeHelperPre(preorder, inorder, rootIndex, mp, mp[rootValue]+1, end);
	
	return root;
}

TreeNode* buildTreePreIn(vector<int>& preorder, vector<int>& inorder) {
	unordered_map<int, int> mp;
	int rootIndex = 0;
	
	for(int i=0; i<inorder.size(); i++)
		mp[inorder[i]] = i;
	
	return buildTreeHelperPre(preorder, inorder, rootIndex, mp, 0, inorder.size()-1);
}

TreeNode* buildTreeHelperPost(vector<int>& inorder, vector<int>& postorder, int& rootIndex, unordered_map<int, int>& mp,  int start, int end){
	if(start > end)
		return NULL;
	
	int rootVal = postorder[rootIndex--];
	TreeNode* root = new TreeNode(rootVal);
	
	root->right = buildTreeHelperPost(inorder, postorder, rootIndex, mp, mp[rootVal]+1, end);
	
	root->left = buildTreeHelperPost(inorder, postorder, rootIndex, mp, start, mp[rootVal]-1);
	
	
	return root;
}

TreeNode* buildTreePostIn(vector<int>& inorder, vector<int>& postorder) {
	unordered_map<int, int> mp;
	int rootIndex = postorder.size()-1;
	
	for(int i=0; i<inorder.size(); i++)
		mp[inorder[i]] = i;
	
	return buildTreeHelperPost(inorder, postorder, rootIndex, mp, 0, inorder.size()-1);
}

int main(){
	TreeNode* root = newNode(10); 
    root->left = newNode(11); 
    root->left->left = newNode(7); 
    root->left->right = newNode(12);
    root->left->right->right = newNode(101);
    root->right = newNode(9); 
    root->right->left = newNode(15); 
    root->right->right = newNode(8); 
  
    /*
									10(0)
						11(-1)						9 (1)
					7(-2)		12(0)			15(0)		8 (2)
	    							101(1)
	    */
    vector<int> result;
    vector<vector<int> > re;
    re = diagonalTraversal(root);
    printVector(re);

	cout<<"Height: "<<getHeight(root)<<endl; 

	cout<<"Diameter: "<<diameter(root)<<endl;

	return 0;
}