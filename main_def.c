//This is main definition file.....

#include"banking_system.h"
//#include"admin.h"
//#include"login.h"

//function to display different categories of accounts
void display_main_menu()
{
	printf("\n*********************Select Your  Account Category*********************\n\n\t1. Admin\n\t2. Employee\n\t3. Customer\n\t0. Exit\n");
}



void get_choice()
{
	int choice, user_name;
	do
	{
		display_main_menu();
		printf("\nChoice : ");
		scanf("%d", &choice);
		
		switch(choice)
		{
			
			case ADMIN:
					user_name = validate_admin_credentials();
					if(user_name == 0)
					{
						printf("\nINVALID CREDENTIALS!!!\n");
						break;
					}
					//get_admin_choice();
					break;
					
			case EMPLOYEE:
					user_name = validate_employee_credentials();
					if(user_name == 0)
					{
						printf("\nINVALID CREDENTIALS!!!\n");
						break;
					}
					break;
					
			case CUSTOMER:
					user_name = validate_customer_credentials();
					if(user_name == 0)
					{
						printf("\nINVALID CREDENTIALS!!!\n");
						break;
					}
					break;
			
			case EXIT:
					printf("\n##############################################################################################################\n\n");
					printf("\t\t\tThank you for using our service");
					printf("\n\n##############################################################################################################\n");
					exit(0);
			
			default: 	printf("INVALID CHOICE\n");
		}
	}while(choice != 0);
}








