#include "abstrac.h"
using namespace std;
int AbstractBoard :: number_of_board=0;
void AbstractBoard :: move(char a){
	if(a=='u' || a=='U')
		move_up();
	else if(a=='l' || a=='L')
		move_left();
	else if(a=='d' || a=='D')
		move_down();
	else if(a=='r' || a=='R')
		move_right();
}
AbstractBoard::AbstractBoard(){
	number_of_board++;
	line=0;
	coloun=0;
	count=0;
}
AbstractBoard::~AbstractBoard(){
	number_of_board--;
}
 int AbstractBoard ::  NumberOfBoard(){
	return number_of_board;
}
char AbstractBoard :: GetLastMove(){
	return last_move;
}
