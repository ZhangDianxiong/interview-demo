#include<iostream>
#include<string>

using namespace std;

#ifndef __MAZELOCATION_HPP
#define __MAZELOCATION_HPP

class MazeLocation{                                      //base class for all derived classes include: wall and openspace 

	public:
		virtual bool is_occupiable()=0;                      //determine the block is occupiable or not 
		virtual char get_display_character()=0;              //return the display character 
   
    virtual bool has_explorer()=0;
    virtual void set_has_explorer(bool)=0;               //for student 
    
    virtual bool is_start()=0;
    virtual void set_is_start(bool)=0;                   //for start
    
    virtual bool is_end()=0;
    virtual void set_is_end(bool)=0;                     //for ladder
    
    virtual void set_is_instructor(bool)=0;
    virtual bool is_instructor()=0;                      //for instructor 
    
    virtual void set_is_ta(bool)=0;
    virtual bool is_ta()=0;                              //for TA 
    
    virtual void set_is_skill(bool)=0;
    virtual bool is_skill()=0;                           //for skills
};


#endif
      