#include<stdio.h>
#include<string.h>
#define SIZE 10
struct bank_record
{
	char account_holder_name[20];
	int branch_id;
	char address[20];
	char PAN_number[10];
	char account_number[10];
	long int deposited_money;	
	char phone_number[10];
};
struct bank_record bank_DB[SIZE];
struct bank_record list1[SIZE];
struct bank_record list2[SIZE];
struct bank_record list3[2*SIZE];

/*structure defined for the names of account_holder with maximum deposited money in a particular branch_id start*/ 
struct names_max_deposit
{
	char names[20];
};
struct names_max_deposit max_deposit_amount_names[SIZE];

void initialize(struct bank_record bank_DB[],int n);

void sort_key_based(struct bank_record bank_DB[],int n);

void insert(struct bank_record bank_DB[],int n,char account_holder_name[],int branch_id,char address[],char PAN_number[],char account_number[],long int deposited_money_money,char phone_number[]);

void delete_details(struct bank_record bank_DB[],int n,char account_holder_name[],int branch_id);

void getNumRecords(struct bank_record bank_DB[],int n);

void isEmpty(struct bank_record bank_DB[],int n);

void isFull(struct bank_record bank_DB[],int n);

void getMaxDeposit(int branch_id);

int list_unique(struct bank_record bank_DB[],int n);

void list_union(struct bank_record list1[],int n_list1,struct bank_record list2[],int n_list2,struct bank_record list3[]);

void list_difference(struct bank_record list1[],int n_list1,struct bank_record list2[],int n_list2);

void list_symmetric_difference(struct bank_record list1[],int n_list1,struct bank_record list2[],int n_list2);

void list_intersection(struct bank_record list1[],int n_list1,struct bank_record list2[],int n_list2);

