#include <iostream>
#include <string.h>
using namespace std;

#include "board.h"

board::board()
{

}
board::~board()
{

}




/*------------------------------------------------*/
void board::initBoard()
{
	int indexP1 = 0, indexP2 = 0;

	for (int i = 0; i < SIZE; i++)
	{

		for (int j = 0; j < SIZE; j++)
		{
			if ((i + j) % 2 == 1 && i < 3)
			{
				boardArray[i][j] = 1;
				p1.getP()[indexP1].setPlace(i, j);
				p1.getP()[indexP1].setLiving(true);
				p1.getP()[indexP1].setEating(false);
				p1.getP()[indexP1].setKing(false);
				p1.getP()[indexP1++].setColor(1); //1 = Yellow

			}
			else if ((i + j) % 2 == 1 && i > 4)
			{
				boardArray[i][j] = 2;
				p2.getP()[indexP2].setPlace(i, j);
				p2.getP()[indexP2].setLiving(true);
				p2.getP()[indexP2].setEating(false);
				p2.getP()[indexP2].setKing(false);
				p2.getP()[indexP2++].setColor(2); //2 = Red
			}
			else if ((i + j) % 2 == 1 && (i > 3 || i < 4))
				boardArray[i][j] = 3;
			else
				boardArray[i][j] = 0;
		}

	}
}
/*------------------------------------------------*/
/*void board::printBoard()
{
	printf("\033[1;32m");
	cout << "\t\t  0 1 2 3 4 5 6 7" << endl;

	for (int i = 0; i < SIZE; i++)
	{
		printf("\033[1;32m");
		cout <<"\t\t"<<i;
		for (int j = 0; j < SIZE; j++)
		{
			printf("\033[1;30m");
			if (boardArray[i][j] == 1)
			{
				printf("\033[1;33m");
				cout << " " << (char)220;
				//cout << " " << i<<""<<j;
				
			}
			if (boardArray[i][j] == 2)
			{
				printf("\033[1;31m");
				cout << " " << (char)220;
				//cout << " " << i << "" << j;
				
			}
			 if (boardArray[i][j] == 3)
			{   
				printf("\033[1;37m");
				cout << " " << (char)220;
				//cout << " " << i << "" << j;
				
			}
			 if (boardArray[i][j] == 4)
			 {
				 printf("\033[1;35m");
				 cout << " " << (char)220;
				// cout << " " << i << "" << j;

			 }
			 if (boardArray[i][j] == 5)
			 {
				 printf("\033[1;34m");
				 cout << " " << (char)220;
				// cout << " " << i << "" << j;

			 }
			else if (boardArray[i][j] == 0)
			{
				 cout << " " << (char)220;

			}
		}
		cout << endl;
	}
}*/
/*------------------------------------------------*/
bool board::checkBoard(int i, int j)
{
	if (i < 0 || i>7 || j < 0 || j>7)
		return false;

	return true;
}
/*------------------------------------------------*/
void board::printBoard()
{
	printf("\033[1;32m");//set green color
	cout << "\t\t  0 1 2 3 4 5 6 7" << endl;

	for (int i = 0; i < SIZE; i++)
	{
		printf("\033[1;32m");//set green color
		cout << "\t\t" << i;
		for (int j = 0; j < SIZE; j++)
		{
			printf("\033[1;30m");//set Black color
			if (boardArray[i][j] == 1)
			{
				printf("\033[1;33m");//set yellow color
				cout << " " << (char)220;  //set ASCII code for 220
				//cout << " " << i<<""<<j;

			}
			if (boardArray[i][j] == 2)
			{
				printf("\033[1;31m");//set Red color
				cout << " " << (char)220;
				//cout << " " << i << "" << j;

			}
			if (boardArray[i][j] == 3)
			{
				printf("\033[1;37m");//set White color
				cout << " " << (char)220;
				//cout << " " << i << "" << j;

			}
			if (boardArray[i][j] == 4)
			{
				printf("\033[1;35m");//set Purple color
				cout << " " << (char)220;
				// cout << " " << i << "" << j;

			}
			if (boardArray[i][j] == 5)
			{
				printf("\033[1;34m");//set Blue color
				cout << " " << (char)220;
				// cout << " " << i << "" << j;

			}
			else if (boardArray[i][j] == 0)
			{
				cout << " " << (char)220;

			}
		}
		cout << endl;
	}
}
/*------------------------------------------------*/

