#include"employee_header_file.h"

char * get_password(int customer_id)
{
	static char password[15];
		
	acc a; //log is short name for struct login
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
		if(customer_id==a.userid)
		{	
			strcpy(password,a.password);
			return password;
		}     
	}	
		
	fclose(fp); //closing the file
	return "q";
}




void display_employee_menu()
{
	printf("\n*********************Select an  Option to Proceed*********************\n\n\t\t21. New account creation\n\t\t22. Accounts\n\t\t36. Help Desk\n\t\t99. Logout\n");
	printf("Enter Choice : ");
	
	return;
}

int new_account()
{
	acc a;
	cust c;
	FILE *fp,*fptr;
	int ch,amount;
	
	printf("\n\tDo you already have an account(press 1-yes and 2-no):\n\t");
	scanf("%d",&ch);
	
	if(ch==1)
	{
		c.id = validate_customerid();
		if(c.id==0)
			return 0;
		else
		{
			printf("\n------------------------------------\n\n");
		   	printf("\tValidated succesfully\n");
		   	printf("\n------------------------------------\n\n");
			strcpy(a.ifsc,"ANDB1461");
			a.account_number = get_latest_acc()+1;		//getting latest account number from file and creating new acc number using it
			a.transaction_limit = 50000;
			printf("\n\tEnter starting Deposit:\n\t");
			scanf("%d",&amount);
			a.balance = amount;
			strcpy(a.password,get_password(c.id));
			a.userid = c.id;
			
		}
		
	}
	else if(ch == 2)
	{								
		strcpy(a.ifsc,"ANDB1461");
									  
		//dt d;
		a.userid = get_latest_id()+1;							//getting latest id from file and creating new id using it
		c.id = a.userid;													
		a.account_number = get_latest_acc()+1;		//getting latest account number from file and creating new acc number using it
		a.transaction_limit = 50000;
		printf("\n\tEnter starting Deposit:\n\t");
		scanf("%d",&amount);
		a.balance = amount;
										
		strcpy(a.password,get_valid_password()); //getting validating password
		if(strcmp(a.password,"q")==0)
			return 0;
										
		strcpy(c.first_name,get_valid_firstname()); //getting validating first name
		if(strcmp(c.first_name,"q")==0)
			return 0;
										
		strcpy(c.last_name,get_valid_lastname()); //getting and validating second name
		if(strcmp(c.last_name,"q")==0)
			return 0;
												
		c.aadhaar = get_valid_aadhaar(); //getting and validating aadhaar number
		if(c.aadhaar==0)
			return 0;
												
		c.phone_number = get_valid_phone_number(); //getting validating phone number
		if(c.phone_number==0)
			return 0;
										
		strcpy(c.email,get_valid_email()); //getting and validating email
		if(strcmp(c.email,"q")==0)
			return 0;
												
		strcpy(c.gender,get_valid_gender()); //getting and validating gender
		if(strcmp(c.gender,"q")==0)
			return 0;
					
		//date validation						
		int n=4;
		while(n!=0)
		{
			printf("\n\tEnter date in the format (dd-mm-yyyy): \n\t");
			scanf("%d-%d-%d",&c.dd,&c.mm,&c.yyyy);
			int w = Validate_Date(c.dd,c.mm,c.yyyy);
			if(w==1)
				break;
			n--;
			printf("\nPlesae Re-enter the correct date. \n(only %d chances left)\n",n);
			printf("\n-------------------------------------------------");
		}
										
		strcpy(c.address,get_valid_address());
		if(strcmp(c.address,"q")==0)
			return 0;
			
		fp = fopen("text_files/customer_personal_details.txt","a"); //opening text file named customer_personal_details
		fprintf(fp,"%d,%s,%s,%ld,%ld,%s,%s,%d-%d-%d,%s\n",c.id,c.first_name,c.last_name,c.aadhaar,c.phone_number,c.email,c.gender,c.dd,c.mm,c.yyyy,c.address);
		fclose(fp); //closing file
	
	}
	else
	{
		printf("\n-------------------------------------------------\n\n");
		printf("ERROR: INVALID CHOICE:\n");
		printf("\n-------------------------------------------------\n");
		return 0;
	}		
	printf("\n################################################################################\n");
	printf("\n\tAccount Created Succesfully\n");
	get_personal_details(c.id); 	//calling functions get personal details
	fptr = fopen("text_files/customer_account_details.txt","a"); //opening text file named customer_personal_details
	fprintf(fptr,"%d,%s,%s,%ld,%d,%d\n",a.userid,a.password,a.ifsc,a.account_number,a.balance,a.transaction_limit);
	fclose(fptr); //closng file	
	e_get_account_details(a.account_number);
	
	return 1;
}
	
	
void display_accounts_menu()
{
	printf("\n*********************Select an  Option to Proceed*********************\n\n\t\t\t201. Display Customer Details\n\t\t\t202. Display Customer Account Details\n\t\t\t203. Display Customer Transactions\n\t\t\t204. Edit Customer Details\n\t\t\t88. main_menu\n");
	printf("\nchoice : ");
	
	return;
}

