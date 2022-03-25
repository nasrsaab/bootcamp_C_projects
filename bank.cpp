#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FOREVER for(;;)
#define pathFile "E:\\bootcamp\\BankCustomer.bin"
#define pathFile2 "E:\\bootcamp\\transactions.bin"
//fpr1 - read bank
//fpr2 - read transactions
//fpw1 - write bank
//fpw2 - write transactions
FILE* fpr1, * fpr2, * fpw1, * fpw2;
int num=0,count=0;
struct bank {
	char name[20];
	long idNumber;
	int accountNumber;
	double money=0.0;
	double CurrentStatus;
	int date;
	int transact = 0;
}Customer[10];

struct transaction {
	int counter=0;         //traffic number
	int accountnumber;
	char details[20];    //traffic description
	double amount;   //sum

}trans[10];

int saveBankFile()
{
	fopen_s(&fpw1, pathFile, "wb");

	if (fpw1 == NULL)
	{
		printf("bank file can't open to write!!!\n");
		return  0;
	}

	fwrite(&Customer, sizeof(struct bank), num, fpw1);

	fclose(fpw1);
	return 1;
}
int readBankFile()
{
	fopen_s(&fpr1, pathFile, "rb");

	if (fpr1 == NULL)
	{
		printf("bank file can't open to read!!!\n");
		return  0;
	}
	num = 0;
	while (!feof(fpr1))
	{
		
		fread(&Customer, sizeof(struct bank),1, fpr1);
		num++;
	}
	fclose(fpr1);

	fopen_s(&fpr1, pathFile, "rb");
	if (fpr1 == NULL)
	{
		printf("bank file can't open to read!!!\n");
		return  0;
	}
	fread(&Customer, sizeof(struct bank), num, fpr1);
	printf("num= %d\n", num);
	fclose(fpr1);
	return 1;
}
int saveTransactionsFile()
{
	fopen_s(&fpw2, pathFile2, "wb");

	if (fpw2 == NULL) 
	{
		printf("Transactions file can't open to write!!!\n");
		return  0;
	}

	fwrite(&trans, sizeof(struct transaction), count, fpw2);

	fclose(fpw2);
	return 1;
}
int readTransactionsFile()
{
	fopen_s(&fpr2, pathFile2, "rb");

	if (fpr2 == NULL) 
	{
		printf("Transactions file can't open to read!!!\n");
		return  0;
	}
	count = 0;
	while (!feof(fpr2))
	{
		
		fread(&trans, sizeof(struct transaction), 1, fpr2);
		count++;
	}
	fclose(fpr2);

	fopen_s(&fpr2, pathFile2, "rb");
	if (fpr2 == NULL)
	{
		printf("Transactions file can't open to read!!!\n");
		return  0;
	}
	fread(&trans, sizeof(struct transaction),count, fpr2);
	printf("count= %d\n", count);
	fclose(fpr2);
	return 1;
}
void sort()
{
	//sort
	struct bank temp;
	//compare the year and swap the intire struct
	for (int i = 0;i < num;i++) {
		for (int j = i + 1; j < num;j++) {
			if (Customer[i].idNumber > Customer[j].idNumber) {
				temp = Customer[i];
				Customer[i] = Customer[j];
				Customer[j] = temp;
			}
		}
	}
	//Put into file

}
void bankList()
{
	printf("\033[1;32m");
	if(num==0)
	{
		printf("Bank list is Empty!!!\n");
		
	}
	for (int i = 0; i < num; i++)
	{
		if (Customer[i].accountNumber>0)
		{
			printf("Customer name= %s\n", Customer[i].name);
			printf("Customer id= %d\n", Customer[i].idNumber);
			printf("Account number= %d\n", Customer[i].accountNumber);
			printf("Customer money= %.2lf\n", Customer[i].money);
			printf("Customer Transaction= %d\n", Customer[i].transact);
			printf("\n");
		}
	}
	printf("\033[1;35m");
}
void transactionsList()
{
	printf("\033[1;32m");
	if (count == 0)
	{
		printf("Transactions list is Empty!!!\n");

	}
	for (int i = 0; i < count; i++)
	{
		if (trans[i].accountnumber > 0)
		{
			printf("Transactions numer= %d\n", trans[i].counter);
			printf("Transactions account number= %d\n", trans[i].accountnumber);
			printf("Transactions details= %s\n", trans[i].details);
			printf("Transactions money= %.2lf\n", trans[i].amount);
			printf("\n");
		}
	}
	printf("\033[1;35m");
}
void newBankAccount()
{
	
		printf("Please enter the Customer Name:\n");
		fgets(Customer[num].name, 20, stdin);
		Customer[num].name[strlen(Customer[num].name) - 1] = 0;

		printf("Please enter Customer Number:\n");
		scanf_s("%d", &Customer[num].idNumber);
		int c = getchar();

		printf("Please enter Account number:\n");
		scanf_s("%d", &Customer[num].accountNumber);
		int c1 = getchar();
				
		printf("\n.....CREATE ACCOUNT SUCCESSFUL....\n");
		num++;
}
void updateBankAcount()
{
	
	int op;
	
	printf("\033[1;31m");
	
	printf("What do you want to do:\n");
	printf("1.cash withrawal\n");
	printf("2.Adding money\n");
	scanf_s("%d", &op);
	int c = getchar();
	switch (op)
	{
	case 1:
	{

		int n = 0;
		printf("Please enter the Account Number\n");
		scanf_s("%d", &trans[count].accountnumber);
		int c1 = getchar();
		for (int i = 0; i < num; i++)
		{
			if (trans[count].accountnumber == Customer[i].accountNumber)
			{
				strcpy_s(trans[count].details, "Cash withrawal");
				printf("How much money are you pulling\n");
				scanf_s("%lf", &trans[count].amount);
				int c = getchar();

				Customer[i].money -= trans[count].amount;
				trans[count].counter = ++Customer[i].transact;
				count++;
				n++;
				printf("*** Cash withrawal SUCCESSFUL ***\n");
			}

		}
		if (n == 0)
		{
			printf("...Sorry Account number not found...\n");

		}
		break;
	}
	case 2:
	{
		printf("Please enter the Account Number\n");
		scanf_s("%d", &trans[count].accountnumber);
		int c1 = getchar();

		int n = 0;
		for (int i = 0; i < num; i++)
		{
			if (trans[count].accountnumber == Customer[i].accountNumber)
			{
				printf("How much money you want to Adding \n");
				scanf_s("%lf", &trans[count].amount);
				int c = getchar();
				strcpy_s(trans[count].details, "Adding money");

				Customer[i].money += trans[count].amount;
				trans[count].counter = ++Customer[i].transact;
				count++;
				n++;
				printf("*** ADDING MONEY SUCCESSFUL ***\n");
			}

		}
		if (n == 0)
		{
			printf("...Sorry Account number not found...\n");

		}
		break;
	}

		default:
		{printf("\n.....YOUR OPTION NOT FOUND....\n");
			break;
		}
	}
}
void specificTrans()
{
	int acc;
	printf("Please enter the Account number\n");
	scanf_s("%d", &acc);
	int c = getchar();
	printf("\033[1;36m");
	for (int i = 0; i < num; i++)
	{
		if (acc == Customer[i].accountNumber)
		{
			for (int j = 0; j < count; j++)
			{
				if (trans[j].accountnumber == Customer[i].accountNumber)
				{
					printf("Transactions numer= %d\n", trans[j].counter);
					printf("Transactions account number= %d\n", trans[j].accountnumber);
					printf("Transactions details= %s\n", trans[j].details);
					printf("Transactions money= %.2lf\n", trans[j].amount);
					printf("\n");
				}
			}
		}
		
	}//end for
	printf("\n.....SORRY ACCOUNT NUMBER NOT FOUND....\n");
}
void positiveBalance()
{
	printf("\033[1;32m");
	for (int i = 0; i < num; i++)
	{
		if (Customer[i].money > 0)
		{
			printf("Customer name= %s\n", Customer[i].name);
			printf("Customer id= %d\n", Customer[i].idNumber);
			printf("Account number= %d\n", Customer[i].accountNumber);
			printf("Customer money= %.2lf\n", Customer[i].money);
			printf("Customer Transaction= %d\n", Customer[i].transact);
			printf("\n");
		}
		else
			printf("...NO positive Balance...\n");
	}
}
void negativeBalance()
{
	printf("\033[1;34m");
	for (int i = 0; i < num; i++)
	{
		if (Customer[i].money < 0)
		{
			printf("Customer name= %s\n", Customer[i].name);
			printf("Customer id= %d\n", Customer[i].idNumber);
			printf("Account number= %d\n", Customer[i].accountNumber);
			printf("Customer money= %.2lf\n", Customer[i].money);
			printf("Customer Transaction= %d\n", Customer[i].transact);
			printf("\n");
		}
		else
			printf("...NO negative Balance...\n");
	}
}
int transferMoney()
{
	printf("\033[1;31m");
	printf("Please Enter Your Account Number\n");
	scanf_s("%d", &trans[count].accountnumber);
	int c1 = getchar();
	for (int i = 0; i < num; i++)
	{
		if (trans[count].accountnumber == Customer[i].accountNumber)
		{
			printf("Please Enter The Customer Account Number\n");
			scanf_s("%d", &trans[count+1].accountnumber);
			int c1 = getchar();
			for (int j = 0; j < num; j++)
			{
				if (trans[count+1].accountnumber == Customer[j].accountNumber)
				{
					printf("Please Enter How Many Money you want to Transfer\n");
					scanf_s("%lf", &trans[count].amount);
					int c1 = getchar();
					Customer[j].money += trans[count].amount;
					Customer[i].money -= trans[count].amount;
					trans[count+1].amount = trans[count].amount;
					trans[count].counter = ++Customer[i].transact;
					trans[count+1].counter = ++Customer[j].transact;
					strcpy_s(trans[count+1].details, "Adding money");
					strcpy_s(trans[count].details, "Transfer money");
					count =count +2;
					printf("\n.....TRANSFER MONEY SUCCESSFUL....\n");
					return 1; 
				}//end if
			}
			printf("\n.....SORRY ACCOUNT NUMBER	NOT FOUND....\n");
			return 0;
		}//end if
			
	}	
	printf("\n.....SORRY YOUR ACCOUNT NUMBER NOT FOUND....\n");
	return 0;
}
int main() {
	int option;
	
	FOREVER{
		printf("\033[1;33m");
		printf("1. New account\n");
		printf("2. Make a transaction\n");
		printf("3. Show all account details\n");
		printf("4. Show all transactions\n");
		printf("5. Show all transactions for a specific client\n");
		printf("6. Show all their customers have a positive balance\n");
		printf("7. Show all their customers have a negative balance\n");
		printf("8. Money transfer from one account to another\n");
		printf("9. Read and print bank file\n");
		printf("10. Read and print transaction file\n");
		printf("99. exit\n");
		scanf_s("%d", &option);
		int c = getchar();
		printf("\033[1;34m");
		switch (option)
		{
		case 1:
		{   printf("Create New account...\n");
			newBankAccount();
			sort();
			//bankList();
			saveBankFile();

		break;
		}
		case 2:
		{	printf("Make a transaction...\n");
			updateBankAcount();
			//bankList();
			saveBankFile();
			saveTransactionsFile();
		break;
		}
		case 3:
		{   printf("Account details...\n");
			bankList();
		break;
		}
		case 4:
		{   printf("The transactions...\n");
			transactionsList();
		break;
		}
		case 5:
		{  printf("Transactions for a specific client...\n");
			specificTrans();
		break;
		}
		case 6:
		{   printf("Customers have a positive balance....\n");
		    positiveBalance();
			break;
		}
		case 7:
		{    printf("Customers have a negative balance....\n");
		     negativeBalance();
			break;
		}
		case 8:
		{
			printf("Transfer money from one account to another...\n");
			transferMoney();
			saveTransactionsFile();
			break;
		}
		case 9:
		{
			printf("***** BANK FILE *****\n");
			readBankFile();
			bankList();
			break;
		}
		case 10:
		{
			printf("***** TRANSACTION FILE\n");
			readTransactionsFile();
			transactionsList();
			break;
		}
		case 99:return 0;
		default:
			break;
		}
	}
	return 0;
}