void board::runGame()
{
	bool isEnd = false;
	bool yellowTurn = true;
	int counter = 50;
	int direction = 1;
	player* px;

	initBoard();

	while (!isEnd)
	{

		printBoard();
		counter--;

		printf("\033[1;34m");////set Blue color
		cout << "\t\t Turn number: " << counter << endl;

		if (counter == 0)
		{
			printf("\033[1;31m");
			cout << " Game Over..." << endl;
			printf("\033[1;30m");
			break;
		}
		if (isWinner() == 1)
		{
			cout << "palyer 1 (Yellow) is winner...." << endl;
			break;
		}
		if (isWinner() == 2)
		{
			cout << "palyer 2 (Red) is winner...." << endl;
			break;
		}

		//yellow turn
		if (direction == 1)
		{
			printf("\033[1;33m");
			cout << " P1: Yellow turn: " << endl;
			px = &p1;
		}

		// Red Turn
		else
		{
			direction = -1;
			px = &p2;
			printf("\033[1;31m");
			cout << " P2: Red turn: " << endl;
		}


		//Begin Game
		int iRow, jCol, pRow, pCol, id;

		cout << " Pawn Number Living: " << pawnNumLiving(px->getP()[0].getColor()) << endl;
		printf("\033[1;30m");

		AvailablePawn(px->getP()[0].getColor());         //update pawn can move
		printPossibleBoard(px->getP()[0].getColor());   //print all pawn move

		cout << "Please enter Pawn number: " << endl;
		cin >> pRow;
		cin >> pCol;

		//Return pawn id
		id = returnPawnId(px->getP()[0].getColor(), pRow, pCol);

		if (id == -1)
		{
			printf("\033[1;31m");  cout << "Sorry the Pawn Id is not found !!!" << endl; printf("\033[1;30m");
			continue;
		}


		if (boardArray[pRow][pCol] == px->getP()[id].getColor() && (px->getP()[id].getPosMove()[0] != "" || px->getP()[id].getPosMove()[1] != ""))
		{
			displayPawnMove(px->getP()[id].getColor(), pRow, pCol);

			cout << "Please enter Row number and Column number: " << endl;
			cin >> iRow;
			cin >> jCol;

			if (boardArray[iRow][jCol] == 3)
			{
				
				//set a new place
				px->getP()[id].setPlace(iRow, jCol);

				printf("\033[1;33m");
				cout << "player number " << id << " plased in " << pRow << "" << pCol << " move to --> " << iRow << "" << jCol << endl;
				printf("\033[1;30m");

				//בדיקת מצב אכילה
				if (px->getP()[id].getEating() == true)
					playerCanEating(pRow, pCol, iRow, jCol, id, direction);

				//plcae number is empty
				boardArray[pRow][pCol] = 3;

				//check king
				CheckKing(pRow, pCol, iRow, id, direction);

				boardArray[iRow][jCol] = px->getP()[id].getColor();

				//update
				AvailablePawn(px->getP()[id].getColor()+ direction);
				AvailablePawn(px->getP()[id].getColor());
			}//pawn is moved
			else
			{
				printf("\033[1;31m"); cout << "Sorry the place number is wrong!!!" << endl; printf("\033[1;30m");
				direction = direction * (-1);  continue;
				
			}

			//the second turn
			direction = direction * (-1);
		

		}
		else
		{
			printf("\033[1;31m");  cout << "Sorry the pawn number is wrong OR you can't move!!!" << endl; printf("\033[1;30m");
			direction = direction * (-1); continue;
		}



	}//eng while

}


