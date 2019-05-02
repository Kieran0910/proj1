/* Below is code used to Encrypt and decrypt a series of messages, using either a rotation
cipher or substituition cipher. To get started select 1. rotation or 2. for substituition.
Type your Messege followed by enter, and your key followed by enter.
select to encript or decrpyt the message, printed to console will be entered message and the 
decrypted or encrypted message */

#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include<ctype.h>

#define SHIFT_MAX      26
#define NUMBER_OF_LETTERS    26
#define NUMBER_OF_DIGITS    10
#define CAESAR_CIPHER_SPECIAL_CHARS  " .!?,;:'()[]{}`"



int main () {
    int n, a, input, RS; /* n used for counter for letters in a message,input is where menu 
                            options are saved, RS is to chose rotaion or substtution */
    int key; //allows user input for how many spaces to shift message
    char s1[250];//initilise a string
    char s2[250]; //only used in substitution for cipher 
    char s3[250]; //used to allow for user input to be printed back to user
    char f1[250]; //
    char f2[250]; //
    char SimpleSubstitutionCipher_Code();
    
    do  {   //do while loop prints menu back to user if input is not a 1 or 2 
    printf("\nDo you want to use Substition Cipher \nOr The rotation Cipher\n");
    printf("\n1. Rotation Cipher\n");
    printf("2. Substitution Cipher\n");
    scanf("%d", &RS); //scans user input to RS which defines which if statement it is taken to next
    } while(RS < 1 || RS >2);
    
    
    if(RS == 1) { //if RS == 1 user is taken here and the rotation cipher is started 
        printf("\nEnter your message to encrypt or decrypt:\n"); 
        scanf(" %[^\n]", s1 ); //scans user input into the string s1
        printf("insert your key\n"); //key allows for a rotation of given amount
        scanf("%d", &key); //key is assigned to key
        do  { //once again a do while loop is used to make sure correct input
            printf("\nSelect from options below:\n"); //allows user to select what to do with there messege
            printf("1 = Encrypt Message.\n");
            printf("2 = Decrypt Message.\n");
            scanf("%d", &input);
        }   while(input < 1 || input >2); //menu will repeat if wrong input
    
        if(input == 1)  { //Encription for the rotation cipher 
            for( n=0 ; n < strlen(s1) ; n++ )   { // for loop to read each letter of string and subtract the key
                f1[n] = s1[n]; //allows for user input to be printed later
                if((s1[n] >= 65) && (s1[n] <= 90))  { //if a capital letter
                    s1[n] = s1[n] - key;  //minuses the key given
                    if((s1[n]) < 65)    { 
                        s1[n] = s1[n] + 26; //allows for rollover if before A
                    }
                }
                if((s1[n] >= 97) && (s1[n] <= 122)) { //lowercase letter entered 
                    s1[n] = s1[n] - key - 32;
                    if((s1[n]) < 65)    { //rollover from z-a 
                        s1[n] = s1[n] + 26;
                    }
                }
            }
            printf("\nRecieved input is: %s\n", f1); //prints users intial input
            printf("\nYour Encription is: %s\n", s1); //Prints final Encription
        }
        if(input == 2)  { //Decryption of rotation
            for( n=0 ; n < strlen(s1) ; n++ )   {
                f1[n] = s1[n];
                if((s1[n] >= 65) && (s1[n] <= 90))  { //If a capitial letter entered 
                    s1[n] = s1[n] + key; // shifts number of spaces
                    if((s1[n]) > 90)    {
                        s1[n] = s1[n] - 26; //allows for rollover from Z back to A
                    }
                }
                if((s1[n] >= 97) && (s1[n] <= 122)) { //allows for input of lowercase letters
                    f1[n] = s1[n];
                    s1[n] = s1[n] + key - 32; //converts to capital letters and adds the key
                    if((s1[n]) > 90)    { 
                        s1[n] = s1[n] - 26; //allows for rollover 
                    }
                }
            }
            printf("\nRecieved input is: %s\n", f1); //prints user inital input
            printf("\nYour Decryption is: %s\n", s1); //prints the Decryption string to user
        }
    }
    if(RS == 2) { // substution cipher
        char originalAlphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";
        char codedAlphabet[]    = "QWERTYUIOPASDFGHJKLZXCVBNM#";
        char originalMessage[]  = "SUBSTITUTION CIPHER";
        char encodedMessage[250];
        char decodedMessage[250];
        
        typedef enum
        {
         OPERATION_SUCCESS = 1U,
         OPERATION_FAILED  = 0U
        }OPERATION_STATUS;
            
            {
             unsigned short alphabetLength = strlen(originalAlphabet);
             unsigned int messageLength    = strlen(originalMessage);
             unsigned int i = 0U;
             char* pointer = NULL;
             unsigned int position = 0U;
             if( alphabetLength != strlen(codedAlphabet) )
                {
                //The lengths of the alphabets do not match
                return OPERATION_FAILED;
                }
                for(i=0; i<messageLength; i++)
                    {
                    pointer  = strchr(originalAlphabet, originalMessage[i]);
                    if(pointer==NULL)
                        {
                        //A character in the message was not found in the
                        //original alphabet
                        return OPERATION_FAILED;
                        }
                        else
                            {
                            position = pointer - originalAlphabet;
                            encodedMessage[i] = codedAlphabet[position];
                            }
                            }
                            encodedMessage[messageLength] = '\0';
                            return OPERATION_SUCCESS;
                            }
                            {
                             //Encoding
                             SimpleSubstitutionCipher_Code(originalAlphabet,codedAlphabet,
                                                           originalMessage, encodedMessage);
                             puts(encodedMessage);
                             //Decoding
                             SimpleSubstitutionCipher_Code(codedAlphabet,originalAlphabet,
                                                           encodedMessage, decodedMessage);
                             puts(decodedMessage);
                        }

            
        }
    }



    

