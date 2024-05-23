#include<stdio.h>

int main(){
	int i, j, count = 0;
	int data[10], stuffed_data[20];

	printf("Enter data to be stuffed: ");
	for(i = 0; i<10; i++)
		scanf("%d", &data[i]);

	j = 0;
	for(i = 0; i<10; i++){
		stuffed_data[j] = data[i];
		if(data[i] == 1) count++;
		else count = 0;
		j++;
		if(count == 5){
			stuffed_data[j] = 0;
			j++;
			count = 0;
		}
	}
	// print stuffed data
	for(i = 0; i<j; i++) printf("%d", stuffed_data[i]);
	printf("\n");
	return 0;
}
