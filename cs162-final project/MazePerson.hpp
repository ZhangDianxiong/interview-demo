#include<iostream>
#include<string>

using namespace std;

#ifndef __MAZEPERSON_HPP
#define __MAZEPERSON_HPP
class MazePerson{                                              //base class for all derived classes include: TA, INtrepidStudet, Instructor.
  public:
    virtual char get_move()=0;
    virtual void set_location(int, int)=0;
    virtual int get_row()=0;
    virtual int get_col()=0;

};

#endif
