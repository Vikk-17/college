#include<stdio.h>

int main(){
	int sent = 0, window_size, ack;

	printf("Enter the window size: ");
	scanf("%d", &window_size);

	while(1){
		for(int i = 0; i<window_size; i++){
			printf("Frame %d has been transmitted\n", sent);
			sent ++;
			if (sent == window_size) break;
		}
		printf("Enter the last acknowledgement recieved: ");
		scanf("%d", &ack);
		if(ack == window_size) break;
		else sent = ack;
	}
	return 0;
}
