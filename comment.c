#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/* Wap to test whether given string is valid comment or not*/
int main() {
	char comment[50];
	int i,a,loc,length;
	printf("Enter comment\n");
	gets(comment);
	length = strlen(comment);
	if(comment[0] == '/')
	{
		if (comment[1] == '/')
			printf("It is a comment");
		
		else if(comment[1] == '*')
		{
			for(i=2;i<=length;i++)
			{
				if(comment[i] == '*' && comment[i+1] == '/')
				{
					a = 1;	
					break;
				}
				else
					continue;	
			}
		}
		else
			printf("\n It is not a comment");			
	}
	else
		printf("\n It is not a comment.");
	return 0;
}
