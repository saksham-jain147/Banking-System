//this file containing all the function declerations
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

//file containing all the structures included in the program

#include"customer_struct.c"

//struct to store the attributes of date

#define Exit 0
#define new_account_creation 21
#define accounts 22
#define transaction 23
#define help_desk_update 24
#define display_customer_details 201
#define display_customer_account_details 202
#define display_customer_transactions 203
#define edit_customer_info 204
#define update_customer_info 2041
#define delete_customer_info 2042
#define Update_First_Name 20411
#define Update_Last_Name 20412
#define Update_Email 20413
#define Update_Phone_Number 20414
#define modify_queries 211
#define modify_contact_info 212
#define personal_profile 31
#define account_details 32
#define transaction_history 33
#define current_balance 34
#define fund_transfer 35
#define display_help_desk 36
#define logout 99
#define main_menu 88
#define previous_menu 77
#define back_to_previous_menu 66

//function to display main menu
void display_main_menu();

//function to display employee options
void display_employee_menu();

//function to display options under accounts
void display_accounts_menu();

//function to display options under edit customer info
void display_edit_customer_info_menu();

//function to display customer options
void display_customer_menu();

//function to validate admin credentials
//int validate_admin_credentials();

//function to validate employee credentials
//int validate_employee_credentials();

//function to validate customer credentials
//int validate_customer_credentials();

//function to get the personal details of customer
void get_personal_details(int);

//function to get the account details of customer
void e_get_account_details(long);

//function to get the account details in customer account
int get_account_details_cust(long,int);

//function to get balance
int get_balance(long,int);

//function to get transaction details
void get_transaction_details(int);

//function to get the customer id from the text file customer_profile
int get_latest_id();

//function to get the customer account number from the text file customer_profile
long get_latest_acc();

//function to get a valid first name
char * get_valid_firstname();

//function to get a valid last name
char * get_valid_lastname();

//function to get a valid aadhaar number
long get_valid_aadhaar();

//function to get valid phone number
long get_valid_phone_number();

//function to get valid email
char * get_valid_email();

//function to get valid gender
char * get_valid_gender();

//function to get valid address
char * get_valid_address();

//function to get valid password
char * get_valid_password();

//function to validate date
int Validate_Date(int,int,int);

//function to get valid deposit
int get_valid_deposit();

//function to validate customer id
int validate_customerid();

//function to get transaction id
int get_transaction_id();

//function to validate transaction type
char * get_valid_transaction_type();

//function to validate fund transfer amount
int validate_amount(long);

//function to validate receiver name
char * get_valid_receiver_name();

//function to validate remarks
char * get_valid_remarks();

//function to get valid receiver account number
long get_valid_Account_Number();

//function to update balance in account details file
void update_balance(long,long, char*, int);

//function to make transaction via bank process
int make_transaction();

//function to create new account
int new_account();

//function to make deposit in customer account
int make_deposit(int,char*);

//function to make withdrawl in customer account
int make_withdrawl(int,char*);

//function to update first name
void update_first_name(int customer_id,char * new_first_name);

//function to update last name
void update_last_name(int customer_id,char * new_last_name);

//function to update email
void update_email(int customer_id,char * email);

//function to update phone number
void update_phone_number(int customer_id,long phone_number);

//function to display update list
void display_update_list();

//function to delete personal details
void delete_personal_details(int);

//function to delete account details
void e_delete_account_details(long);

//function to delete transaction history
void delete_transaction_history(int);

node_t* createNode_t(trans);

node_t* addNode_t(node_t*,node_t*);

node* createNode(cust);

node* addNode(node*,node*);

node_a* createNode_a(acc);

node_a* delete_account(long,node_a*);

node* delete_personal(int,node*);

node_a* addNode_a(node_a*,node_a*);
//function to display help desk details

//void employee_getchoice();

void help_desk();

void get_employee_choice(int);

//int validate_customerid();
	
