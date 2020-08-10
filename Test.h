#ifndef MAIN_H
#define MAIN_H
#include "boardvector.cpp"
#include "board2d.cpp"
#include "board1d.cpp"
#include "abstrac.cpp"
using namespace std;
bool global_function(int size,AbstractBoard * sequence[]){
	bool f=true;
	int i=0;
	int k=0;
	int t=0;
	sequence[i]->print();
		while(i<size-1){
			t=0;
			sequence[i+1]->print();
			if(sequence[i]->move_up()==1){
				if(*sequence[i]==sequence[i+1]){
					cout << "UP\n";
					t=1;
				}
				sequence[i]->move_down();	
			}
			if(sequence[i]->move_left()==1){
				if(*sequence[i]==sequence[i+1]){
					cout << "LEFT\n";
					t=1;
				}
				sequence[i]->move_right();	
			}
			if(sequence[i]->move_down()==1){
				if(*sequence[i]==sequence[i+1]){
					cout << "DOWN\n";
					t=1;
				}
				sequence[i]->move_up();	
			}
			if(sequence[i]->move_right()==1){
				if(*sequence[i]==sequence[i+1]){
					cout << "RIGHT\n";
					t=1;
				}
				sequence[i]->move_left();	
			}
			if(t==0){
				f=false;
			}
			i++;
		}	
	return f;
}
void test_function(){
	char way;
	int selec;
	int x;
	int y;
	int size;
	BoardVector TryVector ; // trying Vector 
	Board1D Tryonedimensional ; // trying 1d
	Board2D Trytwodimensional ; // trying 2d
	AbstractBoard * TryAbstract[3] ; //trying abstract
	// Assign address
	TryAbstract[0]=&TryVector; // Vectorr
	TryAbstract[1]=&Trytwodimensional;
	TryAbstract[2]=&Tryonedimensional;
	TryAbstract[0]->setSize(3,3);
	TryAbstract[1]->setSize(3,3);
	TryAbstract[2]->setSize(3,3);
	
	
	cout << "----------------------- \nGlobal function(valid move)\n";
	
	TryAbstract[2]->move_up();
	TryAbstract[2]->move_left();
	TryAbstract[1]->move_up();
	if(global_function(3,TryAbstract)==1){
		cout << "Valid\n";
	}
	else{
		cout << "Invalid\n";
	}
	cout << "----------------------- \nGlobal function(invalid move)\n";
	TryAbstract[2]->move_up();
	if(global_function(3,TryAbstract)==1){
		cout << "Valid\n";
	}
	else{
		cout << "Invalid\n";
	}
	// back to start stuation 
	TryAbstract[2]->move_down();
	TryAbstract[2]->move_right();
	TryAbstract[1]->move_down();
	TryAbstract[2]->move_down();


 	
	cout << "-----------------------\nPrinting \n" ;
	cout << "Vector printing ... \n" ;
	TryAbstract[0]->print();
	cout << "1D printing ... \n" ;
	TryAbstract[1]->print(); 
	cout << "2D printing ... \n" ;
	TryAbstract[2]->print();
		
	cout << "-----------------------\nInvalid Move right...\n";
	cout << "Vector ...\n";
	TryAbstract[0]->move_right();
	TryAbstract[0]->print();
	cout << "1D ...\n";
	TryAbstract[1]->move_right();
	TryAbstract[1]->print();
	cout << "2D ...\n";
	TryAbstract[2]->move_right();
	TryAbstract[2]->print();  




	cout << "-----------------------\nMove Left \n";
	cout << "Vector moving left ... \n";
	TryAbstract[0]->move_left();
	TryAbstract[0]->print();
	cout << "1D moving left ... \n";
	TryAbstract[1]->move_left();
	TryAbstract[1]->print();
 	cout << "2D moving left ... \n";
	TryAbstract[2]->move_left();
	TryAbstract[2]->print();
 	
	cout << "-----------------------\nMove Up \n";
	cout << "Vector moving up ... \n";
	TryAbstract[0]->move_up();
	TryAbstract[0]->print();
	cout << "1D moving up ... \n";
	TryAbstract[1]->move_up();
	TryAbstract[1]->print();
 	cout << "2D moving up ... \n";
	TryAbstract[2]->move_up();
	TryAbstract[2]->print();	

	cout << "-----------------------\nMove Right \n";
	cout << "Vector moving right ... \n";
	TryAbstract[0]->move_right();
	TryAbstract[0]->print();
	cout << "1D moving right ... \n";
	TryAbstract[1]->move_right();
	TryAbstract[1]->print();
 	cout << "2D moving right ... \n";
	TryAbstract[2]->move_right();
	TryAbstract[2]->print();


	cout << "-----------------------\nMove Down \n";
	cout << "Vector moving down ... \n";
	TryAbstract[0]->move_down();
	TryAbstract[0]->print();
	cout << "1D moving down ... \n";
	TryAbstract[1]->move_down();
	TryAbstract[1]->print();
 	cout << "2D moving down ... \n";
	TryAbstract[2]->move_down();
	TryAbstract[2]->print();

	cout << "-----------------------\nShuffle \n";
	cout << "Vector shuffling ... \n";
	TryAbstract[0]->shuffle();
	TryAbstract[0]->print();
	cout << "1D shuffling ... \n";
	TryAbstract[1]->shuffle();
	TryAbstract[1]->print();
 	cout << "2D shuffling ... \n";
	TryAbstract[2]->shuffle();
	TryAbstract[2]->print();

	cout << "-----------------------\nRead From File \n";
	cout << "Vector reading ... \n";
	TryAbstract[0]->readFromFile("dosya.txt");
	TryAbstract[0]->print();
	cout << "1D reading ... \n";
	TryAbstract[1]->readFromFile("dosya.txt");
	TryAbstract[1]->print();
 	cout << "2D reading ... \n";
	TryAbstract[2]->readFromFile("dosya.txt");
	TryAbstract[2]->print();	

	cout << "----------------------- \nTrying () operator \n";
	cout << "Please Enter Coordinate for x : ";
	cin >> x ;
	cout << "Please Enter Coordinate for y : "; 
	cin >> y ;
	cout << "Operator for vector ... " << (*TryAbstract[0])(x,y) << endl;
	cout << "Operator for one dimensional ... " << (*TryAbstract[1])(x,y) << endl; 
	cout << "Operator for two dimensional ... " << (*TryAbstract[2])(x,y) << endl; 
	
	cout << "----------------------- \n== Operator \n";
	if((*TryAbstract[0])==TryAbstract[2]){
		cout << "Vector and two is equal" << endl ;
	}
	cout << "----------------------- \nIs solved ...\n";
	cout << "----------------------- \nFor Vector\n ";
	if(TryAbstract[0]->isSolved()==1){
		cout << "Solved\n";
	}
	else{
		cout << "Unsolved\n";
	}
	cout << "----------------------- \nFor One dimensional \n";
	if(TryAbstract[1]->isSolved()==1){
		cout << "Solved\n";
	}
	else{
		cout << "Unsolved\n";
	}
	cout << "---------------------- \nFor Two dimensional \n";
	if(TryAbstract[2]->isSolved()==1){
		cout << "Solved\n";
	}
	else{
		cout << "Unsolved\n";
	}
	cout << "---------------------- \nNumber of board ";
	cout << AbstractBoard::NumberOfBoard() << endl ;
	


	

}
#endif
