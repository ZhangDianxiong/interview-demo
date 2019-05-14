#include<iostream>
#include<string>
#include"MazeLocation.hpp"
#include"MazePerson.hpp"
#include"MazeLevel.hpp"
#include"Wall.hpp"
#include"OpenSpace.hpp"
#include"IntrepidStudent.hpp"
#include"TA.hpp"
#include"Instructor.hpp"

using namespace std;

#ifndef __MAZE_HPP
#define __MAZE_HPP
class Maze{
  private:
    int layer;
    int rows;
    int cols;
    int nm_skills;
    int appearent_level;
    vector<MazeLevel*> mazelayer;
    vector<TA*> TAs;
    IntrepidStudent* stu;
    Instructor* Robin;
    bool win;
  public:
    Maze(ifstream&);                                                //constructor
    ~Maze();
    void set_maze_size(int,int,int);                              
    void set_nm_skills(int);
    void set_appearent_level(int);
    void construct_grid(ifstream&);                                 //allocator
    void construct_TA();
    void destruct_TA();
    int set_student();
    int set_Instructor();
    void set_skills();
    
    int get_layer();                                                //getter
    int get_rows();
    int get_cols();
    int get_nm_skills();
    int get_appearent_level();
    vector<MazeLevel* >* get_mazeLayer();
    vector<TA*>* get_TA();
    IntrepidStudent* get_intrepidstudent();
    Instructor* get_instructor();
    
    void print_maze();                                              //game function 
    void print_status();
    void game_flow();
    bool moving_validation(char);
    void execute_move(char);
    
    void TA_move();
    bool TA_validation(char,int);
    void TA_move_exe(char,int);
    
    bool scan_TA(int*,int*);
    void checkout_TA_status();
    void checkout_position();
    
    void set_win(bool);
    bool get_win();
    bool scan_Instructor();
    
    bool check_win();
    
};

#endif