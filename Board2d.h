#ifndef BOARD2D_H
#define BOARD2D_H
#include "abstrac.h"
class Board2D  : public AbstractBoard{
public:
				 // Defining the public functions ...
				 inline void printReport(){		 cout << "Move number -> " << count << "\n" ;}
				 ~Board2D();
				 void setSize(int y,int x);
				 void readFromFile(string name);
				 void writeToFile(string name);
				 void reset(int size);
				 void setSize();
				 void moveRandom();
				 void shuffle();
				 void print_goal();
				 void print() const;
				 int move_up();
				 int move_left();
				 int move_down();
				 int move_right();
				 int isSolved() const;
				 int find_blank_coordinat_x_new(int **arr);
				 int find_blank_coordinat_y_new(int **arr);
			 	 bool operator==(int ** ptr_2);
			 	 void print(Board2D c){
				 	cout << "AAAAAAAAAAAAAAAAAA";
				 	if(c==ptr){
				 		cout << "hello";
				 	}
				 	else{
				 		cout << "hey";
				 	}
				 }
			 	 int operator()(int y,int x){
				 	if(y>=line || y<0 || x>=coloun || x<0){
			 	 		return -1;
			 	 	}
			 	 	else{
			 	 		return ptr[y][x];	
			 	 	}	
			 	 }
				 
			 private :
			 		int ** goal_ptr;
			 		int **ptr;
					
		 };
#endif
