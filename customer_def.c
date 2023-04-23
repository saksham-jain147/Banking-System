#include"employee_header_file.h"

/*functiont to display options under edit customer info
*/
void display_edit_customer_info_menu()
{
	printf("\n*********************Select an  Option to Proceed*********************\n\n\t\t\t\t2041. Update Customer Details\n\t\t\t\t2042. Delete Customer Account\n\t\t\t\t77. previous_menu\n");
	printf("\nEnter Choice : ");
	
	return;
}



/*function to display different options available in the customer account to perform
*/
void display_customer_menu()
{
	printf("\n*********************Select an  Option to Proceed*********************\n\n\t\t31. Personal Profile\n\t\t32. Account Details\n\t\t33. Transaction History\n\t\t34. Balance\n\t\t35. Fund Transfer\n\t\t36. Help Desk\n\t\t99. Logout\n");
	
	return;
}

/*function to create node for storing attributes of customer
parameters: struct customer
*/
node* createNode(cust c)
{
    node *newnode = (node*)malloc(sizeof(node));
       
    newnode->id = c.id;
    strcpy(newnode->first_name,c.first_name);
    strcpy(newnode->last_name,c.last_name);
    newnode->aadhaar=c.aadhaar;
    newnode->phone_number=c.phone_number;
    strcpy(newnode->email,c.email);
    strcpy(newnode->gender,c.gender);
    newnode->dd = c.dd;
    newnode->mm = c.mm;
    newnode->yyyy = c.yyyy;
    strcpy(newnode->address,c.address);
    
    newnode->next = NULL;
    
    return newnode;
}



/*function to add node which store or access the values from the file
parameters: paramters: *head pointing to 1st node of LL, *newnode containing new record fetched from file*/
node* addNode(node *head,node *newnode)
{
    node *temp=head;
    //check if LL is empty
    if(head==NULL)
         head = newnode;
    else
    {
        while(temp->next!=NULL)
              temp = temp->next; //traversing along the linked list
          
        temp->next = newnode; 
    }

   return head;
}



/*function to display the details of the customer accessed from the file
prameters: *head pointing to first node of linked list*/
void displayList(node *head)
{
    node *temp=head;
    
    if(temp==NULL)
         printf("\n\n\tID Does Not Exist.......!!!!!");
    else
    {
    	while(temp!=NULL)
    	{
    		printf("\tCustomer ID:    %d\n\tFirst Name:     %s\n\tLast Name:      %s\n\tAadhaar No.:    %ld\n\tPhone Number:   %ld\n\tEmail ID:       %s\n\tGender:         %s\n\tDate Of Birth:  %d-%d-%d\n\tAddress:\t%s\n",temp->id,temp->first_name,temp->last_name,temp->aadhaar,temp->phone_number,temp->email,temp->gender,temp->dd,temp->mm,temp->yyyy,temp->address);
    		temp = temp->next;    //this will shift temp to next node
    	}
    }
    return;
}



/*function to display the personal details of the customer
parameters: integer value*/
void get_personal_details(int id)
{	
	FILE *fptr=NULL;
	
	//reading from file
	fptr = fopen("text_files/customer_personal_details.txt","r");	//opening file
	
	if(fptr == NULL)
	{
		printf("Internal Error! Data can't be displayed.");
		return;
	}
	
	char buffer[500];
	//int row=0;
	int column=0;
	int count=0;
   
	while( fgets(buffer,500,fptr))
	{
		column=0;
		//row++;
		
		//if(row == 1)
		//	continue;	//To avoid printing of column name
		
		//Splitting the data
		char* value = strtok(buffer,",");
		
		if ( atoi(value) != id )	//checking for specific person details
			continue;
			
		printf("\n################################################################################\n");
		
		while(value)
		{
			count++;
			if (column == 0) {
				printf("\n\tCustomer ID \t\t: ");
			}
			
			if (column == 1) {
				printf("\n\tFirst Name \t\t: ");
			}
			
			if (column == 2) {
				printf("\n\tLast Name \t\t: ");
			}
			
			if (column == 3) {
				printf("\n\tAadhaar No. \t\t: ");
			}
			
			if (column == 4) {
				printf("\n\tPhone No. \t\t: ");
			}
			
			if (column == 5) {
				printf("\n\tEmail Id \t\t: ");
			}
			
			if (column == 6) {
				printf("\n\tGender \t\t\t: ");
			}
			
			if (column == 7) {
				printf("\n\tDOB (DD/MM/YYYY) \t: ");
			}
			
			if (column == 8) {
				printf("\n\tAddress \t\t: ");
			}
			
			printf("%s", value);
			value = strtok(NULL, ",");
			column++;
		}
		printf("\n");
		fclose(fptr);
		break;		       
	}
	
	if(count==0)
		printf("Data Not Found!\n\n");
	
	printf("\n################################################################################\n");		
	return;
}



