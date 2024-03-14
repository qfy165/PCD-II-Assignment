#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<ctype.h>
#pragma warning(disable:4996)

int staff();
void member();
void sales();
void stock();

void main()
{
	int choice;

	do
	{
		printf("     |\\       /|\n");
		printf("     | \\     / |\n");
		printf("     |  \\   /  |\n");
		printf("     |   | |   |\n");
		printf("     |   | |   |\n");
		printf("     |   | |   |\n");
		printf("     |   | |   |\n");
		printf("     |  /   \\  |\n");
		printf("     | /     \\ |\n");
		printf("     |/       \\|\n");
		printf("\n");
		printf("Infinite Impact Group\n");
		printf("  Management System\n\n");
		printf("1.Staff Information\n");
		printf("2.Member Information\n");
		printf("3.Sales Information\n");
		printf("4.Stock Information\n");
		printf("5.Exit\n");
		printf("Your choice: ");
		scanf("%d", &choice);

		if (choice == 1)
			staff(); //function call
		else if (choice == 2)
			member();
		else if (choice == 3)
			sales();
		else if (choice == 4)
			stock();
		else if (choice > 5)
			printf("Please enter a number between 1 to 5\n");
	} while (choice != 5);

	system("pause");
	exit(-1);
}

//Staff Information Module - Hon Chu Jun
typedef struct
{
	char staffID[10];
	char staffName[50];
	char password[10];
	char recovery[10];
	char position[20];
	char phoneNumber[10];

	char username[20];
	char userpass[20];

	char code[10];
	char cont;

}Staff;

void staffLogin();
void menu();
void addStaff();
void searchStaff();
void modifyStaff();
void displayStaff();
void deleteStaff();

int staff()
{
	int choice;

	printf("\n1. Login as Admin\n");
	printf("2. Exit\n");
	printf("\nPlease choose 1 or 2: ");
	scanf("%d", &choice);

	if (choice == 1) {
		printf("\n");
		staffLogin();
		menu();

	}
	else if (choice == 2) {
		printf("\n");
		printf("Thank You For Your Visit\n");
		/*main();*/
	}
	else {
		printf("\n");
		printf("You are allow to choose 1 or 2 only\n");
		printf("Please Enter Again\n");
		printf("\n");
		staff();
	}
}

void menu()
{
	Staff stf;
	int choice;
	do {
		printf("\n=====Menu=====\n");
		printf("1. Add Staff\n");
		printf("2. Search Staff\n");
		printf("3. Modify Staff\n");
		printf("4. Display Staff\n");
		printf("5. Delete staff\n");
		printf("6. Exit\n");
		printf("\nYou have these choices. Please choose it :");
		scanf("%d", &choice);

		if (choice == 1)
			addStaff();

		else if (choice == 2)
			searchStaff();

		else if (choice == 3)
			modifyStaff();

		else if (choice == 4)
			displayStaff();

		else if (choice == 5)
			deleteStaff();

		else if (choice == 6) {
			printf("\nYou have exited the module\n");
			break;
		}
		else {
			printf("\nPlease choose 1 - 6\n");
		}
	} while (choice != 6);
}

void staffLogin()
{
	Staff staff;
	FILE* ptr;
	ptr = fopen("staff.dat", "ab");
	if (ptr == NULL)
	{
		printf("File cannot be open\n ");
		exit(-1);
	}
	printf("Hi , please log in account\n");
	printf("Username : ");
	scanf("%s", &staff.username);
	rewind(stdin);

	printf("Password : ");
	scanf("%s", &staff.userpass);


	if (strcmp(staff.username, "abc") != 0)
	{
		printf("\nWrong username or password, please try again\n\n");


		fwrite(&staff, sizeof(staff), 1, ptr);
		rewind(stdin);

	}

	if (strcmp(staff.userpass, "123") != 0)
	{
		printf("\nWrong username or password, please try again\n");

		fwrite(&staff, sizeof(staff), 1, ptr);
		rewind(stdin);

	}
	fclose(ptr);
}

void addStaff()
{
	Staff staff;
	FILE* ptr;

	ptr = fopen("staff.dat", "ab");

	if (ptr == NULL)
	{
		printf("File cannot be open\n ");
		exit(-1);
	}


	printf("\nEnter staff ID , XXX to stop: ");
	scanf("%10s", &staff.staffID);


	while (strcmp(staff.staffID, "XXX") != 0)
	{
		printf("Enter staff name: ");
		scanf("%s", &staff.staffName);
		rewind(stdin);

		printf("Enter password: ");
		scanf("%s", &staff.password);
		rewind(stdin);

		printf("Enter password recovery: ");
		scanf("%s", &staff.recovery);
		rewind(stdin);

		printf("Enter position: ");
		scanf("%s", &staff.position);
		rewind(stdin);

		printf("Enter staff's phone number: ");
		scanf("%s", &staff.phoneNumber);

		fwrite(&staff, sizeof(Staff), 1, ptr);

		rewind(stdin);
		printf("\nEnter staff ID , XXX to stop: ");
		scanf("%s", &staff.staffID);
	}


	fclose(ptr);

}

