#include <stdio.h>
#include <string.h>

int main () {
    int n, input;
    int key; //allows user input for how many spaces to shift message
    char s1[100]; //initilise a string
    
    printf("Enter your message to encrypt or decrypt:\n"); //use input
    scanf(" %[^\n]", s1 ); //scans user input into the string created above

    printf("insert your key\n"); //key allows for rotation of given amount
    scanf("%d", &key);
    do {
    printf("Select from options below:\n"); //allows user to select what to do with there messege
    printf("1 = Encrypt Message.\n");
    printf("2 = Decrypt Message.\n");
    scanf("%d", &input);
    }
    while(input < 1 || input >2);
    
    if(input == 1)  { //Encription
        for( n=0 ; n < strlen(s1) ; n++ )   {
            if((s1[n] >= 65) && (s1[n] <= 90))  { //if a capital letter
                s1[n] = s1[n] - key;  //minuses the key given
                if((s1[n]) < 65)    { 
                    s1[n] = s1[n] + 26; //allows for rollover if before A
                }
            }
            if((s1[n] >= 97) && (s1[n] <= 122)) {
                s1[n] = s1[n] - key - 32;
                if((s1[n]) < 65)    {
                    s1[n] = s1[n] + 26;
                }
            }
        }
    
        printf("Your Encription is: %s\n", s1); //Prints Encription
    }
    if(input == 2)  { //Decryption
        for( n=0 ; n < strlen(s1) ; n++ )   {
            if((s1[n] >= 65) && (s1[n] <= 90))  { //If a capitial letter entered 
                s1[n] = s1[n] + key; // shifts number of spaces
                if((s1[n]) > 90)    {
                    s1[n] = s1[n] - 26; //allows for rollover from Z back to A
                }
            }
            if((s1[n] >= 97) && (s1[n] <= 122)) { //allows for input of lowercase letters
                s1[n] = s1[n] + key - 32; //converts to capital letters and adds the key
                if((s1[n]) > 90)    { 
                    s1[n] = s1[n] - 26; //allows for rollover 
                }
            }
        }
    
        printf("Your Decryption is: %s\n", s1); //prints the Decryption string to user
        }
    }