/*function to create node for storing attributes account
parameters: struct account*/
node_a* createNode_a(acc a)
{
    node_a *newnode_a = (node_a*)malloc(sizeof(node_a));
       
    newnode_a->userid=a.userid;
    strcpy(newnode_a->password,a.password);
    strcpy(newnode_a->ifsc,a.ifsc);
    newnode_a->account_number=a.account_number;
    newnode_a->balance=a.balance;
    newnode_a->transaction_limit=a.transaction_limit;
    
    newnode_a->next_a = NULL;
    
    return newnode_a;
}



/*function to add node to the linked list
parameters: paramters: *head pointing to 1st node of LL, *newnode containing new record fetched from file*/
node_a* addNode_a(node_a *head_a,node_a *newnode_a)
{
    node_a *temp = head_a;
    //check if LL is empty
    //printf("@@@@@@@@ENTERered!!!@@@@@@\n");
    if(head_a==NULL)
    {
    	//printf("2@@@@@@@@@@@@\n");
    	head_a = newnode_a;	
    }
    else
    {
    	//printf("3@@@@@@@@@@@@@@@@@@@@@\n");
        while(temp->next_a != NULL)
        {
        	//printf("4@@@@@@@@@@@@@@@@\n");
        	temp = temp->next_a;
        }
          
        temp->next_a = newnode_a; 
        //printf("5@@@@@@@@@@@@@@@@@@@@@\n");
    }

   return head_a;
}



/*function to display account details
parameters: *head pointing to the node 1*/
void displaylist(node_a *head_a)
{
    node_a *temp=head_a;
    
    if(temp==NULL)
         printf("\n\n\tAccount Does Not Exist.......!!!!!");
    else
    {
    	while(temp!=NULL)
    	{
    		printf("\tUser ID:\t   %d\n\tIFSC:\t           %s\n\tAccount Number:    %ld\n\tBalance:\t   %d\n\tTransaction Limit: %d\n",temp->userid,temp->ifsc,temp->account_number,temp->balance,temp->transaction_limit);
    		temp = temp->next_a;    //this will shift temp to next node
    	}
    }
    return;
}


/*function to get the details of account for a specific person
parameters: integer value*/
void get_account_details(long account_number,int customerid)
{	
		
	char ac_no[15];
	sprintf(ac_no,"%ld",account_number);
	char id[15];
	sprintf(id,"%d",customerid);
	
	FILE *fptr=NULL;
	
	//reading from file
	fptr = fopen("text_files/customer_account_details.txt","r");
   	
   	if(fptr == NULL)
	{
		printf("Internal Error! Data can't be displayed.");
		return;
	}
	
	char buffer[500];
	//int row=0;
	int column=0;
	int count=0;
	char cid[12];
	char ifsc[10];
   
	while( fgets(buffer,100,fptr))
	{
		
				
		column=0;
		
		char* value = strtok(buffer,",");
			
		while(value)
		{
			if (column == 0)
			{
				//value = strtok(NULL, ",");
				strcpy(cid,value);
				
			}
			if (column == 2)
			{
				//value = strtok(NULL, ",");
				strcpy(ifsc,value);
				
				
			}
			if (column == 3)
			{
				if( strcmp(ac_no,value)==0 && strcmp(id,cid)==0) 
				{
					printf("\n###########################################################################\n\n");
					printf("\n\tCustomer ID\t\t: %s",cid);
					printf("\n\tIFSC Code\t\t: %s",ifsc);
					
					printf("\n\tAccount Number\t\t: %s",value);
					count++;
				}
				else
					break;
			}
			
			if (column == 4)
			{
				printf("\n\tCurrent Balance\t\t: Rs. %s",value);
			}
			if (column == 5)
			{
				printf("\n\tTransaction Limit\t: Rs. %s",value);
				printf("\n\n###########################################################################\n");
			}
						
			//printf("%s", value);
			value = strtok(NULL, ",");
			
			column++;
		}
		
		       
	}
	if(count==0)
		printf("\n\tAccount Number Entered does not belongs to you! Retry\n\n");
	
	fclose(fptr);	
	return;
}

