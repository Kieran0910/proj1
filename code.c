#include <stdio.h>
#include <string.h>

int main () {
    int n;
    int key; //allows user input for how many spaces to shift message
    char s1[100];
    fgets(s1);
    
    printf("Enter your message for encryption\n");
    scanf(" %s", s1 );

    printf("insert your key\n");
    scanf("%d", &key);
    
    for( n=0 ; n < strlen(string) ; n++ ){
          string[n] = string[n] + key;
        
          
    }
    printf("Your Encription is: %s\n", string);
  
