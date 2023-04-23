//This is the header file for LOGIN MODULE...

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include"login_struct.c"

#define EXIT 0
#define ADMIN 1
#define EMPLOYEE 2
#define CUSTOMER 3

//function to validate the admin account lgoin credentials. This function will accept data in local variable and return the variable from function
int validate_admin_credentials();

//function to validate the employee account login credentials. This function will accept data in local variable and return the variable from function
int validate_employee_credentials();

//function to validate the customer account login credentials. This function will accept data in local variable and return the variable from function
int validate_customer_credentials();


