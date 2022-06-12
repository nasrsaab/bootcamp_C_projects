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

	void initBoard();                                  //���� ���� ������ �����
	void printBoard();                               //����� ���� ��� ���
	bool checkBoard(int i, int j);                  //����� �� ����� ������� �� ����


	void runGame();                   //��� ����� �����              
	
	 
	void printPossibleBoard(int pNum);             //������ �� ������� ����� ��� ����
	void AvailablePawn(int playerNum);            //������ ����� ��� ���� ���� ����� 
	void displayPawnMove(int pnum,int i,int j);  //������ ������ ����� ����� ���� �����
	
	bool isRightMove(int pCol, int jCol);
	int returnPawnId(int play,int row, int col);
	int isWinner();

	void playerCanEating(int pR,int pC, int iR,int jC,int ii,int dir);
	int pawnNumLiving(int n);

	void CheckKing(int pRow, int pCol, int iR, int ii, int dir);

};
