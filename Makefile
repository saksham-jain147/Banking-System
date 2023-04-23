all: main

main: main_def.o login_def.o admin_def.o customer_def.o employee_def.o
	gcc main_client.c main_def.c login_def.c admin_def.c customer_def.c employee_def.c -o main
	
main_def.o: main_def.c 
	gcc -c banking_system.h main_def.c

login_def.o: login_def.c 
	gcc -c login.h login_def.c
	
admin_def.o: admin_def.c 
	gcc -c admin.h admin_def.c
	
customer_def.o: customer_def.c
	gcc -c employee_header_file.h customer_def.c

employee_def.o: employee_def.c
	gcc -c employee_header_file.h employee_def.c
