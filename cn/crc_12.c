#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define POLY 0x80F


int main(){
	char data[100];
	unsigned short crc = 0;
	int n;

	printf("Enter the data: ");
	scanf("%s", data);

	n = strlen(data);
	for(int i = 0; i<n; i++){
		crc ^= (unsigned short)(data[i]) << 4;
		for(int j = 0; j<8; j++){
			if(crc & 0x800) crc = (crc << 1) ^ POLY;
			else crc <<= 1;
		}
	}

	printf("CRC-12 code: %03x\n", crc & 0xFFF);
	return 0;
}	