void e_get_account_details(long account_number)
{	
		
	char ac_no[15];
	sprintf(ac_no,"%ld",account_number);
	//char id[15];
	//printf(id,"%d",customerid);
	
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
				if( strcmp(ac_no,value)==0) 
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

long get_latest_acc()
{	
	acc apmnt;
	FILE *fptr;
	char line[200];
	char *token;
	//acc a;
	//node_a *newnode_a;
	//node_a *head_a;
	int count=0;
	static long lac=0;
	long acc;

	fptr = fopen("text_files/customer_account_details.txt","r"); //opening file
	  //loading information into linked list
	while(fgets(line,sizeof(line),fptr)!=NULL) //EOF=-1
	{
		token=strtok(line,",");
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
			
			
			acc=atoi(token);
			apmnt.account_number=acc;
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
		
		
		if(lac<apmnt.account_number)
		{
			lac=apmnt.account_number;
		}
		count=0;
	
	}
	  
	fclose(fptr);	//closing file
	
	return lac;
}


char * get_valid_password()
{
	static char password[15];
		 
	printf("\n\tEnter new Password: \n\t");
	scanf("%s",password);
     
	//finding length of the password
     
	if(strlen(password)>0 && strlen(password)<=15)
		return password;
	else if(strcmp(password,"q")==0)
		return "q";
	else
	{
		printf("\n-------------------------------------------------\n");
		printf("\n\t***Invalid password...!! Re-enter\n\t(Press q and enter for main menu)\n");
		printf("\n-------------------------------------------------");
		get_valid_password();
	}
	
	return "q";
}

/*function to validate first name
takes no input arguments but returns valid first name*/
char * get_valid_firstname()
{
	int i,len;
	static char fname[15];
		 
	printf("\n\tEnter First Name: \n\t");
	scanf("%s",fname);
	//finding length of the string
	len=strlen(fname);
     
	for(i=0;i<len;i++)
	{
		if(((fname[i]>='a' &&  fname[i]<='z') || (fname[i]>='A' && fname[i]<='Z') || fname[i]=='.'))
			continue;
		else if(strcmp(fname,"q")==0)
			return "q";
		else
		{
			printf("\n-------------------------------------------------\n");
			printf("\n\t***Invalid First Name...!! Re-enter\n\t(Press q and enter for main menu)\n");
			printf("\n-------------------------------------------------");
			get_valid_firstname();
		}
	}
	fname[len]='\0';
	
	return fname;        
}



/*function to validate last name
takes no input arguments but returns valid last name*/
char * get_valid_lastname()
{
	int i,len;
	static char lname[15];
		 
	printf("\n\tEnter Last Name: \n\t");
	scanf("%s",lname);
	//finding length of the string
	len=strlen(lname);
     
	for(i=0;i<len;i++)
	{
		if(((lname[i]>='a' &&  lname[i]<='z') || (lname[i]>='A' && lname[i]<='Z') || lname[i]=='.'))
			continue;
		else if(strcmp(lname,"q")==0)
			return "q";
		else
		{
			printf("\n-------------------------------------------------\n");
			printf("\n\t***Invalid Last Name...!! Re-enter\n\t(Press q and enter for main menu)\n");
			printf("\n-------------------------------------------------");
			get_valid_firstname();
		}
	}
	lname[len]='\0';
	
	return lname;
}



/*function to validate aadhaar
returns valid aadhaar number*/
long get_valid_aadhaar()
{         
	int count=0;
	long aadhaar,adr;
     
	printf("\n\tEnter Aadhaar: \n\t");
	scanf("%ld",&aadhaar);
	adr = aadhaar;
	   
	//to find length of the aadhaar
	while(aadhaar!=0)
	{
		count++;
		aadhaar=aadhaar/10;
	}
     
	//checking if length is equal to 12
	if(count==12)
	{
		return adr;
	}
	else if(adr==0)
	{
		return 0;
	}
	else
	{
		printf("\n-------------------------------------------------\n");
		printf("\n\t***Invalid Aadhaar...!! Re-enter\n\t(Press 0 and enter for main menu)\n");
		printf("\n-------------------------------------------------");
		get_valid_aadhaar();
	}
	return 0;
}//end



/*function to validate phone number
returns valid aadhaar number*/
long get_valid_phone_number()
{
	int count=0;
	long phone_number,ph;
	
	printf("\n\tEnter Mobile Number: \n\t");
	scanf("%ld",&phone_number);
	ph=phone_number;
	
	//to find the length of phone number
	while(phone_number!=0)
	{
		count++;
		phone_number/=10;
	}
	//checking if lenght of the phone number is 10
	if(count==10)
		return ph;
	else if(ph==0)
	{
		return 0;
	}
	else
	{
		printf("\n-------------------------------------------------\n");
		printf("\n\t***Invalid Phone Number...!! Re-enter\n\t(Press 0 and enter for main menu)\n");
		printf("\n-------------------------------------------------");
		get_valid_phone_number();
	}
	return 0;
}



/*function to validate email id
parameters: email id(string)*/
char * get_valid_email()
{
	static char Email[30];
	
	printf("\n\tEnter Email ID: \n\t");
	scanf("%s",Email);
	
	int length=strlen(Email); // finding length of email
	int i,at=0,dot=0;
	
	for(i=0;i<length;i++)
	{
		if(Email[i]=='@') //finding the position of @
		{
			at=i;
			break;
		}
	}
	for(i=0;i<length;i++)
	{	
		if(Email[i]=='.') //finding the position of '.'
		{
			dot=i;
			break;
		}
	}
	//checking is it a google email
	if((at==length-10) && (dot==length-4))
		return Email;
	else if(strcmp(Email,"q")==0)
         	return "q";
	else
	{ 
		printf("\n-------------------------------------------------\n");
		printf("\n\t***Invalid Email...!! Re-enter\n\t(Press q and enter for main menu)\n");
		printf("\n-------------------------------------------------");
		get_valid_email();
	}
	
	return "q";
}

         
/*function to validate gender
takes no input arguments but returns valid gender*/
char * get_valid_gender()
{
	static char gender[6];
		 
	printf("\n\tEnter Gender: \n\t");
	scanf("%s",gender);
     
	if((strcmp(gender,"male")==0 || strcmp(gender,"Male")==0 || strcmp(gender,"female")==0 || strcmp(gender,"Female")==0))
		return gender;
	else if(strcmp(gender,"q")==0)
		return "q";
	else
		{ 
			printf("\n-------------------------------------------------\n");
			printf("\n\t***Invalid Gender...!! Re-enter\n\t(Press q and enter for main menu)\n");
			printf("\n-------------------------------------------------");
			get_valid_gender();
		}
	return "q";
}



/*function to validate address
takes no input arguments but returns valid address*/
char * get_valid_address()
{
	static char address[50];
		 
	printf("\n\tEnter city of Living: \n\t");
	scanf("%s",address);
    
	//finding length of the string
     
	if(strlen(address)>0 && strlen(address)<=50)
		return address;
	else if(strcmp(address,"q")==0)
		return "q";
	else
	{
		printf("\n-------------------------------------------------\n");
		printf("\n\t***Invalid address...!! Re-enter\n\t(Press q and enter for main menu)\n");
		printf("\n-------------------------------------------------");
		get_valid_address();
	}
	
	return "q";
}



/*function to validate date
parameters: takes date month and year as input arguments and return true or false*/
int Validate_Date(int dd, int mm, int yyyy)
{	
	time_t ti = time(NULL);
	struct tm tm = *localtime(&ti);
	//int d = tm.tm_mday;
	//int m =  tm.tm_mon + 1;
	int y = tm.tm_year + 1900;
	
	//Check Year is valid or not
	if(yyyy>=(y-60) && yyyy<=(y-18)) 
	{	
		//Check month is valid or not
		if(mm>=1 && mm<=12) 
		{	
			//Check day is valid or not
			if((dd>=1 && dd<=31) && (mm==1 || mm==3 || mm==5 || mm==7 || mm==8 || mm==10 || mm==12))
				return 1;
			else if((dd>=1 && dd<=30) && (mm==4 || mm==6 || mm== 9 || mm==11))
				return 1;
			else if((dd>1 && dd<=28) && (mm==2))
				return 1;
			else if(dd==29 && mm==2 && (yyyy%4==0 || (yyyy%4==0 && yyyy%100!=0)))
				return 1;
			else
			{
				printf("\n-------------------------------------------------\n");
				printf("\n\tDay is Invalid...!!\n");
				return 0;
			}
		}
		else
		{
			printf("\n-------------------------------------------------\n");
			printf("\n\tMonth is Invalid...!!\n");
			return 0;
		}
	}
	else
	{
		printf("\n-------------------------------------------------\n");
		printf("\n\tYear is Invalid...!!\n");
		return 0;
	}
}

void display_update_list()
{
	printf("\n*********************Select Your  Account Category*********************\n\n\t\t\t\t\t20411. Update First Name\n\t\t\t\t\t20412. Update last Name\n\t\t\t\t\t20413. Update email\n\t\t\t\t\t20414. Update Phone Number\n\t\t\t\t\t66. back_to_previous_menu\n");
	printf("\nchoice : ");
}

void update_first_name(int customer_id,char * new_first_name)
{	
	//cust apmt;
	cust c;
	char line[200];
	char *token;
	FILE *fptr;
	node *head=NULL;
	node *newnode=NULL;
	int count=0;
	
	fptr = fopen("text_files/customer_personal_details.txt","r"); //opening file
	  //loading information into linked list
	  
	while(fgets(line,200,fptr))
	{
	   rewind(fptr);
	while(fgets(line,sizeof(line),fptr)!=NULL) //EOF=-1
	{
	    count=0;
		token=strtok(line,",");
		if(count==0)
		{
			c.id=atoi(token);
			count++;
			token=strtok(NULL,",");
		}

		if(count==1)
		{
			strcpy(c.first_name,token);
			token=strtok(NULL,",");
			count++;
		}
		if(count==2)
		{
			strcpy(c.last_name,token);
			token=strtok(NULL,",");
			count++;
			//printf("\n+++%s+++\n", token);
		}
		if(count==3)
		{
			c.aadhaar = atol(token);
			token=strtok(NULL,",");
			count++;
		}
		if(count==4)
		{
			c.phone_number = strtol(token,NULL,strlen(token));
			token=strtok(NULL,",");
			count++;
		}
		if(count==5)
		{
			strcpy(c.email,token);
			token=strtok(NULL,",");
			count++;
		}
		if(count==6)
		{
			strcpy(c.gender,token);
			token=strtok(NULL,"-");
			count++;
		}
		if(count==7)
		{
			c.dd=atoi(token);
			token=strtok(NULL,"-");
			count++;
		}
		if(count==8)
		{
			c.mm=atoi(token);
			token=strtok(NULL,",");
			count++;
		}
		if(count==9)
		{
			c.yyyy=atoi(token);
			token=strtok(NULL,",");
			count++;
		}
		if(count==10)
		{
			strcpy(c.address,token);
			token=strtok(NULL,",");
			count++;
		}



			newnode = createNode(c);
			head = addNode(head,newnode);      
	}
	}
	fclose(fptr); //closing file
	
	fptr = fopen("text_files/customer_personal_details.txt","w"); //opening file
	
	newnode = head;
	while(newnode!=NULL) //EOF=-1
	{	
		if(customer_id==newnode->id)
			{
				strcpy(newnode->first_name,new_first_name);
			}
	
		    c.id = newnode->id;
		    strcpy(c.first_name,newnode->first_name);
		    strcpy(c.last_name,newnode->last_name);
		    c.aadhaar = newnode->aadhaar;
		    c.phone_number = newnode->phone_number;
		    strcpy(c.email,newnode->email);
		    strcpy(c.gender,newnode->gender);
		    c.dd = newnode->dd;
		    c.mm = newnode->mm;
		    c.yyyy = newnode->yyyy;
		    strcpy(c.address,newnode->address);
    
	    //printing information into file
	    fprintf(fptr,"%d,%s,%s,%ld,%ld,%s,%s,%d-%d-%d,%s",c.id,c.first_name,c.last_name,c.aadhaar,c.phone_number,c.email,c.gender,c.dd,c.mm,c.yyyy,c.address); 
	    newnode = newnode->next;
	   }
		
	fclose(fptr);	 //closing file
	printf("\n################################################################################\n");
	printf("\n\tFirst Name Updated Successfully\n\n");
	printf("################################################################################\n");
}



/*function to update last name
parameters: new last name*/
void update_last_name(int customer_id,char * new_last_name)
{	
	cust c;
	char line[200];
	char *token;
	FILE *fptr=NULL;
	node *head=NULL;
	node *newnode=NULL;
	int count=0;
	
	fptr = fopen("text_files/customer_personal_details.txt","r"); //opening file
	  //loading information into linked list
	  
	while(fgets(line,200,fptr))
	{
	   	rewind(fptr);
		while(fgets(line,sizeof(line),fptr)!=NULL) //EOF=-1
		{
			token=strtok(line,",");
			count = 0;
			if(count==0)
			{
				c.id=atoi(token);
				count++;
				token=strtok(NULL,",");
			}

			if(count==1)
			{
				strcpy(c.first_name,token);
				token=strtok(NULL,",");
				count++;
			}
			if(count==2)
			{
				strcpy(c.last_name,token);
				token=strtok(NULL,",");
				count++;
			}
			if(count==3)
			{
				c.aadhaar = atol(token);
				token=strtok(NULL,",");
				count++;
			}
			if(count==4)
			{
				c.phone_number=strtol(token,NULL,strlen(token));
				token=strtok(NULL,",");
				count++;
			}
			if(count==5)
			{
				strcpy(c.email,token);
				token=strtok(NULL,",");
				count++;
			}
			if(count==6)
			{
				strcpy(c.gender,token);
				token=strtok(NULL,"-");
				count++;
			}
			if(count==7)
			{
				c.dd=atoi(token);
				token=strtok(NULL,"-");
				count++;
			}
			if(count==8)
			{
				c.mm=atoi(token);
				token=strtok(NULL,",");
				count++;
			}
			if(count==9)
			{
				c.yyyy=atoi(token);
				token=strtok(NULL,",");
				count++;
			}
			if(count==10)
			{
				strcpy(c.address,token);
				token=strtok(NULL,",");
				count++;
			}
				newnode = createNode(c);
				head = addNode(head,newnode);      
		}
	}
	fclose(fptr); //closing file
			
	
	fptr = fopen("text_files/customer_personal_details.txt","w"); //opening file
  	newnode = head;
	while(newnode!=NULL) //EOF=-1
	{	
		if(customer_id==newnode->id)
		{
			strcpy(newnode->last_name,new_last_name);
		}
	
		c.id = newnode->id;
	        strcpy(c.first_name,newnode->first_name);
	    	strcpy(c.last_name,newnode->last_name);
	    	c.aadhaar = newnode->aadhaar;
	    	c.phone_number = newnode->phone_number;
	    	strcpy(c.email,newnode->email);
	    	strcpy(c.gender,newnode->gender);
	    	c.dd = newnode->dd;
	    	c.mm = newnode->mm;
	    	c.yyyy = newnode->yyyy;
	   	strcpy(c.address,newnode->address);
	    	//printing information into file
	    	fprintf(fptr,"%d,%s,%s,%ld,%ld,%s,%s,%d-%d-%d,%s",c.id,c.first_name,c.last_name,c.aadhaar,c.phone_number,c.email,c.gender,c.dd,c.mm,c.yyyy,c.address);
    		newnode = newnode->next;
   	}
		
	fclose(fptr);	 //closing file
	printf("\n################################################################################\n");
	printf("\n\tLast Name Updated Successfully\n\n");
	printf("################################################################################\n");
}



/*function to update email
parameters: email*/
void update_email(int customer_id,char * email)
{	
	cust c;
	char line[200];
	char *token;
	FILE *fptr=NULL;
	node *head=NULL;
	node *newnode=NULL;
	int count=0;
	
	fptr = fopen("text_files/customer_personal_details.txt","r"); //opening file
	  //loading information into linked list
	while(fgets(line,200,fptr))
	{
	        rewind(fptr);
		while(fgets(line,sizeof(line),fptr)!=NULL) //EOF=-1
		{
			token=strtok(line,",");
			count = 0;
			if(count==0)
			{
				c.id=atoi(token);
				count++;
				token=strtok(NULL,",");
			}

			if(count==1)
			{
				strcpy(c.first_name,token);
				token=strtok(NULL,",");
				count++;
			}
			if(count==2)
			{
				strcpy(c.last_name,token);
				token=strtok(NULL,",");
				count++;
			}
			if(count==3)
			{
				c.aadhaar = atol(token);
				token=strtok(NULL,",");
				count++;
			}
			if(count==4)
			{
				c.phone_number=strtol(token,NULL,strlen(token));
				token=strtok(NULL,",");
				count++;
			}
			if(count==5)
			{
				strcpy(c.email,token);
				token=strtok(NULL,",");
				count++;
			}
			if(count==6)
			{
				strcpy(c.gender,token);
				token=strtok(NULL,"-");
				count++;
			}
			if(count==7)
			{
				c.dd=atoi(token);
				token=strtok(NULL,"-");
				count++;
			}
			if(count==8)
			{
				c.mm=atoi(token);
				token=strtok(NULL,",");
				count++;
			}
			if(count==9)
			{
				c.yyyy=atoi(token);
				token=strtok(NULL,",");
				count++;
			}
			if(count==10)
			{
				strcpy(c.address,token);
				token=strtok(NULL,",");
				count++;
			}
				newnode = createNode(c);
				head = addNode(head,newnode);      
		}
	}
	fclose(fptr); //closing file
	
	fptr = fopen("text_files/customer_personal_details.txt","w"); //opening file
	
  newnode = head;
	while(newnode!=NULL) //EOF=-1
	{	
	    if(customer_id==newnode->id)
	    {
		strcpy(newnode->email,email);
	    }
	
	    c.id = newnode->id;
    	    strcpy(c.first_name,newnode->first_name);
	    strcpy(c.last_name,newnode->last_name);
	    c.aadhaar = newnode->aadhaar;
	    c.phone_number = newnode->phone_number;
	    strcpy(c.email,newnode->email);
	    strcpy(c.gender,newnode->gender);
	    c.dd = newnode->dd;
	    c.mm = newnode->mm;
	    c.yyyy = newnode->yyyy;
	    strcpy(c.address,newnode->address);
	    //printing information into file
	    fprintf(fptr,"%d,%s,%s,%ld,%ld,%s,%s,%d-%d-%d,%s",c.id,c.first_name,c.last_name,c.aadhaar,c.phone_number,c.email,c.gender,c.dd,c.mm,c.yyyy,c.address);
	    newnode = newnode->next;
        }
		
	fclose(fptr);	 //closing file
	printf("\n################################################################################\n");
	printf("\n\tEmail Updated Successfully\n\n");
	printf("################################################################################\n");
}



/*function to update phone number
parameters: new phone number*/
void update_phone_number(int customer_id,long phone_number)
{	
	cust c;
	char line[200];
	char *token;
	FILE *fptr=NULL;
	node *head=NULL;
	node *newnode=NULL;
	int count=0;
	
	fptr = fopen("text_files/customer_personal_details.txt","r"); //opening file
	  //loading information into linked list
	while(fgets(line,200,fptr))
	{
	        rewind(fptr);
		while(fgets(line,sizeof(line),fptr)!=NULL) //EOF=-1
		{
			token=strtok(line,",");
			count = 0;
			if(count==0)
			{
				c.id=atoi(token);
				count++;
				token=strtok(NULL,",");
			}

			if(count==1)
			{
				strcpy(c.first_name,token);
				token=strtok(NULL,",");
				count++;
			}
			if(count==2)
			{
				strcpy(c.last_name,token);
				token=strtok(NULL,",");
				count++;
			}
			if(count==3)
			{
				c.aadhaar = atol(token);
				token=strtok(NULL,",");
				count++;
			}
			if(count==4)
			{
				c.phone_number=strtol(token,NULL,strlen(token));
				token=strtok(NULL,",");
				count++;
			}
			if(count==5)
			{
				strcpy(c.email,token);
				token=strtok(NULL,",");
				count++;
			}
			if(count==6)
			{
				strcpy(c.gender,token);
				token=strtok(NULL,"-");
				count++;
			}
			if(count==7)
			{
				c.dd=atoi(token);
				token=strtok(NULL,"-");
				count++;
			}
			if(count==8)
			{
				c.mm=atoi(token);
				token=strtok(NULL,",");
				count++;
			}
			if(count==9)
			{
				c.yyyy=atoi(token);
				token=strtok(NULL,",");
				count++;
			}
			if(count==10)
			{
				strcpy(c.address,token);
				token=strtok(NULL,",");
				count++;
			}
				newnode = createNode(c);
				head = addNode(head,newnode);      
		}
	}
	fclose(fptr); //closing file
	
	fptr = fopen("text_files/customer_personal_details.txt","w"); //opening file
	
  newnode = head;
	while(newnode!=NULL) //EOF=-1
	{	
		if(customer_id==newnode->id)
		{
			newnode->phone_number=phone_number;
		}
		c.id = newnode->id;
    		strcpy(c.first_name,newnode->first_name);
    		strcpy(c.last_name,newnode->last_name);
   		c.aadhaar = newnode->aadhaar;
   		c.phone_number = newnode->phone_number;
    		strcpy(c.email,newnode->email);
    		strcpy(c.gender,newnode->gender);
   		c.dd = newnode->dd;
   		c.mm = newnode->mm;
    		c.yyyy = newnode->yyyy;
   		strcpy(c.address,newnode->address);
    		//printing information into file
    		fprintf(fptr,"%d,%s,%s,%ld,%ld,%s,%s,%d-%d-%d,%s",c.id,c.first_name,c.last_name,c.aadhaar,c.phone_number,c.email,c.gender,c.dd,c.mm,c.yyyy,c.address);
    		newnode = newnode->next;
  	 }	
	 fclose(fptr);	 //closing file
	 printf("\n################################################################################\n");
	 printf("\n\tPhone Number Updated Successfully\n\n");
	 printf("################################################################################\n");
}

void delete_personal_details(int customer_id)
{	
	cust apmt;
	cust c;
	char line[500];
	char *token;
	FILE *fptr=NULL;
	node *head=NULL;
	node *newnode=NULL;
	int count=0;
	printf("\n in delete");
	fptr = fopen("text_files/customer_personal_details.txt","r"); 
	//opening file
	if(fptr==NULL)
	{
	     printf("\nCant access this file");
	}
	  //loading information into linked list
	  
	  // printf("\nCant access this file");
	while(fgets(line,500,fptr))
	{
	   
        rewind(fptr);
	
	while(fgets(line,sizeof(line),fptr)!=NULL) //EOF=-1
	{
		token=strtok(line,",");
		count=0;
		if(count==0)
		{
			apmt.id=atoi(token);
			token=strtok(NULL,",");
			count++;
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
			apmt.aadhaar=atoi(token);
			token=strtok(NULL,",");
			count++;
		}
		if(count==4)
		{
			apmt.phone_number=atoi(token);
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


			newnode = createNode(apmt);
			head = addNode(head,newnode);      
	}
	}
	fclose(fptr); //closing file
	
	//deleting customer personal details
	//printf("\n near delete");
	head=delete_personal(customer_id,head); //deleting node
	
	fptr = fopen("text_files/customer_personal_details.txt","w"); //opening file
	
  newnode = head;
	while(newnode!=NULL) //EOF=-1
	{	
		c.id = newnode->id;
    strcpy(c.first_name,newnode->first_name);
    strcpy(c.last_name,newnode->last_name);
    c.aadhaar = newnode->aadhaar;
    c.phone_number = newnode->phone_number;
    strcpy(c.email,newnode->email);
    strcpy(c.gender,newnode->gender);
    c.dd = newnode->dd;
    c.mm = newnode->mm;
    c.yyyy = newnode->yyyy;
    strcpy(c.address,newnode->address);
    //printing updated information into file
   fprintf(fptr,"%d,%s,%s,%ld,%ld,%s,%s,%d-%d-%d,%s",c.id,c.first_name,c.last_name,c.aadhaar,c.phone_number,c.email,c.gender,c.dd,c.mm,c.yyyy,c.address);
    newnode = newnode->next;
   }
		
	fclose(fptr);	 //closing file
}



/*function to delete customer account details
parameters: customer id*/
void e_delete_account_details(long account_number)
{	
	acc a; 
	FILE *fp;
	FILE *fptr;
	char *token;
        char line[100];
        node_a * newnode_a=NULL;
        node_a * head_a=NULL;
	int count=0;
	long acc;
	
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
		    acc=atoi(token);
			a.account_number=acc;
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
			newnode_a = createNode_a(a);
			head_a = addNode_a(head_a,newnode_a);       
	}
	fclose(fp); //closing file
	//deleting customer account details
	head_a=delete_account(account_number,head_a); //deleting node
	
	fptr = fopen("text_files/customer_account_details.txt","w"); //opening file
	
  newnode_a = head_a;
	while(newnode_a!=NULL) //EOF=-1
	{	
		a.userid = newnode_a->userid;
    strcpy(a.password,newnode_a->password);
    strcpy(a.ifsc,newnode_a->ifsc);
    a.account_number = newnode_a->account_number;
    a.balance = newnode_a->balance;
    a.transaction_limit = newnode_a->transaction_limit;
    //printing updated information into file
    fprintf(fptr,"%d,%s,%s,%ld,%d,%d\n",a.userid,a.password,a.ifsc,a.account_number,a.balance,a.transaction_limit);
    newnode_a = newnode_a->next_a;
   }
		
	fclose(fptr);	 //closing file
}


node_t* createNode_t(trans t)
{
    node_t *newnode_t = (node_t*)malloc(sizeof(node_t));
       
    newnode_t->customerid=t.customerid;
    newnode_t->transid=t.transid;
    strcpy(newnode_t->type,t.type);
    newnode_t->amount=t.amount;
    newnode_t->dd=t.dd;
    newnode_t->mm=t.mm;
    newnode_t->yyyy=t.yyyy;
    strcpy(newnode_t->remarks,t.remarks);
    strcpy(newnode_t->receiver_name,t.receiver_name);
    newnode_t->receiver_acc_no=t.receiver_acc_no;
    
    newnode_t->next_t = NULL;
    
    return newnode_t;
}



/*function to add node to the linked list
parameters: paramters: *head pointing to 1st node of LL, *newnode containing new record fetched from file*/
node_t* addNode_t(node_t *head_t,node_t *newnode_t)
{
    node_t *temp=head_t;
    //check if LL is empty
    if(head_t==NULL)
         head_t = newnode_t;
    else
    {
        while(temp->next_t!=NULL)
              temp = temp->next_t;
          
        temp->next_t = newnode_t; 
    }

   return head_t;
}

node* delete_personal(int id,node *head)
{
    node *temp=head;
    node *tag;
    int flag=0;
    if(head==NULL)
    {
        printf("\nLIST EMPTY");
    }
    else if(head->next==NULL)
    {
        if(temp->id==id)
        {
            free(temp);
            flag++;
        }
    }
    else if(head->id==id)
    {
         head=head->next;
         free(temp);
         flag++;
    }
    else
    {
        while(temp!=NULL && temp->id!=id)
        {
            tag=temp;
            temp=temp->next;
        }
        if(temp!=NULL)
        {
           tag->next=temp->next;
           free(temp);
           flag++;
        }
        
    }
    if(flag==0)
    {
         printf("\nError:employee details doesnt exist");
    }
    return head;    
}



/*functionto delete account details
parameters: customer id, head*/
node_a* delete_account(long id,node_a *head_a)
{
    node_a *temp=head_a;
    node_a *tag_a;
    if(head_a==NULL)
    {
        printf("\nLIST EMPTY");
    }
    else if(head_a->next_a==NULL)
    {
        if(temp->account_number==id)
        {
            free(temp);
        }
    }
    else if(head_a->account_number==id)
    {
         head_a=head_a->next_a;
         free(temp);
    }
    else
    {
        while(temp!=NULL && temp->account_number!=id)
        {
            tag_a=temp;
            temp=temp->next_a;
        }
        if(temp!=NULL)
        {
           tag_a->next_a=temp->next_a;
           free(temp);
        }
        
    }
    return head_a;    
}


void get_transaction_details(int customerid)
{	
	FILE *fptr=NULL;
	
	
	//reading from file and loading all data in LinkedList
	fptr = fopen("text_files/transactions.txt","r");
   	
   	if(fptr == NULL)
	{
		printf("Internal Error! Data can't be displayed.\n");
		return;
	}
	
	char buffer[500];
	int row=0;
	int column=0;
	int count=0;
	
	printf("\n\nDisplaying Transaction History for Customer ID : %d\n\n\t",customerid);
	printf("\n###########################################################################################################################################################################\n\n");
	printf("\t\tCUSTOMER ID\t\tACCOUNT NUMBER\t\tMODE\t\tAMOUNT\t\tDATE\t\t\tREMARK\t\tRECEIVER NAME\tRECEIVER ACCOUNT NUMBER\n\n\t\t");
   
	while( fgets(buffer,100,fptr))
	{
		
				
		column=0;
		row++;
		
				
		//Splitting the data
		char* value = strtok(buffer,", ");
		
		if ( atoi(value) != customerid )
			continue;

		while(value)
		{
			count++;	
			printf("%s\t\t", value);
			value = strtok(NULL, ", ");
			column++;
		}
		       
	}
	if(count==0)
		printf("\n\t****No Data Found!****\n\n");
	printf("\n###########################################################################################################################################################################\n\n");
	fclose(fptr);	
	return;
}

void get_employee_choice(int eid)
{
	int choice;
	do{
		display_employee_menu();
		scanf("%d",&choice); //accepting choice from user
		switch(choice)
		{
			case new_account_creation:
			{	
				
				    int n = new_account();
					if(n==0)
						break;
				break;
			}
			case accounts:
			{
				do{
					display_accounts_menu();
					scanf("%d",&choice); //accepting choice from user
					int id;
					long account_number;
					switch(choice)
					{
						case display_customer_details:
						{	
							printf("\n\tEnter Customer ID: \n\t");
							scanf("%d",&id);
							get_personal_details(id); //calling function get_personal_details()
							break;
						}
						case display_customer_account_details:
						{
							printf("\n\tEnter account number: \n\t");
							scanf("%ld",&account_number);
							e_get_account_details(account_number); //calling function e_get_account_details()
							break;
						}
						case display_customer_transactions:
						{
							printf("\n\tEnter Customer ID: \n\t");
							scanf("%d",&id);
							get_transaction_details(id); //calling function gat_transaction_details()
							break;
						}
						case edit_customer_info:
						{
							do{
								display_edit_customer_info_menu();
								scanf("%d",&choice); //accepting choice from user
								switch(choice)
								{
									case update_customer_info:
									{
										 do{
								 			display_update_list(); //calling function to display a list that can be updated
											scanf("%d",&choice); //accepting choice from user
											switch(choice)
											{	
												int id;
												case Update_First_Name: 
												{
													printf("\n\tEnter customer ID:\n\t");
													scanf("%d",&id);
													char fn[15];
													strcpy(fn,get_valid_firstname());
													//printf("\n%s",fn); //getting and validating first name
													if(strcmp(fn,"q")==0)
														break;
													update_first_name(id,fn);//updating first name by calling function
													break;
												}
												case Update_Last_Name:
												{
													printf("\n\tEnter customer ID:\n\t");
													scanf("%d",&id);
													char ln[15];
													strcpy(ln,get_valid_lastname()); //getting and validating last name
													if(strcmp(ln,"q")==0)
														break;
													update_last_name(id,ln); //updating last name by calling a function
													break;
												}
												case Update_Email:
												{
													printf("\n\tEnter customer ID:\n\t");
													scanf("%d",&id);
													char e[30];
													strcpy(e,get_valid_email()); //getting and validating email
													if(strcmp(e,"q")==0)
														break;
													update_email(id,e); //updating email
													break;
												}
												case Update_Phone_Number:
												{
													printf("\n\tEnter customer ID:\n\t");
													scanf("%d",&id);
													long ph = get_valid_phone_number(); //getting and validating phone number
													if(ph==0)
														break;
													update_phone_number(id,ph); //calling a function to update phone number
													break;
												}
												case back_to_previous_menu: //going back to the previous menu
												{
													break;
												}
												case Exit:
												{	
													exit(0); //exit from program
												}
												default:
												{
													printf("\n----------------------------------------------\n");
													printf("\n\tInvalid Choice...!!\n");
													printf("\n----------------------------------------------\n");
													continue;
													//choice = back_to_previous_menu;
												}
											}
										 			
										 }while(choice!=back_to_previous_menu);
										 
										break;
									}
									case delete_customer_info:
									{
										
										printf("\n\tEnter accountnumber to delete:\n\t");
										scanf("%d",&id);
										//printf("%d",id); //taking customer id as user input
										//delete_personal_details(id);	//function calling to delete personal details
										e_delete_account_details(id);		//function calling to delete account details
										//delete_transaction_history(id); //function calling to delete all transactions for a particular id
										
										printf("\n################################################################################\n");
										printf("\n\tCustomer Account (ACCOUNT NUMBER: %d) has closed/deleted\n\n",id);
										printf("################################################################################\n");
											
										break;
									}
									case previous_menu:
									{
										break;
									}
									
									default:
									{
										printf("\n----------------------------------------------\n");
										printf("\n\tInvalid Choice...!!\n");
										printf("\n----------------------------------------------\n");
										continue;
										//choice = previous_menu;
									}
								}
							}while(choice!=previous_menu); //validating condition and break the loop if condition fails
							break;
							}
							case main_menu:
							{
								break;
							}
							default:
							{
								printf("\n----------------------------------------------\n");
								printf("\n\tInvalid Choice...!!\n");
								printf("\n----------------------------------------------\n");
								continue;
								//choice = main_menu;
							}
						}
					}while(choice!=main_menu); //validating condition and break the loop if condition fails
				break;
			}
			
			case display_help_desk:
			{
				help_desk();
				break;
			}
			case logout:
			{
				return;
			}
			default:
			{
				printf("\n----------------------------------------------\n");
				printf("\n\tInvalid Choice...!!\n");
				printf("\n----------------------------------------------\n");
				continue;
				//get_employee_choice(eid);
				//choice = logout;
			}
		}
	}while(choice!=logout); //validating condition and break the loop if condition fails
}

