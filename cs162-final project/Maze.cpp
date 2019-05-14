#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<ctime>
#include<cstdlib>
#include"Maze.hpp"

using namespace std;
/*****************************
Name: nondefault constructor of maze
Input: ifilestream
Output: NULL
To do: construct the maze object.
******************************/   
Maze :: Maze(ifstream& input){
  int layer,rows,cols;
  input>>layer>>rows>>cols;
  set_maze_size(layer,rows,cols);                                //assign different number to memeber variable.
  set_nm_skills(9);                                              //set number of skill
  set_appearent_level(0);                                        //set level where user stand on
  construct_grid(input);
  
  set_win(true);                                                 //set game status.
  
  for(int j=0;j<2;j++){
    TAs.push_back(new TA);                                       //construct TA vector
  }/*
  for(int k=0;k<2;k++){
    TAs[k]=new TA;
  }*/
  construct_TA();
  
  stu=new IntrepidStudent;                                       //consstruct student and instructor 
  set_student();
  
  Robin=new Instructor;
  set_Instructor();
  
  set_skills();
  
  
}

/*****************************
Name: set_maze_size
Input: int, int, int
Output: NULL
To do: set the whole maze size.
******************************/   
void Maze :: set_maze_size(int layer,int rows,int cols){
  this->layer=layer;
  this->rows=rows;
  this->cols=cols;

}
/*****************************
Name: set_nm_skills
Input: int
Output: NULL
To do: set number of skills
******************************/
void Maze :: set_nm_skills(int nm_skills){
  this->nm_skills=nm_skills;
}
/*****************************
Name: set_appearent level
Input: int
Output: NULL
To do: set appearent level
******************************/   
void Maze :: set_appearent_level(int appearent_level){
  this->appearent_level=appearent_level;
}
/*****************************
Name: construct_grid
Input: ifstream
Output: NULL
To do: construct a grid
******************************/   
void Maze :: construct_grid(ifstream& input){
  char t;
  input.get(t);
  
  for(int i=0;i<get_layer();i++){
    mazelayer.push_back(new MazeLevel(input,get_rows(),get_cols()));
  }
  
  input.close();
}
/*****************************
Name: sconstruct TA
Input: NULL
Output: NULL
To do: construct TA
******************************/   
void Maze :: construct_TA(){
  int level=get_appearent_level();

  srand(time(NULL));
  MazeLevel* mz1=(*get_mazeLayer())[level];
  
  for(int p=0;p<2;p++){                                                                //randomly generate a location for allocate TA
    bool truth=true;                                                                
    do{
      int y=random()%+get_rows();
      int x=random()%+get_cols();
      if(mz1->get_location(y,x)->get_display_character()==' '){                        //do the validation of random location, if is empty space that's available for allocating 
        mz1->get_location(y,x)->set_is_ta(true);
        TAs[p]->set_location(y,x);
        truth=false;
      }
  
    }while(truth);
  }
}
/*****************************
Name: destruct_TA
Input: NULL
Output: NULL
To do: destruct TA's class. 
******************************/   
void Maze :: destruct_TA(){                                              
  for(int i=0;i<2;i++){
    delete TAs[i];
  }

}

