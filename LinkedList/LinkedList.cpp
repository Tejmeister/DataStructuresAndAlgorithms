#include<bits/stdc++.h>

using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode() : val(0), next(NULL) {}
 	ListNode(int x) : val(x), next(NULL) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void displayList(ListNode *head){
	if(head == NULL)
		return;
	ListNode *temp = head;
	cout<<"HEAD->";
	while(temp!=NULL){
		cout<<temp->val<<" -> ";
		temp = temp->next;
	}
	cout<<"NULL\n";
}

ListNode* newNode(int val){
	ListNode *temp = new ListNode(val);
	return temp;
}

void deleteList(ListNode** head){
	ListNode *temp = *head;
	ListNode *prev = temp;
	while(temp!=NULL){
		prev = temp;
		temp = temp->next;
		cout<<"Deleting node: "<<prev->val<<endl;
		delete prev;
	}
	*head = NULL;
}

ListNode* deepCopy(ListNode *head){
	ListNode *dummyHead = new ListNode(0);
	ListNode *temp = dummyHead;
	//head = head->next;
	while(head!=NULL){
		temp->next  = new ListNode(head->val);
		head = head->next;
		temp = temp->next;
	}

	return dummyHead->next;
}

void push(ListNode** head, int val){
	ListNode *temp = *head;
	while(temp->next!=NULL){
		temp = temp->next;
	}
	temp->next = new ListNode(val);
}

int main(){
	ListNode *head = new ListNode(101);
	push(&head, 102);
	push(&head, 1);
	push(&head, 43);
	push(&head, 54);
	push(&head, 16);
	push(&head, 5);
	push(&head, 81);
	push(&head, 28);

	displayList(head);
	push(&head, 7);
	displayList(head);
	return 0;
}