void searchStaff()
{
	Staff staff;
	FILE* fp;
	char staffID[10];
	int found = 0;

	fp = fopen("staff.dat", "rb");

	if (fp == NULL) {
		printf("File cannot be opened\n");
		exit(-1);
	}

	printf("\nType 'stop' to end search");
	printf("\nEnter staff ID to be searched: ");
	scanf("%s", &staffID);

	fread(&staff, sizeof(Staff), 1, fp);

	while (strcmp(staffID, "stop") != 0)
	{
		while (!feof(fp)) {
			if (strcmp(staffID, staff.staffID) == 0) {
				printf("\nStaff have found!\n\n");
				printf("Staff ID\tName\t\tPassword\tPassword Recovery\tPosition\tPhone number\n");
				printf("=====================================================================================================\n");
				printf("%-16s%-16s%-16s%-24s%-16s%-16s\n", staff.staffID, staff.staffName, staff.password, staff.recovery, staff.position, staff.phoneNumber);
				found = 1;
				break;
			}
			fread(&staff, sizeof(Staff), 1, fp);
		}

		if (!found) {
			printf("\nRecord not found!\n");
		}

		rewind(fp);
		printf("\nType 'stop' to end search");
		printf("\nEnter staff ID to be searched: ");
		scanf("%s", &staffID);

		fread(&staff, sizeof(Staff), 1, fp);
	}

}

void modifyStaff() {

	Staff staff[20];
	FILE* ptr;


	ptr = fopen("staff.dat", "rb");
	char cont;
	int count = 0;
	char staffID[10];
	if (ptr == NULL)
	{
		printf("File cannot be open\n ");
		exit(-1);
	}

	while (fread(&staff[count], sizeof(Staff), 1, ptr)) {
		count++;
	}
	fclose(ptr);

	int found = 0;

	do {
		printf("Enter staff ID to modified: ");
		rewind(stdin);
		scanf("%s", &staffID);


		for (int i = 0; i < count; i++)
		{
			if (strcmp(staff[i].staffID, staffID) == 0)
			{
				found++;
				printf("Staff name: ");
				scanf("%s", &staff[i].staffName);
				rewind(stdin);

				printf("Enter password: ");
				scanf("%s", &staff[i].password);
				rewind(stdin);

				printf("Enter password recovery: ");
				scanf("%s", &staff[i].recovery);
				rewind(stdin);

				printf("Position: ");
				scanf("%s", &staff[i].position);
				rewind(stdin);

				printf("Enter staff's phone number: ");
				scanf("%s", &staff[i].phoneNumber);
			}
		}
		if (!found)
		{
			printf("\nNot Found\n");
		}

		else
		{
			printf("\nUpdated\n");
			ptr = fopen("staff.dat", "wb");
			for (int i = 0; i < count; i++)
			{
				fwrite(&staff[i], sizeof(Staff), 1, ptr);
			}
			fclose(ptr);
		}
		printf("\nContinue edit? (y/n): ");
		rewind(stdin);
		scanf("%c", &cont);
	} while (toupper(cont) == 'y');

}

void displayStaff()
{

	Staff staff;
	int numRec = 0;
	FILE* ptr;
	ptr = fopen("staff.dat", "rb");

	if (ptr == NULL)
	{
		printf("File cannot be open\n ");
		exit(-1);
	}

	printf("========Staff Records========\n");
	printf("Staff ID\tName\t\tPassword\tPassword Recovery\tPosition\tPhone number\n");
	printf("=====================================================================================================\n");

	while (fread(&staff, sizeof(staff), 1, ptr))
	{
		printf("%-16s%-16s%-16s%-24s%-16s%-16s\n", staff.staffID, staff.staffName, staff.password, staff.recovery, staff.position, staff.phoneNumber);
		numRec++;
	}
	printf("-----------------------------------------------------------------------------------------------------\n");
	printf("%d records listed\n\n", numRec);
	menu();
	fclose(ptr);
}

void deleteStaff()
{
	Staff staff;
	FILE* fp, * fp1;
	char id[10];
	int found = 0;
	fp = fopen("staff.dat", "rb");
	fp1 = fopen("temp.dat", "wb");
	printf("Enter staff ID to delete: ");
	scanf("%s", &id);
	while (fread(&staff, sizeof(Staff), 1, fp))
	{
		if (strcmp(staff.staffID, id) == 0) {
			found = 1;
		}
		else
			fwrite(&staff, sizeof(Staff), 1, fp1);
	}
	fclose(fp);
	fclose(fp1);
	if (found) {
		fp1 = fopen("temp.dat", "rb");
		fp = fopen("staff.dat", "wb");
		printf("\nRecord has be delete\n");
		while (fread(&staff, sizeof(Staff), 1, fp1)) {
			fwrite(&staff, sizeof(Staff), 1, fp);
		}

		fclose(fp);
		fclose(fp1);
	}
	else {
		printf("\nRecord not found\n");
		menu();
	}
}

