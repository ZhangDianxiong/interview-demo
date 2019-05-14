#include<iostream>
#include<string>
#include"IntrepidStudent.hpp"

using namespace std;

IntrepidStudent :: IntrepidStudent(){
  pg_skills=0;
}
IntrepidStudent :: ~IntrepidStudent(){}

void IntrepidStudent :: set_location(int rows,int cols){
  this->rows=rows;
  this->cols=cols;
}

char IntrepidStudent :: get_move(){
  char userch;
  cout<<"Please choose a direction for moving, 'W' for up; 'S' for down; 'A' for left; 'D' for right."<<endl;
  cout<<"And you can also choose to step into next level use 'U' or use 'P' to demo your programming skills."<<endl;
  cin>>userch;
  
  return userch;
}
    
int IntrepidStudent :: get_row(){
  return rows;
}

int IntrepidStudent :: get_col(){
  return cols;
}

void IntrepidStudent :: set_skills(int pg_skills){
  this->pg_skills=pg_skills;
}

int IntrepidStudent :: get_skills(){
  return pg_skills;
}