#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
typedef struct Node_tag
{
	char account_holder_name[20];
	int branch_id;
	char address[20];
	char PAN_number[10];
	char account_number[10];
	char deposited_money[10];	
	char phone_number[10];
	
	struct Node_tag *next;
}Node;
#include "bank_files.h"
int main()
{
	char account_holder_name[20],address[20],PAN_number[10],account_number[10],deposited_money[10],phone_number[10],filename[50];
	int branch_id,select,next_itr=1,filechoice;
	Node *head=NULL,*list1=NULL,*list2=NULL,*list=NULL,*inter=NULL,*skew=NULL,*max_money=NULL,*lidt_diff=NULL;
	
	variable_initialize(account_holder_name,&branch_id,address,PAN_number,account_number,deposited_money,phone_number);	
	head=initialize("BANK_DATABASE.txt");
	list1=initialize("list1.txt");
	list2=initialize("list2.txt");
	do
	{
			printf("\n\t\t=============================================");
			printf("\n\t\t\tBank Database Manangement System");
			printf("\n\t\t=============================================");
			printf("\n\n\t\t\t[1]  Insert\n\t\t\t[2]  Print\n\t\t\t[3]  Delete customer\n\t\t\t[4]  Total customers\n\t\t\t[5]  Check Empty\n\t\t\t[6]  Merge\n\t\t\t[7]  Common Elements\n\t\t\t[8]  Not Common\n\t\t\t[9]  Max Money\n\t\t\t[10] List Difference\n\t\t\t[11] Exit");
			printf("\n\t\t=============================================\n");
			printf("\n\nEnter Operation:");
			scanf("%d",&select);
			switch(select)
			{
				case 1:
						system("cls");
						variable_initialize(account_holder_name,&branch_id,address,PAN_number,account_number,deposited_money,phone_number);	
						filename[0]='\0';
						getDetails(account_holder_name,&branch_id,address,PAN_number,account_number,deposited_money,phone_number);
						system("cls");//clear screen;
						filechoice=print_file_names();
						switch(filechoice)	
						{
							case 1:
									strcpy(filename,"BANK_DATABASE.txt");
									head=insert(filename,head,account_holder_name,branch_id,address,PAN_number,account_number,deposited_money,phone_number);
									print(head);
									next_itr=next_iteration();
									break;
							case 2:
									strcpy(filename,"list1.txt");
									list1=insert(filename,list1,account_holder_name,branch_id,address,PAN_number,account_number,deposited_money,phone_number);
									print(list1);
									next_itr=next_iteration();
									break;
							case 3:
									strcpy(filename,"list2.txt");
									list2=insert(filename,list2,account_holder_name,branch_id,address,PAN_number,account_number,deposited_money,phone_number);
									print(list2);
									next_itr=next_iteration();
									break;
							default:
									system("cls");
									printf("\n\t\t\tEntered Wrong Choice\n\n");										
						}											
						break;
				
				case 2:
						system("cls");
						filechoice=print_file_names();
						switch(filechoice)	
						{
							case 1:
									print(head);
									next_itr=next_iteration();
									break;
							case 2:
									print(list1);
									next_itr=next_iteration();
									break;
							case 3:
									print(list2);
									next_itr=next_iteration();
									break;										
						}											
						break;
				case 3:
						system("cls");
						variable_initialize(account_holder_name,&branch_id,address,PAN_number,account_number,deposited_money,phone_number);	
						printf("\n\t\t---------------------------------------------");
						printf("\n\t\t\tCustomer Details");
						printf("\n\t\t---------------------------------------------");
						printf("\n\n\tEnter Name   : ");
						scanf("%s",account_holder_name);
						printf("\n\tEnter Branch : ");
						scanf("%d",&branch_id);
						system("cls");
						filechoice=print_file_names();
						switch(filechoice)	
						{
							case 1:
									head=delete("BANK_DATABASE.txt",head,account_holder_name,branch_id);
									print(head);
									next_itr=next_iteration();
									break;
							case 2:
									list1=delete("list1.txt",list1,account_holder_name,branch_id);
									print(list1);
									next_itr=next_iteration();
									break;
							case 3:
									list2=delete("list2.txt",list2,account_holder_name,branch_id);
									print(list2);
									next_itr=next_iteration();
									break;										
						}			
						break;
				case 4:system("cls");
						filechoice=print_file_names();
						switch(filechoice)	
						{
							case 1:
									getNumRecords(head);
									break;
							case 2:
									getNumRecords(list1);
									break;
							case 3:
									getNumRecords(list2);
									break;										
						}
						next_itr=next_iteration();											
						break; 
						// case 5 missing
				case 6:system("cls");
						list=list_union(list1,list2);
						print(list);
						next_itr=next_iteration();
						break;
				case 7:system("cls");
						inter=intersect(list1,list2);
						print(inter);
						next_itr=next_iteration();
						break;
				case 8:system("cls");
						skew=skew_symmetric(list1,list2);
						print(skew);
						next_itr=next_iteration();
						break;
				case 9:system("cls");
						filechoice=print_file_names();
						switch(filechoice)	
						{
							case 1:
									max_money=deposit_money(head);
									break;
							case 2:
									max_money=deposit_money(list1);
									break;
							case 3:
									max_money=deposit_money(list2);
									break;										
						}											
						print(max_money);
						next_itr=next_iteration();
						break;
				case 10:system("cls");
						lidt_diff=list_difference(list1,list2);
						print(lidt_diff);
						next_itr=next_iteration();
						break;
				case 11:
						next_itr=0;
						break;
				default:
					system("cls");
					printf("\n\n\t\t\tSelected Wrong Operation.\n\n");
					
			}
	}while(next_itr);

return 0;
}

