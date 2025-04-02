#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *link;
//self referencial structure is a structure which contain pointer to a structure of the same type
};

void traverse(struct node *);

int main() {
	struct node *head = malloc(sizeof(struct node));
	head->data = 45;
	head->link = NULL;  
	
	struct node *current = malloc(sizeof(struct node));
	current->data = 50;
	current->link = NULL;
	head->link = current;
	
	//hamley current lai nei feri use garna sakxau
	//unnecessary pointer feri kina banairaknu bhanera
	
	current = malloc(sizeof(struct node));
	current->data = 55;
	current->link = NULL;
	
	head->link->link = current;
	
	current = malloc(sizeof(struct node));
	current -> data = 60;
	current -> link = NULL;
	
	head->link->link->link = current;
	traverse(head);
	return 0;
}

void traverse(struct node *head) {
	int count = 0;
	if(head == 0) {
		printf("Linked List is empty");
	}
	struct node *ptr = NULL;
	ptr = head;
	printf("Data: ");
	while(ptr != NULL) {
		count ++;
		printf("%d ", ptr->data);
		ptr = ptr -> link;
		
	}
	printf("\nTotal Node: %d", count);
}
