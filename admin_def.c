//This is function definition file for ADMIN MODULE...

#include"admin.h"


//Function definition to create a Node and loads data into newly created node. It returns address of node.
enode* e_createNode(emp e)
{
	//Malloc function to create memory in heap section.
	enode *newNode = (enode *)malloc(sizeof(enode));

	//Load data from employee's Structure to a node
	newNode->id = e.id;
	strcpy(newNode->first_name, e.first_name);
	strcpy(newNode->last_name, e.last_name);
	newNode->aadhaar = e.aadhaar;
	newNode->phone_number = e.phone_number;
	strcpy(newNode->email, e.email);
	strcpy(newNode->gender, e.gender);
	newNode->dd = e.dd;
	newNode->mm = e.mm;
	newNode->yyyy = e.yyyy;
	strcpy(newNode->address, e.address);
	strcpy(newNode->password, e.password);
	//Initialies node's next to NULL
	newNode->next = NULL;
	
	return newNode;
}

//Function definition to add a Node. It returns address of node.
enode* e_addNode(enode *head, enode *newNode)
{
	enode *temp = head;
	
	if(head == NULL)
		head = newNode;
	else
	{	
		while(temp->next != NULL)
			temp = temp->next;
			
		temp->next = newNode;
	}
	
	return head;
}

//Function definition to create File.
void writeFile(FILE *fptr,emp e)
{
	fptr = fopen("text_files/employee_details.txt", "a");
     	fprintf(fptr,"%d,%s,%s,%ld,%ld,%s,%s,%d-%d-%d,%s,%s\n", e.id, e.first_name, e.last_name, e.aadhaar, e.phone_number, e.email, e.gender, e.dd, e.mm, e.yyyy, e.address, e.password);
     	fclose(fptr);
     	
     	return;
}

int get_latest_eid()
{	
	emp e;
	char line[200];
	char *token;
	FILE *fptr=NULL;
	//enode *head=NULL;
	//enode *newnode=NULL;
	int count=0;
	int temp_eid = 0;
	
	fptr = fopen("text_files/employee_details.txt","r"); //opening file
	  //loading information into linked list
	while(fgets(line,sizeof(line),fptr) != NULL) //EOF=-1
	{
		count = 0;
		token=strtok(line,",");
		if(count==0)
		{
			//printf("%s\n", token);
			e.id=atoi(token);
			temp_eid = e.id;
			count++;
			token=strtok(NULL,",");
		}

		if(count==1)
		{
			//printf("%s\n", token);
			strcpy(e.first_name,token);
			token=strtok(NULL,",");
			count++;
		}
		if(count==2)
		{
			//printf("%s\n", token);
			strcpy(e.last_name,token);
			token=strtok(NULL,",");
			count++;
		}
		if(count==3)
		{
			//printf("%s\n", token);
			e.aadhaar = atol(token);
			token=strtok(NULL,",");
			count++;
		}
		if(count==4)
		{
			//printf("%s\n", token);
			e.phone_number=strtol(token,NULL,strlen(token));
			token=strtok(NULL,",");
			count++;
		}
		if(count==5)
		{
			//printf("%s\n", token);
			strcpy(e.email,token);
			token=strtok(NULL,",");
			count++;
		}
		if(count==6)
		{
			//printf("%s\n", token);
			strcpy(e.gender,token);
			token=strtok(NULL,"-");
			count++;
		}
		if(count==7)
		{
			//printf("%s\n", token);
			e.dd=atoi(token);
			token=strtok(NULL,"-");
			count++;
		}
		if(count==8)
		{
			//printf("%s\n", token);
			e.mm=atoi(token);
			token=strtok(NULL,",");
			count++;
		}
		if(count==9)
		{
			//printf("%s\n", token);
			e.yyyy=atoi(token);
			token=strtok(NULL,",");
			count++;
		}
		if(count==10)
		{
			//printf("%s\n", token);
			strcpy(e.address,token);
			token=strtok(NULL,",");
			count++;
		}
		
		if(count==11)
		{
			//printf("%s\n", token);
			strcpy(e.password,token);
			token=strtok(NULL,",");
			count++;
		}
	}
	fclose(fptr);	//closing file
	return temp_eid;
	
}