/*function to display account balance
parameters: *head pointing to the node 1*/
void displaylist_forbalance(node_a *head_a)
{
    node_a *temp=head_a;
    
    if(temp==NULL)
         printf("\n\n\tAccount Does Not Exist.......!!!!!");
    else
    {
    	while(temp!=NULL)
    	{
    		printf("\tBalance:   %d\n",temp->balance);
    		temp = temp->next_a;    //this will shift temp to next node
    	}
    }
    return;
}//display()



/*function to get the balance of account for a specific person
parameters: integer value*/
int get_balance(long account_number,int customerid)
{	
		
	char ac_no[15];
	sprintf(ac_no,"%ld",account_number);
	
	FILE *fptr=NULL;
	
	//reading from file
	fptr = fopen("text_files/customer_account_details.txt","r");
   	
   	if(fptr == NULL)
	{
		printf("Internal Error! Data can't be displayed.");
		return 0;
	}
	
	char buffer[500];
	//int row=0;
	int column=0;
	int count=0;
	
	printf("Displaying Available Balance for Customer ID : %d\n\n",customerid);
	printf("\t--------------\t---------------\n");
	printf("\tAccount Number\tCurrent Balance\n");
	printf("\t--------------\t---------------\n");
   
	while( fgets(buffer,100,fptr))
	{
		
				
		column=0;
		//row++;
		
		//if(row == 1)
			//continue;	//To avoid printing of column name
		
		//Splitting the data
		char* value = strtok(buffer,",");
		
		if ( atoi(value) != customerid )
			continue;
				
		while(value)
		{
					
			if (column == 3)
			{
				if( strcmp(ac_no,value)==0 ) 
				{
					printf("\n\t%s", value);
					count++;
				}
				else
					break;
			}
			
			if (column == 4)
			{
				printf("\t%s", value);
			}
			
						
			//printf("%s", value);
			value = strtok(NULL, ",");
			column++;
		}
		
		       
	}
	if(count==0)
		printf("\n\t*********No Data Found!*********\n\n");
	
	fclose(fptr);	
	return 0;
}


/*function to get valid amount
parameters: returns valid amount*/
int get_valid_deposit()
{
	static int amount;
	printf("\n\tEnter Starting Deposit: \n\t");
	scanf("%d",&amount);
	if(amount>0 && amount<=50000)
		return amount;
	else if(amount==0)
		return 0;
	else
	{
		printf("\n-------------------------------------------------\n");
		printf("\n\t***Invalid amount or limit exceeded. Re-enter amount\n\t(Press q and enter for main menu)\n");
		printf("\n-------------------------------------------------\n");
		get_valid_deposit();
	}
	return 0;
}



/*function to validate customer id
parameters: returns valid existing customer id*/
int validate_customerid()
{
	static int id; //variable dclaration
	printf("\n\tEnter Customer ID:\n\t");
	scanf("%d",&id); //taking user input
	int latest_id = get_latest_id();
	//printf("%d", latest_id);
	if(id>501005000 && id<=latest_id)
		return id;
	else if(id==0)
		return 0;
	else
	{
		printf("\n-------------------------------------------------\n");
		printf("\n\t***ID Does Not Exist...!! Re-enter\n\t(Press 0 and enter for main menu)\n");
		printf("\n-------------------------------------------------\n");
		validate_customerid();
	}
	return 0;
}



