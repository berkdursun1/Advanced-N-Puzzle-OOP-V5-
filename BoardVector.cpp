#include "boardvector.h"
void BoardVector :: setSize(int y,int x){
	line=y;
	coloun=x;
	reset(line);
}
int BoardVector::find_blank_coordinat_y_new(vector<vector<int>> arr){ 
	for(int i=0;i<line;i++){
		for(int k=0;k<coloun;k++){
			if(arr[i][k]==97){
				return i ;
			}
		}
	}
	return -1;
}
int BoardVector::find_blank_coordinat_x_new(vector<vector<int>> arr){ 
	for(int i=0;i<line;i++){
		for(int k=0;k<coloun;k++){
			if(arr[i][k]==97){
				return k ;
			}
		}
	}
	return -1;
}
void BoardVector::reset(int size){
	int i=0;
	int k=0;
	for(i=0;i<line;i++){
		ptr.push_back(vector<int>());
		goal_ptr.push_back(vector<int>());
		for(k=0;k<coloun;k++){
			ptr[i].push_back((i*size)+k+1);
			goal_ptr[i].push_back(ptr[i][k]);
		}
		for(k=k;k<9;k++){
			ptr[i].push_back(99);
			goal_ptr[i].push_back(ptr[i][k]);
		}
	}
	ptr[size-1][size-1]=97;
	goal_ptr[size-1][size-1]=97;
	for(i=i;i<9;i++){
		ptr.push_back(vector<int>());
		goal_ptr.push_back(vector<int>());
		for(k=0;k<9;k++){
			ptr[i].push_back(99);
			goal_ptr[i].push_back(ptr[i][k]);
		}
	}
}
void BoardVector::print()const{ // print the current configuration
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

int BoardVector::move_up(){

	int blank_coordinat_x;
	int blank_coordinat_y;
	for(int i=0;i<line;i++){
		for(int k=0;k<coloun;k++){
			if(ptr[i][k]==97){
				blank_coordinat_y=i;
				blank_coordinat_x=k;
			}
		}
	}
	
	if(blank_coordinat_y==0 || ptr[blank_coordinat_y-1][blank_coordinat_x]==0){
		return 99 ; // warning returning
	}
	else{
		ptr[blank_coordinat_y][blank_coordinat_x]=ptr[blank_coordinat_y-1][blank_coordinat_x];
		ptr[blank_coordinat_y-1][blank_coordinat_x]=97;
		return 1;  // true returning
		last_move='d';
	}
}
int BoardVector::move_left(){
	int blank_coordinat_x;
	int blank_coordinat_y;
	for(int i=0;i<line;i++){
		for(int k=0;k<coloun;k++){
			if(ptr[i][k]==97){
				blank_coordinat_y=i;
				blank_coordinat_x=k;
			}
		}
	}
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
int BoardVector::move_down(){
	int blank_coordinat_x;
	int blank_coordinat_y;
	for(int i=0;i<line;i++){
		for(int k=0;k<coloun;k++){
			if(ptr[i][k]==97){
				blank_coordinat_y=i;
				blank_coordinat_x=k;
			}
		}
	}
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
int BoardVector::move_right(){
	int blank_coordinat_x;
	int blank_coordinat_y;
	for(int i=0;i<line;i++){
		for(int k=0;k<coloun;k++){
			if(ptr[i][k]==97){
				blank_coordinat_y=i;
				blank_coordinat_x=k;
			}
		}
	}
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
void BoardVector::shuffle(){
	int blank_coordinat_x;
	int blank_coordinat_y;
	int random;
	int selection;
	int i;
	int last_move=-1;
	int number_of_move=(line+1)*(coloun+1);
	ptr=goal_ptr;
	for(i=0;i<number_of_move || isSolved()==1;i++){
		random=rand()%4;
		while((random==0 && (move_up()==99))
			|| (random==1 && (move_left()==99))
			|| (random==2 && (move_down()==99))
			|| (random==3 && (move_right()==99))){
			random=rand()%4;
		}
	}
}
int BoardVector::isSolved() const {
	int i,j;
	for(i=0;i<=line;i++){
		for(j=0;j<=coloun;j++){
			if(ptr[i][j]!=goal_ptr[i][j])
			{
				return 0;
			}
		}
	}
	return 1;
}
void BoardVector::print_goal(){ // print the goal state
	int i;
 	int k;
 	for(i=0;i<=line;i++){
	 	for(k=0;k<=coloun;k++){
		 	if(goal_ptr[i][k]!=99 && goal_ptr[i][k]!=95){
			 	if(goal_ptr[i][k]==97)
				 	cout << "\t" ;
			 	else{
				 	if(goal_ptr[i][k]<10)
					 	cout << "0" ;
				 	cout << "" << goal_ptr[i][k] << "\t";
			 	}
		 	}
	 	}
	 	cout << "\n" ;
 }
}

void BoardVector::readFromFile(string name){
  char first;
  char second;
  char point='0';
  int i=0;
  int m=0;
  int k=0;
  ifstream file;
  file.open(name);
  if(line!=0 || coloun!=0){
  	ptr.clear();
  }
  if(file.is_open()){
  	cout << file.eof();
  	point='0';
  	ptr.push_back(vector<int>());
	  	while(!file.eof()  && point!='\0' ){
		  	file.get(first); 
		  	file.get(second);
		  	file.get(point);
		  	
		  	if(first=='b' && second=='b'){
		  		ptr[i].push_back(97);
		  		m++;
		  	}	
		  	else{
		  		ptr[i].push_back((10*(first-'0'))+second-'0');
		  		m++;
		  		k++;
		  	}
		  	if(point=='\n'){
		  		if(i==0){
		  			coloun=k;
		  		}
		  		i++;
		  		ptr.push_back(vector<int>());
		  		m=0;
		  	}		  	
  		
  		}
 		line=i+1;	
  }
  i=0;
  m=0;
  	
}
