#include<stdio.h>
#include<string.h>


int mult(unsigned int x, unsigned int key, unsigned int mod){
  unsigned long int k = 1;
  for(int i = 1; i<=key; i++) k = (k*x) % mod;
  return (unsigned int) k;
}

int main(){
  char data[100];
  unsigned int pt[100], ct[100];
  
  // RSA params
  unsigned int encKey = 13, decKey = 17, mod = 253;

  printf("Enter the data: ");
  scanf("%s", data);
  
  for(int i = 0; i<strlen(data); i++) pt[i] = data[i];

  // Encrypted data
  printf("Cipher Text: ");
  for(int i = 0; i<strlen(data); i++){
    ct[i] = mult(pt[i], encKey, mod);
    printf("%d ", ct[i]);
  }
  printf("\n");

  // Decrypted data
  printf("Plain Text: ");
  for(int i = 0; i<strlen(data); i++){
    pt[i] = mult(ct[i], decKey, mod);
    printf("%c", pt[i]);
  }

  printf("\n");

  return 0;
}