/*function to get transaction id
parameters: returns transaction id*/
int get_transaction_id()
{	
	trans t; 
	FILE *fp;
	char *token;
  char line[100];
  //static long trid=0;
	int count=0;
	int temp_id;
	
	fp = fopen("text_files/transactions.txt","r"); //opening text file named customer_account_details in read only access

	while(fgets(line,sizeof(line),fp)!=NULL)
	{
		token=strtok(line,",");
		if (count==0)
		{
			t.customerid=atoi((token));
			count++;
			token=strtok(NULL,",");
		}
		if (count==1)
		{
			t.transid=strtol(token,NULL,strlen(token));
			temp_id = t.transid;
			count++;
			token=strtok(NULL,",");
		}
		if (count==2)
		{
			strcpy(t.type,token);
			count++;
			token=strtok(NULL,",");
		}
		if (count==3)
		{
			t.amount=atoi((token));
			count++;
			token=strtok(NULL,"-");
		}
		if (count==4)
		{
			t.dd=atoi(token);
			token=strtok(NULL,"-");
			count++;
		}
		if (count==5)
		{
			t.mm=atoi(token);
			token=strtok(NULL,",");
			count++;
		}
		if (count==6)
		{
			t.yyyy=atoi(token);
			token=strtok(NULL,",");
			count++;
		}
		if (count==7)
		{
			strcpy(t.remarks,token);
			count++;
			token=strtok(NULL,",");
		}
		if (count==8)
		{
			strcpy(t.receiver_name,token);
			count++;
			token=strtok(NULL,",");
		}
		if (count==9)
		{
			t.receiver_acc_no=strtol(token,NULL,strlen(token));
			count++;
			token=strtok(NULL,",");
		}
	
	}
	
	fclose(fp);	 //closing file
	//free(token);
	return temp_id;
}



/*function to validate transaction type
takes no input arguments but returns transaction type*/
char * get_valid_transaction_type()
{
	static char type[6];
		 
	printf("\n\tEnter transaction type (Credit/Debit): \n\t");
	scanf("%s",type);
     
	if((strcmp(type,"credit")==0 || strcmp(type,"Credit")==0 || strcmp(type,"debit")==0 || strcmp(type,"Debit")==0)) //checking for transaction type i.e., credit or debit
		return type;
	else if(strcmp(type,"q")==0)
		return "q";
	else
		{ 
			printf("\n-------------------------------------------------\n");
			printf("\n\t***Invalid Transaction Type...!! Re-enter\n\t(Press q and enter for main menu)\n");
			printf("\n-------------------------------------------------");
			get_valid_transaction_type();
		}
	return "q";
}



/*function to validate amount of transfer with balance and transaction limit
parameters: customer id*/
int validate_amount(long acc_no)
{	
	acc a; 
	FILE *fp;
	char *token;
  	char line[100];
 	int temp_bal=0;
  	long temp_acc_no=0;
  	static int amount;
	printf("\n\tEnter amount to transfer:\n\t");
	scanf("%d",&amount);
	
	int count=0;
	
	fp = fopen("text_files/customer_account_details.txt","r"); //opening text file named Employee_credentials in read only access

	while(fgets(line,sizeof(line),fp)!=NULL)
	{
		token=strtok(line,",");
		if (count==0)
		{
			a.userid=atoi((token));
			count++;
			token=strtok(NULL,",");
		}
		if (count==1)
		{
			strcpy(a.password,token);
			count++;
			token=strtok(NULL,",");
		}
		if (count==2)
		{
			strcpy(a.ifsc,token);
			count++;
			token=strtok(NULL,",");
		}
		if (count==3)
		{
			a.account_number=strtol(token,NULL,strlen(token));
			if(a.account_number == acc_no)
			{
				temp_acc_no = a.account_number;
			}
			count++;
			token=strtok(NULL,",");
		}
		if (count==4)
		{
			a.balance=atoi((token));
			if(a.account_number == acc_no)
			{
				temp_bal=a.balance;
			}
			count++;
			token=strtok(NULL,",");
		}
		if (count==5)
		{
			a.transaction_limit=atoi((token));
			count++;
			token=strtok(NULL,",");
		}
	
		count=0;
	
	}	
		
	fclose(fp); //closing the file
	
		if(acc_no==temp_acc_no)
		{	
			if(amount<=temp_bal)
			{
				return amount;}
			else if(amount==0)
				return 0;
			else if(amount>a.balance)
			{
				printf("\n-------------------------------------------------\n");
				printf("\n\t***Insufficient Funds...!! Re-enter\n\t(Press 0 and enter for main menu)\n");
				printf("\n-------------------------------------------------\n");
				validate_amount(acc_no);
			}
			else if(amount>a.transaction_limit)
			{
				printf("\n-------------------------------------------------\n");
				printf("\n\t***Limit Exceeded...!! Re-enter\n\t(Press 0 and enter for main menu)\n");
				printf("\n-------------------------------------------------\n");
				validate_amount(acc_no);
			}
			else
			{
				printf("\n-------------------------------------------------\n");
				printf("\n\t***Invalid amount...!! Re-enter\n\t(Press 0 and enter for main menu)\n");
				printf("\n-------------------------------------------------\n");
				validate_amount(acc_no);
			}
		}  
		free(token);   
		return 0;
}