int main()
{
	int i;
	int perform;/*it is used to ask whether user want to perform any operation*/
	int choice;/*it is used for giving choice to user for selection of operation*/
	int duplicate;/*it is used in list_unique function for finding whether duplicate removed or not/*/
	
	int n_list1;/*number of enteries by the user for list1*/
	int n_list2;/*number of enteries by the user for list2*/
	int n_bankDB;/*number of enteries by the user for bank_DB*/
	
	char account_holder_name[20];
	int branch_id;
	char address[20];
	char PAN_number[10];
	char account_number[10];
	long int deposited_money;	
	char phone_number[10];
	
	/*initialization of bank_DB starts*/
	initialize(bank_DB,SIZE);
	/*initialization of bank_DB completed*/

	/*filling of bank_DB array*/
	printf("\n****ENTER DETAILS OF BANK_DB:****\n");
	printf("enter the number of elements for bank_DB :");
	scanf("%d",&n_bankDB);
	
	for(i=0;i<n_bankDB;i++)
	{
		printf("\nDETAILS OF CUSTOMER-%d :\n",i+1);
		
		printf("Enter account_holder_name :");
		scanf("%s",bank_DB[i].account_holder_name);
		
		printf("Enter account_number :");
		scanf("%s",bank_DB[i].account_number);
		
		printf("Enter address :");
		scanf("%s",bank_DB[i].address);
		
		printf("Enter branch_id :");
		scanf("%d",&bank_DB[i].branch_id);
		
		printf("Enter deposited_money :");
		scanf("%ld",&bank_DB[i].deposited_money);
		
		printf("Enter PAN_number :");
		scanf("%s",bank_DB[i].PAN_number);
		
		printf("Enter phone_number :");
		scanf("%s",bank_DB[i].phone_number);
	}
	/*filling of bank array completed*/
	
	printf("\n****ENTER THE DETAILS OF LIST 1:****\n");
	printf("enter number of elements for list1:");
	scanf("%d",&n_list1);
	/*filling of list1 array*/
	for(i=0;i<n_list1;i++)
	{
		printf("\nDETAILS OF CUSTOMER-%d :\n",i+1);
			
		printf("Enter account_holder_name :");
		scanf("%s",list1[i].account_holder_name);
		
		printf("Enter account_number :");
		scanf("%s",list1[i].account_number);
		
		printf("Enter address :");
		scanf("%s",list1[i].address);
		
		printf("Enter branch_id :");
		scanf("%d",&list1[i].branch_id);
		
		printf("Enter deposited_money :");
		scanf("%ld",&list1[i].deposited_money);
		
		printf("Enter PAN_number :");
		scanf("%s",list1[i].PAN_number);
		
		printf("Enter phone_number :");
		scanf("%s",list1[i].phone_number);
	}
	/*filling of list1 completed*/
		
	printf("\n****ENTER THE DETAILS OF LIST 2:*****\n");
	printf("enter number of elements for list1:");
	scanf("%d",&n_list2);
		
	/*filling of list2 array*/
	for(i=0;i<n_list2;i++)
	{
		printf("\nDETAILS OF CUSTOMER-%d :\n",i+1);
			
		printf("Enter account_holder_name :");
		scanf("%s",list2[i].account_holder_name);
		
		printf("Enter account_number :");
		scanf("%s",list2[i].account_number);
		
		printf("Enter address :");
		scanf("%s",list2[i].address);
		
		printf("Enter branch_id :");
		scanf("%d",&list2[i].branch_id);
		
		printf("Enter deposited_money :");
		scanf("%ld",&list2[i].deposited_money);
		
		printf("Enter PAN_number :");
		scanf("%s",list2[i].PAN_number);
		
		printf("Enter phone_number :");
		scanf("%s",list2[i].phone_number);
	}
	/*filling of list2 completed*/
	
printf("\nWANT TO PERFORM ANY OPERATION (1 for yes/0 for NO):");
scanf("%d",&perform);
while(perform==1)
{
	printf("\nSELECT THE OPERATION\n");
	printf("1  : insert\n");
	printf("2  : delete\n");
	printf("3  : getNumRecords\n");
	printf("4  : isEmpty\n");
	printf("5  : isFull\n");
	printf("6  : getMaxDeposit\n");
	printf("7  : list_unique\n");
	printf("8  : list_union\n");
	printf("9  : list_intersection\n");
	printf("10 : list_difference\n");
	printf("11 : list_symmetric_difference\n\n");
	
	printf("ENTER YOUR CHOICE :");
	scanf("%d",&choice);
	
	switch(choice)
	{
		case 1:
			/*insertion of custmer details start*/
			printf("DETAILS OF CUSTOMER FOR INSERTION :\n");
		
			printf("Enter account_holder_name :");
			scanf("%s",account_holder_name);
		
			printf("Enter account_number :");
			scanf("%s",account_number);
		
			printf("Enter address :");
			scanf("%s",address);
		
			printf("Enter branch_id :");
			scanf("%d",&branch_id);
		
			printf("Enter deposited_money :");
			scanf("%ld",&deposited_money);
		
			printf("Enter PAN_number :");
			scanf("%s",PAN_number);
		
			printf("Enter phone_number :");
			scanf("%s",phone_number);
		
			insert(bank_DB,SIZE,account_holder_name,branch_id,address,PAN_number,account_number,deposited_money,phone_number);
			/*insertion of customer details completed*/
			
			/*soring of bank database based of 2 given keys*/	
			sort_key_based(bank_DB,SIZE);
			/*soring completed*/
			break;
			
		case 2:
			/*deletion of custmer details start*/
	
			printf("DETAILS OF CUSTOMER FOR DELETION :\n");
			
			printf("Enter account_holder_name :");
			scanf("%s",account_holder_name);
		
			printf("Enter branch_id :");
			scanf("%d",&branch_id);
	
			delete_details(bank_DB,SIZE,account_holder_name,branch_id);		
	
			/*deletion of customer details completed*/
			
			/*soring of bank database based of 2 given keys*/	
			sort_key_based(bank_DB,SIZE);
			/*soring completed*/
			break;
			
		case 3:
			/*finding of total number of active records start*/
			getNumRecords(bank_DB,SIZE);
			/*finding of total number of active records completed*/
	
			/*soring of bank database based of 2 given keys*/	
			sort_key_based(bank_DB,SIZE);
			/*soring completed*/
			break;
				
		case 4:
			
			/*finding of bank database is empty start*/
			isEmpty(bank_DB,SIZE);
			/*finding of bank database is empty completed*/
			
			/*soring of bank database based of 2 given keys*/	
			sort_key_based(bank_DB,SIZE);
			/*soring completed*/
			break;
				
		case 5:
			/*finding of bank database is full start*/
			isFull(bank_DB,SIZE);
			/*finding of bank database is full completed*/
		
			/*soring of bank database based of 2 given keys*/	
			sort_key_based(bank_DB,SIZE);
			/*soring completed*/
	
			break;
				
		case 6:
			/*finding of names with maximum deposited_money start*/
			printf("branch_id :");
			scanf("%d",&branch_id);
			getMaxDeposit(branch_id);
			/*finding of names with maximum deposited_money completed*/
		
			/*soring of bank database based of 2 given keys*/	
			sort_key_based(bank_DB,SIZE);
			/*soring completed*/
			break;
				
		case 7:
			/*removing of duplicate present in bank database start*/
			duplicate=list_unique(bank_DB,SIZE);
			/*removing of duplicate present in bank database completed*/
			
				if(duplicate==1)
				{
					printf("\nDUPLICATE IS REMOVED\n");
				}
				else
				{
					printf("\nDUPLICATE IS NO PRESENT TO BE REMOVED\n");
				}
	
			/*soring of bank database based of 2 given keys*/	
			sort_key_based(bank_DB,SIZE);
			/*soring completed*/
	
		/*printing of bank_DB array*/
		for(i=0;i<SIZE;i++)
		{
			printf("\nDETAILS OF CUSTOMER-%d :\n",i+1);
		
			printf("account_holder_name :%s\n",bank_DB[i].account_holder_name);
			printf("account_number :%s\n",bank_DB[i].account_number);
			printf("address :%s\n",bank_DB[i].address);
			printf("branch_id :%d\n",bank_DB[i].branch_id);
			printf("deposited_money :%ld\n",bank_DB[i].deposited_money);
			printf("PAN_number :%s\n",bank_DB[i].PAN_number);
			printf("phone_number :%s\n",bank_DB[i].phone_number);
		}
		/*printing of bank array completed*/
			
			/*soring of bank database based of 2 given keys*/	
			sort_key_based(bank_DB,SIZE);
			/*soring completed*/
			break;
				
		case 8:
			/*union/merge of 2 lists of bank database*/
		
			/*soring of list1 based of 2 given keys*/	
			sort_key_based(list1,n_list1);
			/*soring completed*/
		
			/*soring of list2 based of 2 given keys*/	
			sort_key_based(list2,n_list2);
			/*soring completed*/
		
		
			list_union(list1,n_list1,list2,n_list2,list3);
		
			/*soring of bank database based of 2 given keys*/	
			sort_key_based(bank_DB,SIZE);
			/*soring completed*/
	
	
			/*merge/union of 2 lists of bank database completed*/
			break;	
			
		case 9:
			/*intersection of 2 lists of bank database start*/
			list_intersection(list1,n_list1,list2,n_list2);
		
			/*soring of bank database based of 2 given keys*/	
			sort_key_based(bank_DB,SIZE);
			/*soring completed*/
	
			/*intersection of 2 lists of bank database completed*/
	
			break;	
			
		case 10:
			/*finding elements not common to any other list of list1 start*/
			list_difference(list1,n_list1,list2,n_list2);
		
			/*soring of bank database based of 2 given keys*/	
			sort_key_based(bank_DB,SIZE);
			/*soring completed*/
	
			/*finding elements not common to any other list of list1 completed*/
			break;
				
		case 11:
			/*finding the symmetric difference of 2 given list start*/
			list_symmetric_difference(list1,n_list1,list2,n_list2);
		
			/*soring of bank database based of 2 given keys*/	
			sort_key_based(bank_DB,SIZE);
			/*soring completed*/
	
			/*finding the symmetric difference of 2 given list start*/
			break;
			
		default :
			printf("\n*****CHOICE IS NOT VALID !*****\n");
			break;
			
	}
	
	printf("\n****WANT TO PERFORM ANY OTHER OPERATION(1 for YES/0 for NO) :****\n");
	scanf("%d",&perform);
}
	
	
	
	printf("\n\n\n\n\n");
	/*printing of bank_DB array for the last time to see bank_DB after completion of several operations*/
	for(i=0;i<SIZE;i++)
	{
		printf("\nDETAILS OF CUSTOMER-%d :\n",i+1);
		
			printf("account_holder_name :%s\n",bank_DB[i].account_holder_name);
			printf("account_number :%s\n",bank_DB[i].account_number);
			printf("address :%s\n",bank_DB[i].address);
			printf("branch_id :%d\n",bank_DB[i].branch_id);
			printf("deposited_money :%ld\n",bank_DB[i].deposited_money);
			printf("PAN_number :%s\n",bank_DB[i].PAN_number);
			printf("phone_number :%s\n",bank_DB[i].phone_number);
	}
	/*printing of bank array completed*/
return 0;
}

