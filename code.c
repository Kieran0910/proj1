#include <stdio.h>
#include <string.h>

int main () {
    int n, input, RS;
    int key; //allows user input for how many spaces to shift message
    char s1[100];//initilise a string
    char s2[100];//only used in substitution for cipher 
    char s3[100];
    char f1[100];
    char f2[200];
    
    do  {
    printf("\nDo you want to use Substition Cipher \nOr The rotation Cipher\n");
    printf("\n1. Rotation Cipher\n");
    printf("2. Substitution Cipher\n");
    scanf("%d", &RS);
    } while(RS < 1 || RS >2);
    
    
    if(RS == 1) {
        printf("\nEnter your message:\n"); //use input
        scanf(" %[^\n]", s1 ); //scans user input into the string created above
    
        printf("\ninsert your key\n"); //key allows for rotation of given amount
        scanf("%d", &key);
        do  {
            printf("\nSelect from options below:\n"); //allows user to select what to do with there messege
            printf("1 = Encrypt Message.\n");
            printf("2 = Decrypt Message.\n");
            scanf("%d", &input);
        }   while(input < 1 || input >2);
    
        if(input == 1)  { //Encription
            for( n=0 ; n < strlen(s1) ; n++ )   {
                if((s1[n] >= 65) && (s1[n] <= 90))  { //if a capital letter
                    f1[n] = s1[n] - key;  //minuses the key given
                    if((f1[n]) < 65)    { 
                        f1[n] = f1[n] + 26; //allows for rollover if before A
                    }
                }
                if((s1[n] >= 97) && (s1[n] <= 122)) { //not a capital
                    f1[n] = s1[n] - key - 32;
                    if((f1[n]) < 65)    {
                        f1[n] = f1[n] + 26;
                    }
                }
            }
            printf("\nRecieved input is: %s\n", s1);
            printf("Your Encription is: %s\n", f1);//Prints Encription
            
        }
        if(input == 2)  { //Decryption
            for( n=0 ; n < strlen(s1) ; n++ )   {
                if((s1[n] >= 65) && (s1[n] <= 90))  { //If a capitial letter entered 
                    f1[n] = s1[n] + key; // shifts number of spaces
                    if((f1[n]) > 90)    {
                        f1[n] = f1[n] - 26; //allows for rollover from Z back to A
                    }
                }
                if((s1[n] >= 97) && (s1[n] <= 122)) { //allows for input of lowercase letters
                    f1[n] = s1[n] + key - 32; //converts to capital letters and adds the key
                    if((f1[n]) > 90)    { 
                        f1[n] = f1[n] - 26; //allows for rollover 
                    }
                }
            }
            printf("\nRecieved input is: %s\n", s1); //prints the input to user
            printf("Your Decription is: %s\n", f1);//Prints Encription
        }
    }
    if(RS == 2) {
        printf("\nEnter your message:\n");
        scanf(" %[^\n]", s1 ); //user input
        printf("Enter Ciper code:\n");
        scanf(" %[^\n]", s2 );
        do  {
            printf("\nSelect from options below:\n"); //allows user to select what to do with there messege
            printf("1 = Encrypt Message.\n");
            printf("2 = Decrypt Message.\n");
            scanf("%d", &input);
        }   while(input < 1 || input >2);
        
        if(input == 1) { //encription of message
            for( n=0 ; n < strlen(s1) ; n++ )   { //taking users message into ascii 
                if((s1[n] >= 65) && (s1[n] <= 90)) {//capital letters
                    s1[n] = s1[n] - 65; //get to 0 - 26 value  
                }
                if((s1[n] >= 97) && (s1[n] <= 122)) {//lowercase letters
                    s1[n] = s1[n] - 96; //get lowercase to 0-25 value 
                }
                
            }
            
            for( n=0 ; n < strlen(s2) ; n++ ) { //users encription into ascii
                if((s2[n] >= 65) && (s2[n] <= 90)) {//capital letters
                    s2[n] = s2[n] - 65; //get to 0 - 25 value  
                }
                if((s2[n] >= 97) && (s2[n] <= 122)) {//lowercase letters
                    s2[n] = s2[n] - 96; //get lowercase to 0-25 value
                }
            }
            printf("Your Encription is: %s\n", s2);
        }
    }
}