/*function to validate receiver name
takes no input arguments but returns valid receiver name*/
char * get_valid_receiver_name()
{
	int i,len;
	static char receiver_name[15];
		 
	printf("\n\tEnter receiver Name: \n\t");
	scanf("%s",receiver_name);
	//finding length of the string
	len=strlen(receiver_name);
     
	for(i=0;i<len;i++)
	{
		if(((receiver_name[i]>='a' &&  receiver_name[i]<='z') || (receiver_name[i]>='A' && receiver_name[i]<='Z') || receiver_name[i]=='.'))
			continue;
		else if(strcmp(receiver_name,"q")==0)
			return "q";
		else
		{
			printf("\n-------------------------------------------------\n");
			printf("\n\t***Invalid receiver Name...!! Re-enter\n\t(Press q and enter for main menu)\n");
			printf("\n-------------------------------------------------");
			get_valid_receiver_name();
		}
	}
	receiver_name[len]='\0';
	return receiver_name;        
}



/*function to validate remarks
takes no input arguments but returns valid remarks*/
char * get_valid_remarks()
{
	int i,len;
	static char remarks[30];
		 
	printf("\n\tEnter remarks:\n\t(rent/hospital etc for debit savings for deposit)\n\t");
	scanf("%s",remarks);
	//finding length of the string
	len=strlen(remarks);
     
	for(i=0;i<len;i++)
	{
		if(((remarks[i]>='a' &&  remarks[i]<='z') || (remarks[i]>='A' && remarks[i]<='Z')))
			continue;
		else if(strcmp(remarks,"q")==0)
			return "q";
		else
		{
			printf("\n-------------------------------------------------\n");
			printf("\n\t***Invalid remarks...!! Re-enter\n\t(Press q and enter for main menu)\n");
			printf("\n-------------------------------------------------");
			get_valid_remarks();
		}
	}
	remarks[len]='\0';
	return remarks;        
}



/*function to validate Account Number
returns valid account number*/
long get_valid_Account_Number()
{        
	static long acc;
	long accountnumber;
	printf("\n\tEnter Receiver Account Number:\n\t");
	scanf("%ld",&acc);	
	accountnumber=acc;
	int count=0;
  //to find length of the Account Number
	while(accountnumber!=0)
	{
		count++;
		accountnumber=accountnumber/10;
	}
				 
	//checking if length is equal to 11
	if(count==10)
		return acc;
	else if(acc==0)
		return 0;
	else
	{
		printf("\n-------------------------------------------------\n");
		printf("\n\t***Invalid Account Number...!!\n");
		printf("\n-------------------------------------------------");
		get_valid_Account_Number();	
	}
		
	return 0;
}



/*function to validate Account Number
returns valid account number*/
long get_valid_Account_Number_sender()
{        
	static long acc;
	long accountnumber;
	printf("\n\tEnter Account Number Transfering from:\n\t");
	scanf("%ld",&acc);	
	accountnumber=acc;
	int count=0;
  	//to find length of the Account Number
	while(accountnumber!=0)
	{
		count++;
		accountnumber=accountnumber/10;
	}
				 
	//checking if length is equal to 11
	if(count==10)
		return acc;
	else if(acc==0)
		return 0;
	else
	{
		printf("\n-------------------------------------------------\n");
		printf("\n\t***Invalid Account Number...!!\n");
		printf("\n-------------------------------------------------");
		get_valid_Account_Number_sender();	
	}
		
	return 0;
}



