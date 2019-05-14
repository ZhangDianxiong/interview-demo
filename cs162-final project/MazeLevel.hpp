#include<iostream>
#include<string>
#include<vector>
#include"OpenSpace.hpp"
#include"Wall.hpp"

using namespace std;

#ifndef __MAZELEVEL_HPP
#define __MAZELEVEL_HPP
class  MazeLevel{
  private:
    vector<vector<MazeLocation*> >locations;              //vector for 2-D maze grid.
    int rows;
    int cols;
  public:
    MazeLevel();
    MazeLevel(ifstream&,int rows,int cols);               //constructor
    ~MazeLevel();
    void  set_rows(int);
    void  set_cols(int);
    
    int get_rows();
    int get_cols();
    
    void initialization_fun(ifstream&);
    
    MazeLocation* get_location(int,int);                 //get location


};


#endif