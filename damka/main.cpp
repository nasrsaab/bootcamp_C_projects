#include <iostream>
#include "board.h"
using namespace std;


int main() 
{
	cout << "\t\t    " << __DATE__ << endl;
	cout << "\t\t     " << __TIME__ << endl;

	board b;
	b.runGame();

	return 0;
}