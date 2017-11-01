#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	/* code */
	// get data from file and store it in array
	// int start;
	int curr_state;
	int next_state;
	int **a;
	int l;
	int count=0;
	char in[5444];
	char out[5444];

	FILE *P=fopen("moore.txt","r");
	if(P==NULL)
	{
		printf("couldn't open file\n");
		exit(1);
	}
	//save it in array
	fscanf(P,"%d",&curr_state);
	printf("Starting state %d\n",curr_state);
	for(int c=fgetc(P);c!=EOF;c=getc(P))
		if(c=='\n')
			count=count+1;
	// line is counted
	a=(int **)malloc(sizeof(int*)*count);
	// printf("\ncount %d\n",count);
	fseek(P,2,0);
	// Declare an array containing the no of line
	for(int i=0;i<count;i++)
	{
		a[i]=(int *)malloc(sizeof(int)*4);
		for(int j=0;j<4;j++)
			fscanf(P,"%d",&a[i][j]);


	}
	printf("CurrStates Input    NextStat    Output\n ------- ------------- ----------------\n");
	for(int i=0;i<count;i++){
		for(int j=0;j<4;j++)
			if(a[i][j]>=0)
			 printf("    %d      ",a[i][j]);
			else
			 printf("   %d      ",a[i][j]);
		printf("\n");
	}

	printf("Enter the input string ");
	scanf("%s",in);
	l=strlen(in);

	for(int k=0;k<l;k++)
	{
		next_state=a[2*curr_state +(in[k]-48)][2];
		if(next_state!=-1)
		{
			out[k]=a[2*curr_state +(in[k]-48)][3]+48;
			curr_state=next_state;

		}
		else{
			printf("\nInput not acceptable");
			exit(-1);
		}

	}
	out[l]='\0';
	printf("Output is %s \n",out);

	// fscanf(P,"%d",&start);
	// printf("%d",start);
return 0;
}
