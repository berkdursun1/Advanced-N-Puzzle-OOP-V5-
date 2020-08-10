#ifndef BOARDVECTOR_H
#define BOARDVECTOR_H
#include "abstrac.h"
class BoardVector : public AbstractBoard  {
		 	public:
				 // Defining the public functions ...
				 void setSize(int y,int x);
				 void readFromFile(string name); 
				 void writeToFile(string name);
				 void reset(int size); //+
				 void shuffle(); //+
				 void print_goal(); //+
				 void print() const; //+
				 int move_up(); //+
				 int move_left(); //+
				 int move_down(); //+
				 int move_right(); //+
				 int isSolved() const; //+
				 int find_blank_coordinat_x_new(vector<vector<int>> arr); //+
				 int find_blank_coordinat_y_new(vector<vector<int>> arr); //+
			 	 int operator()(int y,int x){
				 	if(y>=line || y<0 || x>=coloun || x<0){
			 	 		return -1;
			 	 	}
			 	 	else{
			 	 		return ptr[y][x];	
			 	 	}	
			 	 }

				 
			 private :
			 		vector<vector<int> > goal_ptr;
			 		vector<vector<int>> ptr;
					
};
#endif