/*------------------------------------------------*/
void board::AvailablePawn(int playerNum)
{
	player* px;
	px = &p1;
	int direction = 1; //Yellow...color= 1

	if (playerNum == 2) {
		px = &p2;
		direction = -1;
	}
	for (int i = 0; i < 12; i++)
	{
		px->getP()[i].cleanPosMove();

		if (px->getP()[i].getLiving() == false)
			continue;

		//if (px->getP()[i].getKing() == true)
		//	direction = direction * (-1);

		int pRow = px->getP()[i].getRow();
		int pCol = px->getP()[i].getCol();

		/*-------------------------------------------------------------------------------------*/
		//בדיקה אם המקום הימיני נכון וריק
		if (checkBoard(pRow + direction, pCol - 1) && boardArray[pRow + direction][pCol - 1] == 3)
		{

			px->getP()[i].addPosMove(pRow + direction, pCol - 1);

		}
		/*-------------------------------------------------------------------------------------*/
		//בדיקה אם המקום השמלי נכון וריק
		if (checkBoard(pRow + direction, pCol + 1) && boardArray[pRow + direction][pCol + 1] == 3)
		{
			px->getP()[i].addPosMove(pRow + direction, pCol + 1);

		}
		/*-------------------------------------------------------------------------------------*/
		// check if yellow can eat
		if (checkBoard(pRow + direction, pCol - 1) && direction == 1 && boardArray[pRow + direction][pCol - 1] == 2
			&& checkBoard(pRow + direction * 2, pCol - 2) && boardArray[pRow + direction * 2][pCol - 2] == 3)
		{
			px->getP()[i].cleanPosMove();
			px->getP()[i].addPosMove(pRow + direction * 2, pCol - 2);
			px->getP()[i].setEating(true);

		}
		if (checkBoard(pRow + direction, pCol + 1) && direction == 1 && boardArray[pRow + direction][pCol + 1] == 2
			&& checkBoard(pRow + direction * 2, pCol + 2) && boardArray[pRow + direction * 2][pCol + 2] == 3)
		{
			px->getP()[i].cleanPosMove();
			px->getP()[i].addPosMove(pRow + direction * 2, pCol + 2);
			px->getP()[i].setEating(true);
		}

		/*-------------------------------------------------------------------------------------*/
		// check if red can eat
		if (checkBoard(pRow + direction, pCol - 1) && direction == -1 && boardArray[pRow + direction][pCol - 1] == 1
			&& checkBoard(pRow + direction * 2, pCol - 2) && boardArray[pRow + direction * 2][pCol - 2] == 3)
		{
			px->getP()[i].cleanPosMove();
			px->getP()[i].addPosMove(pRow + direction * 2, pCol - 2);
			px->getP()[i].setEating(true);
		}
		if (checkBoard(pRow + direction, pCol + 1) && direction == -1 && boardArray[pRow + direction][pCol + 1] == 1
			&& checkBoard(pRow + direction * 2, pCol + 2) && boardArray[pRow + direction * 2][pCol + 2] == 3)
		{
			px->getP()[i].cleanPosMove();
			px->getP()[i].addPosMove(pRow + direction * 2, pCol + 2);
			px->getP()[i].setEating(true);
		}

	}
}
/*------------------------------------------------*/
void board::printPossibleBoard(int pNum)
{
	bool ok = false;

	if (pNum == 1)
	{
		cout << "the pawn number about Player number 1:" << endl;
		for (int i = 0; i < pawnNumber; i++)
		{
			if (p1.getP()[i].getLiving() && p1.getP()[i].getEating())
			{   
				cout <<"["<<i<<"]="<< p1.getP()[i].getRow() << p1.getP()[i].getCol() << endl;
				ok = true;
			}
		}
		if (!ok)
		{
			for (int i = 0; i < pawnNumber; i++)
			{
				if (p1.getP()[i].getLiving() && (p1.getP()[i].getPosMove()[0] != "" || p1.getP()[i].getPosMove()[1] != ""))
				{
					cout << "[" << i << "]=" << p1.getP()[i].getRow() << p1.getP()[i].getCol() << endl;
					
				}
			}
		}
		
	}
	/*------------------------------------------------------------------------------*/
	else // player number 2
	{
		cout << "the pawn number about Player number 2:" << endl;
		for (int i = 0; i < pawnNumber; i++)
		{ 
			
			if (p2.getP()[i].getLiving() && p2.getP()[i].getEating())
			{
				cout << "[" << i << "]=" << p2.getP()[i].getRow() << p2.getP()[i].getCol() << endl;
				ok = true;
			}
		}
		if (!ok)
		{
			for (int i = 0; i < pawnNumber; i++)
			{

				if (p2.getP()[i].getLiving() && (p2.getP()[i].getPosMove()[0] != "" || p2.getP()[i].getPosMove()[1] != ""))
				{
					cout << "[" << i << "]=" << p2.getP()[i].getRow() << p2.getP()[i].getCol() << endl;
					
				}
			}
		}
	}
}
/*------------------------------------------------*/
void board::displayPawnMove(int pnum,int irow, int jcol)
{
	if (pnum == 1)
	{
		cout << "the pawn move number about Player number " << irow << jcol << endl;
		for (int i = 0; i < pawnNumber; i++)
		{
			if (p1.getP()[i].getLiving() && p1.getP()[i].getRow() == irow && p1.getP()[i].getCol() == jcol)
			{
				cout << "his player number " << i << endl;
				
				cout << p1.getP()[i].getPosMove()[0] << "," << p1.getP()[i].getPosMove()[1] << endl;
				
			}
		}
		
		
	}
	else // player number 2
	{
		cout << "the pawn move number about Player number " << irow << jcol << endl;
		for (int i = 0; i < pawnNumber; i++)
		{
			if (p2.getP()[i].getLiving() && p2.getP()[i].getRow() == irow && p2.getP()[i].getCol() == jcol)
			{
				cout << "his player number " << i << endl;
				cout << p2.getP()[i].getPosMove()[0] << "," << p2.getP()[i].getPosMove()[1] << endl;

			}
		}
	}
}
/*------------------------------------------------*/




