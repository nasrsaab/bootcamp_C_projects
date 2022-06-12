#pragma once
#include <iostream>
#include <string>
using namespace std;
const int pawnNumber = 12;


class pawn {
private:
	int color;  //1 is yellow //2 is red
	bool living;
	int row;
	int col;
	string posMoves[2];
	bool eating;
	bool king;

public:
	pawn();
	void setColor(int c);
	void setLiving(bool l);
	void setPlace(int r, int c);
	void setEating(bool e);
	void setKing(bool k);

	int getColor();
	bool getLiving();
	bool getEating();
	bool getKing();

	int getRow();
	int getCol();


	void addPosMove(int i ,int j);
	string* getPosMove();

	void cleanPosMove();
};
