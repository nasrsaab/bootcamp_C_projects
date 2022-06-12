#include "pawn.h"


pawn::pawn(){}

void pawn::setPlace(int r, int c)
{
	row = r;
	col = c;
}
/*-----------------------------------------*/
int pawn::getRow()
{
	return row;
}
/*-----------------------------------------*/
int pawn::getCol()
{
	return col;
}


/*-----------------------------------------*/
void pawn::setColor(int c) 
{
	color = c;
}
/*-----------------------------------------*/
void pawn::setLiving(bool l)
{
	living = l;
}


/*-----------------------------------------*/
int pawn::getColor()
{
	return color;
}
/*-----------------------------------------*/
bool pawn::getLiving()
{
	return living;
}


/*-----------------------------------------*/
void pawn::addPosMove(int i, int j)
{
	string s1;
	s1 = to_string(i)+ to_string(j);
	
	if(posMoves[0]=="")
		posMoves[0] = s1;
	else
		posMoves[1] = s1;

	
}
/*-----------------------------------------*/
string* pawn::getPosMove()
{
	return posMoves;
}


/*-----------------------------------------*/
void pawn::cleanPosMove()
{
	posMoves[0] = "";
	posMoves[1] = "";
}


/*-----------------------------------------*/
void pawn::setEating(bool eat)
{
	eating = eat;
}
/*-----------------------------------------*/
bool pawn::getEating()
{
	return eating;
}


/*-----------------------------------------*/
void pawn::setKing(bool k)
{
	king = k;
}
/*-----------------------------------------*/
bool pawn::getKing()
{
	return king;
}
/*-----------------------------------------*/