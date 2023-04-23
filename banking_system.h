//this file containing all the function declerations
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

//file containing all the structures included in the program
/*#include"admin.h"
#include"employee.h"
#include"customer.h"*/
#include"login.h"

//struct to store the attributes of date

#define EXIT 0
#define ADMIN 1
#define EMPLOYEE 2
#define CUSTOMER 3

//Function to get choice from user...
void get_choice();

//function to display different categories of accounts
void display_main_menu();