Node* initialize(char filename[])
{
	char file_account_holder_name[20],file_address[20],file_PAN_number[10],file_account_number[10],file_deposited_money[10],file_phone_number[10];
	int file_branch_id,first_time=1;
	file_initialize(file_account_holder_name,&file_branch_id,file_address,file_PAN_number,file_account_number,file_deposited_money,file_phone_number);
	
	Node *fptr=NULL,*ptr;
	
	FILE *Fpointer;
	Fpointer=fopen(filename,"a");
	close(Fpointer);
	
	Fpointer=fopen(filename,"r");
	fscanf(Fpointer,"%s%d%s%s%s%s%s",file_account_holder_name,&file_branch_id,file_address,file_PAN_number,file_account_number,file_deposited_money,file_phone_number);
	
	if(strlen(file_account_holder_name)==0)
	{
		printf("\n\t\t%s is empty.\n",filename);
	} 
	else
	{
		Node* newnode;
		while(strlen(file_account_holder_name)!=0)
		{
			newnode=(Node*)malloc(sizeof(Node));
			
			if(newnode!=NULL)
			{
				
				strcpy(newnode->account_holder_name,file_account_holder_name);
				newnode->branch_id=file_branch_id;
				strcpy(newnode->address,file_address);
				strcpy(newnode->PAN_number,file_PAN_number);
				strcpy(newnode->account_number,file_account_number);
				strcpy(newnode->deposited_money,file_deposited_money);
				strcpy(newnode->phone_number,file_phone_number);
				newnode->next=NULL;
			
				
				if( strlen(newnode->phone_number)!=0)
				{
					if(first_time==1)
					{
						fptr=newnode;
						ptr=newnode;
						first_time=2;	
					}
					else
					{
						ptr->next=newnode;
						ptr=ptr->next;
					}
				}
				file_initialize(file_account_holder_name,&file_branch_id,file_address,file_PAN_number,file_account_number,file_deposited_money,file_phone_number);
				
				fscanf(Fpointer,"%s%d%s%s%s%s%s\n",file_account_holder_name,&file_branch_id,file_address,file_PAN_number,file_account_number,file_deposited_money,file_phone_number);												
			}
		}	
	}
return fptr;
}

void file_initialize(char file_account_holder_name[],int *file_branch_id,char file_address[],char file_PAN_number[],char file_account_number[],char file_deposited_money[],char file_phone_number[])
{
			file_account_holder_name[0]='\0';
			file_address[0]='\0';
			file_PAN_number[0]='\0';
			file_account_number[0]='\0';
			file_deposited_money[0]='\0';
			file_phone_number[0]='\0';
			*file_branch_id=0;
}

