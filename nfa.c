//                              2.   NFA (String acceptance or not using nfa)       

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{   
       	char ch,str[100];
	int count,initial,final[5],k,curstate,flag,col=0;
	int i,j,l;
	int nfa[10][10][10];
	FILE *f;
	f=fopen("nfa.txt","r");
	if(f == NULL)
	{
		printf("Empty File ");
	} 
    
    for(i=0;i<10;i++)
    for(j=0;j<10;j++)
    for(k=0;k<10;k++)
    nfa[i][j][k]=-2;
    
	ch=getc(f);
	count=0;
	k=0;      
	
    while(ch !=EOF )
	{   if(count==0 && ch!='\n')
	    {
	    	initial=ch-48;	    	printf("Initial State : %d\n",initial);
	    }
  	if(ch=='\n')  
	count++;
		if(count==1)
		{   ch=getc(f);
			if(ch!=',')
			{
				final[k]=ch-48;		
				printf("Final State %d: q%d\n",k+1,final[k]);
				k++;	col++;}
}
		if(count==2)
	   	 break; 
	
	ch=getc(f);
		    }
    ch=getc(f);
    i=0; j=0; k=0;
    while(ch!=EOF)
    {  	    
        if(ch==',')
        {
        	k++; 	ch=getc(f);	nfa[i][j][k]=ch-48;
        }
        if(ch==' ')
        {	j++;	k=0;
        }
        if(ch=='\n')
        {
        	j=0;	k=0;  	  i++;
        }
        if(ch=='-')
        {
       	ch=getc(f);
		nfa[i][j][k]=ch-48;
        nfa[i][j][k]= (-1)*nfa[i][j][k];
        }      
        if(nfa[i][j][k]!=-1)
        {
        nfa[i][j][k]=ch-48;
        }
        ch=getc(f);
    }
    fclose(f);
    while(1)
	{ curstate=initial;	flag=0;    printf("\nEnter String :");
	gets(str);	
	for(i=0;i<strlen(str);i++)
	{
		if(str[i]-97 > 1)
		{
			printf("Invalid String\n");
			break;
		}
		if(nfa[curstate][str[i]-97][0]== -1 || nfa[curstate][str[i]-97][1]==-1)
		{
			printf("REJECTED.\n");
			flag=-1;
			break;
		}
		if(nfa[curstate][str[i]-97][0] >0 && nfa[curstate][str[i]-97][1] > 0 )
		{
		curstate=nfa[curstate][str[i]-97][1] || nfa[curstate][str[i]-97][0] ;
	  }}
	if(flag!=-1)
	{
	   if(curstate==final[i]) 
			{ printf("ACCEPTED\n");
			  flag=1;
			 // break;	    }
	}
	if(flag==0)
	{
		printf("REJECTED\n");
	}
	}   
	
}

