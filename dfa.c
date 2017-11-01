#include<stdio.h>
#include<string.h>
#include<stdlib.h>

	FILE *fp;
	char s[50],ch;
	int n,i=0,k=0,j=0,init,final[10],n_final,tab[100][100],newstate,count=0,row=-1,col=0;
int column_no(char c)
{
	switch(c)
	{
		case 'a':
		return 0;
		case 'b':
		return 1;
		case 'c':
		return 2;
		case 'd':
		return 3;
		case 'e':
		return 4;
		case 'f':
		return 5;
		case 'g':
		return 6;
	}
}
void Read_Automaton()
{
	fp=fopen("dfa.txt","r");

	if(!fp)
	{
			printf("Cannot open the file\n");
		return ;
	}
	
	ch=fgetc(fp);

	init=ch-'0';
	
	while(!feof(fp))
	{
		ch=fgetc(fp);

		if(ch=='\n')
		{
			count++;
		}

		else if(count == 1 && (ch>='0' && ch<='9') )
		{
			final[i]=ch-'0';
			i++;
		}
		if(count >= 2)
		{
				if(ch>='0' && ch<='9')
				{	
					tab[row][col]=ch-'0';
					col++;
				}
				else if(ch=='\n')
				{
					col=0;
					row++;
				}
		}
	}
		n_final=i;
//////////////////////////////////////////////////////////////////

		//Print 
	   printf("Initia state :%d\n",init);

	   printf("Final State:");
	   for(j=0;j<i;j++)
	   printf("%d ",final[j]);
	  
	   printf("\nAutomaton in Tabular Form:");
	   for(i=0;i<=row;i++)
	   {
			printf("\n");
			for(j=0;j<col;j++)
			{
		    	printf("%d\t",tab[i][j]);
			}
	   }
}
int main()
{
	
	Read_Automaton();
	printf("\tDFA for odd no of 'a' and even no of 'b'\n\n");
	while(1)
	{
	   		a20:
	   		
	   		printf("\nEnter the string\n ");
	   		scanf("%s",s);
	  		if(strlen(s)>49)
	  		{
	     		printf("string size should be less than 50\n");
	     		return 0;
	  		}
	   		newstate=init;
	   		j=0;
	   		while(s[j]!='\0')
	   		{
	   				if(s[j]>='a' && s[j]<='z')
	   				{	
	   					i=column_no(s[j]);
	   					if(i>col-1)
	   					{
	   						printf("Not accepted\n");
							goto a20;	
	   					}
						newstate=tab[newstate][i];
						if(newstate==-1)
						{
							printf("Not accepted\n");
							goto a20;
						}
					}
					else
					{
						printf("Enter string in the form of letters\n");
						goto a20;
					}
				j++;
	
			}

			for(i=0;i<n_final;i++)
			{
	   			if(newstate == final[i])
	   			{
	   				printf("Accepted\n");
	   				goto a20;
	   			}
	   		}
	   			printf("Not accepted\n");
	   			goto a20;
	}

}