void variable_initialize(char account_holder_name[],int* branch_id,char address[],char PAN_number[],char account_number[],char deposited_money[],char phone_number[])
{
			account_holder_name[0]='\0';
			address[0]='\0';
			PAN_number[0]='\0';
			account_number[0]='\0';
			deposited_money[0]='\0';
			phone_number[0]='\0';
			*branch_id=0;
}

Node* insert(char filename[],Node* lptr,char account_holder_name[],int branch_id,char address[],char PAN_number[],char account_number[],char deposited_money[],char phone_number[])
{
	Node *newnode,*ptr=lptr,*prev=ptr;
	int flag=0;
	newnode=makenode(account_holder_name,branch_id,address,PAN_number,account_number,deposited_money,phone_number);
	if(newnode!=NULL)
	{
				FILE *Fpointer,*fp;
				fp=fopen(filename,"w");	
					if(ptr!=NULL)
					{	
									while((ptr!=NULL) && (flag==0))
									{
										if(strcmp(ptr->account_holder_name,newnode->account_holder_name)==0)   // modify data present in ptr and change flag.
										{
													if(ptr->branch_id==newnode->branch_id)      // nothing is added ptr data is modified since name and id both are same 
													{
														strcpy(ptr->account_holder_name,newnode->account_holder_name);
														ptr->branch_id=newnode->branch_id;
														strcpy(ptr->address,newnode->address);
														strcpy(ptr->PAN_number,newnode->PAN_number);
														strcpy(ptr->account_number,newnode->account_number);
														strcpy(ptr->deposited_money,newnode->deposited_money);
														strcpy(ptr->phone_number,newnode->phone_number);
														flag=1;
														
														printf("\n\t\tData is updated.\n");
														fprintf(fp,"%s\t%d\t%s\t%s\t%s\t%s\t%s\n",account_holder_name,branch_id,address,PAN_number,account_number,deposited_money,phone_number);
														   // fprintf is writing in a file. "w" mode overwrites ,"a" mode should have been used.
														prev=ptr;   
														ptr=ptr->next;
													}
													else if(ptr->branch_id>newnode->branch_id)    // name is same id is different , still node will be added
													{
																			if(prev==ptr)   // newnode added at start of l.list.
																			{
																				newnode->next=ptr;
																				lptr=newnode;
																				fprintf(fp,"%s\t%d\t%s\t%s\t%s\t%s\t%s\n",account_holder_name,branch_id,address,PAN_number,account_number,deposited_money,phone_number);
																				fprintf(fp,"%s\t%d\t%s\t%s\t%s\t%s\t%s\n",ptr->account_holder_name,ptr->branch_id,ptr->address,ptr->PAN_number,ptr->account_number,ptr->deposited_money,ptr->phone_number);
																				// do do bar fprintf probably bcoz first time ptr data was overwritten
                               																	prev=ptr;     // why update ptr and prev?
																				ptr=ptr->next;
																			}
																			else   // new node addded in b/w ptr and prev
																			{
																				newnode->next=ptr;
																				prev->next=newnode;
																				fprintf(fp,"%s\t%d\t%s\t%s\t%s\t%s\t%s\n",account_holder_name,branch_id,address,PAN_number,account_number,deposited_money,phone_number);
																				fprintf(fp,"%s\t%d\t%s\t%s\t%s\t%s\t%s\n",ptr->account_holder_name,ptr->branch_id,ptr->address,ptr->PAN_number,ptr->account_number,ptr->deposited_money,ptr->phone_number);
																				prev=ptr;
																				ptr=ptr->next;
																			}
																flag=1;    // flag change means newnode added.
													}
													else     //ptr->branch_id  <  newnode->branch_id  ,adding at end of l.list
													{
														fprintf(fp,"%s\t%d\t%s\t%s\t%s\t%s\t%s\n",ptr->account_holder_name,ptr->branch_id,ptr->address,ptr->PAN_number,ptr->account_number,ptr->deposited_money,ptr->phone_number);fprintf(fp,"%s%d%s%s%s%s%s\n",ptr->account_holder_name,ptr->branch_id,ptr->address,ptr->PAN_number,ptr->account_number,ptr->deposited_money,ptr->phone_number);
														prev=ptr;
														ptr=ptr->next;
													}
										}
										else if(strcmp(ptr->account_holder_name,newnode->account_holder_name)>0)     // ptr name is larger than newnode name
										{
																			if(prev==ptr)   //added at front of l.list
																			{
																				newnode->next=ptr;
																				lptr=newnode;
																				fprintf(fp,"%s\t%d\t%s\t%s\t%s\t%s\t%s\n",account_holder_name,branch_id,address,PAN_number,account_number,deposited_money,phone_number);
																				fprintf(fp,"%s\t%d\t%s\t%s\t%s\t%s\t%s\n",ptr->account_holder_name,ptr->branch_id,ptr->address,ptr->PAN_number,ptr->account_number,ptr->deposited_money,ptr->phone_number);
																				prev=ptr;
																				ptr=ptr->next;
																			}
																			else    // adding in b/w ptr and prev
																			{
																				newnode->next=ptr;
																				prev->next=newnode;
																				fprintf(fp,"%s\t%d\t%s\t%s\t%s\t%s\t%s\n",account_holder_name,branch_id,address,PAN_number,account_number,deposited_money,phone_number);
																				fprintf(fp,"%s\t%d\t%s\t%s\t%s\t%s\t%s\n",ptr->account_holder_name,ptr->branch_id,ptr->address,ptr->PAN_number,ptr->account_number,ptr->deposited_money,ptr->phone_number);
																				prev=ptr;
																				ptr=ptr->next;
																			}
																flag=1;
										}
										else    // $ ptr name is smaller than newnode name. But it seems we didn't add the newnode.
										{
											fprintf(fp,"%s\t%d\t%s\t%s\t%s\t%s\t%s\n",ptr->account_holder_name,ptr->branch_id,ptr->address,ptr->PAN_number,ptr->account_number,ptr->deposited_money,ptr->phone_number);
											prev=ptr;
											ptr=ptr->next;
										}
									}
									
									 // ptr became null , reached the end of l.list
									if(flag==0)   // last case ($) main flag modify nahi hua. Abhi newnode add kar rahe hain at the end of l.list
									{
										prev->next=newnode;
										fprintf(fp,"%s\t%d\t%s\t%s\t%s\t%s\t%s\n",account_holder_name,branch_id,address,PAN_number,account_number,deposited_money,phone_number);
									}
									else     // flag=1 means kuch toh add hua hain. Why fprintf the list ?
									{
										while(ptr!=NULL)
										{
											fprintf(fp,"%s\t%d\t%s\t%s\t%s\t%s\t%s\n",ptr->account_holder_name,ptr->branch_id,ptr->address,ptr->PAN_number,ptr->account_number,ptr->deposited_money,ptr->phone_number);
											ptr=ptr->next;
										}
									}
					}
					else   // ptr is NULL
					{
						printf("\n\t\tFile is empty.");
						fprintf(fp,"%s\t%d\t%s\t%s\t%s\t%s\t%s\n",account_holder_name,branch_id,address,PAN_number,account_number,deposited_money,phone_number);
						lptr=newnode;
					}
			close(fp);
	}
	else   // newnode is NULL
	{
		printf("\n\n\t\tData cannot be inserted.\n\t\tStorage is Full.\n\n");
	}
return lptr;
}

