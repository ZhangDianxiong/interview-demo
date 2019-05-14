#include<iostream>
#include<string>
#include"MazePerson.hpp"

using namespace std;

#ifndef __INSTRUCTOR_HPP
#define __INSTRUCTOR_HPP
class Instructor : public MazePerson{
  private:
    int rows;
    int cols;
    bool satisfaction;
  public:
    Instructor();
    ~Instructor();
    char get_move();
    void set_location(int,int);
    int get_row();
    int get_col();

    void set_satisfaction(bool);
    bool get_satisfaction();
};

#endif