//This is header file for ADMIN MODULE...

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"admin_struct.c"





//Function declaration to create a Node and loads data into newly created node. It returns address of node.
enode* e_createNode(emp);

//Function declaration to add a Node. It returns address of node.
enode* e_addNode(enode *, enode *);

//Function declaration to open File in APPEND mode... 
void writeFile(FILE *,emp);

//Function declaration to get latest employee id from file employee_details.txt....
int get_latest_eid();

//Function declaration to create File and stores empomer's Personal data information in a file.
FILE* new_emp_creation(FILE *, emp);

//Function declaration to display the personal details of the employee. Parameters: integer value
void get_employee_personal_details(int);

//Function declaration to create a linked-list of data stored in file employee_details.txt... 
enode* create_elinkedlist();

//Function declaration to display Linked-list data...
//void displayList(enode *);

//Functionto delete personal details. Parameters: customer id, head
enode* delete_employee_personal_details(int, enode *);

//Function declaration to open File in WRITE mode... 
void overwriteFile(enode *);

//Function declaration to get admin choice...
void get_admin_choice();

//Function declaration to display admin menu...
void display_admin_menu();

