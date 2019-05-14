#include<iostream>
#include<string>
#include"MazeLocation.hpp"

using namespace std;

#ifndef __OPENSPACE_HPP
#define __OPENSPACE_HPP

class OpenSpace : public MazeLocation{
  private:
    bool player;                                  //memebr variables
    bool start;
    bool exit;
    
    bool instructor;
    bool ta;
    bool skill;
    
	public:
    OpenSpace();                                 //constructor
    ~OpenSpace();
		bool is_occupiable();
    char get_display_character();               //accessor
		void set_has_explorer(bool);
		bool has_explorer();
		
    void set_is_start(bool);
		bool is_start();
   
		void set_is_end(bool);                      //mutator
		bool is_end();
   
    void set_is_instructor(bool);
    bool is_instructor();
    
    void set_is_ta(bool);
    bool is_ta();
    
    void set_is_skill(bool);
    bool is_skill();
    
    
    
		

};

#endif
