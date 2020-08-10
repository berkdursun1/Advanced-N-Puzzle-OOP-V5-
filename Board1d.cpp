#include "board1d.h"
Board1D::~Board1D(){
	delete [] ptr;
}
void Board1D :: setSize(int y,int x){
	if(line!=0 || coloun!=0){
		delete [] ptr ;
		delete [] goal_ptr ;
	}
	line=y;
	coloun=x;
	ptr=new int(line*coloun);
	goal_ptr=new int(line*coloun);
	reset(line);
}		 
// find the blank y coordinat 


int Board1D::find_blank_coordinat_y_new(int *arr){ 
	for(int i=0;i<line*coloun;i++){
		if(arr[i]==97){
			return (i/line);
		}
	}
	return -1;
}
// find the blank x coordinat


int Board1D::find_blank_coordinat_x_new(int *arr){ 
	for(int i=0;i<line*coloun;i++){
		if(arr[i]==97){
			return (i%coloun);
		}
	}
	return -1;
}


void Board1D::reset(int size){	
	int i;
	for(int i=0;i<line*coloun;i++){
		ptr[i]=i+1;
		goal_ptr[i]=i+1;	
	}
	goal_ptr[(line*coloun)-1]=97;
	ptr[(line*coloun)-1]=97;	
}


void Board1D::print()const{ // print the current configuration
	int i;
 	int k;
 	for(i=0;i<line*coloun;i++){
			if(i%coloun==0 && i!=0){
				cout << "\n";
			}
			if(ptr[i]==97)
				cout << "\t" ;
			else{
				if(ptr[i]<10)
					cout << "0" ;
				cout << "" << ptr[i] << "\t";
			}	
 	}
 	cout << "\n";
}
int Board1D::move_up(){
	int blank_coordinat_x=find_blank_coordinat_x_new(ptr);
	int blank_coordinat_y=find_blank_coordinat_y_new(ptr);
	if(blank_coordinat_y==0 || ptr[((blank_coordinat_y*coloun)+blank_coordinat_x)-coloun]==0){
		return 99 ;
	}
	else{
		ptr[((blank_coordinat_y*coloun)+blank_coordinat_x)]=ptr[((blank_coordinat_y*coloun)+blank_coordinat_x)-coloun];
		ptr[((blank_coordinat_y*coloun)+blank_coordinat_x)-coloun]=97;
		return 1;
		last_move='d';
	}
}

int Board1D::move_left(){
	int blank_coordinat_x=find_blank_coordinat_x_new(ptr);
	int blank_coordinat_y=find_blank_coordinat_y_new(ptr);
	if(blank_coordinat_x==0 || ptr[((blank_coordinat_y*coloun)+blank_coordinat_x)-1]==0){
		return 99 ;
	}
	else{
		ptr[((blank_coordinat_y*coloun)+blank_coordinat_x)]=ptr[((blank_coordinat_y*coloun)+blank_coordinat_x)-1];
		ptr[((blank_coordinat_y*coloun)+blank_coordinat_x)-1]=97;
		return 1;
		last_move='r';
	}
}


int Board1D::move_down(){
	int blank_coordinat_x=find_blank_coordinat_x_new(ptr);
	int blank_coordinat_y=find_blank_coordinat_y_new(ptr);
	if(blank_coordinat_y==line-1 || ptr[((blank_coordinat_y*coloun)+blank_coordinat_x)+coloun]==0){
		return 99 ;
	}
	else{
		ptr[((blank_coordinat_y*coloun)+blank_coordinat_x)]=ptr[((blank_coordinat_y*coloun)+blank_coordinat_x)+coloun];
		ptr[((blank_coordinat_y*coloun)+blank_coordinat_x)+coloun]=97;
		return 1;
		last_move='u';
	}
}


int Board1D::move_right(){
	int blank_coordinat_x=find_blank_coordinat_x_new(ptr);
	int blank_coordinat_y=find_blank_coordinat_y_new(ptr);
	if(blank_coordinat_x==coloun-1 || ptr[((blank_coordinat_y*coloun)+blank_coordinat_x)+1]==0){
		return 99 ;
	}
	else{
		ptr[((blank_coordinat_y*coloun)+blank_coordinat_x)]=ptr[((blank_coordinat_y*coloun)+blank_coordinat_x)+1];
		ptr[((blank_coordinat_y*coloun)+blank_coordinat_x)+1]=97;
		return 1;
		last_move='l';
	}
}


void Board1D::shuffle(){
	int blank_coordinat_x;
	int blank_coordinat_y;
	int random;
	int selection;
	int i;
	int last_move=-1;
	int number_of_move=(line+1)*(coloun+1);
		
	for(i=0;i<number_of_move;i++){
		random=rand()%4;
		while((random==0 && (move_up()==99))
			|| (random==1 && (move_left()==99))
			|| (random==2 && (move_down()==99))
			|| (random==3 && (move_right()==99))){
			random=rand()%4;
		}
	}
}





int Board1D::isSolved() const {
	int i;
	for(i=0;i<line*coloun;i++){
			if(ptr[i]!=goal_ptr[i])
			{
				return 0;
			}
	}
	return 1;
}


void Board1D::print_goal(){ // print the goal state
	int i;
 	int k;
 	for(i=0;i<line;i++){
 				if(i%coloun==0 && i!=0){
 					cout << "\n";
 				}
	 	 	 	else if(goal_ptr[i]==97)
				 	cout << "\t" ;
			 	else{
				 	if(goal_ptr[i]<10)
					 	cout << "0" ;
				 	cout << "" << goal_ptr[i] << "\t";
			 	}
	 	
 	}
}
void Board1D::readFromFile(string name){
  char first;
  char second;
  char point='0';
  int i=0;
  int k=0;
  int m=0;
  int ptr_2[81];
  ifstream file;
  file.open(name);
  if(line !=0 || coloun !=0 ){
  	delete [] ptr ;
  }
  if(file.is_open()){
  	point='0';
	  	while(!file.eof()  && point!='\0' ){
		  	file.get(first); 
		  	file.get(second);
		  	file.get(point);
		  	
		  	if(first=='b' && second=='b'){
		  		ptr_2[i]=97;
		  		i++;
		  	}	
		  	else{
		  		ptr_2[i]=(10*(first-'0'))+second-'0';
		  		i++;
		  		k++;
		  	}
		  	if(point=='\n'){
		  		if(m==0){
		  			coloun=i;
		  		}
		  		m++;
		  	}		  	
  		}
 		line=m+1;
  	int *ptr_3=new int[line*coloun];
	ptr=ptr_3;	
  }
  i=0;
  m=0;
  for(i=0;i<line*coloun;i++){
  		ptr[i]=ptr_2[i];
  }	
}
