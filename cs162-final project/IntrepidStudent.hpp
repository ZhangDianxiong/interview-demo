#include<iostream>
#include<string>
#include"MazePerson.hpp"

using namespace std;

#ifndef __INTREPIDSTUDENT_HPP
#define __INTREPIDSTUDENT_HPP
class IntrepidStudent : public MazePerson{
  private:
    int rows;
    int cols;
    int pg_skills;
  public:
    IntrepidStudent();
    ~IntrepidStudent();
    void set_location(int,int);
    char get_move();
    
    int get_row();
    int get_col();
    
    void set_skills(int);
    int get_skills();


};

#endif