Node* makenode(char account_holder_name[],int branch_id,char address[],char PAN_number[],char account_number[],char deposited_money[],char phone_number[])
{
	Node* newnode;
	newnode=(Node*)malloc(sizeof(Node));
			strcpy(newnode->account_holder_name,account_holder_name);
			newnode->branch_id=branch_id;
			strcpy(newnode->address,address);
			strcpy(newnode->PAN_number,PAN_number);
			strcpy(newnode->account_number,account_number);
			strcpy(newnode->deposited_money,deposited_money);
			strcpy(newnode->phone_number,phone_number);
			
			newnode->next=NULL;
return newnode;
}

void getDetails(char account_holder_name[],int* branch_id,char address[],char PAN_number[],char account_number[],char deposited_money[],char phone_number[])
{
		printf("\n\t\t=============================================");
		printf("\n\t\t\tCustumor Details");
		printf("\n\t\t=============================================");
	printf("\n\n\t\t>> Enter Name : ");
	scanf("%s",account_holder_name);
	printf("\n\t\t>> Enter ID   : ");
	scanf("%d",branch_id);
	printf("\n\t\t>> Enter Addr.: ");
	scanf("%s",address);
	printf("\n\t\t>> Enter PanNo: ");
	scanf("%s",PAN_number);
	printf("\n\t\t>> Enter AccNo: ");
	scanf("%s",account_number);
	printf("\n\t\t>> Enter Money: ");
	scanf("%s",deposited_money);
	printf("\n\t\t>> Enter Mob  : ");
	scanf("%s",phone_number);	
}