//Member Information Module - Soon Zi Jie
typedef struct {

	char memberID[15];
	char memberName[50];
	char password[10];
	char gender[10];
	char IC[20];
	char phoneNumber[10];

	char username[20];
	char userpass[20];

}Member;

void memberMenu(void);
void memberLogin(void);
void addMember(void);
void searchMember(void);
void modifyMember(void);
void displayMember(void);
void deleteMember(void);

void member()
{
	memberLogin();
}

void memberMenu()
{
	int choice;

	do {
		printf("\n======Menu======\n");
		printf("1. Add Member\n");
		printf("2. Search Member\n");
		printf("3. Modify Member\n");
		printf("4. Display Member\n");
		printf("5. Delete Member\n");
		printf("6. Exit\n");
		printf("\nYou have these choices. What is your choice? \n");
		scanf("%d", &choice);

		if (choice == 1)
			addMember();
		else if (choice == 2)
			searchMember();
		else if (choice == 3)
			modifyMember();
		else if (choice == 4)
			displayMember();
		else if (choice == 5)
			deleteMember();
		else if (choice == 6)
			break;
		else
			printf("\nPlease choose 1 - 6\n");
	} while (choice != 6);

	system("pause");
}

void memberLogin(void)
{
	Member member;

	printf("\nHi , please log in member account\n");
	printf("Member Username : ");
	scanf("%s", &member.username);

	printf("Member Password : ");
	scanf("%s", &member.userpass);

	if (strcmp(member.username, "abc123") != 1, strcmp(member.userpass, "123abc") != 1)
	{
		memberMenu();
	}
	else
	{
		printf("\nWrong username or password, please try again\n");

		rewind(stdin);

		void member();
	}

}

void addMember(void)
{
	Member member;
	FILE* filemember;

	filemember = fopen("member2.txt", "a");

	if (filemember == NULL)
	{
		printf("File cannot be open\n ");
		exit(-1);
	}


	printf("\nEnter member ID , XXX to stop: ");
	scanf("%s", &member.memberID);


	while (strcmp(member.memberID, "XXX") != 0)
	{
		printf("Enter member name: ");
		rewind(stdin);
		scanf("%[^\n]", &member.memberName);


		printf("Enter password: ");
		rewind(stdin);
		scanf("%[^\n]", &member.password);


		printf("Enter Gender: ");
		rewind(stdin);
		scanf("%[^\n]", &member.gender);


		printf("Enter IC: ");
		rewind(stdin);
		scanf("%[^\n]", &member.IC);


		printf("Enter member's phone number: ");
		rewind(stdin);
		scanf("%[^\n]", &member.phoneNumber);


		fprintf(filemember, "%s|%s|%s|%s|%s|%s \n", member.memberID, member.memberName, member.password, member.gender, member.IC, member.phoneNumber);

		rewind(stdin);
		printf("\nEnter memberID , XXX to stop: ");
		scanf("%s", &member.memberID);
	}


	fclose(filemember);

}

void searchMember(void) {
	Member member;
	int found = 0;
	FILE* filemember;
	char memberID[10];
	char option;


	filemember = fopen("member2.txt", "r");

	if (filemember == NULL) {
		printf("File cannot be opened\n");
		exit(-1);
	}

	do {
		printf("\nType 'stop' to end search");
		printf("\nEnter member ID to be searched: ");
		rewind(stdin);
		scanf("%s", &memberID);


		while (fscanf(filemember, "%[^\|]| %[^\|]| %[^\|]| %[^\|]| %[^\|]| %s\n",
			&member.memberID, &member
			.memberName, &member.password, &member.gender, &member.IC, &member.phoneNumber) != EOF) {
			if (strcmp(memberID, member.memberID) == 0)
			{
				found = 1;
				printf("Member ID           : %s \n", member.memberID);
				printf("Member Name         : %s \n", &member.memberName);
				printf("Password            : %s \n", &member.password);
				printf("Gender              : %s \n", &member.gender);
				printf("IC                  : %s \n", &member.IC);
				printf("Phone number        : %s \n", &member.phoneNumber);
			}

		}
		if (!found) {
			printf("Record not found!\n");
		}

		printf("Do you want to search another record ( y / n ) : ");
		rewind(stdin);
		scanf("%c", &option);


	} while (toupper(option) == 'Y');

	fclose(filemember);
}

