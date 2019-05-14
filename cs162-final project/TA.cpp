#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include"TA.hpp"

using namespace std;
/*****************************
Name: constructor of TA 
Input: NULL
Output: NULL
To do: constructor of TA
******************************/ 
TA :: TA(){
  set_status(false);
  set_satisfaction(false);
  set_term(0);
}
/*****************************
Name: destructor of TA
Input: NULL
Output: NULL
To do: destructorof TA
******************************/ 
TA :: ~TA(){}

/*****************************
Name: get move
Input: NULL
Output: char
To do: get move 
******************************/ 
char TA :: get_move(){
  int TAch;
  TAch=random()%+4;                                                      //randomly get a direction for moving 
  
  if(TAch==0){                                                  
    cout<<"TA moving direction: W "<<endl;                               //return character
    return 'W';
  }
  
  else if(TAch==1){
    cout<<"TA moving direction: S "<<endl;
    return 'S';
  }  
  
  else if(TAch==2){
    cout<<"TA moving direction: A "<<endl;
    return 'A';
  }
  
  else if(TAch==3){
    cout<<"TA moving direction: D "<<endl;
    return 'D';
  }
  
  else 
    cout<<"No available moving direction. "<<endl;


}

/*****************************
Name: set location
Input: int,int
Output: NULL
To do: set location
******************************/ 
void TA :: set_location(int rows,int cols){
  this->rows=rows;
  this->cols=cols;
}
/*****************************
Name: get row
Input: NULL
Output: TA
To do: get row
******************************/ 
int TA :: get_row(){
  return rows;
}
/*****************************
Name: get col
Input: NULL
Output: TA
To do: get col
******************************/ 
int TA :: get_col(){
  return cols;
}
/*****************************
Name: set status
Input: bool
Output: NULL
To do: set status
******************************/     
void TA :: set_status(bool status){
  this->status=status;
}
/*****************************
Name: get status
Input: NULL
Output: bool
To do: get status
******************************/ 
bool TA :: get_status(){
  return status;
}
/*****************************
Name: set term
Input: int
Output: NULL
To do: set term
******************************/     
void TA :: set_term(int term){
  this->term=term;
}
/*****************************
Name: get term
Input: NULL
Output: int
To do: get term
******************************/ 
int TA :: get_term(){
  return term;
}
/*****************************
Name: set satisfaction
Input: bool
Output: NULL
To do: set satisfaction
******************************/     
void TA :: set_satisfaction(bool satisfaction){
  this->satisfaction=satisfaction;
}    
/*****************************
Name: set satisfaction
Input: NULL
Output: bool
To do: set satisfaction
******************************/ 
bool TA :: get_satisfaction(){
  return satisfaction;
}
    
    
    
    
    
    
    
    
    
    
    
    
    