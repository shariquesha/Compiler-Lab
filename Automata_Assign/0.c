#include<stdio.h>
#include<string.h>

	FILE *fp;
	char ch[25],w1[25],w2[25],w3[25],a,l,m,c;
	int i,j,k=0,count1=0,count2=0,count=0,count3=0,count4=0,flag;
void print()
{
	fclose(fp);
	printf("w = %s\n",w1);
	//Printing Grammer after removal of Variables not producing terminals
	printf("Normalized Grammer is :\n");
	fp=fopen("cfg.txt","r");
	while(!feof(fp))
		{
			fscanf(fp,"%s",ch);
			//printf("string is :%s \n",ch);
			flag=0;
			count3=0;count4=0;
			for(i=0;i<=strlen(ch);i++)
			{
				if(i==0)
				for(j=0;j<strlen(w1);j++)
				{
				
					if(ch[i]==w1[j])
					{
				 		printf("%c",ch[i]);
				 		flag=1;
				 	}
			    }
				else if((i==1||i==2)&&flag==1)
				{
					printf("%c",ch[i]);
				}
				
				else if(flag==1&&i>2)
				{

					count1=0;count2=0,count3=0;
					for(m=0;m<strlen(ch);m++)
					{
						if(ch[m]=='|')
						count3++;
					}
					//printf("%d",count3);
					if(count3>0)
					{
					    	if(count3>count4)
					    	{
					    		count4++;
									for(j=i;ch[j]!='|';j++)
									{
										count1++;
										if(ch[j]>='a'&&ch[j]<='z')
										count2++;
										for(l=0;l<strlen(w1);l++)
											if(ch[j]==w1[l])
												count2++;
													
									}
									if(count1==count2)
								 {	
									for(j=i;ch[j]!='|';j++)
									{
										printf("%c",ch[j]);
									
									}
									printf("%c",ch[j]);
								}
									i=j;
							}
							else if(count3==count4)
							{
							
								count4++;
								for(j=i;ch[j]!='\0';j++)
								{
									count1++;
									if(ch[j]>='a'&&ch[j]<='z')
										count2++;
									for(l=0;l<strlen(w1);l++)
										if(ch[j]==w1[l])
											count2++;
								}
									if(count1==count2)
								{
									for(j=i;ch[j]!='\0';j++)
									{
										printf("%c",ch[j]);
									
									}
								}
									i=j;
							
							}
							
						
					}
					else
					{
					
							for(j=i;ch[j]!='\0';j++)
								{
									
									count1++;
									if(ch[j]>'a'&&ch[j]<='z')
										count2++;
									for(l=0;l<strlen(w1);l++)
										if(ch[j]==w1[l])
										count2++;
								}
					
						if(count1==count2)
						{
									for(j=i;ch[j]!='\0';j++)
									printf("%c",ch[j]);
						
						}		
						i=j;
					}
				}
					
			
 			}
 				printf("\n");

				
	
		}
		fclose(fp);
			
	printf("\n+++++++++END++++++++++++");

}
main()
{
	fp=fopen("cfg.txt","r");
	printf("Grammer to be Normalized\n");
	while(fscanf(fp,"%s",ch)!=EOF)
	{
		printf("%s",ch);
		printf("\n");
	}
	fclose(fp);
	printf("\n");
	fp=fopen("cfg.txt","r");
	while(!feof(fp))
	{
		count1=0;
		count2=0;
		fscanf(fp,"%s",ch);
		//checking the production for terminals
		for(i=0;i<=strlen(ch);i++)
		{
			
				if(ch[i]!='|'&&ch[i]!='-'&&ch[i]!='>'&&i!=0&&ch[i]!='\0')
				{
					count1++;
					if(ch[i]>='a'&&ch[i]<='z')
					{
						count2++;
					}
				}
				if((ch[i]=='|'||ch[i]=='\0')&&(count1==count2))
				{
					//Saving variable producing terminal directly
					w1[k]=ch[0];
					k++;
				}
				if((ch[i]=='|'||ch[i]=='\0')&&(count1!=count2))
				{
					
					count1=0;
					count2=0;
				}
		}
 }
	
	fclose(fp);
	while(1)
	{
		
		fp=fopen("cfg.txt","r");
		while(!feof(fp))
		{
			fscanf(fp,"%s",ch);
			
			count1=0;count2=0;
			for(i=0;i<=strlen(ch);i++)
			{
			
				if(ch[i]!='|'&&ch[i]!='-'&&ch[i]!='>'&&i!=0&&ch[i]!='\0')
				{
					count1++;
					
					
					if(ch[i]>='a'&&ch[i]<='z')
					{
						count2++;
					}
					for(j=0;j<strlen(w1);j++)
					{
						if(ch[i]==w1[j])
						count2++;
						
					}
					
					
				}
				
				if((ch[i]=='|'||ch[i]=='\0')&&(count1==count2))
				{
					count=0;
					
					
					
							for(l=0;w1[l]!=NULL;l++)
							{
								if(w1[l]==ch[0])
								count++;		
							}
							if(count==0)
							{
								w1[k]=ch[0];
								k++;
							}
		
					
					if(strcmp(w1,w2)==0)
					{
						print();
						return;
					}
					
				}
				if((ch[i]=='|'||ch[i]=='\0')&&(count1!=count2))
				{
					
					count1=0;
					count2=0;
				}
			}
		
		}
		
		fclose(fp);
		strcpy(w2,w1);
	}	
}