/*function to update balance
parameters: customer id, transaction type, amount*/
void update_balance(long sender_acc_no, long receiver_acc_no, char * type, int amount)
{	
	acc apmnt;
	FILE *fptr;
	char line[500];
	char *token;
	acc a;
	node_a *newnode_a = NULL;
	node_a *head_a = NULL;
	int count=0;

    //printf("\n in update balance");
	fptr = fopen("text_files/customer_account_details.txt","r"); //opening file
	  //loading information into linked list
	  //printf("\n already in update balance");
	  
	while(fgets(line,sizeof(line),fptr))
	{
		rewind(fptr);
		while(fgets(line,sizeof(line),fptr)!=NULL) //EOF=-1
		{
			token=strtok(line,",");
			count=0;
			if(count==0)
			{
				apmnt.userid=atoi(token);
				count++;
				token=strtok(NULL,",");
			}

			if(count==1)
			{
				strcpy(apmnt.password,token);
				token=strtok(NULL,",");
				count++;
			}
			if(count==2)
			{
				strcpy(apmnt.ifsc,token);
				token=strtok(NULL,",");
				count++;
			}
			if(count==3)
			{
				apmnt.account_number = atol(token);
				token=strtok(NULL,",");
				count++;
			}
			if(count==4)
			{
				apmnt.balance=atoi(token);
				token=strtok(NULL,",");
				count++;
			}
			if(count==5)
			{
				apmnt.transaction_limit=atoi(token);
				token=strtok(NULL,",");
				count++;
			}
			newnode_a = createNode_a(apmnt);
			head_a = addNode_a(head_a,newnode_a);    			
		}
	}
	fclose(fptr);
	//free(newnode_a);
	
	fptr = fopen("text_files/customer_account_details.txt","w"); //opening file
	newnode_a = head_a;
	while(newnode_a!=NULL) //EOF=-1
	{ 	//updating information
			
		if(sender_acc_no==newnode_a->account_number)
		{
			if(strcmp(type,"Credit")==0 || strcmp(type,"credit")==0)
			{
				newnode_a->balance=newnode_a->balance+amount;
			}
			else
			{
				newnode_a->balance=newnode_a->balance-amount;
			}
		}
		if(receiver_acc_no==newnode_a->account_number && sender_acc_no != receiver_acc_no)
		{
			newnode_a->balance=newnode_a->balance+amount;
		}

		    a.userid = newnode_a->userid;
		    strcpy(a.password,newnode_a->password);
		    strcpy(a.ifsc,newnode_a->ifsc);
		    a.account_number = newnode_a->account_number;
		    a.balance = newnode_a->balance;
		    a.transaction_limit = newnode_a->transaction_limit;
		    //printing updated info into the file
		    fprintf(fptr,"%d,%s,%s,%ld,%d,%d\n",a.userid,a.password,a.ifsc,a.account_number,a.balance,a.transaction_limit);
		    newnode_a = newnode_a->next_a;
	}

	fclose(fptr); //closing file
	free(newnode_a);
	free(head_a);
	free(token);
	return;
}



/*function to check an account number is existing or not
takes account number as input argument and returns an integer*/
int check_acc_no(long account_number)
{
	acc a; 
	FILE *fp;
	char *token;
        char line[100];
        
	int count=0;
	
	fp = fopen("text_files/customer_account_details.txt","r"); //opening text file named customer_account_details in read only access

	while(fgets(line,sizeof(line),fp)!=NULL)
	{
		token=strtok(line,",");
		if (count==0)
		{
			a.userid=atoi((token));
			count++;
			token=strtok(NULL,",");
		}
		if (count==1)
		{
			strcpy(a.password,token);
			count++;
			token=strtok(NULL,",");
		}
		if (count==2)
		{
			strcpy(a.ifsc,token);
			count++;
			token=strtok(NULL,",");
		}
		if (count==3)
		{
			a.account_number=strtol(token,NULL,strlen(token));
			count++;
			token=strtok(NULL,",");
		}
		if (count==4)
		{
			a.balance=atoi((token));
			count++;
			token=strtok(NULL,",");
		}
		if (count==5)
		{
			a.transaction_limit=atoi((token));
			count++;
			token=strtok(NULL,",");
		}
	
		count=0;
		
		if(a.account_number==account_number)
		{
			return 1;
		}
	}	
		
	fclose(fp); //closing the file
	
	free(token);
	return 0;
}