void initialize(struct bank_record bank_DB[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		bank_DB[i].account_holder_name[0]='\0';
		bank_DB[i].branch_id=0;
		bank_DB[i].address[0]='\0';
		bank_DB[i].PAN_number[0]='\0';
		bank_DB[i].account_number[0]='\0';
		bank_DB[i].deposited_money=0;
		bank_DB[i].phone_number[0]='\0';
	}
}

void sort_key_based(struct bank_record bank_DB[],int n)
{
	int j,sorted=0,k,i;
	char temp[20];
	int t;
	long int lt;
	/*sorting based on name of account_holder*/
	for(j=0;(j<(n-1) && sorted==0);j++)
	{
		sorted=1;
		for(k=0;k<(n-1-j);k++)
		{
			
			if(strcmp(bank_DB[k].account_holder_name,bank_DB[k+1].account_holder_name)>0)
			{
				strcpy(temp,bank_DB[k].account_holder_name);
				strcpy(bank_DB[k].account_holder_name,bank_DB[k+1].account_holder_name);
				strcpy(bank_DB[k+1].account_holder_name,temp);
				
				strcpy(temp,bank_DB[k].account_number);
				strcpy(bank_DB[k].account_number,bank_DB[k+1].account_number);
				strcpy(bank_DB[k+1].account_number,temp);
				
				strcpy(temp,bank_DB[k].address);
				strcpy(bank_DB[k].address,bank_DB[k+1].address);
				strcpy(bank_DB[k+1].address,temp);
				
				t=bank_DB[k].branch_id;
				bank_DB[k].branch_id=bank_DB[k+1].branch_id;
				bank_DB[k+1].branch_id=t;
				
			    lt=bank_DB[k].deposited_money;
				bank_DB[k].deposited_money=bank_DB[k+1].deposited_money;
				bank_DB[k+1].deposited_money=lt;
				
				strcpy(temp,bank_DB[k].PAN_number);
				strcpy(bank_DB[k].PAN_number,bank_DB[k+1].PAN_number);
				strcpy(bank_DB[k+1].PAN_number,temp);
				
				strcpy(temp,bank_DB[k].phone_number);
				strcpy(bank_DB[k].phone_number,bank_DB[k+1].phone_number);
				strcpy(bank_DB[k+1].phone_number,temp);
		
				sorted=0;
				
			}
		}
	}
	/*sorting based on branch_id of same account_holder_name*/
	for(i=0;i<(n-1);i++)
	{
		for(j=i+1;j<n;j++)
		{
			if((strcmp(bank_DB[i].account_holder_name,bank_DB[j].account_holder_name)==0) && (bank_DB[i].branch_id>bank_DB[j].branch_id))
			{
				strcpy(temp,bank_DB[i].account_holder_name);
				strcpy(bank_DB[i].account_holder_name,bank_DB[j].account_holder_name);
				strcpy(bank_DB[j].account_holder_name,temp);
				
				strcpy(temp,bank_DB[i].account_number);
				strcpy(bank_DB[i].account_number,bank_DB[j].account_number);
				strcpy(bank_DB[j].account_number,temp);
				
				strcpy(temp,bank_DB[i].address);
				strcpy(bank_DB[i].address,bank_DB[j].address);
				strcpy(bank_DB[j].address,temp);
				
				t=bank_DB[i].branch_id;
				bank_DB[i].branch_id=bank_DB[j].branch_id;
				bank_DB[j].branch_id=t;
				
			    lt=bank_DB[k].deposited_money;
				bank_DB[k].deposited_money=bank_DB[k+1].deposited_money;
				bank_DB[k+1].deposited_money=lt;
				
				strcpy(temp,bank_DB[i].PAN_number);
				strcpy(bank_DB[i].PAN_number,bank_DB[j].PAN_number);
				strcpy(bank_DB[j].PAN_number,temp);
				
				strcpy(temp,bank_DB[i].phone_number);
				strcpy(bank_DB[i].phone_number,bank_DB[j].phone_number);
				strcpy(bank_DB[j].phone_number,temp);
		
				
			}
		}
	}
}

