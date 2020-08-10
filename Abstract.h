#ifndef ABSTRAC_H
#define ABSTRAC_H
#include<iostream>
#include<fstream>
#include<ctime>
#include<cstdlib>
#include<vector>
#include<string>
using namespace std;
class AbstractBoard {
		 	public:
				 // Defining the public functions ...
				 virtual void readFromFile(string name)=0; 
				 // virtual void writeToFile(string name)=0;
				 virtual void setSize(int y,int x)=0;
				 virtual void reset(int size)=0; //+
				 virtual void shuffle()=0; //+
				 virtual void print_goal()=0; //+
				 virtual void print() const=0; //+
				 virtual int move_up()=0; //+
				 virtual int move_left()=0; //+
				 virtual int move_down()=0; //+
				 virtual int move_right()=0; //+
				 virtual int isSolved() const=0; //+
				 static int NumberOfBoard();
				 bool operator==(AbstractBoard * compare){
					 	bool i=true;
					 	int k=0;
						int m=0;
						for(k=0;k<compare->line;k++){
				 			for(m=0;m<compare->coloun;m++){
						//		cout << "KEY -> " <<(*this)(k,m)<<"EM -> "<<(*compare)(k,m)<<endl;
								 if((*this)(k,m)!=(*compare)(k,m)){
								 		i=false;		
								 }
							}

						}
						return i;

				}

			 	 void print_hello(){
			 	 	cout << (2,1);
			 	 }
				
				 virtual int operator()(int y,int x)=0; 	 
				 char GetLastMove();
				 void move(char a);
				 AbstractBoard();
				 ~AbstractBoard();
			 protected :
			 		int line;
					int coloun;
					int count;
					static int number_of_board;
					char last_move;
};
#endif
