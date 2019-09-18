#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
 int main()
 {
	 char cipher, text[50];
	 int i, key;

	 printf("Encrypting a message with a caesar cipher!\n");
	 printf("Enter the text(max 50 letters and uppercase only): ");
	 gets(text);
	 printf("\nEnter the key value: ");
	 scanf("%d", &key);

	 for(i=0; i < strlen(text); i ++)
	 {
		 if(isupper(text[i]))
		 {
			 if(text[i]+key>90){
				 cipher = (text[i]+key)-26;
			 	 text[i] = cipher;
			 }
			 else{
			 cipher = text[i]+key;
			 text[i] = cipher;}
		 }
	 }
	 	printf("\n%s\n", text);
		 return(EXIT_SUCCESS);
