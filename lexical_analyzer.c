#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>

/* Wap to implement lexical analyzer in C */
char keyword[32][10] ={
"auto","double","int","struct","break","else","long","float","short","unsigned","continue","switch","case",
"enum","register","typedef","char","extern","return","union","const","for","signed","void","default","goto","sizeof","volatile","do","if","static","while"
};
int iskeyword(char str[])
{
	int i;
	for (i = 0;i<32;i++)
	{
		if(strcmp(str,keyword[i]) == 0)
		return 1;
	}
	return 0;
}
int main()
{
	char ch, buffer[15], operators[] = "+-*/%=";
	FILE *fp;
	int i,j=0;
	fp = fopen("lexical_code.txt","r");
	if(fp==NULL)
	{
		printf("error while opening the file \n");
		return 0;
	}
	while((ch=fgetc(fp))!= EOF)
	{
		for(i=0;i<6;++i)
		{
			if(ch == operators[i])
				printf("\n%c is operator\n",ch);
		}
		if(isalnum(ch))
		{
			buffer[j++] = ch;
		}
		else if((ch == ' ' || ch == '\n') && (j!=0) )
		{
			buffer[j] = '\0';
			j = 0;
			if(iskeyword(buffer) == 1)
				printf("\n%s is a keyword",buffer);
			else
				printf("\n%s is a identifier",buffer);
		}
	}
	fclose(fp);
	return 0;
}


