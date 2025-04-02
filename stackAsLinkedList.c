#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *link;
};

void addAtEnd(struct node*, int);
void traverse(struct node*);
struct node* deleteAtLast(struct node*);

int main() {
	struct node *head = (struct node*)malloc(sizeof(struct node));
	head->link = NULL;
	head->data = 45;
	
	addAtEnd(head, 98);
	addAtEnd(head, 3);
	
	traverse(head);
	printf("After deletion\n"); 
	head = deleteAtLast(head);
	traverse(head);
	return 0;
}

void addAtEnd(struct node* head, int data) {
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->link = NULL;
	temp->data = data;
	
	struct node *ptr = head;
	while(ptr->link != NULL) {
		ptr = ptr->link;
	}
	ptr->link = temp;
}

void traverse(struct node*head) {
	if(head == NULL) {
		printf("The list is empty.");
		return;
	}
	struct node *ptr = head;
	while(ptr != NULL) {
		printf("%d ", ptr->data);
		ptr = ptr->link;
	}
	printf("\n");
}

struct node* deleteAtLast(struct node *head) {
	if(head == NULL) {
		printf("List is empty");
		exit(1);
	}
	struct node *temp = head;
	struct node *temp2 = head;
	while(temp->link != NULL) {
		temp2 = temp;
		temp = temp->link;
	}
	temp2->link = NULL;
	free(temp);
	temp = NULL;
	return head; 
	/*Note that there is no need to return head
	as we are not updataing it in the function */
	
}
