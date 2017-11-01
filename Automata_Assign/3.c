/*			Normalization -- Removal of epsilon , epsilon is tken as $
						Author 	MD. SHARIQUE SHAHAB
								13-BCS-0035
						B.TECH COMPUTER ENGONEERING Vth SEM
							
							
*/

//NOTE: FILE cgf1.c  IS OPENED AND CLOSED MULTIPLE TIME
#include<stdio.h>
#include<string.h>

	FILE *fp;
	char ch[25],w1[25],w2[25],w3[25],a,l,c;
	int i,j,m,k=0,x,count1=0,count2=0,count=0,count3=0,count4=0,flag;
void print()
{
	fclose(fp);
	printf("\nw = %s\n",w1);
	//Printing Grammer after removal of Variables not producing terminals
	printf("\nNormalized Grammer is :\n\n");
	fp=fopen("cfg1.txt","r");
	while(!feof(fp))
		{
			fscanf(fp,"%s",ch);
			flag=0;	
			flag++;
			count3=0;count4=0;
			for(i=0;i<strlen(ch);i++)
			{
				if(i==0)
				{
				 	printf("%c",ch[i]);
				 	
				}
				else if(i==1||i==2)
					printf("%c",ch[i]);
				
				else if(i>2)
				{

					count1=0;count2=0;count3=0;
					for(m=0;m<strlen(ch);m++)
					{
						if(ch[m]=='|')
						count3++;
					}
					
					if(count3>0)
					{
					    	if(count3>count4)
					    	{
					    		count4++;
									
									for(j=i;ch[j]!='|';j++)
										if(ch[i]!='$')
										{
										
										printf("%c",ch[j]);
										}
										printf("|");
									
										count1=0;
									
										for(j=i;ch[j]!='|';j++)
											for(l=0;l<strlen(w1);l++)
											if(ch[j]==w1[l])
											count1++;
										
									
										for(j=i;ch[j]!='|';j++)
										{
											for(l=0;l<strlen(w1);l++)
											{
												if(ch[j]==w1[l])
												{
											
													for(m=i;ch[m]!='|';m++)
													{
														if(m!=j&&ch[i]!='$')
														{
															
															printf("%c",ch[m]);
														}
													}
													
												}
											}
											printf("|");
											
										}
									
									i=j;
									
							}
					
							else if(count3==count4)
							{
							
								count4++;
									
									for(j=i;ch[j]!='\0';j++)
										if(ch[i]!='$')
										printf("%c",ch[j]);
										
										printf("|");
									
										count1=0;
									
										for(j=i;ch[j]!='\0';j++)
											for(l=0;l<strlen(w1);l++)
											if(ch[j]==w1[l])
											count1++;
										
									
										for(j=i;ch[j]!='\0';j++)
										{
											for(l=0;l<strlen(w1);l++)
											{
												if(ch[j]==w1[l])
												{
											
													for(m=i;ch[m]!='\0';m++)
													{
														if(m!=j&&ch[i]!='$')
														{
															printf("%c",ch[m]);
														}
													}
													
												}
											}
											printf("|");
							
										}
										//return;
											i=j;
									
							}
							
						
					}
					else
					{
				
							for(j=i;ch[j]!='\0';j++)
							if(ch[i]!='$')
										printf("%c",ch[j]);
										printf("|");
									
										count1=0;
									
										for(j=i;ch[j]!='\0';j++)
											for(l=0;l<strlen(w1);l++)
											if(ch[j]==w1[l])
											count1++;
										
									
										for(j=i;ch[j]!='\0';j++)
										{
											for(l=0;l<strlen(w1);l++)
											{
												if(ch[j]==w1[l])
												{
											
													for(m=i;ch[m]!='\0';m++)
													{
														if(m!=j&&ch[i]!='$')
														{
															printf("%c",ch[m]);
														}
													}
													
												}
											}
											
										}
										
									
									i=j;
									//printf("Check\n");
									//printf("i=%d",i);
	
					}
				}
						
 			}
 			
 			printf("\n");
 			
		}
fclose(fp);
}
main()
{
fp=fopen("cfg1.txt","r");
	printf("Grammer to be Normalized\n");
	while(fscanf(fp,"%s",ch)!=EOF)
	{
		printf("%s",ch);
		printf("\n");
	}
	k=0;
	fclose(fp);
	fp=fopen("cfg1.txt","r");

	while(!feof(fp))
	{
		fscanf(fp,"%s",ch);
		
		//varaibles producing null directly
		for(i=0;i<strlen(ch);i++)
		{
			
			
					if(ch[i]=='$')	// $ stands for epsilon or null
					{	
						w1[k]=ch[0];
						
						k++;
					}
		}
 	}
	
	//printf("w1=%s",w1);
	fclose(fp);
	
	//variables producing null indirectly
	while(1)
	{
		
		fp=fopen("cfg1.txt","r");
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
					
					
							//checking redundancy				
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
		//making w2 as w1 ,new element will be added into w1 and union will bw taken between w1 and w2
		strcpy(w2,w1);
	}	
}