//Function definition to create File and stores empomer's Personal data information in a file.
FILE* new_emp_creation(FILE *fptr, emp e)
{	
	e.id = get_latest_eid() + 1;
	printf("\nEnter first name:\n");
	scanf("%s", e.first_name);
	
	printf("\nEnter last name:\n");
	scanf("%s", e.last_name);
	
	printf("\nEnter Aadhaar Number:\n");
	scanf("%ld", &e.aadhaar);
	
	printf("\nEnter Phone Number:\n");
	scanf("%ld", &e.phone_number);
	
	printf("\nEnter Email:\n");
	scanf("%s", e.email);
	
	printf("\nEnter gender:\n");
	scanf("%s", e.gender);
	
	printf("\nEnter date of birth (dd-mm-yyyy):\n");
	scanf("%d-%d-%d", &e.dd, &e.mm, &e.yyyy);
	
	while(getchar() != '\n');
	printf("\nEnter Address:\n");
	fgets(e.address, 50,stdin);
	e.address[strlen(e.address) - 1] = '\0';
	
	printf("\nEnter new Password:\n");
	scanf("%s", e.password);
	
	writeFile(fptr, e);
	printf("\n------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
	printf("\tCONGRATULATIONS!! You have been added to our database. Your Employee ID for future reference is %d.\n", e.id);
	printf("\n------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
	return fptr;
}



/*function to display the personal details of the employee
parameters: integer value*/
void get_employee_personal_details(int id)
{	
	FILE *fptr=NULL;
	
	//reading from file
	fptr = fopen("text_files/employee_details.txt","r");	//opening file
	
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
		//Splitting the data
		char* value = strtok(buffer,",");
		
		if ( atoi(value) != id )	//checking for specific person details
			continue;
			
		printf("\n################################################################################\n");
		
		while(value)
		{
			count++;
			if (column == 0) {
				printf("\n\tEmployee ID \t\t: ");
				printf("%s", value);
				value = strtok(NULL, ",");
				column++;
			}
			
			if (column == 1) {
				printf("\n\tFirst Name \t\t: ");
				printf("%s", value);
				value = strtok(NULL, ",");
				column++;
			}
			
			if (column == 2) {
				printf("\n\tLast Name \t\t: ");
				printf("%s", value);
				value = strtok(NULL, ",");
				column++;
			}
			
			if (column == 3) {
				printf("\n\tAadhaar Number \t\t: ");
				printf("%s", value);
				value = strtok(NULL, ",");
				column++;
			}
			
			if (column == 4) {
				printf("\n\tPhone Number \t\t: ");
				printf("%s", value);
				value = strtok(NULL, ",");
				column++;
			}
			
			if (column == 5) {
				printf("\n\tEmail Id \t\t: ");
				printf("%s", value);
				value = strtok(NULL, ",");
				column++;
			}
			
			if (column == 6) {
				printf("\n\tGender \t\t\t: ");
				printf("%s", value);
				value = strtok(NULL, ",");
				column++;
			}
			
			if (column == 7) {
				printf("\n\tDOB (DD-MM-YYYY) \t: ");
				printf("%s", value);
				value = strtok(NULL, ",");
				column++;
			}
			
			if (column == 8) {
				printf("\n\tAddress \t\t: ");
				printf("%s", value);
				value = strtok(NULL, ",");
				column++;
			}
			if (column == 9) {
				value = strtok(NULL, ",");
				column++;
			}
			column = 0;
		}
		printf("\n");
		fclose(fptr);
		break;		       
	}
	
	if(count==0)
	{
		printf("\n--------------------------------------------------\n\n");
		printf("\tERROR : DATA NOT FOUND !!!\n");	
		printf("\n\n--------------------------------------------------\n");
	}
	
	printf("\n################################################################################\n");		
	return;
}

//Function definition to create a linked-list of data stored in file employee_details.txt... 
enode* create_elinkedlist()
{
	enode *head=NULL;
	enode *newNode=NULL;
	enode *temp=NULL;
	FILE *fptr=NULL;
	char buffer[500];
	char *token;
	int count;
	emp e;
	
	//File is opened for reading.
	fptr = fopen("text_files/employee_details.txt", "r");
	
	while( fgets(buffer,500,fptr))
	{
		//int column=0;
		rewind(fptr);	
		//Splitting the data
		while(fgets(buffer,sizeof(buffer),fptr) != NULL) //EOF=-1
		{
			count = 0;
			token=strtok(buffer,",");
			if(count==0)
			{
				e.id=atoi(token);
				count++;
				token=strtok(NULL,",");
			}

			if(count==1)
			{
				//printf("%s\n", token);
				strcpy(e.first_name,token);
				token=strtok(NULL,",");
				count++;
			}
			if(count==2)
			{
				//printf("%s\n", token);
				strcpy(e.last_name,token);
				token=strtok(NULL,",");
				count++;
			}
			if(count==3)
			{
				//printf("%s\n", token);
				e.aadhaar = atol(token);
				token=strtok(NULL,",");
				count++;
			}
			if(count==4)
			{
				//printf("%s\n", token);
				e.phone_number=strtol(token,NULL,strlen(token));
				token=strtok(NULL,",");
				count++;
			}
			if(count==5)
			{
				//printf("%s\n", token);
				strcpy(e.email,token);
				token=strtok(NULL,",");
				count++;
			}
			if(count==6)
			{
				//printf("%s\n", token);
				strcpy(e.gender,token);
				token=strtok(NULL,"-");
				count++;
			}
			if(count==7)
			{
				//printf("%s\n", token);
				e.dd=atoi(token);
				token=strtok(NULL,"-");
				count++;
			}
			if(count==8)
			{
				//printf("%s\n", token);
				e.mm=atoi(token);
				token=strtok(NULL,",");
				count++;
			}
			if(count==9)
			{
				//printf("%s\n", token);
				e.yyyy=atoi(token);
				token=strtok(NULL,",");
				count++;
			}
			if(count==10)
			{
				//printf("%s\n", token);
				strcpy(e.address,token);
				token=strtok(NULL,",");
				count++;
			}
			
			if(count==11)
			{
				//printf("%s\n", token);
				strcpy(e.password,token);
				token=strtok(NULL,",");
				count++;
			}
			
			newNode = e_createNode(e);
			head = e_addNode(head, newNode);
		}
	}
	fclose(fptr);
	free(temp);
	return head;
}	

/*functionto delete personal details
parameters: customer id, head*/
enode* delete_employee_personal_details(int id, enode *head)
{
    enode *temp=head;
    enode *tag;
    int flag = 0;
    
    if(head==NULL)
    {
        printf("\nLIST EMPTY\n");
    }
    else if(head->next==NULL)
    {
        if(temp->id==id)
        {
            //free(temp);
            head = NULL;
            flag++;
        }
    }
    else if(head->id==id)
    {
         head=head->next;
         //free(temp);
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
           //free(temp);
           flag++;
        }
    }
    if(flag == 0)
    {
    	printf("\nERROR: Employee does not exist\n");
    }
    else
    {
    	printf("\n------------------------------------------------------------------------\n");
    	printf("\nData for Employee ID %d has been deleted sucessfully!!!\n", id);
    	printf("\n------------------------------------------------------------------------\n");
    }
    overwriteFile(head);
    free(tag);
    free(temp);
    return head;    
}

