#include<iostream>
#include<string>
#include<exception>
#include"MazeLocation.hpp"
#include"Wall.hpp"
#include"OpenSpace.hpp"
#include"MazeLevel.hpp"
#include"Maze.hpp"
#include<fstream>
#include<cstdlib>
#include<vector>

using namespace std;

bool check_fun(char*);
/*****************************
Name: main function
Input: commend line argument
Output: NULL
To do: the starting of whole game.
******************************/
int main(int argc , char* argv[]){
  bool truth=false;
	if(argc==2){
    truth=check_fun(argv[1]);                                    //check user's commend line input, call the function to do the validation
	}else{
    cout<<"Too many or too less input arguments. "<<endl;
	}
  
  if(truth==true){
    ifstream file("maze.txt");
    if(file.fail()){
      cout<<"Fail to open the file. "<<endl;                     //if no such name fail in folder.
    }else{
      

        Maze game(file);                                           //construct the game 
        game.game_flow();                                          //call game flow function to start the game

    }
    
  }
  
}
/*****************************
Name: check function
Input: commend line argument
Output: NULL
To do: do the validation of 
the user's input.
******************************/
bool check_fun(char* arguement){
  if(string(arguement)=="maze.txt"){
    return true;
  }else{
    cout<<"No such file matched. "<<endl;                        //if input is not valided. 
    return false;
  }

}