/*****************************
Name: set_student 
Input: NULL
Output: NULL
To do: set student
******************************/   
int Maze :: set_student(){

  int level=get_appearent_level();
  MazeLevel* mz1=(*get_mazeLayer())[level];
  
  for(int i=0;i<get_rows();i++){
    for(int j=0;j<get_cols();j++){
      if(mz1->get_location(i,j)->get_display_character()=='@'){                            //find the starting pisition and allocate student there.
        stu->set_location(i,j);
        return 0;
      }
    }
  }
}
/*****************************
Name: set_Instructor
Input: NULL
Output: NULL
To do: set instructor
******************************/ 
int Maze :: set_Instructor(){
  int level=2;
  MazeLevel* mz1=(*get_mazeLayer())[level];  
  for(int m=0;m<get_rows();m++){
    for(int n=0;n<get_cols();n++){
      if(mz1->get_location(m,n)->get_display_character()=='%'){                           //find the place of instructor and then allocate the position
        Robin->set_location(m,n);
        return 0;
      }
    }
  }
}
/*****************************
Name: set_win
Input: bool
Output: NULL
To do: set game status
******************************/ 
void Maze :: set_win(bool win){
  this->win=win;

}
/*****************************
Name: get appearent level 
Input: NULL
Output: int
To do: get appearent level
******************************/ 
int Maze :: get_appearent_level(){
  return appearent_level;
}
/*****************************
Name: get layer
Input: NULL
Output: int
To do: get layer
******************************/ 
int Maze :: get_layer(){
  return layer;
}
/*****************************
Name: get rows 
Input: NULL
Output: int
To do: get rows
******************************/ 
int Maze :: get_rows(){
  return rows;
}
/*****************************
Name: get cols
Input: NULL
Output: int
To do: cols
******************************/ 
int Maze :: get_cols(){
  return cols;
}
/*****************************
Name: get number of skills 
Input: NULL
Output: int
To do: get number of skills
******************************/ 
int Maze :: get_nm_skills(){
  return nm_skills;
}