void modifyMember(void) {
	Member member[20];
	int nmember;
	char modifyID[20];
	char option;
	int i = 0, found = 0;
	FILE* filemember;
	filemember = fopen("member2.txt", "r");

	if (filemember == NULL)
	{
		printf("File Open Error...... \n\n");
		exit(-1);
	}

	while (fscanf(filemember, "%[^\|]| %[^\|]| %[^\|]| %[^\|]| %[^\|]| %s\n",
		&member[i].memberID, &member[i].memberName, &member[i].password, &member[i].gender, &member[i].IC, &member[i].phoneNumber) != EOF)
	{
		i++;
	}
	nmember = i;
	fclose(filemember);

	do
	{
		printf("\nEnter Member ID to modify : ");
		rewind(stdin);
		scanf("%s", modifyID);
		for (i = 0; i < nmember; i++)
		{
			if (strcmp(modifyID, member[i].memberID) == 0)
			{
				found = 1;


				printf("Enter New Member ID: ");
				rewind(stdin);
				scanf("%[^\n]", &member[i].memberID);


				printf("Enter New Member name: ");
				rewind(stdin);
				scanf("%[^\n]", &member[i].memberName);


				printf("Enter New password: ");
				rewind(stdin);
				scanf("%[^\n]", &member[i].password);


				printf("Enter New Gender: ");
				rewind(stdin);
				scanf("%[^\n]", &member[i].gender);


				printf("New IC: ");
				rewind(stdin);
				scanf("%[^\n]", &member[i].IC);


				printf("Enter New member's phone number: ");
				rewind(stdin);
				scanf("%[^\n]", &member[i].phoneNumber);



			}

		}

		if (!found)
		{
			printf("No record was found with the code entered: %s \n", modifyID);
		}

		printf("Any more to modify (Y/N) : ");
		rewind(stdin);
		scanf("%c", &option);

	} while (toupper(option) == 'Y');

	filemember = fopen("member2.txt", "w");
	for (i = 0; i < nmember; i++)
	{
		fprintf(filemember, "%s|%s|%s|%s|%s|%s\n",
			&member[i].memberID, &member[i].memberName, &member[i].password, &member[i].gender, &member[i].IC, &member[i].phoneNumber);
	}
	printf("Data updated successfully......\n");
	fclose(filemember);
}

void displayMember(void) {

	Member member;
	int numRec = 0;
	FILE* filemember;
	filemember = fopen("member2.txt", "r");

	if (filemember == NULL)
	{
		printf("File cannot be open\n ");
		exit(-1);
	}

	printf("============================================Member Records===========================================\n");
	printf("Member ID\tMember Name\tPassword\tGender\t\tIC\t\t\tPhone number\n");
	printf("=====================================================================================================\n");


	while (fscanf(filemember, "%[^\|]|", &member.memberID) != EOF)
	{
		fscanf(filemember, "%[^\|]|", &member.memberName);
		fscanf(filemember, "%[^\|]|", &member.password);
		fscanf(filemember, "%[^\|]|", &member.gender);
		fscanf(filemember, "%[^\|]|", &member.IC);
		fscanf(filemember, "%s\n", &member.phoneNumber);
		printf("%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n", member.memberID, member.memberName, member.password, member.gender, member.IC, member.phoneNumber);
		numRec++;
	}
	printf("-----------------------------------------------------------------------------------------------------\n");
	printf("%d records listed\n\n", numRec);

	fclose(filemember);
}

void deleteMember() {
	Member member;
	FILE* filemember, * filemember2;
	char id[10];
	int found = 0;
	filemember = fopen("member2.txt", "r");
	filemember2 = fopen("temp2.txt", "w");


	printf("Enter member ID to delete: ");
	scanf("%s", &id);
	while (fscanf(filemember, "%[^\|]| %[^\|]| %[^\|]| %[^\|]| %[^\|]| %s\n", &member.memberID, &member.memberName, &member.password, &member.gender, &member.IC, &member.phoneNumber) != EOF)
	{
		if (strcmp(member.memberID, id) != 0) {
			found = 1;
			fprintf(filemember2, "%s|%s|%s|%s|%s|%s\n", &member.memberID, &member.memberName, &member.password, &member.gender, &member.IC, &member.phoneNumber);
		}

	}

	fclose(filemember);
	fclose(filemember2);
	remove("member2.txt");
	rename("member2.txt", "temp2.txt");

	if (found == 1) {
		filemember2 = fopen("temp2.txt", "r");
		filemember = fopen("member2.txt", "w");
		printf("\nRecord has be delete\n");
		while (fscanf(filemember2, "%[^\|]| %[^\|]| %[^\|]| %[^\|]| %[^\|]| %s\n", &member.memberID, &member.memberName, &member.password, &member.gender, &member.IC, &member.phoneNumber) != EOF) {
			fprintf(filemember, "%s|%s|%s|%s|%s|%s\n", &member.memberID, &member.memberName, &member.password, &member.gender, &member.IC, &member.phoneNumber);
		}

		fclose(filemember);
		fclose(filemember2);
		remove("member2.txt");
		rename("temp2.txt", "member2.txt");

	}
	else
		printf("\nRecord not found\n");


}

//Sales Information Module - Yue Qi Fuh
typedef struct {
	char new_memberID[11];
	char new_itemCode[10];
	int new_quantity;
	double new_price;
}NewSalesOrder;

