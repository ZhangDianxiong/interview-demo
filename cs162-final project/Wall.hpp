#include<iostream>
#include<string>
#include"MazeLocation.hpp"

using namespace std;


#ifndef __WALL_HPP
#define __WALL_HPP

class Wall : public MazeLocation{                              //wall class 

	public:
		bool is_occupiable();
		char get_display_character();
   
    virtual bool has_explorer(){};
    virtual void set_has_explorer(bool){};                      //uselless function because wall doesn't have so much buch of function 
    
    virtual bool is_start(){};
    virtual void set_is_start(bool){};
    
    virtual bool is_end(){};
    virtual void set_is_end(bool){};
    
    virtual void set_is_instructor(bool){};
    virtual bool is_instructor(){};
    
    virtual void set_is_ta(bool){};
    virtual bool is_ta(){};
    
    virtual void set_is_skill(bool){};
    virtual bool is_skill(){};
};

#endif