/*****************************
Name: get amaze layer 
Input: NULL
Output: vector
To do: get maze layer
******************************/ 
vector<MazeLevel*>* Maze :: get_mazeLayer(){
  return &mazelayer;
}
/*****************************
Name: get TA
Input: NULL
Output: vector
To do: get TA
******************************/ 
vector<TA*>* Maze :: get_TA(){
  return &TAs;
}
/*****************************
Name: get intrepidstudent
Input: NULL
Output: Intrepidstudent
To do: get intrepidstudent
******************************/ 
IntrepidStudent* Maze :: get_intrepidstudent(){
  return stu;
}
/*****************************
Name: get instructor
Input: NULL
Output: instructor
To do: get instructor
******************************/     
Instructor* Maze :: get_instructor(){
  return Robin;
}
/*****************************
Name: get win
Input: NULL
Output: bool
To do: get win
******************************/ 
bool Maze :: get_win(){
  return win;
}
/*****************************
Name: print maze
Input: NULL
Output: NULL
To do: print appearent maze layer.
******************************/ 
void Maze :: print_maze(){

    for(int j=0;j<get_rows();j++){
      for(int k=0;k<get_cols();k++){
        cout<<mazelayer[appearent_level]->get_location(j,k)->get_display_character();         //loop to print ou the whole maze layer 
      }
      cout<<endl;
    }
  
    print_status(); 
}
/*****************************
Name: set skills
Input: NULL
Output: NULL
To do: set skills
******************************/ 
void Maze :: set_skills(){
  for(int i=0;i<get_layer();i++){
//    int skills=3;
    srand(time(NULL));
      int skills=3;
      do{
        int x=random()%+get_rows();
        int y=random()%+get_cols();
        if((*get_mazeLayer())[i]->get_location(x,y)->get_display_character()==' '){              //find a random empty space to allocate the skills
          (*get_mazeLayer())[i]->get_location(x,y)->set_is_skill(true);
          --skills;
        }

      }while(skills>=1);  
    
  
  }


}
/*****************************
Name: print status
Input: NULL
Output: NULL
To do: print status
******************************/ 
void Maze :: print_status(){
  cout<<"Appearent level: "<<get_appearent_level()+1<<endl;
  cout<<"Student has programming skills: "<<stu->get_skills()<<endl;
  cout<<"student at position, rows: "<<stu->get_row()<<" cols: "<<stu->get_col()<<endl;            //print position and student status.
  
  cout<<">>>For TA1<<<"<<endl;
  cout<<" TA1 at rows: "<<TAs[0]->get_row()<<" cols: "<<TAs[0]->get_col()<<endl;
  cout<<"-TA1 status for satis faction: "<<TAs[0]->get_satisfaction()<<",appease: "<<TAs[0]->get_status()<<endl;
  cout<<"-----TA1 has rest appesed term: "<<TAs[0]->get_term()<<" -----"<<endl;
  if(TAs[0]->get_satisfaction()==true)
    cout<<"TA1 has satisfied with your skills."<<endl;                                            //print TA's status 
  else
    cout<<"TA1 is not satisfied with your skills."<<endl;
  
  cout<<">>>For TA2<<<"<<endl;
  cout<<" TA2 at rows: "<<TAs[1]->get_row()<<" cols: "<<TAs[1]->get_col()<<endl;
  cout<<"-TA2 status for satis faction: "<<TAs[1]->get_satisfaction()<<",appease: "<<TAs[1]->get_status()<<endl;
  cout<<"-----TA1 has rest appesed term: "<<TAs[1]->get_term()<<" -----"<<endl;
  if(TAs[1]->get_satisfaction()==true)
    cout<<"TA2 has satisfied with your skills."<<endl;
  else
    cout<<"TA2 is not satisfied with your skills."<<endl;  
  
  cout<<"There are "<<get_nm_skills()<<" programming skills in maze"<<endl;
//  cout<<"The instructor is at position, rows: "<<Robin->get_row()<<" cols: "<<Robin->get_col()<<endl;
}
/*****************************
Name: game flow 
Input: NULL
Output: NULL
To do: game flow function
******************************/ 
void Maze :: game_flow(){//----------------------------------------------------------------------------gameflow function here~
  bool truth=true;
  do{
    print_maze();
    bool valided=true;                                    //ask for user to take an action a nd then do the validation
    char userch;
    do{
      userch=stu->get_move();
      valided=moving_validation(userch);
    }while(valided);
    execute_move(userch);

    checkout_position();                                 //check the position surround the student
    cout<<endl;
    print_maze();                                        //print maze again
  
    truth=check_win();

  }while(truth);


}
/*****************************
Name: moving validation
Input: char
Output: NULL
To do: moving validation
******************************/ 
bool Maze :: moving_validation(char userch){
  if(userch=='W'){                                        //checking for different direction user may want to move, if valided return true  else return false
    if((*get_mazeLayer())[get_appearent_level()]->get_location(stu->get_row()-1,stu->get_col())->get_display_character()!='#'){

      return false;
    }
    else {
      cout<<"Can't move in this direction, please choose again. "<<endl;
      return true;
    }
  }
  
  if(userch=='S'){
    if((*get_mazeLayer())[get_appearent_level()]->get_location(stu->get_row()+1,stu->get_col())->get_display_character()!='#'){

      return false;
    }
    else {
      cout<<"Can't move in this direction, please choose again. "<<endl;
      return true;
    }
  }  

  if(userch=='A'){
    if((*get_mazeLayer())[get_appearent_level()]->get_location(stu->get_row(),stu->get_col()-1)->get_display_character()!='#'){

      return false;
    }
    else {
      cout<<"Can't move in this direction, please choose again. "<<endl;
      return true;
    }
  }  
  
  if(userch=='D'){
    if((*get_mazeLayer())[get_appearent_level()]->get_location(stu->get_row(),stu->get_col()+1)->get_display_character()!='#'){

      return false;
    }
    else {
      cout<<"Can't move in this direction, please choose again. "<<endl;
      return true;
    }
  }  
  
  if(userch=='U'){
      int rows=stu->get_row(),cols=stu->get_col();
      
      for(int i=0;i<get_rows();i++){
        for(int j=0;j<get_cols();j++){
          if(mazelayer[appearent_level]->get_location(i,j)->get_display_character()=='^'){                  //if player want to step into next layer, check wether or not tey are on the
                                                                                                            //ladder.
            if(rows==i && cols==j)
              return false;
            else{
              cout<<"Not standing on ladder can't step to next level. "<<endl;                              //if not on the ladder.
              return true;
            }
              
          }
        }
      
      }
  }

  if(userch=='P'){
    if(stu->get_skills()<=0){
      cout<<"No programming skills available, failed to show programming skills. "<<endl;                  //make sure student has available skills when they want to choose programming
      return true;
    }
    else {
      return false;
    
    }
    
  }


}

