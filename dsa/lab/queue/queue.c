#include<stdio.h>
#include<stdlib.h>
#define MAX 20

int queue_arr[MAX];
int front = -1, rear = -1;

void insert(){
	int item;
	if(rear == MAX-1) printf("Overflow\n");
	else{
		if(front == -1) front = 0;
		printf("Enter the item to add: ");
		scanf("%d", &item);
		rear += 1;
		queue_arr[rear] = item;
	}
}

void delete(){
	if(front == -1 || front > rear) printf("Underflow\n");
	else{
		printf("Deleted item is %d\n", queue_arr[front]);
		front += 1;
	}
}

void display(){
	int i;
	if(front == -1) printf("No item to show\n");
	else{
		printf("Queue items\n");
		for(i = front; i<=rear; i++){
			printf("%d\n", queue_arr[i]);
		}
		printf("\n");
	}
}

int main(){
	int choice;
	while(1){
		printf("\n1. Insert element to queue\n2. Delete element from queue\n3. Display Element\n4. Exit\nEnter your choice: ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				insert();
				break;
			case 2: 
				delete();
				break;
			case 3:
				display();
				break;
			case 4: exit(0);
			default: printf("Enter valid choice\n");
		}
	}
	return 0;
}