/*function for inserting details of customer*/
void insert(struct bank_record bank_DB[],int n,char account_holder_name[],int branch_id,char address[],char PAN_number[],char account_number[],long int deposited_money,char phone_number[])
{
	int i=0;
	int found=0;/*it is used to check customer details allready present*/
	int free_index=0;/*it is used to check free space available in bank database*/
	int insertion=1;/*it is used to check customer details are added or not?*/
	while((i<n) && (found==0))
	{
		if((strcmp(bank_DB[i].account_holder_name,account_holder_name)==0) && (bank_DB[i].branch_id==branch_id))
		{
			found=1;
		}
		else
		{
			i++;
		}
	}
	
	if(found==1)
	{
		strcpy(bank_DB[i].account_number,account_number);	
		strcpy(bank_DB[i].address,address);
		bank_DB[i].deposited_money=deposited_money;
		strcpy(bank_DB[i].PAN_number,PAN_number);
		strcpy(bank_DB[i].phone_number,phone_number);
	}
	else
	{
		i=0;
		while((i<n) && (free_index==0))
		{
			if((strlen(bank_DB[i].account_holder_name)==0) && (bank_DB[i].branch_id==0))
			{
				free_index=1;
			}
			else
			{
				i++;
			}
		}
		if(free_index==1)
		{
			strcpy(bank_DB[i].account_holder_name,account_holder_name);
			bank_DB[i].branch_id=branch_id;
			strcpy(bank_DB[i].account_number,account_number);	
			strcpy(bank_DB[i].address,address);
			bank_DB[i].deposited_money=deposited_money;
			strcpy(bank_DB[i].PAN_number,PAN_number);
			strcpy(bank_DB[i].phone_number,phone_number);
		
		}
		else
		{
		 	insertion=0;	
		}		
	}
	if(insertion==1)
	{
		printf("\nDETAILS OF CUSTOMER IS INSERTED\n");
	}
	else
	{
		printf("\nDETAILS OF CUSTOMER CANNOT BE INSERTED\nAS NO FREE SPACE AVAILABLE IN BANK DATABASE\n");
	}
	
	/*soring of bank database based of 2 given keys*/	
	sort_key_based(bank_DB,SIZE);
	/*soring completed*/

 	if(insertion==1)
	{
	 	
		/*printing of bank_DB array*/
		for(i=0;i<SIZE;i++)
		{
			printf("\nDETAILS OF CUSTOMER-%d :\n",i+1);
		
			printf("account_holder_name :%s\n",bank_DB[i].account_holder_name);
			printf("account_number :%s\n",bank_DB[i].account_number);
			printf("address :%s\n",bank_DB[i].address);
			printf("branch_id :%d\n",bank_DB[i].branch_id);
			printf("deposited_money :%ld\n",bank_DB[i].deposited_money);
			printf("PAN_number :%s\n",bank_DB[i].PAN_number);
			printf("phone_number :%s\n",bank_DB[i].phone_number);
		}
		/*printing of bank array completed*/
	}
}