/*****************************
Name: execute move  
Input: char
Output: NULL
To do: execute move 
******************************/ 
void Maze :: execute_move(char userch){
  if(userch=='W'){
    mazelayer[appearent_level]->get_location(stu->get_row(),stu->get_col())->set_has_explorer(false);      //executive different moving direction
    mazelayer[appearent_level]->get_location(stu->get_row()-1,stu->get_col())->set_has_explorer(true);     //destruct from old address then alocate at new address finally renew rows and cols in student object.
    stu->set_location(stu->get_row()-1,stu->get_col());
    TA_move();
  }
  else if(userch=='S'){
    mazelayer[appearent_level]->get_location(stu->get_row(),stu->get_col())->set_has_explorer(false);
    mazelayer[appearent_level]->get_location(stu->get_row()+1,stu->get_col())->set_has_explorer(true);
    stu->set_location(stu->get_row()+1,stu->get_col());
    TA_move();
   }
   else if(userch=='A'){
      mazelayer[appearent_level]->get_location(stu->get_row(),stu->get_col())->set_has_explorer(false);
      mazelayer[appearent_level]->get_location(stu->get_row(),stu->get_col()-1)->set_has_explorer(true);
      stu->set_location(stu->get_row(),stu->get_col()-1);
      TA_move();
    }
    else if(userch=='D'){
      mazelayer[appearent_level]->get_location(stu->get_row(),stu->get_col())->set_has_explorer(false);
      mazelayer[appearent_level]->get_location(stu->get_row(),stu->get_col()+1)->set_has_explorer(true);
      stu->set_location(stu->get_row(),stu->get_col()+1);
      TA_move();
     }

  else if(userch=='P'){//--------------------------------------------------------------havent done yet.
    int * rows=new int,* cols=new int;
    if(scan_TA(rows,cols)){
      stu->set_skills(stu->get_skills()-1);
      for(int i=0;i<2;i++){
        if(TAs[i]->get_row()==*rows && TAs[i]->get_col()==*cols){                              //if you show your skills for TAs, they will be satisfied. 
          TAs[i]->set_satisfaction(true);
        }
      }
      cout<<"Your programming skills satisfied with TA. "<<endl;
    }
    
    else{
      stu->set_skills(stu->get_skills()-1);                                                   //if no TA surrounded you but you appeased for TA.
      for(int j=0;j<2;j++){
        TAs[j]->set_status(true);
        TAs[j]->set_term(10);
      }
      cout<<"You appeas for all TA in this level. "<<endl;
    }
  delete rows;
  delete cols;  
  }
  
  else if(userch=='U'){                                                                      //if student choose to step into next layer. 
    for(int kk=0;kk<2;kk++){
      mazelayer[get_appearent_level()]->get_location(TAs[kk]->get_row(),TAs[kk]->get_col())->set_is_ta(false);
    }
    
    mazelayer[get_appearent_level()]->get_location(stu->get_row(),stu->get_col())->set_has_explorer(false);
    set_appearent_level(get_appearent_level()+1);                                            //destruct student and TA at old layer then construct in new layer 
    set_student();                                                                           //renew the rows and cols on TA and student object
    construct_TA();
    for(int z=0;z<2;z++){
      TAs[z]->set_status(false);
      TAs[z]->set_satisfaction(false);                                                       //reset status
    }
    cout<<"you step into next layer. "<<endl;
  }

}

