#include <stdio.h>
#include <string.h>

int main () {
    int n;
    int key; //allows user input for how many spaces to shift message
    char s1[100];
    
    
    printf("Enter your message for encryption\n");
    scanf(" %[^\n]", s1 );

    printf("insert your key\n");
    scanf("%d", &key);
    
    for( n=0 ; n < strlen(s1) ; n++ )   {
        if((s1[n] >= 65) && (s1[n] <= 90)){
            s1[n] = s1[n] + key;
        }
        if((s1[n]) > 90){
           s1[n] = s1[n] - 26;
        }
        
        if((s1[n] >= 97) && (s1[n] <= 122)){
            s1[n] = s1[n] + key - 32;
        }
        if((s1[n]) > 90){
           s1[n] = s1[n] - 26;
        }
    }
    
    printf("Your Encription is: %s\n", s1);
  
}
    