/*function to make withdrawl
returns an integer value*/
int make_withdrawl(int cu,char *type)
{
	FILE *fp=NULL;
	trans t;
	acc a;
	FILE *fptr=NULL;
	node_a *head_a=NULL,*temp=NULL;
	node_a *newnode_a=NULL;
	
	time_t ti = time(NULL);
	struct tm tm = *localtime(&ti);
	t.dd = tm.tm_mday;
	t.mm =  tm.tm_mon + 1;
	t.yyyy = tm.tm_year + 1900;
	
	//sending money from (account number)
	long sender_acc_no = get_valid_Account_Number_sender();
	if(sender_acc_no == 0)
		return 0;
		
	char *token;
        char line[100];
        
	int count=0;
	
	fp = fopen("text_files/customer_account_details.txt","r"); //opening text file named customer_account_details in read only access

	while(fgets(line,sizeof(line),fp)!=NULL)
	{
		token=strtok(line,",");
		if (count==0)
		{
			a.userid=atoi((token));
			count++;
			token=strtok(NULL,",");
		}
		if (count==1)
		{
			strcpy(a.password,token);
			count++;
			token=strtok(NULL,",");
		}
		if (count==2)
		{
			strcpy(a.ifsc,token);
			count++;
			token=strtok(NULL,",");
		}
		if (count==3)
		{
			a.account_number=strtol(token,NULL,strlen(token));
			count++;
			token=strtok(NULL,",");
		}
		if (count==4)
		{
			a.balance=atoi((token));
			count++;
			token=strtok(NULL,",");
		}
		if (count==5)
		{
			a.transaction_limit=atoi((token));
			count++;
			token=strtok(NULL,",");
		}
	
		count=0;
		
		if(sender_acc_no==a.account_number)	
		{
			if(cu==a.userid)
			{	
				break; 
			}      
			else
			{
				printf("\n?????????????????????????????????????????????????????????????????????\n");
				printf("\n\tOops! Account Number You Entered does not belongs to you.  \n");
				printf("\n?????????????????????????????????????????????????????????????????????\n");
				return 0;
			}
		}
		
	}	
		
	fclose(fp); //closing the file
		
	
	
	//receiver acc number									
	t.receiver_acc_no = get_valid_Account_Number();
	if(t.receiver_acc_no == 0)
	{
		return 0;
	}
	
	strcpy(t.receiver_name,get_valid_receiver_name());
	if(strcmp(t.receiver_name,"q") ==0)
	{
		return 0;
	}
		
	int h = check_acc_no(t.receiver_acc_no);
	if(h==0)
	{	
		printf("\n?????????????????????????????????????????????????????????????????????\n");
		printf("\n\tOops! Account Number You Entered does not Exist.  \n");
		printf("\n?????????????????????????????????????????????????????????????????????\n");
		return 0;
	}
	
								
	t.customerid = cu; //getting cusomer id
									
	t.transid = get_transaction_id(); //getting transaction id
									
	strcpy(t.type,"debit");
									
	t.amount = validate_amount(sender_acc_no); //validating amount
	if(t.amount==0)
	{
		return 0;
	}
					
	//remarks					
	strcpy(t.remarks,get_valid_remarks());
	if(strcmp(t.remarks,"q")==0)
	{
		return 0;
	}
										
	fptr = fopen("text_files/transactions.txt","a"); //opening text file named transactions from the specific location
	fprintf(fptr,"%d,%ld,%s,%d,%d-%d-%d,%s,%s,%ld\n",t.customerid,t.transid,t.type,t.amount,t.dd,t.mm,t.yyyy,t.remarks,t.receiver_name,t.receiver_acc_no); //printing information into file
	fclose(fptr); //file closing
									
	printf("\n################################################################################\n");
	printf("\n\tTransaction Succesful\n\n");
	printf("################################################################################\n");
	
	update_balance(sender_acc_no,t.receiver_acc_no,t.type,t.amount); //calling function to update balance
	//printf("*********************************************\n");
	free(head_a);
	free(temp);
	free(newnode_a);
	free(token);
	
	return 0;
}