typedef struct {
	char salesOrderID[11];
	char memberID[11];
	char itemCode[10];
	int quantity;
	double price;
	int found;
	double comm;
	NewSalesOrder newSO;
}SalesOrder;

//function declaration
void addSalesOrder(void);
void searchSalesOrder(void);
void modifySalesOrder(void);
void displaySalesOrder(void);
void salesOrderReport(void);
void calculateCommission(FILE* fp, char searchID[], SalesOrder* so);

//function definition
void sales()
{
	int choice;

	do
	{
		printf("\n----------------------");
		printf("\n|> Sales Order Menu <|\n");
		printf("----------------------\n");
		printf("1.Add Sales Order\n");
		printf("2.Search Sales Order\n");
		printf("3.Modify Sales Order\n");
		printf("4.Display Sales Order\n");
		printf("5.Display Sales Summary\n");
		printf("6.Calculate Sales Commission\n");
		printf("7.Exit\n");
		printf("Your choice: ");
		scanf("%d", &choice);

		if (choice == 1)
			addSalesOrder(); //function call
		else if (choice == 2)
			searchSalesOrder();
		else if (choice == 3)
			modifySalesOrder();
		else if (choice == 4)
			displaySalesOrder();
		else if (choice == 5)
			salesOrderReport();
		else if (choice == 6) {
			SalesOrder so;

			FILE* fp;
			char searchID[11];

			//open the binary file in read mode
			fp = fopen("salesorder.dat", "rb");

			if (fp == NULL) {
				printf("File cannot be opened\n");
				exit(-1);
			}

			while (strcmp(searchID, "stop") != 0)
			{
				// get the id of the sales order to search for
				printf("\nType 'stop' to end search");
				printf("\nEnter sales order id to be searched: ");
				scanf("%s", searchID);

				//perform the search
				calculateCommission(fp, searchID, &so);

				//reset the search flag
				so.found = 0;

				rewind(fp);
			}

			// close the file
			fclose(fp);
		}
		else if (choice > 7)
			printf("Please enter a number between 1 to 7\n");

	} while (choice != 7);
}

void addSalesOrder(void)
{
	SalesOrder so; //structure variable
	//declare file variable
	FILE* fp;

	//open file
	fp = fopen("salesorder.dat", "ab");

	//check file opening errors
	if (fp == NULL)
	{
		printf("File cannot be opened\n");
		exit(-1);
	}

	//working with file
	printf("\nInsert new sales order, type 'stop' to return");
	printf("\nEnter sales order ID: ");
	scanf("%s", so.salesOrderID); //step 1
	while (strcmp(so.salesOrderID, "stop") != 0) //step 2
	{
		//step 3
		printf("\nEnter item code: ");
		scanf("%s", &so.itemCode);

		rewind(stdin);
		printf("Enter order quantity: ");
		scanf("%d", &so.quantity);

		rewind(stdin);
		printf("Enter total price of sales order: ");
		scanf("%lf", &so.price);

		rewind(stdin);
		printf("Enter member ID of seller: ");
		scanf("%s", &so.memberID);

		//write to file
		fwrite(&so, sizeof(SalesOrder), 1, fp);

		printf("\nSales order data inserted successfully!\n");

		rewind(stdin);
		printf("\nInsert new sales order, type 'stop' to return");
		printf("\nEnter sales order ID: ");
		scanf("%s", so.salesOrderID); //step 4
	}

	//close file
	fclose(fp);
}

void searchSalesOrder(void)
{
	SalesOrder so;

	FILE* fp;
	so.found = 0;
	char searchID[11];

	//open the binary file in read mode
	fp = fopen("salesorder.dat", "rb");

	if (fp == NULL) {
		printf("File cannot be opened\n");
		exit(-1);
	}

	//get the id of the employee to search for
	printf("\nType 'stop' to end search");
	printf("\nEnter sales order id to be searched: ");
	scanf("%s", &searchID);

	//read the first record of the file
	fread(&so, sizeof(SalesOrder), 1, fp);

	while (strcmp(searchID, "stop") != 0)
	{
		//search for the record
		while (!feof(fp)) {
			if (strcmp(searchID, so.salesOrderID) == 0) {
				printf("\nSales Order found!\n\n");

				printf("Sales Order ID\t\tItem Code\t\tQuantity\t\tTotal Price\t\tMember ID\n");
				printf("==============\t\t=========\t\t========\t\t===========\t\t=========\n");
				//print records
				printf("%s\t\t%s\t\t\t%d\t\t\tRM %0.2f\t\t%s\n",
					so.salesOrderID, so.itemCode, so.quantity, so.price, so.memberID);

				so.found = 1;
				break;
			}
			fread(&so, sizeof(SalesOrder), 1, fp);
		}

		//if the record is not found
		if (!so.found) {
			printf("Record not found!\n");
		}

		rewind(fp);
		printf("\nType 'stop' to end search");
		printf("\nEnter sales order id to be searched: ");
		scanf("%s", &searchID);

		fread(&so, sizeof(SalesOrder), 1, fp);
	}
}