void print(Node* lptr)
{
	Node* ptr=lptr;
	printf("\n\t\t=============================================");
	printf("\n\t\t\tCustumor Details");
	printf("\n\t\t=============================================");
	while(ptr!=NULL)
	{
		printf("\n\n\t\t>> Name    : %s\n\t\t>> ID      : %d\n\t\t>> Address : %s\n\t\t>> PAN No. : %s\n\t\t>> Accnt No: %s\n\t\t>> Money   : %s\n\t\t>> Mobile  : %s\n\n",ptr->account_holder_name,ptr->branch_id,ptr->address,ptr->PAN_number,ptr->account_number,ptr->deposited_money,ptr->phone_number);
		printf("\n\t\t---------------------------------------------");
		ptr=ptr->next;	
	}	
}

Node* delete(char filename[],Node* lptr,char account_holder_name[],int branch_id)
{
            Node* ptr=lptr;
            Node* prev=ptr;
            char file_account_holder_name[20],file_address[20],file_PAN_number[10],file_account_number[10],file_deposited_money[10],file_phone_number[10];
			int file_branch_id,flag=0,i=1;
			file_initialize(file_account_holder_name,&file_branch_id,file_address,file_PAN_number,file_account_number,file_deposited_money,file_phone_number);
            if(ptr!=NULL)
            {
            			FILE *Fpointer;
                        Fpointer=fopen(filename,"w");
                         while(ptr!=NULL)
                         {
                         				printf("%d",i);
                         				i++;
                                         if((strcmp(ptr->account_holder_name,account_holder_name)==0) && (ptr->branch_id==branch_id))
                                         {
                                              Node* del=ptr;
                                               if(prev==ptr)
                                               {
                                                      lptr=ptr->next;      
                                               }
                                               else
                                               {
                                                 prev->next=ptr->next;
                                               }  
                                        	   ptr=ptr->next;                                                                                         
                                               free(del);
                                               flag=1;     // flag=1 indicates deletion is done.
                                         }
                                         else  // name and id didn't match - move further in l.list. Particular Data cannot be deleted from file, we have to rewrite the whole data again 
                                         {
											 	fprintf(Fpointer,"%s\t%d\t%s\t%s\t%s\t%s\t%s\n",ptr->account_holder_name,ptr->branch_id,ptr->address,ptr->PAN_number,ptr->account_number,ptr->deposited_money,ptr->phone_number);
										 		prev=ptr;
                                         		ptr=ptr->next;
										 }
                                         
                         }
                         
                         if(flag==0)   // No deletion and whole l.list has been traversed.
                         {
                                    printf("\n\t\tData not found in the list.\n");
                         } 
						 else    // flag=1 indicates deletion is done.
						 {
						      printf("\n\t\tData is successfully deleted.\n");	
						 }                   
                        close(Fpointer);    // Close file to save changes                                           
            }
            else
            {
                printf("\n\t\tList is Empty.");
            }
return lptr;
}

void getNumRecords(Node* lptr)
{
     Node* ptr=lptr;
     int count=0;
     while(ptr!=NULL)
     {
            count++;
            ptr=ptr->next;
     }
     printf("\n\t\t>>>>  Total Number of Records : %d <<<<",count);
}

