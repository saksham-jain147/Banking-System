//function to display different categories of accounts

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"login.h"
#include"admin.h"
#include"employee_header_file.h"
//#include"employee.h"

/*function to validate the admin account lgoin credentials
this function will accept data in local variable and return the variable from function*/
int validate_admin_credentials()
{	
	log a; //log is short name of struct login
	FILE *fp;
	char *token;
        char line[100];
        int count=0;
	fp = fopen("text_files/admin_credentials.txt","r"); //opening text file named Admin_credentials in read only access
	char pwd[20]; 
	int un,mark = 0; //un=username pwd=password
	
	printf("\nEnter User name: \n");
	scanf("%d",&un); //accepting username as input
	printf("\nEnter password: \n");
	while(getchar()!='\n');
	fgets(pwd,20,stdin); //accepting password as input

		
	while(fgets(line,sizeof(line),fp)!=NULL)
	{
		token=strtok(line,",");
		if (count==0)
		{
			a.username=atoi((token));
			count++;
			token=strtok(NULL,",");
		}
		if (count==1)
		{
			
			strcpy(a.password,token);
			count++;
			token=strtok(NULL,",");
			
		}
	
		count=0;
		
		if(un==a.username && (strcmp(pwd,a.password)==0)) //checking if accepted user name and password are correct
		{
			mark=1;
			printf("\n################################################################################\n");
			printf("\n\t\t\tYou are Sucessfully Logged In\n");
			printf("\n################################################################################\n");
			get_admin_choice();
			return a.username;
		}
		else if(un==a.username && (strcmp(pwd,a.password)!=0)) //condition if username is correct and password incorrect
		{
			mark=1;
			printf("\n################################################################################\n");
			printf("\n\t\t\tInvalid Password...!!\n");
			printf("\n################################################################################\n");
			return 0;
		}
	}
	if(mark==0) //condition for both username and password are incorrect
	{
		printf("\n################################################################################\n");
		printf("\n\t\t\tAccount does Not Exist...!!\n");
		printf("\n################################################################################\n");
		return 0;
	}
	fclose(fp); //closing the text file
	return 0;
}



/*function to validate the employee account login credentials
this function will accept data in local variable and return the variable from function*/
int validate_employee_credentials()
{
	
	log e; //log is short name for struct login
	FILE *fp;
	char *token;
        char line[150];
        char pwd[15]; //un=username pwd=password
	int un,mark = 0;
	int count=0;
	fp = fopen("text_files/employee_details.txt","r"); //opening text file named Employee_credentials in read only access


	printf("\nEnter User name: \n");
	scanf("%d",&un); //accepting username as input
	printf("\nEnter password: \n");
	while(getchar()!='\n');
	fgets(pwd,15,stdin); //accepting password as input
	
	
	while(fgets(line,sizeof(line),fp)!=NULL)
	{
		count = 0;
		token=strtok(line,",");
		if(count==0)
		{
			//printf("%s\n", token);
			e.username=atoi(token);
			count++;
			token=strtok(NULL,",");
		}

		if(count==1)
		{
			//printf("%s\n", token);
			token=strtok(NULL,",");
			count++;
		}
		if(count==2)
		{
			//printf("%s\n", token);
			token=strtok(NULL,",");
			count++;
		}
		if(count==3)
		{
			//printf("%s\n", token);
			token=strtok(NULL,",");
			count++;
		}
		if(count==4)
		{
			//printf("%s\n", token);
			token=strtok(NULL,",");
			count++;
		}
		if(count==5)
		{
			//printf("%s\n", token);
			token=strtok(NULL,",");
			count++;
		}
		if(count==6)
		{
			//printf("%s\n", token);
			token=strtok(NULL,"-");
			count++;
		}
		if(count==7)
		{
			//printf("%s\n", token);
			token=strtok(NULL,"-");
			count++;
		}
		if(count==8)
		{
			//printf("%s\n", token);
			token=strtok(NULL,",");
			count++;
		}
		if(count==9)
		{
			//printf("%s\n", token);
			token=strtok(NULL,",");
			count++;
		}
		if(count==10)
		{
			//printf("1 %s\n", token);
			token=strtok(NULL,",");
			count++;
		}
		
		if(count==11)
		{
			//printf("2 %s\n", token);
			strcpy(e.password,token);
			token=strtok(NULL,",");
			count++;
		}
		
		if(un==e.username && (strcmp(pwd,e.password)==0))  //checking if accepted user name and password are correct
		{
			mark=1;
			printf("\n################################################################################\n");
			printf("\n\t\t\tYou are Sucessfully Logged In\n");
			printf("\n################################################################################\n");
			get_employee_choice(e.username);
			return e.username;
		}
		else if(un==e.username && (strcmp(pwd,e.password)!=0)) //condition if username is correct and password incorrect
		{
			mark=1;
			printf("\n################################################################################\n");
			printf("\n\t\t\tInvalid Password...!!\n");
			printf("\n################################################################################\n");
			return 0;
		}
		//count=0;
	}
	if(mark==0) //condition for both username and password are incorrect
	{
		printf("\n################################################################################\n");
		printf("\n\t\t\tAccount does Not Exist...!!\n");
		printf("\n################################################################################\n");
		return 0;
	}
	fclose(fp); //closing the text file
	return 0;
}



/*function to validate the customer account login credentials
this function will accept data in local variable and return the variable from function*/
int validate_customer_credentials()
{
	log c; //log is short name for struct login
	FILE *fp;
	char *token;
        char line[100];
        char pwd[20]; //un=username pwd=password
	int un,mark = 0;
	int count=0;
	
	fp = fopen("text_files/customer_account_details.txt","r"); //opening text file named Employee_credentials in read only access

	printf("\nEnter User name: \n");
	scanf("%d",&un); //accepting username as input
	printf("\nEnter password: \n");
	//scanf("%s",pwd);
	while(getchar()!='\n');
	fgets(pwd,20,stdin); //accepting password as input
	pwd[strlen(pwd)-1]='\0';
	//printf("------%d\t%s\n\n",un,pwd);
	while(fgets(line,sizeof(line),fp)!=NULL)
	{
		token=strtok(line,",");
		if (count==0)
		{
			c.username=atoi((token));
			count++;
			token=strtok(NULL,",");
		}
		if (count==1)
		{
			strcpy(c.password,token);
			count++;
			token=strtok(NULL,",");
		}
	
		count=0;
	
				
		if(un==c.username && (strcmp(pwd,c.password)==0))  //checking if accepted user name and password are correct
		{
			mark=1;
			printf("\n################################################################################\n");
			printf("\n\t\t\tYou are Sucessfully Logged In\n");
			printf("\n################################################################################\n");
			get_customer_choice(c.username);
			return c.username;
		}
		else if(un==c.username && (strcmp(pwd,c.password)!=0)) //condition if username is correct and password incorrect
		{
			mark=1;
			printf("\n################################################################################\n");
			printf("\n\t\t\tInvalid Password...!!\n");
			printf("\n################################################################################\n");
			return 0;
		}
	}
	if(mark==0) //condition for both username and password are incorrect
	{
		printf("\n################################################################################\n");
		printf("\n\t\t\tAccount does Not Exist...!!\n");
		printf("\n################################################################################\n");
		return 0;
	}
	fclose(fp); //closing the file
	return 0;
}


