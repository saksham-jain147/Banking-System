//This is structure file for ADMIN MODULE...

//struct employee to store the attributes of employee
typedef struct employee
{
	int id; //id = employee ID
	char first_name[15];
	char last_name[15]; //last name
	long aadhaar;
	long phone_number;
	char email[30];
	char gender[10];
	int dd,mm,yyyy; //date for date of birth dd=date; mm=month; yyyy=year
	char address[50];
	char password[20];
}emp; //short name for struct employee

typedef struct e_linkedlist
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
	char password[20];
	struct e_linkedlist *next;
}enode;