/*function for deletion of customer details*/
void delete_details(struct bank_record bank_DB[],int n,char account_holder_name[],int branch_id)
{
	int i=0;
	int found=0;
	while((i<n) && (found==0))
	{
		if((strcmp(bank_DB[i].account_holder_name,account_holder_name)==0) && (bank_DB[i].branch_id==branch_id))
		{
			found=1;
		}
		else
		{
			i++;
		}
	}
	
	if(found==1)
	{
		bank_DB[i].account_holder_name[0]='\0';
		bank_DB[i].branch_id=0;
		bank_DB[i].address[0]='\0';
		bank_DB[i].PAN_number[0]='\0';
		bank_DB[i].account_number[0]='\0';
		bank_DB[i].deposited_money=0;
		bank_DB[i].phone_number[0]='\0';
		
		printf("\nCUSTOMER DETAILS DELETED\n");
	}
	else
	{
		printf("\nCUSTOMER DETAILS NOT FOUND AND HENCE IT CANNOT BE DELETED\n");
	}
	
	/*soring of bank database based of 2 given keys*/	
	sort_key_based(bank_DB,SIZE);
	/*soring completed*/
	
	if(found==1)
	{
	
		/*printing of bank_DB array*/
		for(i=0;i<SIZE;i++)
		{
			printf("\nDETAILS OF CUSTOMER-%d :\n",i+1);
		
			printf("account_holder_name :%s\n",bank_DB[i].account_holder_name);
			printf("account_number :%s\n",bank_DB[i].account_number);
			printf("address :%s\n",bank_DB[i].address);
			printf("branch_id :%d\n",bank_DB[i].branch_id);
			printf("deposited_money :%ld\n",bank_DB[i].deposited_money);
			printf("PAN_number :%s\n",bank_DB[i].PAN_number);
			printf("phone_number :%s\n",bank_DB[i].phone_number);
		}
		/*printing of bank array completed*/
	}
}

/*function to find total number of active records in bank database*/
void getNumRecords(struct bank_record bank_DB[],int n)
{
	int i=0;
	int total_records=0;
	while(i<n)
	{
		if((strlen(bank_DB[i].account_holder_name)!=0) && (bank_DB[i].branch_id!=0))
		{
			total_records=total_records+1;
		}
		i++;
	}
	
	printf("\nTOTAL NUMBER OF ACTIVE RECORDS :%d\n",total_records);	
}

/*function to find bank database is EMPTY or nor ?*/
void isEmpty(struct bank_record bank_DB[],int n)
{
	int i=0;
	int found=0;
	while((i<n) && (found==0))
	{
		if((strlen(bank_DB[i].account_holder_name)!=0) &&(bank_DB[i].branch_id!=0))
		{
			found=1;
		}
	
		i++;
	}
	
	if(found==1)
	{
		printf("\nBANK DATABASE IS  NOT EMPTY\n");
	}
	else
	{
			printf("\nBANK DATABASE IS EMPTY\n");
	}	
}

/*function to find bank database is FULL or nor ?*/
void isFull(struct bank_record bank_DB[],int n)
{
	int i=0;
	int found=0;
	while((i<n) && (found==0))
	{
		if((strlen(bank_DB[i].account_holder_name)==0) && (bank_DB[i].branch_id==0))
		{
			found=1;
		}
	
		i++;
	}
	
	if(found==1)
	{
		printf("\nBANK DATABASE IS  NOT FULL\n");
	}
	else
	{
			printf("\nBANK DATABASE IS FULL\n");
	}	
}

/*function to get the maximum deposited money account_holder*/
void getMaxDeposit(int branch_id)
{
	int max=0;/*it id used to find account holder with maximum money*/
	int i=0;
	int j=0;/*count of the number of account_holder with maximum money*/
	while(i<SIZE)
	{
		if(bank_DB[i].branch_id==branch_id)/*comparison of branch_id*/
		{
			if(bank_DB[i].deposited_money>max)/*finding maximum money*/
			{
				max=bank_DB[i].deposited_money;/*copying into max*/
			}
			
		}
		i++;
	
	}
	i=0;
	while(i<SIZE)
	{
		if(bank_DB[i].branch_id==branch_id)
		{
			if(bank_DB[i].deposited_money==max)/*finding account holder with maximum money*/
			{
				
				strcpy(max_deposit_amount_names[j].names,bank_DB[i].account_holder_name);/*copying into structure of names_max_deposit*/
				j++;
			}
		}
		i++;
	}
	i=0;
	printf("\nHIGHEST DEPOSITED MONEY :%d\n",max);
	printf("\nNAMES OF ACCOUNT_HOLDER WITH MAXIMUM DEPOSITED AMOUNT :\n");
	while(i<SIZE)
	{
		printf("%s\n",max_deposit_amount_names[i].names);
		i++;
	}
}

