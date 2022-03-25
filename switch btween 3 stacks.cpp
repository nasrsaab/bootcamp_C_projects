#include "stdio.h"
#include "stdlib.h"

#define SIZE 3
#define TRUE 1
#define FALSE 0
#define EMPTY -1

#define NO_ITEMS -2
#define ONE_ITEM -1
char ch;
char S[SIZE];
char T[SIZE];
char U[SIZE];
int topu = -1;   int tops = -1; int topt = -1;
//int top = -1;

int stackEmpty(int top) {
	return (top == EMPTY);
}

int stackFull(int top) {
	return (top == SIZE - 1);
}


int spush(char x) {
	if (stackFull(tops)) return FALSE;
	tops++;
	S[tops] = x;
	return TRUE;
}

char spop() {
	char x;
	if (stackEmpty(tops)) return FALSE;
	x = S[tops];
	tops--;
	return x;
}
int tpush(char x) {
	if (stackFull(topt)) return FALSE;
	topt++;
	T[topt] = x;
	return TRUE;
}

char tpop() {
	char x;
	if (stackEmpty(topt)) return FALSE;
	x = T[topt];
	topt--;
	return x;
}

int upush(char x) {
	if (stackFull(topu)) return FALSE;
	topu++;
	U[topu] = x;
	return TRUE;
}

char upop() {
	char x;
	if (stackEmpty(topu)) return FALSE;
	x = U[topu];
	topu--;
	return x;
}



void swap()
{

	upush(spop());
	upush(spop());
	upush(spop());


	spush(tpop());
	spush(tpop());
	spush(tpop());


	tpush(upop());
	tpush(upop());
	tpush(upop());


	upush(spop());
	upush(spop());
	upush(spop());


	char x = upop();
	char y = upop();
	char z = upop();


	spush(z);
	spush(y);
	spush(x);

	
}

void main()
{
	for (int i = 0; i < 3; i++)
	{
		printf("enter char: ");
		char ch;
		ch = getchar();
		spush(ch);
		getchar();

	}
	for (int i = 0; i < 3; i++)
	{
		printf("enter char: ");
		char ch;
		ch = getchar();
		tpush(ch);
		getchar();

	}

	swap();

	printf("FTER SWAP:\n");
	for (int i = 0; i < 3; i++)
	{
		printf("S= %c ", spop());
	}


	printf("\n");

	for (int i = 0; i < 3; i++)
	{
		printf("T= %c ", tpop());
	}

	
}