void isEmpty(Node* lptr)
{
        if(lptr==NULL)
        {
                   printf("\n\t\t>>>>>   List is empty.  <<<<<");
        }
        else
        {
        			printf("\n\t\t>>>>>   List is not empty.  <<<<<");
		}
}

//********************************************************************************************************************
//Remove Duplicate Function is not required as my list is always updated.
//******************************************************************************************************************  
/*Node* list_unique(Node* lptr)
{
      Node *ptr=lptr,*prev=ptr;
      Node* del;
     
     if(ptr!=NULL && ptr->next!=NULL)
     { 
     		FILE *Fpointer;
     		int flag=0;
            Fpointer=fopen("BANK_DATABASE.txt","w");
            fprintf(Fpointer,"%s\t%d\t%s\t%s\t%s\t%s\t%s\n",ptr->account_holder_name,ptr->branch_id,ptr->address,ptr->PAN_number,ptr->account_number,ptr->deposited_money,ptr->phone_number);
            ptr=ptr->next;      
            while(ptr!=NULL)
            {
                            if((strcmp(ptr->account_holder_name,prev->account_holder_name)==0) && (ptr->branch_id==prev->branch_id))
                            {
                                  del=ptr;
                                  ptr=ptr->next;
                                  prev->next=ptr;
                                  free(del);
                                  flag=1;
                            }
                            else
                            {
                                fprintf(Fpointer,"%s\t%d\t%s\t%s\t%s\t%s\t%s\n",ptr->account_holder_name,ptr->branch_id,ptr->address,ptr->PAN_number,ptr->account_number,ptr->deposited_money,ptr->phone_number);
                            	ptr=ptr->next;
							}
            }
            if(flag==0)
            {
            	printf("\n\t\tNo duplicate.");
			}
			else
			{
				printf("\n\t\tData updated.");
			}
     }
     else
     {
         printf("\n\n\t\tOperation Failed.\n\tEither file is empty or have single element.\n\n");
     }
return lptr;
}
*/
//*******************************************************************************************************************

Node* list_union(Node* list1,Node* list2)
{
	Node *head=NULL,*ptr=NULL;
	int firsttime=1;
	if(list1==NULL)
	{
		head=list2;
	}
	else if(list2==NULL)
	{
		head=list1;
	}
	else
	{
		Node *ptr1=list1,*ptr2=list2;
		ptr=makenode("test",0,"test","test","test","test","test");
		head=ptr;
		while(ptr1!=NULL && ptr2!=NULL)
		{
			if(strcmp(ptr1->account_holder_name,ptr2->account_holder_name)<0)
			{
				ptr->next=makenode(ptr1->account_holder_name,ptr1->branch_id,ptr1->address,ptr1->PAN_number,ptr1->account_number,ptr1->deposited_money,ptr1->phone_number);
				ptr=ptr->next;
				ptr1=ptr1->next;
			}
			else if(strcmp(ptr1->account_holder_name,ptr2->account_holder_name)==0)
			{
				if(ptr1->branch_id<ptr2->branch_id)
				{
					ptr->next=makenode(ptr1->account_holder_name,ptr1->branch_id,ptr1->address,ptr1->PAN_number,ptr1->account_number,ptr1->deposited_money,ptr1->phone_number);
					ptr=ptr->next;
					ptr1=ptr1->next;
				}
				else if(ptr1->branch_id==ptr2->branch_id)
				{
					ptr->next=makenode(ptr1->account_holder_name,ptr1->branch_id,ptr1->address,ptr1->PAN_number,ptr1->account_number,ptr1->deposited_money,ptr1->phone_number);
					ptr=ptr->next;
					ptr1=ptr1->next;
					ptr2=ptr2->next;
				}
				else
				{
					ptr->next=makenode(ptr2->account_holder_name,ptr2->branch_id,ptr2->address,ptr2->PAN_number,ptr2->account_number,ptr2->deposited_money,ptr2->phone_number);
					ptr=ptr->next;
					ptr2=ptr2->next;
				}
			}
			else
			{
					ptr->next=makenode(ptr2->account_holder_name,ptr2->branch_id,ptr2->address,ptr2->PAN_number,ptr2->account_number,ptr2->deposited_money,ptr2->phone_number);
					ptr=ptr->next;
					ptr2=ptr2->next;
			}
		}
		
		if(ptr1!=NULL)
		{
			while(ptr1!=NULL)
			{
				ptr->next=makenode(ptr1->account_holder_name,ptr1->branch_id,ptr1->address,ptr1->PAN_number,ptr1->account_number,ptr1->deposited_money,ptr1->phone_number);
				ptr=ptr->next;
				ptr1=ptr1->next;
			}
		}
		else
		{
			while(ptr2!=NULL)
			{	
				ptr->next=makenode(ptr2->account_holder_name,ptr2->branch_id,ptr2->address,ptr2->PAN_number,ptr2->account_number,ptr2->deposited_money,ptr2->phone_number);
				ptr=ptr->next;
				ptr2=ptr2->next;
			}
		}
		Node* del=head;
		head=head->next;
		free(del);
	}
return head;
}

