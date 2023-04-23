//file containing all the structures included in the program
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>



//struct to store the attributes of date
typedef struct date
{
	int dd,mm,yyyy; //dd=date; mm=month; yyyy=year
}dt; //short name for strcut date


//struct customer to store the attributes of customer
typedef struct customer
{
	int id; //id = customer ID
	char first_name[15];
	char last_name[15]; //last name
	long aadhaar;
	long phone_number;
	char email[30];
	char gender[10];
	int dd,mm,yyyy; //date for date of birth dd=date; mm=month; yyyy=year
	char address[50];
}cust; //short name for struct customer

//struct linkedlist to store the values of customer
typedef struct linkedlist
{
	int id;
	char first_name[15];
	char last_name[15];
	long aadhaar;
	long phone_number;
	char email[30];
	char gender[10];
	int dd,mm,yyyy;
	char address[50];
	
	
	struct linkedlist *next;
}node;

//struct to store the attributes of account
typedef struct account
{
	int userid; //userid or customer id
	char password[15]; 
	char ifsc[9];
	long account_number;
	int balance;
	int transaction_limit;
}acc; //short name for struct account

//struct Linkedlist to store the details of the account
typedef struct linked_list
{
	int userid;
	char password[15];
	char ifsc[9];
	long account_number;
	int balance;
	int transaction_limit;
	
	struct linked_list *next_a;
}node_a;

//struct to store the attributes of transaction
typedef struct transaction
{
	int customerid;
	long transid; //transaction id
	char type[6]; //transaction type
	int amount;
	int dd,mm,yyyy; //date of transaction dd=date; mm=month; yyyy=year
	char remarks[30]; //reamrks of transaction
	char receiver_name[20];
	long receiver_acc_no; //receiver account number
}trans; //short name for struct transaction

//strcut Linkedlist to store the values fetched from file of transaction
typedef struct Linkedlist
{
	int customerid;
	long transid;
	char type[6];
	int amount;
	int dd,mm,yyyy;
	char remarks[30];
	char receiver_name[20];
	long receiver_acc_no; //receiver account number
	
	struct Linkedlist *next_t;
}node_t;

//struct helpdesk to store department and phonenumber
typedef struct helpdesk
{
	long phone_number;
	char name[30];
}help; //short name for struct helpdesk

//struct linkedlist_h to store department and phonenumber in linked list
typedef struct linkedlist_h
{
	long phone_number;
	char name[30];
	
	struct linkedlist_h *next_h;
}node_h; //short name for struct helpdesk
