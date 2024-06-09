// Encryption and decryption
//
#include<stdio.h>
#include<string.h>

int mult(char x, int key, int modulus){
  unsigned long int k = 1;
  for(int i = 0; i<key; i++){
    k = (k*x) % modulus;
  }
  return (unsigned int) k;
}


int main(){

  char text[100];
  int n;
  int pt[100], ct[100];
  int encryptionKey = 13, decryptionKey = 17, modulus = 253;

  printf("Enter the message: ");
  scanf("%s", text);
  
  n = strlen(text);

  // copied the value
  for(int i = 0; i<n; i++){
    pt[i] = text[i];
  }

  // Encryption // alpha = 5
  printf("Cipher Text: ");
  for(int i = 0; i<n; i++){
    ct[i] = mult(pt[i], encryptionKey, modulus);
    printf("%d", ct[i]);
  }

  // printf("\n");

  printf("Plain Text: ");
  for(int i = 0; i<n; i++){
    pt[i] = mult(ct[i], decryptionKey, modulus);
    printf("%c", pt[i]);
  }

  //printf("\n\n");




  return 0;
}