/*function for removing the duplicate based on 2 given keys*/
int list_unique(struct bank_record bank_DB[],int n)
{
	int i;/*it is used in sorting*/
	int j;/*it is used in sorting*/
	int duplicate=0;/*it is used to check duplicate present or not?*/
	
	for(i=0;i<(n-1);i++)
	{
		for(j=i+1;((j<n) && (strlen(bank_DB[i].account_holder_name)!=0));j++)
		{
			if(strcmp(bank_DB[i].account_holder_name,bank_DB[j].account_holder_name)==0 && (bank_DB[i].branch_id==bank_DB[j].branch_id))
			{
				if(strcmp(bank_DB[i].account_number,bank_DB[j].account_number)==0)
				{
					if(bank_DB[i].deposited_money>bank_DB[j].deposited_money)
					{
						bank_DB[j].account_holder_name[0]='\0';
						bank_DB[j].branch_id=0;
						bank_DB[j].address[0]='\0';
						bank_DB[j].PAN_number[0]='\0';
						bank_DB[j].account_number[0]='\0';
						bank_DB[j].deposited_money=0;
						bank_DB[j].phone_number[0]='\0';	
					}
					else
					{
						bank_DB[i].account_holder_name[0]='\0';
						bank_DB[i].branch_id=0;
						bank_DB[i].address[0]='\0';
						bank_DB[i].PAN_number[0]='\0';
						bank_DB[i].account_number[0]='\0';
						bank_DB[i].deposited_money=0;
						bank_DB[i].phone_number[0]='\0';	
					}
							duplicate=1;
				}
			}
		
		}
	}
return(duplicate);
}

/*function for merge/union of 2 lists of bank database*/
void list_union(struct bank_record list1[],int n_list1,struct bank_record list2[],int n_list2,struct bank_record list3[])
{
	int i=0;/*counter for list1*/
	int j=0;/*counter for list2*/
	int k=0;/*counter for list3*/
	char temp[20];/*it is used to store temporary values*/
	int count;
	
	/*merging of 2 given lists start*/
	while((i<n_list1) && (j<n_list2))
	{
		if(strcmp(list2[j].account_holder_name,list1[i].account_holder_name)<0)/*condition for entry present in both the list*/
		{
			strcpy(list3[k].account_holder_name,list2[j].account_holder_name);
			list3[k].branch_id=list2[j].branch_id;
			strcpy(list3[k].account_number,list2[j].account_number);
			list3[k].deposited_money=list2[j].deposited_money;
			strcpy(list3[k].address,list2[j].address);
			strcpy(list3[k].PAN_number,list2[j].PAN_number);
			strcpy(list3[k].phone_number,list2[j].phone_number);
			
			j++;
			k++;
		}
		else if(strcmp(list2[j].account_holder_name,list1[i].account_holder_name)==0)
		{
			strcpy(list3[k].account_holder_name,list1[i].account_holder_name);
			list3[k].branch_id=list1[i].branch_id;
			strcpy(list3[k].account_number,list1[i].account_number);
			list3[k].deposited_money=list1[i].deposited_money;
			strcpy(list3[k].address,list1[i].address);
			strcpy(list3[k].PAN_number,list1[i].PAN_number);
			strcpy(list3[k].phone_number,list1[i].phone_number);
			
			i++;
			j++;/*it is used to drop the entry of the element in list2 which is common to both the list*/ 
			k++;
		}
		else
		{
			strcpy(list3[k].account_holder_name,list1[i].account_holder_name);
			list3[k].branch_id=list1[i].branch_id;
			strcpy(list3[k].account_number,list1[i].account_number);
		    list3[k].deposited_money=list1[i].deposited_money;
			strcpy(list3[k].address,list1[i].address);
			strcpy(list3[k].PAN_number,list1[i].PAN_number);
			strcpy(list3[k].phone_number,list1[i].phone_number);
			
			i++;
			k++;
		}
	}
	
	if(i<n_list1)
	{
		while(i<n_list1)
		{
		
			strcpy(list3[k].account_holder_name,list1[i].account_holder_name);
			list3[k].branch_id=list1[i].branch_id;
			strcpy(list3[k].account_number,list1[i].account_number);
			list3[k].deposited_money=list1[i].deposited_money;
			strcpy(list3[k].address,list1[i].address);
			strcpy(list3[k].PAN_number,list1[i].PAN_number);
			strcpy(list3[k].phone_number,list1[i].phone_number);
			
			i++;
			k++;	
		}
	}
	
	if(j<n_list2)
	{
		while(j<n_list2)
		{
			strcpy(list3[k].account_holder_name,list2[j].account_holder_name);
			list3[k].branch_id=list2[j].branch_id;
			strcpy(list3[k].account_number,list2[j].account_number);
			list3[k].deposited_money=list2[j].deposited_money;
			strcpy(list3[k].address,list2[j].address);
			strcpy(list3[k].PAN_number,list2[j].PAN_number);
			strcpy(list3[k].phone_number,list2[j].phone_number);
			
			j++;
			k++;
		}
	}
	/*merging of 2 given lists completed*/
	
	list_unique(list3,k);
	
	/*soring of bank database based of 2 given keys*/	
	sort_key_based(list3,k);
	/*soring completed*/
	
	if((n_list1!=0) || (n_list2!=0))
	{
		count=1;
		/*printing of list3 array*/	
		printf("\n\n\n\n**** MERGE / UNION ****");
		for(i=0;i<k;i++)
		{
			if((strlen(list3[i].account_holder_name)!=0) && (list3[i].branch_id!=0))
			{
				printf("\nDETAILS OF CUSTOMER-%d :\n",count);
		
				printf("account_holder_name :%s\n",list3[i].account_holder_name);
				printf("account_number :%s\n",list3[i].account_number);
				printf("address :%s\n",list3[i].address);
				printf("branch_id :%d\n",list3[i].branch_id);
				printf("deposited_money :%ld\n",list3[i].deposited_money);
				printf("PAN_number :%s\n",list3[i].PAN_number);
				printf("phone_number :%s\n",list3[i].phone_number);
				count++;
			}
		}
		/*printing of list3 completed*/
	}
	else
	{
		printf("NO ELEMENTS IN BOTH THE LISTS");
	}
}