Node* intersect(Node* list1,Node* list2)
{
	Node *head=NULL,*ptr=NULL;
	int firsttime=1;
	
	
	if(list1!=NULL && list2!=NULL)
	{
		Node *ptr1=list1,*ptr2=list2;
		while(ptr1!=NULL && ptr2!=NULL)
		{
			if(strcmp(ptr1->account_holder_name,ptr2->account_holder_name)<0)
			{
				ptr1=ptr1->next;
			}
			else if(strcmp(ptr1->account_holder_name,ptr2->account_holder_name)==0)
			{
				if(ptr1->branch_id<ptr2->branch_id)
				{
					ptr1=ptr1->next;
				}
				else if(ptr1->branch_id==ptr2->branch_id)
				{
					if(firsttime==1)
					{
						ptr=makenode(ptr1->account_holder_name,ptr1->branch_id,ptr1->address,ptr1->PAN_number,ptr1->account_number,ptr1->deposited_money,ptr1->phone_number);
						head=ptr;
						firsttime=2;
					}
					else
					{
						ptr->next=makenode(ptr1->account_holder_name,ptr1->branch_id,ptr1->address,ptr1->PAN_number,ptr1->account_number,ptr1->deposited_money,ptr1->phone_number);
						ptr=ptr->next;
					}
					ptr1=ptr1->next;
					ptr2=ptr2->next;
				}
				else
				{
					ptr2=ptr2->next;
				}
			}
			else
			{
					ptr2=ptr2->next;
			}
		}
	}
return head;
}

Node* skew_symmetric(Node* list1,Node* list2)
{
	Node *head=NULL,*ptr=NULL;
	int firsttime=1;
	if(list1==NULL)
	{
		head=list2;
	}
	else if(list2==NULL)
	{
		head=list1;
	}
	else
	{
		Node *ptr1=list1,*ptr2=list2;
		ptr=makenode("test",0,"test","test","test","test","test");
		head=ptr;
		while(ptr1!=NULL && ptr2!=NULL)
		{
			if(strcmp(ptr1->account_holder_name,ptr2->account_holder_name)<0)
			{
				ptr->next=makenode(ptr1->account_holder_name,ptr1->branch_id,ptr1->address,ptr1->PAN_number,ptr1->account_number,ptr1->deposited_money,ptr1->phone_number);
				ptr=ptr->next;
				ptr1=ptr1->next;
			}
			else if(strcmp(ptr1->account_holder_name,ptr2->account_holder_name)==0)
			{
				if(ptr1->branch_id<ptr2->branch_id)
				{
					ptr->next=makenode(ptr1->account_holder_name,ptr1->branch_id,ptr1->address,ptr1->PAN_number,ptr1->account_number,ptr1->deposited_money,ptr1->phone_number);
					ptr=ptr->next;
					ptr1=ptr1->next;
				}
				else if(ptr1->branch_id==ptr2->branch_id)
				{
					ptr1=ptr1->next;
					ptr2=ptr2->next;
				}
				else
				{
					ptr->next=ptr=ptr=makenode(ptr2->account_holder_name,ptr2->branch_id,ptr2->address,ptr2->PAN_number,ptr2->account_number,ptr2->deposited_money,ptr2->phone_number);
					ptr=ptr->next;
					ptr2=ptr2->next;
				}
			}
			else
			{
				ptr->next=makenode(ptr2->account_holder_name,ptr2->branch_id,ptr2->address,ptr2->PAN_number,ptr2->account_number,ptr2->deposited_money,ptr2->phone_number);
				ptr=ptr->next;
				ptr2=ptr2->next;
			}
		}
		
		if(ptr1!=NULL)
		{
			ptr->next=ptr1;
		}
		else
		{
			if(ptr2!=NULL)
			{
				ptr->next=ptr2;
			}
		}
		Node* del=head;
		head=head->next;
		free(del);
	}
return head;
}