/*function to get the latest customer id from the text file customer-personal_details
*/
int get_latest_id()
{	
	cust apmt;
	//cust c;
	char line[200];
	char *token;
	FILE *fptr=NULL;
	//node *head=NULL;
	//node *newnode=NULL;
	int count=0;
	int custid;
	
	fptr = fopen("text_files/customer_personal_details.txt","r"); //opening file
	  //loading information into linked list
	while(fgets(line,sizeof(line),fptr) != NULL) //EOF=-1
	{
		token=strtok(line,",");
		count = 0;
		if(count==0)
		{
			apmt.id=atoi(token);
			custid = apmt.id;
			count++;
			token=strtok(NULL,",");
		}

		if(count==1)
		{
			strcpy(apmt.first_name,token);
			token=strtok(NULL,",");
			count++;
		}
		if(count==2)
		{
			strcpy(apmt.last_name,token);
			token=strtok(NULL,",");
			count++;
		}
		if(count==3)
		{
			apmt.aadhaar=atol(token);
			token=strtok(NULL,",");
			count++;
		}
		if(count==4)
		{
			apmt.phone_number=atol(token);
			token=strtok(NULL,",");
			count++;
		}
		if(count==5)
		{
			strcpy(apmt.email,token);
			token=strtok(NULL,",");
			count++;
		}
		if(count==6)
		{
			strcpy(apmt.gender,token);
			token=strtok(NULL,"-");
			count++;
		}
		if(count==7)
		{
			apmt.dd=atoi(token);
			token=strtok(NULL,"-");
			count++;
		}
		if(count==8)
		{
			apmt.mm=atoi(token);
			token=strtok(NULL,",");
			count++;
		}
		if(count==9)
		{
			apmt.yyyy=atoi(token);
			token=strtok(NULL,",");
			count++;
		}
		if(count==10)
		{
			strcpy(apmt.address,token);
			token=strtok(NULL,",");
			count++;
		}
	}
	fclose(fptr);	//closing file
	free(token);
	return custid;
}


//Displaying contact Number in Help Desk file.....
void help_desk()
{
	//Variable to store Contact Number listed in help_desk file
	long int phone_Number;
	char name[30];
	FILE *fptr = NULL;
	
	//helpdesk.txt file opened in reading mode
	fptr = fopen("text_files/helpdesk.txt", "r");
	//Checking whether fptr is pointing to a file or not...
	if(fptr == NULL)
	{
		printf("No such file exist\n");
	}
	
	printf("\n");
	printf("\n-----------------------------------------------------------------------------------------\n\n");
	printf("\t\t\tHELP DESK\n\n");
	//Reading data from Customer_Personal_Information file
	while( fscanf(fptr, "%s%ld",name, &phone_Number) != -1) //EOF = -1
	{
		printf("%s\t\t\t %ld\n",name, phone_Number);
	}
	printf("\n-----------------------------------------------------------------------------------------\n");
	
	//Closing helpdesk.txt file
	fclose(fptr);
	
	return;
}



void get_customer_choice(int cu)
{
	int choice;
	do{
		long account_number;
		display_customer_menu(); //calling function display_customer_menu
		printf("Enter Choice : ");
		scanf("%d",&choice); //accepting choice from user
		switch(choice)
		{
			case personal_profile:
			{	
				get_personal_details(cu); //calling function get_personal_details()
				break;
			}
			case account_details:
			{
				printf("\n\tEnter account number: \n\t");
				scanf("%ld",&account_number);
				get_account_details(account_number,cu); //calling function get_account_details()
				break;
			}
			case transaction_history:
			{
				get_transaction_details(cu); //calling function get_transaction_details()
				break;
			}
			case current_balance:
			{
				printf("\n\tEnter account number: \n\t");
				scanf("%ld",&account_number);
				int account = get_balance(account_number,cu); //calling function get_balance()
				if(account==0)
					break;
				break;
			}
			case fund_transfer:
			{
				trans t;
				int wi = make_withdrawl(cu,t.type);
				if(wi == 0)
					printf("\n");
				break;
			}
			case display_help_desk:
			{	
				help_desk();	
				break;
			}
			case logout:
			{
				printf("\n********************************************************************\n\n");
				printf("\tYou have been successfully logged out!!!\n");
				printf("\n********************************************************************\n");
				return;
			}
			default:
			{
				printf("\n----------------------------------------------\n");
				printf("\n\tInvalid Choice...!!\n");
				printf("\n----------------------------------------------\n");
				choice = logout;
			}
		}
	}while(choice!=logout); //validating condition and break the loop if condition fails
	
	return;
}