/*function for finding the intersection of 2 lists of bank database*/
void list_intersection(struct bank_record list1[],int n_list1,struct bank_record list2[],int n_list2)
{
	int i;/*counter for list1*/
	int j;/*counter for list2*/
	int k=0;/*counter fot list3*/
	int found;/*it is used to find common element present or not?*/
	int count;/*it is used in printing*/
	
	
	for(i=0;i<n_list1;i++)
	{
		found=0;
		for(j=0;((j<n_list2) && (found==0));j++)
		{
			if((strcmp(list1[i].account_holder_name,list2[j].account_holder_name)==0) && (list1[i].branch_id==list2[j].branch_id) && (strcmp(list1[i].account_number,list2[j].account_number)==0))
			/*3 neccesary and sufficient conditions for finding the intersection of 2 given lists*/ 
			{
				strcpy(list3[k].account_holder_name,list2[j].account_holder_name);
				list3[k].branch_id=list2[j].branch_id;
				strcpy(list3[k].account_number,list2[j].account_number);
				list3[k].deposited_money=list2[j].deposited_money;
				strcpy(list3[k].address,list2[j].address);
				strcpy(list3[k].PAN_number,list2[j].PAN_number);
				strcpy(list3[k].phone_number,list2[j].phone_number);
			
				k++;
				found=1;
			}	
		}
	}
	
	/*it is called for retaining least number of available copies*/
	list_unique(list3,k);
	
	/*soring of bank database based of 2 given keys*/	
	sort_key_based(list3,k);
	/*soring completed*/
	
	if((n_list1!=0) || (n_list2!=0))
	{
		count=1;
		/*printing of list3 array start*/
		printf("\n\n\n\n****INTERSECTION****");
		for(i=0;i<k;i++)
		{
			if((strlen(list3[i].account_holder_name)!=0) && (list3[i].branch_id!=0))
			{
				printf("\nDETAILS OF CUSTOMER-%d :\n",count);
			
				printf("account_holder_name :%s\n",list3[i].account_holder_name);
				printf("account_number :%s\n",list3[i].account_number);
				printf("address :%s\n",list3[i].address);
				printf("branch_id :%d\n",list3[i].branch_id);
				printf("deposited_money :%ld\n",list3[i].deposited_money);
				printf("PAN_number :%s\n",list3[i].PAN_number);
				printf("phone_number :%s\n",list3[i].phone_number);
				count++;
			}
		}
	/*printing of list3 array completed*/
	}
	else
	{
		printf("NO ELEMENTS IN BOTH THE LISTS");
	}
}


