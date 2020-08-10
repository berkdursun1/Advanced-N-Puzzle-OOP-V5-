#ifndef BOARD1D_H
#define BOARD1D_H
#include "abstrac.h"
class Board1D  : public AbstractBoard{
		public:
				 ~Board1D();
				 // Defining the public functions ...
			     void readFromFile(string name);
			     void print_goal();
			     int isSolved() const ;;
				 void shuffle();
				 int move_up();
				 int move_left();
				 int move_right();
				 int move_down();
				 void print()const ;
				 void reset(int size);
				 int find_blank_coordinat_x_new(int *arr);
				 int find_blank_coordinat_y_new(int *arr);
				 void setSize(int y,int x);
			 	 int operator()(int y,int x){
				 	if(y>=line || y<0 || x>=coloun || x<0){
			 	 		return -1;
			 	 	}
			 	 	else{
			 	 		return ptr[(y*coloun)+x];	
			 	 	}	
			 	 }
			 private :
			 		int * goal_ptr;
			 		int * ptr;
					
		 };
#endif
