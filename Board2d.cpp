#include "board2d.h"
Board2D::~Board2D(){
	delete [] ptr;
}
bool Board2D :: operator==(int ** ptr_2){
	int i=0;
	bool result=true;
	int k=0;
	for(i=0;i<line;i++){
		for(k=0;k<coloun;k++){
			if(ptr[i][k]!=ptr_2[i][k]){
				result = false ;
			}
		}
	}
	return result ;
}
void Board2D :: setSize(int y,int x){
	int i;
	if(line!=0 || coloun !=0){
		delete [] ptr ;
		delete [] goal_ptr ;
	}
	line=y;
	coloun=x;

	// Allocation the memory 
	int **ptr_2=new int*[line];
	int **ptr_3=new int*[line];
	for(i=0;i<line;i++){
		ptr_2[i]=new int[coloun];
		ptr_3[i]=new int[coloun];
	}
	ptr=ptr_2;
	goal_ptr=ptr_3;
	reset(line);
}
int Board2D::find_blank_coordinat_y_new(int **arr){ 
	for(int i=0;i<line;i++){
		for(int k=0;k<coloun;k++){
			if(arr[i][k]==97){
				return i ;
			}
		}
	}
	return -1;
}
int Board2D::find_blank_coordinat_x_new(int **arr){ 
	for(int i=0;i<line;i++){
		for(int k=0;k<coloun;k++){
			if(arr[i][k]==97){
				return k ;
			}
		}
	}
	return -1;
}
void Board2D::reset(int size){
	int i=0;
	int k=0;
	
	for(i=0;i<line;i++){
		for(k=0;k<coloun;k++){
			ptr[i][k]=(i*size)+k+1;
			goal_ptr[i][k]=ptr[i][k];
		}	
	}
	goal_ptr[size-1][size-1]=97;
	ptr[size-1][size-1]=97;	
/*	copy_ptr(ptr,goal_ptr);*/
}
void Board2D::print()const{ // print the current configuration
	int i;
 	int k;
 	for(i=0;i<line;i++){
		for(k=0;k<coloun;k++){
				if(ptr[i][k]==97)
					cout << "\t" ;
				else{
					if(ptr[i][k]<10)
						cout << "0" ;
					cout << "" << ptr[i][k] << "\t";
				}
		}
	cout << "\n" ;
 	}
 	cout << "\n";
}
int Board2D::move_up(){
	int blank_coordinat_x=find_blank_coordinat_x_new(ptr);
	int blank_coordinat_y=find_blank_coordinat_y_new(ptr);
	if(blank_coordinat_y==0 || ptr[blank_coordinat_y-1][blank_coordinat_x]==0){
		return 99 ;
	}
	else{
		ptr[blank_coordinat_y][blank_coordinat_x]=ptr[blank_coordinat_y-1][blank_coordinat_x];
		ptr[blank_coordinat_y-1][blank_coordinat_x]=97;
		return 1;
		last_move='d';
	}
}
int Board2D::move_left(){
	int blank_coordinat_x=find_blank_coordinat_x_new(ptr);
	int blank_coordinat_y=find_blank_coordinat_y_new(ptr);
	if(blank_coordinat_x==0 || ptr[blank_coordinat_y][blank_coordinat_x-1]==0){
		return 99 ;
	}
	else{
		ptr[blank_coordinat_y][blank_coordinat_x]=ptr[blank_coordinat_y][blank_coordinat_x-1];
		ptr[blank_coordinat_y][blank_coordinat_x-1]=97;
		return 1;
		last_move='r';
	}
}
int Board2D::move_down(){
	int blank_coordinat_x=find_blank_coordinat_x_new(ptr);
	int blank_coordinat_y=find_blank_coordinat_y_new(ptr);
	if(blank_coordinat_y==line-1 || ptr[blank_coordinat_y+1][blank_coordinat_x]==0){
		return 99 ;
	}
	else{
		ptr[blank_coordinat_y][blank_coordinat_x]=ptr[blank_coordinat_y+1][blank_coordinat_x];
		ptr[blank_coordinat_y+1][blank_coordinat_x]=97;
		return 1;
		last_move='u';
	}
}
int Board2D::move_right(){
	int blank_coordinat_x=find_blank_coordinat_x_new(ptr);
	int blank_coordinat_y=find_blank_coordinat_y_new(ptr);
	if(blank_coordinat_x==coloun-1 || ptr[blank_coordinat_y][blank_coordinat_x+1]==0){
		return 99 ;
	}
	else{
		ptr[blank_coordinat_y][blank_coordinat_x]=ptr[blank_coordinat_y][blank_coordinat_x+1];
		ptr[blank_coordinat_y][blank_coordinat_x+1]=97;
		return 1;
		last_move='l';
	}
}
void Board2D::shuffle(){
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
int Board2D::isSolved() const {
	int i,j;
	for(i=0;i<line;i++){
		for(j=0;j<coloun;j++){
			cout << ptr[i][j] << "-" << goal_ptr[i][j] << endl;
			if(ptr[i][j]!=goal_ptr[i][j])
			{
				return 0;
			}
		}
	}
	return 1;
}
void Board2D::print_goal(){ // print the goal state
	int i;
 	int k;
 	for(i=0;i<line;i++){
	 	for(k=0;k<coloun;k++){
		 	 	if(goal_ptr[i][k]==97)
				 	cout << "\t" ;
			 	else{
				 	if(goal_ptr[i][k]<10)
					 	cout << "0" ;
				 	cout << "" << goal_ptr[i][k] << "\t";
			 	}
	 	}
	 	cout << "\n" ;
 	}
}
void Board2D::readFromFile(string name){
  char first;
  char second;
  char point='0';
  int i=0;
  int m=0;
  int k=0;
  int ptr_2[9][9];
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
		  		ptr_2[i][m]=97;
		  		m++;
		  	}	
		  	else{
		  		ptr_2[i][m]=(10*(first-'0'))+second-'0';
		  		m++;
		  		k++;
		  	}
		  	if(point=='\n'){
		  		if(i==0){
		  			coloun=k;
		  		}
		  		i++;
		  		m=0;
		  	}		  	
  		
  		}
 		line=i+1;
  	int **ptr_3=new int*[line];
	for(i=0;i<line;i++){
		ptr_3[i]=new int[coloun];
	}
	ptr=ptr_3;	
  }
  i=0;
  m=0;
  for(i=0;i<line;i++){
  	for(m=0;m<coloun;m++){
  		
  		ptr[i][m]=ptr_2[i][m];
  	}
  }	
}