void list_difference(struct bank_record list1[],int n_list1,struct bank_record list2[],int n_list2)
{
	
	int i;/*counter for list1*/
	int j;/*counter for list2*/
	int k=0;/*counter fot list3*/
	int common;/*it is used to check common element*/
	int count;/*it is used in printing*/
	
	for(i=0;i<n_list1;i++)
	{
		common=0;
		for(j=0;((j<n_list2) && (common==0));j++)
		{
			if((strcmp(list1[i].account_holder_name,list2[j].account_holder_name)==0) && (list1[i].branch_id==list2[j].branch_id))
			/*3 neccesary and sufficient conditions for finding the intersection of 2 given lists*/ 
			{
				common=1;
			}	
		}
		
		if(common==0)
		{
			strcpy(list3[k].account_holder_name,list1[i].account_holder_name);
			list3[k].branch_id=list1[i].branch_id;
			strcpy(list3[k].account_number,list1[i].account_number);
			list3[k].deposited_money=list1[j].deposited_money;
			strcpy(list3[k].address,list1[i].address);
			strcpy(list3[k].PAN_number,list1[i].PAN_number);
			strcpy(list3[k].phone_number,list1[i].phone_number);
			
			k++;
		}
	}
	
	list_unique(list3,k);/*it is called for removing the same element in list1*/
	
	/*soring of bank database based of 2 given keys*/	
	sort_key_based(list3,k);
	/*soring completed*/
	
	if((n_list1!=0) || (n_list2!=0))
	{
		count=1;
		/*printing of list3 array start*/
		printf("\n\n\n\n****LIST DIFFERENCE****");
		for(i=0;i<k;i++)
		{
			if((strlen(list3[i].account_holder_name)!=0) && (list3[i].branch_id!=0))
			{
				printf("\nDETAILS OF CUSTOMER-%d :\n",count);
			
				printf("account_holder_name :%s\n",list3[i].account_holder_name);
				printf("account_number :%s\n",list3[i].account_number);
				printf("address :%s\n",list3[i].address);
				printf("branch_id :%d\n",list3[i].branch_id);
				printf("deposited_money :%ld\n",list3[i].deposited_money);
				printf("PAN_number :%s\n",list3[i].PAN_number);
				printf("phone_number :%s\n",list3[i].phone_number);
				
				count++;
			}
		}
		/*printing of list3 array completed*/
	}
	else
	{
		printf("NO ELEMENTS IN BOTH THE LISTS");
	}
}

void list_symmetric_difference(struct bank_record list1[],int n_list1,struct bank_record list2[],int n_list2)
{
	int i;/*counter for list1*/
	int j;/*counter for list2*/
	int k=0;/*counter fot list3*/
	int common;/*it is used to check common element*/
	int count;/*it is used in printing*/
	for(i=0;i<n_list1;i++)
	{
		common=0;
		for(j=0;((j<n_list2) && (common==0));j++)
		{
			if((strcmp(list1[i].account_holder_name,list2[j].account_holder_name)==0) && (list1[i].branch_id==list2[j].branch_id) && (strcmp(list1[i].account_number,list2[j].account_number)==0))
			/*3 neccesary and sufficient conditions for finding the intersection of 2 given lists*/ 
			{
				common=1;
			}	
		}
		
		if(common==0)
		{
				strcpy(list3[k].account_holder_name,list1[i].account_holder_name);
				list3[k].branch_id=list1[i].branch_id;
				strcpy(list3[k].account_number,list1[i].account_number);
	            list3[k].deposited_money=list2[j].deposited_money;
				strcpy(list3[k].address,list1[i].address);
				strcpy(list3[k].PAN_number,list1[i].PAN_number);
				strcpy(list3[k].phone_number,list1[i].phone_number);
			
				k++;
		}
	}
	
	for(j=0;j<n_list2;j++)
	{
		common=0;
		for(i=0;((i<n_list2) && (common==0));i++)
		{
			if((strcmp(list1[i].account_holder_name,list2[j].account_holder_name)==0) && (list1[i].branch_id,list2[j].branch_id) && (strcmp(list1[i].account_number,list2[j].account_number)==0))
			/*3 neccesary and sufficient conditions for finding the intersection of 2 given lists*/ 
			{
				common=1;
			}	
		}
		
		if(common==0)
		{
			strcpy(list3[k].account_holder_name,list2[j].account_holder_name);
			list3[k].branch_id=list2[j].branch_id;
			strcpy(list3[k].account_number,list2[j].account_number);
			list3[k].deposited_money=list2[j].deposited_money;
			strcpy(list3[k].address,list2[j].address);
			strcpy(list3[k].PAN_number,list2[j].PAN_number);
			strcpy(list3[k].phone_number,list2[j].phone_number);
			
			k++;
		}
	}
	
	list_unique(list3,k);
	
	/*soring of bank database based of 2 given keys*/	
	sort_key_based(list3,k);
	/*soring completed*/
	
	if((n_list1!=0) || (n_list2!=0))
	{
		count=1;
		/*printing of list3 array start*/
		printf("\n\n\n\n****SYMMETRIC INTERSECTION****");
		for(i=0;i<k;i++)
		{
			if((strlen(list3[i].account_holder_name)!=0) && (list3[i].branch_id!=0))
			{
				printf("\nDETAILS OF CUSTOMER-%d :\n",count);
		
				printf("account_holder_name :%s\n",list3[i].account_holder_name);
				printf("account_number :%s\n",list3[i].account_number);
				printf("address :%s\n",list3[i].address);
				printf("branch_id :%d\n",list3[i].branch_id);
				printf("deposited_money :%ld\n",list3[i].deposited_money);
				printf("PAN_number :%s\n",list3[i].PAN_number);
				printf("phone_number :%s\n",list3[i].phone_number);
				count++;
			}
			/*printing of list3 array completed*/
		}
	}
	else
	{
		printf("NO ELEMENTS IN BOTH THE LISTS");
	}
}
