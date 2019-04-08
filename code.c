#include <stdio.h>

int main()
{
   int i, x; //declare values 
   char msge[100] = "ATTACK AT SUNRISE"; // max size of string
   char key;
   printf("Please enter a Message use - as a space:\n"); //input from the user
   scanf("%s",&msge);
   
   printf("please enter a key:\n");//users input for key
   scanf("%d", &key);

   printf("Select from options below:\n");
   printf("1 = Encrypt Message.\n");
   printf("2 = Decrypt Message.\n");
   scanf("%d", &x);

   
}