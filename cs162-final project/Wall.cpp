#include<iostream>
#include<string>
#include"Wall.hpp"

using namespace std;


bool Wall :: is_occupiable(){
	return false;
}

char Wall :: get_display_character(){                     //return '#' when called
	return '#';
}
