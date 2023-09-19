#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node* next;
};


Node* push(Node* head, int new_data)
{
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = head;
	head = new_node;
	return head;
}

Node* removeElements(Node* head, int data)
{
	if(head == nullptr)
        return head;
    while(head && head->data == data)
        head = head->next;
        
    Node *current = head;
    while(current && current->next) {
        if(current->next->data != data)
            current = current->next;
        else
            current->next = current->next->next;
    }
    return head;
}

void printList(Node* node)
{
	while (node) {
		cout << node->data << " ";
		node = node->next;
	}
}

int main()
{
	Node* head = NULL;
	head = push(head, 7);
	head = push(head, 2);
	head = push(head, 3);
	head = push(head, 2);
	head = push(head, 8);
	head = push(head, 1);
	head = push(head, 2);
	head = push(head, 2);

	int key = 2;
	head = removeElements(head, key);

	printList(head);
	return 0;
}
