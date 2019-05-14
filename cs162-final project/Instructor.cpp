#include<iostream>
#include<string>
#include"Instructor.hpp"

using namespace std;
Instructor :: Instructor(){
}

Instructor :: ~Instructor(){}

char Instructor :: get_move(){
  return ')' ;//means didn't monve
}

void Instructor :: set_location(int rows,int cols){
  this->rows=rows;
  this->cols=cols;
}

void Instructor :: set_satisfaction(bool satisfaction){
  this->satisfaction=satisfaction;
}

int Instructor :: get_row(){
  return rows;
}

int Instructor :: get_col(){
  return cols;
}

bool Instructor :: get_satisfaction(){
  return satisfaction;
}