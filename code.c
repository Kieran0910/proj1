#include <stdio.h>

int main()
{
   int i, x; //declare values 
   char code[100]; // max size of string
   char key;
   printf("Please enter a Message use - as a space:\n"); //input from the user
   scanf("%s",&code);
   
   printf("please enter a key:\n");//users input for key
   scanf("%d", &code);

   printf("Select from options below:\n");
   printf("1 = Encrypt Message.\n");
   printf("2 = Decrypt Message.\n");
   scanf("%d", &x);

   //using switch case statements
   switch(x)
   {
   case 1:
      for(i = 0; code[i] != '\0'; i++)
        code[i] = code[i] - key; //the key for encryption that is added to ASCII value
        
      printf("\nEncrypted: %s\n", code);
      break;

   case 2:
      for(i = 0; (i < 100 && code[i] != '\0'); i++)
        code[i] = code[i] + key; //the key for encryption that is subtracted to ASCII value

      printf("\nDecrypted: %s\n", code);
      break;

   default:
      printf("\nError\n");
   }
   return 0;
}