/*****************************
Name: TA_move  
Input: NULL
Output: NULL
To do: TA's move 
******************************/ 
void Maze :: TA_move(){
  for(int i=0;i<2;i++){
    char TAch;
    bool truth=true;
    do{
      TAch=TAs[i]->get_move();
      truth=TA_validation(TAch,i);                          //randomly choose a direction  and do the validation
    }while(truth);
    
    TA_move_exe(TAch,i);
  }

}
/*****************************
Name: TA validation
Input: NULL
Output: bool
To do: TA validation
******************************/ 
bool Maze :: TA_validation(char userch,int i){
  if(userch=='W'){                                               //looking for the choosing direction to moake sure no walls on that direction.
    if((*get_mazeLayer())[get_appearent_level()]->get_location(TAs[i]->get_row()-1,TAs[i]->get_col())->get_display_character()!='#'){

      return false;
    }
    else {
      cout<<"Can't move in this direction, please choose again. "<<endl;
      return true;
    }
  }
  
  if(userch=='S'){
    if((*get_mazeLayer())[get_appearent_level()]->get_location(TAs[i]->get_row()+1,TAs[i]->get_col())->get_display_character()!='#'){

      return false;
    }
    else {
      cout<<"Can't move in this direction, please choose again. "<<endl;
      return true;
    }
  }  

  if(userch=='A'){
    if((*get_mazeLayer())[get_appearent_level()]->get_location(TAs[i]->get_row(),TAs[i]->get_col()-1)->get_display_character()!='#'){

      return false;
    }
    else {
      cout<<"Can't move in this direction, please choose again. "<<endl;
      return true;
    }
  }  
  
  if(userch=='D'){
    if((*get_mazeLayer())[get_appearent_level()]->get_location(TAs[i]->get_row(),TAs[i]->get_col()+1)->get_display_character()!='#'){

      return false;
    }
    else {
      cout<<"Can't move in this direction, please choose again. "<<endl;
      return true;
    }
  }    

}
/*****************************
Name: TA move execution
Input: NULL
Output: NULL
To do: TA move execution 
******************************/ 
void Maze :: TA_move_exe(char userch,int i){
  if(userch=='W'){
    mazelayer[appearent_level]->get_location(TAs[i]->get_row(),TAs[i]->get_col())->set_is_ta(false); //destruct from old position
    mazelayer[appearent_level]->get_location(TAs[i]->get_row()-1,TAs[i]->get_col())->set_is_ta(true);//construct at new position
    TAs[i]->set_location(TAs[i]->get_row()-1,TAs[i]->get_col());
  }else if(userch=='S'){
    mazelayer[appearent_level]->get_location(TAs[i]->get_row(),TAs[i]->get_col())->set_is_ta(false);
    mazelayer[appearent_level]->get_location(TAs[i]->get_row()+1,TAs[i]->get_col())->set_is_ta(true);
    TAs[i]->set_location(TAs[i]->get_row()+1,TAs[i]->get_col());
   }else if(userch=='A'){
      mazelayer[appearent_level]->get_location(TAs[i]->get_row(),TAs[i]->get_col())->set_is_ta(false);
      mazelayer[appearent_level]->get_location(TAs[i]->get_row(),TAs[i]->get_col()-1)->set_is_ta(true);
      TAs[i]->set_location(TAs[i]->get_row(),TAs[i]->get_col()-1);
    }else if(userch=='D'){
      mazelayer[appearent_level]->get_location(TAs[i]->get_row(),TAs[i]->get_col())->set_is_ta(false);
      mazelayer[appearent_level]->get_location(TAs[i]->get_row(),TAs[i]->get_col()+1)->set_is_ta(true);
      TAs[i]->set_location(TAs[i]->get_row(),TAs[i]->get_col()+1);
     }

}
/*****************************
Name: scan TA 
Input: NULL
Output: bool
To do: scan TA
******************************/ 
bool Maze :: scan_TA(int *r,int *c){
  int rows=stu->get_row(),cols=stu->get_col();    //look arround the student's surrounding and determine wether or not ther is a TA there.
  if(mazelayer[get_appearent_level()]->get_location(rows,cols)->get_display_character()!='#' && mazelayer[get_appearent_level()]->get_location(rows,cols)->is_ta()==true)
    {  *r=rows;                                   //if yes then copy the location of that TA.
       *c=cols;
      return true;
    }
  if(mazelayer[get_appearent_level()]->get_location(rows-1,cols)->get_display_character()!='#' && mazelayer[get_appearent_level()]->get_location(rows-1,cols)->is_ta()==true)
    {  *r=rows-1;
       *c=cols;
      return true;
    }
  else if(mazelayer[get_appearent_level()]->get_location(rows+1,cols)->get_display_character()!='#' && mazelayer[get_appearent_level()]->get_location(rows+1,cols)->is_ta()==true)
    {  *r=rows+1;
       *c=cols;
      return true;
    } 
  else if(mazelayer[get_appearent_level()]->get_location(rows-1,cols-1)->get_display_character()!='#' && mazelayer[get_appearent_level()]->get_location(rows-1,cols-1)->is_ta()==true)
    {  *r=rows-1;
       *c=cols-1;
      return true;
    }
  else if(mazelayer[get_appearent_level()]->get_location(rows,cols-1)->get_display_character()!='#' && mazelayer[get_appearent_level()]->get_location(rows,cols-1)->is_ta()==true)
    {  *r=rows;
       *c=cols-1;
      return true;
    }
  else if(mazelayer[get_appearent_level()]->get_location(rows+1,cols-1)->get_display_character()!='#' && mazelayer[get_appearent_level()]->get_location(rows+1,cols-1)->is_ta()==true)
    {  *r=rows+1;
       *c=cols-1;
      return true;
    }
  else if(mazelayer[get_appearent_level()]->get_location(rows-1,cols+1)->get_display_character()!='#' && mazelayer[get_appearent_level()]->get_location(rows-1,cols+1)->is_ta()==true)
    {  *r=rows-1;
       *c=cols+1;
      return true;
    }  
  else if(mazelayer[get_appearent_level()]->get_location(rows,cols+1)->get_display_character()!='#' && mazelayer[get_appearent_level()]->get_location(rows,cols+1)->is_ta()==true)
    {  *r=rows;
       *c=cols+1;
      return true;
    }
  else if(mazelayer[get_appearent_level()]->get_location(rows+1,cols+1)->get_display_character()!='#' && mazelayer[get_appearent_level()]->get_location(rows+1,cols+1)->is_ta()==true)
    {  *r=rows+1;
       *c=cols+1;
      return true;
    }
  else 
    return false;
}
/*****************************
Name: scan instructor 
Input: NULL
Output: bool
To do: scan instructor 
******************************/ 
bool Maze :: scan_Instructor(){
  int rows=stu->get_row(),cols=stu->get_col(); //look arround the instructor and then if find instructor return truth, nothing finded return false 
  if(mazelayer[get_appearent_level()]->get_location(rows,cols)->get_display_character()!='#' && mazelayer[get_appearent_level()]->get_location(rows,cols)->is_instructor()==true)
    return true;
    
  if(mazelayer[get_appearent_level()]->get_location(rows-1,cols)->get_display_character()!='#' && mazelayer[get_appearent_level()]->get_location(rows-1,cols)->is_instructor()==true)
    return true;
  else if(mazelayer[get_appearent_level()]->get_location(rows+1,cols)->get_display_character()!='#' && mazelayer[get_appearent_level()]->get_location(rows+1,cols)->is_instructor()==true)
    return true;
  else if(mazelayer[get_appearent_level()]->get_location(rows-1,cols-1)->get_display_character()!='#' && mazelayer[get_appearent_level()]->get_location(rows-1,cols-1)->is_instructor()==true)
    return true;
  else if(mazelayer[get_appearent_level()]->get_location(rows,cols-1)->get_display_character()!='#' && mazelayer[get_appearent_level()]->get_location(rows,cols-1)->is_instructor()==true)
    return true;
  else if(mazelayer[get_appearent_level()]->get_location(rows+1,cols-1)->get_display_character()!='#' && mazelayer[get_appearent_level()]->get_location(rows+1,cols-1)->is_instructor()==true)
    return true;
  else if(mazelayer[get_appearent_level()]->get_location(rows-1,cols+1)->get_display_character()!='#' && mazelayer[get_appearent_level()]->get_location(rows-1,cols+1)->is_instructor()==true)
    return true;
  else if(mazelayer[get_appearent_level()]->get_location(rows,cols+1)->get_display_character()!='#' && mazelayer[get_appearent_level()]->get_location(rows,cols+1)->is_instructor()==true)
    return true;
  else if(mazelayer[get_appearent_level()]->get_location(rows+1,cols+1)->get_display_character()!='#' && mazelayer[get_appearent_level()]->get_location(rows+1,cols+1)->is_instructor()==true)
    return true;
  else 
    return false;
}
/*****************************
Name: checkout_position 
Input: NULL
Output: NULL
To do: checkout_position
******************************/ 
void Maze :: checkout_position(){
  int *rows=new int,*cols=new int,i;
  checkout_TA_status();
  MazeLevel* Lv=mazelayer[appearent_level];                                  
  if(Lv->get_location(stu->get_row(),stu->get_col())->is_skill()==true){      //if met programming skills just pick up 
    stu->set_skills(stu->get_skills()+1);
    set_nm_skills(get_nm_skills()-1);
    Lv->get_location(stu->get_row(),stu->get_col())->set_is_skill(false);
    cout<<"You pick up a programming skill. "<<endl;
  }


  else if(scan_Instructor()){                                                //if met instructor validate student has at least 3 programming skills to satisfy the instructor
    if(stu->get_skills()<3 && Robin->get_satisfaction()==false){
      //set_win(false);
      cout<<"You don't have enough skills to convince the Instructor. "<<endl;
      cout<<"Yo fail in this class. "<<endl;
      for(int k=0;k<2;k++){
        mazelayer[appearent_level]->get_location(TAs[k]->get_row(),TAs[k]->get_col())->set_is_ta(false);
      }
        mazelayer[appearent_level]->get_location(stu->get_row(),stu->get_col())->set_has_explorer(false);
        
      for(int j=0;j<layer;j++){
        for(int s=0;s<get_rows();s++){
          for(int p=0;p<get_cols();p++){
            if(mazelayer[j]->get_location(s,p)->is_skill()==true)
              mazelayer[j]->get_location(s,p)->set_is_skill(false);
          }
        }
      
      }
      set_appearent_level(0);
      set_student();
      construct_TA();
      set_skills();
      set_nm_skills(9);
      stu->set_skills(0);
      
    }else{
       if(Robin->get_satisfaction()==false){                                 //if has enouth skills to satisfy the instructor
         stu->set_skills(stu->get_skills()-3);
         Robin->set_satisfaction(true);
         cout<<"Your programming ability convinced the Instructor. "<<endl;
         set_win(false);
       }
    
    
     }
  }
  
  else if(scan_TA(rows,cols)){
    for(int j=0;j<2;j++){                                                   //if met TA 
      if(TAs[j]->get_row()==*rows && TAs[j]->get_col()==*cols)              
        i=j;
    }

   if(stu->get_skills()<=0 && TAs[i]->get_satisfaction()==false){           //if don't have enough skills to convince the TA.
     cout<<"You are catched by TA. "<<endl;
     mazelayer[appearent_level]->get_location(stu->get_row(),stu->get_col())->set_has_explorer(false);
     set_student();
   }else{
       if(TAs[i]->get_satisfaction()==false){                              //if has skills to convince TA.
         stu->set_skills(stu->get_skills()-1);
         TAs[i]->set_satisfaction(true);
         cout<<"Your programming skills convinced a TA. "<<endl;
       }
    }
  }
  
  delete rows;
  delete cols;
}
/*****************************
Name: checkout_TA_status 
Input: NULL
Output: NULL
To do: checkout_TA_status
******************************/ 
void Maze :: checkout_TA_status(){
  for(int i=0;i<2;i++){
    if(TAs[i]->get_status()==true){
      TAs[i]->set_term(TAs[i]->get_term()-1);                             //if TA has been appeased make a term deduction
    }
    
    if(TAs[i]->get_status()==true && TAs[i]->get_term()==0){             //if TA has zero terms available for appease then set status back to no appeased. 
      TAs[i]->set_status(false);
    }
  }


}
/*****************************
Name: checkout_win
Input: NULL
Output: bool
To do: checkout_win
******************************/ 
bool Maze :: check_win(){
  if(get_win()==true){
    return true;                                                        //check game status true means gas still on going 
  }
  
  else if(get_win()==false){                                           //false means the game is done then check the satisfaction  of Instructor, if true win the game if not failed. 
    if(Robin->get_satisfaction()==true){
      cout<<"You pass the cs162, congratulation! "<<endl;
      return false;                          
    }else{
       cout<<"You failed in this class. Robin: see you next term in cs162 class HA~HA~ "<<endl;
       return false;
     }
    
  }
}
/*****************************
Name: destructor of maze obj
Input: NULL
Output: NULL
To do: destruct the whole class
******************************/ 
Maze :: ~Maze(){
  destruct_TA();
  for(int i=0;i<layer;i++){
    mazelayer[i]->~MazeLevel();
    delete mazelayer[i];
  }

  delete stu;
  delete Robin;
}









