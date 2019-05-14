#include<iostream>
#include<string>
#include<string.h>
#include<fstream>
#include"MazeLevel.hpp"

using namespace std;
/*****************************
Name: default constructor of Maze
Input: NULL
Output: NULL
To do: construct the maze object
******************************/
MazeLevel :: MazeLevel(){

}
/*****************************
Name: nondefault constructor
Input: ifstream,int,int
Output: NULL
To do: construct the object.
******************************/
MazeLevel :: MazeLevel(ifstream& infile,int rows,int cols){
  set_rows(rows);
  set_cols(cols);
  
  for(int i=0;i<rows;i++){
    locations.push_back(vector<MazeLocation*>(cols));                              //construct 2-D level of mazelayer and call function for initialization.
  }
  initialization_fun(infile);
  
}
/*****************************
Name: destructor
Input: NULL
Output: NULL
To do: destruct the object.
******************************/
MazeLevel :: ~MazeLevel(){
  for(int i=0;i<get_rows();i++){
    for(int j=0;j<get_cols();j++){
      locations[i][j]->~MazeLocation();                                           //delete the 2-D layer. 
      delete locations[i][j];
    }
  }
}
/*****************************
Name: set_rows
Input: int
Output: NULL
To do: assign rows
******************************/
void  MazeLevel :: set_rows(int rows){
  this->rows=rows;
}
/*****************************
Name: set_cols
Input: int
Output: NULL
To do: assign cols
******************************/
void  MazeLevel:: set_cols(int cols){
  this->cols=cols;
}
/*****************************
Name: get_rows
Input: NULL
Output: int
To do: get rows
******************************/    
int MazeLevel :: get_rows(){
  return rows;
}
/*****************************
Name: get_cols
Input: NULL
Output: int
To do: get cols
******************************/   
int MazeLevel :: get_cols(){
  return cols;
}
/*****************************
Name: initialization function
Input: ifstream
Output: null
To do: Initial the grid of 
2-D maze.
******************************/   
void MazeLevel :: initialization_fun(ifstream& infile){
  char sigCH;  
  
  for(int i=0;i<get_rows();i++){
    for(int j=0;j<get_cols()+1;j++){                                        //read through the whole txt file and assign them to maze grid.
      infile.get(sigCH);
      if(sigCH=='#')
        locations[i][j]=new Wall;
      else if(sigCH=='@'){
        locations[i][j]=new OpenSpace;
        locations[i][j]->set_is_start(true);
      }
      else if(sigCH=='^'){
        locations[i][j]=new OpenSpace;
        locations[i][j]->set_is_end(true);
      }
      else if(sigCH=='%'){
        locations[i][j]=new OpenSpace;
        locations[i][j]->set_is_instructor(true);
      }
      else if(sigCH=='T'){
        locations[i][j]=new OpenSpace;
        locations[i][j]->set_is_ta(true);
      }      
      else if(sigCH=='*'){
        locations[i][j]=new OpenSpace;
        locations[i][j]->set_has_explorer(true);
      }
      else if(sigCH=='$'){
        locations[i][j]=new OpenSpace;
        locations[i][j]->set_is_skill(true);
      }
      else if(sigCH==' '){
        locations[i][j]=new OpenSpace;
      }

    
    }
  
  }

}

/*****************************
Name: get_location
Input: int,int
Output: NULL
To do: get specific maze location.
******************************/   
MazeLocation* MazeLevel :: get_location(int rows,int cols){
  return locations[rows][cols];

}

