#include <stdio.h>

int main () {
    int n, x;
    int key; //allows user input for how many spaces to shift message
    char string[100];
    
    printf("Enter your message for encryption\n");
    scanf("%s", &string);
    
    printf("insert your key");
    scanf("%d", &key);
    
    for(n=0;n>x;n++){
          string[n] = string[n] + key;
    }
  

}