void modifySalesOrder(void)
{
	SalesOrder so;

	FILE* fp;

	long int size = sizeof(SalesOrder);
	so.found = 0;
	char searchID[11];

	//open the binary file in read and write mode
	fp = fopen("salesorder.dat", "rb+");

	if (fp == NULL) {
		printf("File cannot be opened\n");
		exit(-1);
	}

	while (strcmp(searchID, "stop") != 0)
	{
		//get the id of the employee to search for
		printf("\nType 'stop' to end search");
		printf("\nEnter sales order id to be modified: ");
		scanf("%s", &searchID);

		if (strcmp(searchID, "stop") == 0) {
			break;
		}

		//search for the record
		while (fread(&so, size, 1, fp) == 1) {
			if (strcmp(searchID, so.salesOrderID) == 0) {

				printf("\nSales Order found!\n\n");

				printf("Sales Order ID\t\tItem Code\t\tQuantity\t\tTotal Price\t\tMember ID\n");
				printf("==============\t\t=========\t\t========\t\t===========\t\t=========\n");
				//print records
				printf("%s\t\t%s\t\t\t%d\t\t\tRM %0.2f\t\t%s\n",
					so.salesOrderID, so.itemCode, so.quantity, so.price, so.memberID);

				so.found = 1;

				//prompt user to enter the new data
				printf("\nEnter new item code: ");
				scanf("%s", &so.newSO.new_itemCode);

				printf("\nEnter new order quantity: ");
				scanf("%d", &so.newSO.new_quantity);

				printf("\nEnter new price: ");
				scanf("%lf", &so.newSO.new_price);

				printf("\nEnter new member ID: ");
				scanf("%s", &so.newSO.new_memberID);

				//update the record with the new input data in binary file
				strcpy(so.itemCode, so.newSO.new_itemCode);
				so.quantity = so.newSO.new_quantity;
				so.price = so.newSO.new_price;
				strcpy(so.memberID, so.newSO.new_memberID);

				//move the file position indicator back to the beginning of the record
				fseek(fp, -((long)sizeof(SalesOrder)), SEEK_CUR);

				//write the modified record to the file
				fwrite(&so, sizeof(SalesOrder), 1, fp);

				printf("\nSales order updated successfully!\n");
				break;
			}
		}

		//if the record is not found
		if (!so.found) {
			printf("Record not found!\n");
		}

		//reset the found flag
		so.found = 0;

		//move the file position indicator back to the beginning of the file
		rewind(fp);
	}

	fclose(fp);
}

void displaySalesOrder(void)
{
	SalesOrder so; //structure variable

	//declare file variable
	FILE* fp;
	int counter = 0;

	SYSTEMTIME t;
	GetLocalTime(&t);

	//open file
	fp = fopen("salesorder.dat", "rb");

	//check file opening errors
	if (fp == NULL)
	{
		printf("File cannot be opened\n");
		exit(-1);
	}

	//print heading
	printf("\nAll Sales Order - as of %d/%d/%d  \n\n", t.wDay, t.wMonth, t.wYear);
	printf("Sales Order ID\t\tItem Code\t\tQuantity\t\tTotal Price\t\tMember ID\n");
	printf("==============\t\t=========\t\t========\t\t===========\t\t=========\n");

	while (fread(&so, sizeof(SalesOrder), 1, fp))
	{
		//print records
		printf("%s\t\t%s\t\t\t%d\t\t\tRM %0.2f\t\t%s\n",
			so.salesOrderID, so.itemCode, so.quantity, so.price, so.memberID);
		counter++;
	}
	printf("<%d sales orders listed>\n", counter);

	fclose(fp);

	system("pause");
}

void salesOrderReport(void)
{
	SalesOrder so; //structure variable

	//declare file variable
	FILE* fp;
	int counter = 0;
	int total_quantity = 0;
	double total_sales = 0;
	double total_commission = 0;
	double maxPrice = 0;
	char maxSalesOrderID[11];

	//open file
	fp = fopen("salesorder.dat", "rb");

	//check file opening errors
	if (fp == NULL)
	{
		printf("File cannot be opened\n");
		exit(-1);
	}

	while (fread(&so, sizeof(SalesOrder), 1, fp) == 1)
	{
		total_sales += so.price;
		total_quantity += so.quantity;
		total_commission += (so.price * 0.05);
		if (so.price > maxPrice) {
			maxPrice = so.price;
			strcpy(maxSalesOrderID, so.salesOrderID);
		}
		counter++;
	}

	printf("\n Sales Summary");
	printf("\n---------------\n\n");
	printf("Number of Sales Orders made\t%d\n\n", counter);
	printf("Total Sales Amount\tRM% 0.2f\n\n", total_sales);
	printf("Total Quantity Sold\t%d\n\n", total_quantity);
	printf("Total Amount of Commission earned\tRM%0.2f\n\n", total_commission);
	printf("Member with highest amount of sales is %s.\n", maxSalesOrderID);
	printf("Highest sales amount: RM %0.2f\n\n", maxPrice);

	fclose(fp);

	system("pause");
}

