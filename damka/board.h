#pragma once
#include "player.h"

const int SIZE = 8;

class board {
private:
	int boardArray[SIZE][SIZE]={0};
	player p1, p2;

public:
	board();
	~board();

	void initBoard();                                  //הכנת הלוח לתחילת המשחק
	void printBoard();                               //הדפסת הלוח בכל שלב
	bool checkBoard(int i, int j);                  //לבדוק אם יצאנו מהמזגרת של הלוח


	void runGame();                   //כאן מתחיל המשחק              
	
	 
	void printPossibleBoard(int pNum);             //להדפיס מי השחקנים שמותר להם לזוז
	void AvailablePawn(int playerNum);            //מקומות שמותר לכל שחקן לזוז אילהם 
	void displayPawnMove(int pnum,int i,int j);  //להדפיס המקומת שמותר לשחקן לזוז אילהם
	
	bool isRightMove(int pCol, int jCol);
	int returnPawnId(int play,int row, int col);
	int isWinner();

	void playerCanEating(int pR,int pC, int iR,int jC,int ii,int dir);
	int pawnNumLiving(int n);

	void CheckKing(int pRow, int pCol, int iR, int ii, int dir);

};
