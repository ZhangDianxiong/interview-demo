#include<iostream>
#include<string>
#include"OpenSpace.hpp"

using namespace std;
/*****************************
Name: constructor of openspace 
Input: NULL
Output: NULL
To do: constructor of openspace
******************************/ 
OpenSpace :: OpenSpace(){
    player=false;
    start=false;
    exit=false;
    
    instructor=false;
    ta=false;
    skill=false;
}
/*****************************
Name: destructor of openspace 
Input: NULL
Output: NULL
To do: destructor of openspace
******************************/ 
OpenSpace :: ~OpenSpace(){

}
/*****************************
Name: is occupiable 
Input: NULL
Output: bool
To do: validate the block is 
occupiable or not
******************************/ 
bool OpenSpace :: is_occupiable(){
	return true;
}
/*****************************
Name: set has explorer 
Input: bool
Output: NULL
To do: set has explorer
******************************/ 
void OpenSpace :: set_has_explorer(bool player){
  this->player=player;
}
/*****************************
Name: has explorer 
Input: NULL
Output: bool
To do: has explorer
******************************/ 
bool OpenSpace :: has_explorer(){
  return player;
}
/*****************************
Name: set is start
Input: bool
Output: NULL
To do: set is start
******************************/ 
void OpenSpace :: set_is_start(bool start){
  this->start=start;
}
/*****************************
Name: is atart
Input: NULL
Output: bool
To do: cis start
******************************/ 
bool OpenSpace :: is_start(){
  return start;
}
/*****************************
Name: set is end 
Input: bool
Output: NULL
To do: set is end
******************************/ 
void OpenSpace :: set_is_end(bool exit){
  this->exit=exit;
}
/*****************************
Name: is end 
Input: NULL
Output: bool
To do: is end
******************************/ 
bool OpenSpace :: is_end(){
  return exit;
}
/*****************************
Name: set is instructor
Input: bool
Output: NULL
To do: cset is instructor
******************************/ 
void OpenSpace :: set_is_instructor(bool instructor){
  this->instructor=instructor;
}
/*****************************
Name: is instructor 
Input: NULL
Output: bool
To do: is instructor
******************************/ 
bool OpenSpace :: is_instructor(){
  return instructor;
}
/*****************************
Name: set is ta
Input: bool
Output: NULL
To do: set is ta
******************************/     
void OpenSpace :: set_is_ta(bool ta){
  this->ta=ta;
}
/*****************************
Name: is_ta
Input: NULL
Output: bool
To do: is_ta
******************************/ 
bool OpenSpace :: is_ta(){
  return ta;
}
/*****************************
Name: set is skill 
Input: NULL
Output: bool
To do: set is skill
******************************/     
void OpenSpace :: set_is_skill(bool skill){
  this->skill=skill;
}
/*****************************
Name: is skill 
Input: NULL
Output: bool
To do: is skill
******************************/ 
bool OpenSpace :: is_skill(){
  return skill;
}
/*****************************
Name: get_display_character 
Input: char
Output: NULL
To do: get_display_character
******************************/ 
char OpenSpace :: get_display_character(){

  if(player==true)
    return '*';
  else if(exit==true)
    return '^';
  else if(instructor==true)
    return '%';
  else if(ta==true)
    return 'T';
  else if(skill==true)
    return '$';
  else if(start==true)
    return '@';
  else
    return ' ';
}




