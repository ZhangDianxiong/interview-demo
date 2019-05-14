#include<iostream>
#include<string>
#include"MazePerson.hpp"

using namespace std;

#ifndef __TA_HPP
#define __TA_HPP
class TA : public MazePerson{
  private:
    int rows;                                //different variable for TA class
    int cols;
    bool status;
    int term;
    bool satisfaction;
  public:
    TA();
    ~TA();
    char get_move();
    void set_location(int,int);             //accessor
    int get_row();
    int get_col();
    
    void set_status(bool);
    bool get_status();
                        
    void set_term(int);                     //mutator
    int get_term();
    
    void set_satisfaction(bool);
    bool get_satisfaction();


};

#endif