void calculateCommission(FILE* fp, char searchID[], SalesOrder* so)
{
	//read the first record of the file
	fread(so, sizeof(SalesOrder), 1, fp);

	//search for the record
	while (!feof(fp)) {
		if (strcmp(searchID, so->salesOrderID) == 0) {
			printf("\nSales Order ID: %s\n", so->salesOrderID);
			printf("Price: RM %0.2f\n", so->price);
			so->comm = so->price * 0.05;
			printf("Member %s's upline will receive RM %0.2f of commission.\n", so->memberID, so->comm);
			so->found = 1;
			break;
		}
		fread(so, sizeof(SalesOrder), 1, fp);
	}

	//if the record is not found
	if (!so->found) {
		printf("Record not found!\n");
	}
}

//Stock Information Module - Tan Kuan Qi
void search();
void add();
void modify();
void display();
void check();
void delete();

typedef struct {
	int add, price, stock, level, quantity;
	char name[20];
}tupper;

void stock() {
	int menu;

	do {
		printf("\nStock Information Menu\n");
		printf("1. [Add Stock]     : \n");
		printf("2. [Search Stock]  : \n");
		printf("3. [Modify Stock]  :\n");
		printf("4. [Display Stock] :\n");
		printf("5. [Check Stock]   :\n");
		printf("6. [Delete Stock]  :\n");
		printf("7. [Exit]\n");
		printf("Choose a number : ");
		scanf("%d", &menu);
		if (menu == 1)
			add();
		else if (menu == 2)
			search();
		else if (menu == 3)
			modify();
		else if (menu == 4)
			display();
		else if (menu == 5)
			check();
		else if (menu == 6) 
			delete();
	} while (menu != 7);
}

void add() {
	tupper title;
	FILE* fptr;
	fptr = fopen("text.txt", "w");
	if (!fptr) {
		printf("Open File Error....");
		exit(0);
	}
	printf("Item ID: ");
	if (scanf("%d", &title.add) != 1) {
		printf("Invalid input. Item code must be a number.\n");
		fclose(fptr);
		return;
	}
	printf("Item description: ");
	if (scanf("%99s", title.name) != 1) {
		printf("Invalid input. Item description must be a string.\n");
		fclose(fptr);
		return;
	}
	printf("item price: ");
	if (scanf("%d", &title.price) != 1) {
		printf("Invalid input. Item price must be a number.\n");
		fclose(fptr);
		return;
	}
	printf("Quantity in stock: ");
	if (scanf("%d", &title.stock) != 1) {
		printf("Invalid input. Quantity in stock must be a number.\n");
		fclose(fptr);
		return;
	}
	printf("Minimum level: ");
	if (scanf("%d", &title.level) != 1) {
		printf("Invalid input. Minimum level must be a number.\n");
		fclose(fptr);
		return;
	}
	printf("Reorder quantity: ");
	if (scanf("%d", &title.quantity) != 1) {
		printf("Invalid input. Reorder quantity must be a number.\n");
		fclose(fptr);
		return;
	}
	fprintf(fptr, "%d %s %d %d %d %d\n", title.add, title.name, title.price, title.stock, title.level, title.quantity);
	printf("Item added successfully!\n");
	fclose(fptr);
}

void search() {
	int searchCode;
	tupper title;
	FILE* fptr;
	fptr = fopen("text.txt", "r");
	if (!fptr) {
		printf("Open File Error....");
		exit(0);
	}
	printf("Enter item code to search: ");
	if (scanf("%d", &searchCode) != 1) {
		printf("Invalid input. Item code must be a number.\n");
		fclose(fptr);
		return;
	}
	int found = 0;
	while (fscanf(fptr, "%d %s %d %d %d %d", &title.add, title.name, &title.price, &title.stock, &title.level, &title.quantity) == 6) {
		if (title.add == searchCode) {
			printf("Item Code: %d\n", title.add);
			printf("Item Description: %s\n", title.name);
			printf("Item Price: %d\n", title.price);
			printf("Quantity in Stock: %d\n", title.stock);
			printf("Minimum Level: %d\n", title.level);
			printf("Reorder Quantity: %d\n", title.quantity);
			found = 1;
			break;
		}
	}
	if (!found) {
		printf("Item with code %d not found.\n", searchCode);
	}
	fclose(fptr);
}