void board::playerCanEating(int pR, int pC, int iR, int jC, int ii, int dir)
{
	player* px,*px1;
	int p;

	px = &p1;
	px1 = &p2;
	p = 1;

	if (dir == 1)
	{
		px = &p2;
		px1 = &p1;
		p = 2;
	}
	

	if (boardArray[pR + dir][pC - 1] == p && boardArray[iR][jC] == 3 && !isRightMove(pC, jC))
	{       //eating 
		px1->getP()[ii].setEating(false);
		for (int k = 0; k < pawnNumber; k++)
		{
			if (px->getP()[k].getLiving() && px->getP()[k].getRow() == pR + dir && px->getP()[k].getCol() == pC - 1)
			{
				px->getP()[k].setLiving(false);
				px->getP()[k].setEating(false);
				printf("\033[1;34m");
				cout << "p"<<p<<" number s " << k << " placed in " << pR + dir << "" << pC - 1 << " eated (-:-)" << endl;
				boardArray[pR + dir][pC - 1] = 3;
				
				printf("\033[1;30m");
			}
		}

	}
	if (boardArray[pR + dir][pC + 1] == p && boardArray[iR][jC] == 3 && isRightMove(pC, jC))
	{
		px1->getP()[ii].setEating(false);
		for (int k = 0; k < pawnNumber; k++)
		{
			if (px->getP()[k].getLiving() && px->getP()[k].getRow() == pR + dir && px->getP()[k].getCol() == pC + 1)
			{
				px->getP()[k].setLiving(false);
				px->getP()[k].setEating(false);
				printf("\033[1;34m");
				cout << "p" << p << " number " << k << " placed in " << pR + dir << "" << pC + 1 << " eated (-:-)" << endl;
				boardArray[pR + dir][pC + 1] = 3;
				printf("\033[1;30m");
			}
		}
	}
}
/*------------------------------------------------*/
bool board::isRightMove(int pCol, int jCol)
{
	if (jCol == pCol + 2)
		return true;

	else return false;
}
/*------------------------------------------------*/
int board::returnPawnId(int play,int row, int col)
{
	player *px1;
	px1 = &p2;

	if (play == 1)
		px1 = &p1;
	
		

	for (int i = 0; i < pawnNumber; i++)
	{
		if (px1->getP()[i].getLiving() && px1->getP()[i].getRow() == row && px1->getP()[i].getCol() == col)
		{
			return i;
		}
	}
	return -1;

}
/*------------------------------------------------*/


//check how is a winner
int board::isWinner()
{
	bool alive = false;

	for (int i = 0; i < pawnNumber; i++)
	{
		if (p1.getP()[i].getLiving())
		{
			alive = true;
			break;
		}
		
	}
	if (alive == false)
		return 2;
	
	/*-------------------------*/
	alive = false;

	for (int i = 0; i < pawnNumber; i++)
	{
		if (p2.getP()[i].getLiving())
		{
			alive = true;
			break;
		}

	}
	if (alive == false)
		return 1;


	return 0;
}
/*------------------------------------------------*/
//count how many pawn are living
int board::pawnNumLiving(int n)
{
	player* pp;
	pp = &p1;
	if (n == 2)
		pp = &p2;
	int PawnNum = 0;

	for (int i = 0; i < pawnNumber; i++)
	{
		if (pp->getP()[i].getLiving())
		{
			PawnNum++;
			
		}

	}
	return PawnNum;
}
/*------------------------------------------------*/
void board::CheckKing(int pRow, int pCol, int iR, int ii, int dir)
{

	player* px;
	
	px = &p2;
	

	if (dir == 1)
	{
		px = &p1;
		
	}

	if (iR == 0)
	{
		
		px->getP()[ii].setColor(4);
		px->getP()[ii].setKing(true);
		
	}
	else if (iR == 7)
	{
		px->getP()[ii].setColor(5);
		px->getP()[ii].setKing(true);
	}

	
}