//Function definition to open File in WRITE mode... 
void overwriteFile(enode *head)
{
	enode *temp = head;
	FILE *fptr = NULL;
	fptr = fopen("text_files/employee_details.txt", "w");
	while(temp != NULL)
	{
		fprintf(fptr,"%d,%s,%s,%ld,%ld,%s,%s,%d-%d-%d,%s,%s", temp->id, temp->first_name, temp->last_name, temp->aadhaar, temp->phone_number, temp->email, temp->gender, temp->dd, temp->mm, temp->yyyy, temp->address, temp->password);	
		temp = temp->next;
	}
     	fclose(fptr);
     	free(temp);
     	
     	return;
}

void display_admin_menu()
{
	printf("\n*********************Select Your Choice*********************\n\n\t1. Create new Employee\n\t2. View Employee Details\n\t3. Delete Employee Details\n\t0. Logout\n");
	return;
}

//Function definition to get admin choice...
void get_admin_choice()
{
	int choice,id;
	FILE *fptr = NULL;
	enode *head = NULL;
	emp e;
	do
	{
		display_admin_menu();
		printf("\nChoice : ");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1:
					new_emp_creation(fptr, e);
					break;
			
			case 2:
					printf("Enter Employee ID : ");
					scanf("%d", &id);
					get_employee_personal_details(id);
					break;
			
			case 3:
					head = create_elinkedlist();
					printf("Enter Employee ID : ");
					scanf("%d", &id);
					head = delete_employee_personal_details(id, head);
					break;
					
			case 0:
					printf("\n##############################################################################################################\n\n");
					printf("\t\t\tYou have logged out successfully!!!");
					printf("\n\n##############################################################################################################\n");
					return;
					
			default: 
					printf("\n----------------------------------------------\n");
					printf("\n\tInvalid Choice...!!\n");
					printf("\n----------------------------------------------\n");
		}
	}while(choice != 0);
	free(head);
	fclose(fptr);
}