Node* deposit_money(Node* lptr)
{
	Node* ptr=lptr;
	Node *head=NULL,*ptr1=NULL;
	int max=0,firsttime=1;
	while(ptr!=NULL)
	{
		if(atoi(ptr->deposited_money)>max)
		{
			max=atoi(ptr->deposited_money);
		}
		ptr=ptr->next;
	}
	ptr=lptr;
	while(ptr!=NULL)
	{
		if(atoi(ptr->deposited_money)==max)
		{
					if(firsttime==1)
					{
						ptr1=makenode(ptr->account_holder_name,ptr->branch_id,ptr->address,ptr->PAN_number,ptr->account_number,ptr->deposited_money,ptr->phone_number);
						head=ptr1;
						firsttime=2;	
					}
					else
					{
						ptr1->next=makenode(ptr->account_holder_name,ptr->branch_id,ptr->address,ptr->PAN_number,ptr->account_number,ptr->deposited_money,ptr->phone_number);
						ptr1=ptr1->next;
						
					}
		}
		ptr=ptr->next;
	}
return head;
}

Node* list_difference(Node* list1,Node* list2)
{
	Node *head=NULL,*ptr=NULL;
	int firsttime=1;
	if(list1==NULL)
	{
		head=list1;
	}
	else if(list2==NULL)
	{
		head=list1;
	}
	else
	{
		Node *ptr1=list1,*ptr2=list2;
		ptr=makenode("test",0,"test","test","test","test","test");
		head=ptr;
		while(ptr1!=NULL && ptr2!=NULL)
		{
			if(strcmp(ptr1->account_holder_name,ptr2->account_holder_name)<0)
			{
				ptr->next=makenode(ptr1->account_holder_name,ptr1->branch_id,ptr1->address,ptr1->PAN_number,ptr1->account_number,ptr1->deposited_money,ptr1->phone_number);
				ptr=ptr->next;
				ptr1=ptr1->next;
			}
			else if(strcmp(ptr1->account_holder_name,ptr2->account_holder_name)==0)
			{
				if(ptr1->branch_id<ptr2->branch_id)
				{
					ptr->next=makenode(ptr1->account_holder_name,ptr1->branch_id,ptr1->address,ptr1->PAN_number,ptr1->account_number,ptr1->deposited_money,ptr1->phone_number);
					ptr=ptr->next;
					ptr1=ptr1->next;
				}
				else if(ptr1->branch_id==ptr2->branch_id)
				{
					ptr1=ptr1->next;
					ptr2=ptr2->next;
				}
				else
				{
					ptr2=ptr2->next;
				}
			}
			else
			{
					ptr2=ptr2->next;
			}
		}
		
		if(ptr1!=NULL)
		{
			ptr->next=ptr1;
		}
		Node* del=head;
		head=head->next;
		free(del);
	}
return head;
}
int *)
{
	int next_itr;
printf("\n\n\t\t[1]  Menu\t[0]  Exit\n");
printf("\tEnter Choice :");
scanf("%d",&next_itr);
system("cls");
return 	next_itr;
}
int print_file_names()
{	int filechoice;
	printf("\n\t\t---------------------------------------------");
	printf("\n\t\t\tSelect File");
	printf("\n\t\t---------------------------------------------");
	printf("\n\t\t\t[1]  Records\n\t\t\t[2]  List1\n\t\t\t[3]  List2\n\n\t\tEnter Code:");
    scanf("%d",&filechoice);
	system("cls");
return filechoice;
}