void modify() {
	int modifyCode;
	tupper title;
	FILE* fptr;
	FILE* fptr2;
	fptr = fopen("text.txt", "r");
	fptr2 = fopen("temp.txt", "w");
	if (!fptr || !fptr2) {
		printf("Open File Error....");
		exit(0);
	}
	printf("Enter item code to modify: ");
	if (scanf("%d", &modifyCode) != 1) {
		printf("Invalid input. Item code must be a number.\n");
		fclose(fptr);
		fclose(fptr2);
		return;
	}
	int found = 0;
	while (fscanf(fptr, "%d %s %d %d %d %d", &title.add, title.name, &title.price, &title.stock, &title.level, &title.quantity) == 6) {
		if (title.add == modifyCode) {
			printf("Enter new item code: ");
			if (scanf("%d", &title.add) != 1) {
				printf("Invalid input. Item code must be a number.\n");
				fclose(fptr);
				fclose(fptr2);
				return;
			}
			printf("Enter new item description: ");
			if (scanf("%99s", title.name) != 1) {
				printf("Invalid input. Item description must be a string.\n");
				fclose(fptr);
				fclose(fptr2);
				return;
			}
			printf("Enter new item price: ");
			if (scanf("%d", &title.price) != 1) {
				printf("Invalid input. Item price must be a number.\n");
				fclose(fptr);
				fclose(fptr2);
				return;
			}
			printf("Enter new quantity in stock: ");
			if (scanf("%d", &title.stock) != 1) {
				printf("Invalid input. Quantity in stock must be a number.\n");
				fclose(fptr);
				fclose(fptr2);
				return;
			}
			printf("Enter new minimum level: ");
			if (scanf("%d", &title.level) != 1) {
				printf("Invalid input . Minimum level must be a number.\n");
				fclose(fptr);
				fclose(fptr2);
				return;
			}
			printf("Enter new reorder quantity: ");
			if (scanf("%d", &title.quantity) != 1) {
				printf("Invalid input. Reorder quantity must be a number.\n");
				fclose(fptr);
				fclose(fptr2);
				return;
			}
			fptr = fopen("text.txt", "w");
			fprintf(fptr2, "%d %s %d %d %d %d\n", title.add, title.name, title.price, title.stock, title.level, title.quantity);
			printf("Item modified successfully!\n");
			found = 1;
		}
		else {
			fprintf(fptr2, "%d %s %d %d %d %d\n", title.add, title.name, title.price, title.stock, title.level, title.quantity);
		}
	}
	if (!found) {
		printf("Item with code %d not found.\n", modifyCode);
	}
	fclose(fptr);
	fclose(fptr2);
}

void delete() {
	int deleteCode;
	tupper title;
	FILE* fptr;
	FILE* fptr2;
	fptr = fopen("text.txt", "r");
	fptr2 = fopen("temp.txt", "w");
	if (!fptr || !fptr2) {
		printf("Open File Error....");
		exit(0);
	}
	printf("Enter item code to delete: ");
	if (scanf("%d", &deleteCode) != 1) {
		printf("Invalid input. Item code must be a number.\n");
		fclose(fptr);
		fclose(fptr2);
		return;
	}
	int found = 0;
	while (fscanf(fptr, "%d %s %d %d %d %d", &title.add, title.name, &title.price, &title.stock, &title.level, &title.quantity) == 6) {
		if (title.add == deleteCode) {
			printf("Item with code %d deleted successfully!\n", deleteCode);
			found = 1;
		}
		else {
			fprintf(fptr2, "%d %s %d %d %d %d\n", title.add, title.name, title.price, title.stock, title.level, title.quantity);
		}
	}
	if (!found) {
		printf("Item with code %d not found.\n", deleteCode);
	}
	fclose(fptr);
	fclose(fptr2);

}

void display() {
	tupper title;
	FILE* fptr;
	fptr = fopen("text.txt", "r");
	if (!fptr) {
		printf("Open File Error....");
		exit(0);
	}
	printf("=========================================TUPPERWARE STORE===========================================\n");
	printf("%-12s %-30s %-10s %-10s %-10s %-10s\n", "Item Code", "Item Description", "Price", "Stock qty", "Minimum Lvl", "Reorder Quantity");

	while (fscanf(fptr, "%d %s %d %d %d %d", &title.add, title.name, &title.price, &title.stock, &title.level, &title.quantity) == 6) {
		printf("%-12d %-30s %-10d %-10d %-10d %-10d\n", title.add, title.name, title.price, title.stock, title.level, title.quantity);
		printf("====================================================================================================\n");
	}
	fclose(fptr);
}

void check() {
	tupper title;
	FILE* fptr;
	fptr = fopen("text.txt", "w");
	if (!fptr) {
		printf("Open File Error....");
		exit(0);
	}
	printf("Tupperware below minimum level:\n");
	printf("ID\tName\t\tPrice\tStock\tMin. Level\tReorder Qty\n");
	int id, price, stock, level, quantity;
	char name[100];
	while (fscanf(fptr, "%d %99s %d %d %d %d", &id, name, &price, &stock, &level, &quantity) != EOF) {
		if (stock < level) {
			printf("%d\t%-15.*s%d\t%d\t%d\t\t%d\n", id, sizeof(name), name, price, stock, level, quantity);
		}
	}
	fclose(fptr);
}
