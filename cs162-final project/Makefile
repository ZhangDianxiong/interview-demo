general: escape.cpp MazeLocation.hpp Wall.hpp Wall.cpp OpenSpace.hpp OpenSpace.cpp MazeLevel.cpp MazeLevel.hpp MazePerson.hpp continual  
	g++ escape.cpp Wall.cpp OpenSpace.cpp MazeLevel.cpp IntrepidStudent.cpp Instructor.cpp TA.cpp Maze.cpp -o escape 

debug: escape.cpp MazeLocation.hpp Wall.hpp Wall.cpp OpenSpace.hpp OpenSpace.cpp MazeLevel.cpp MazeLevel.hpp MazePerson.hpp continual
	g++ -g escape.cpp Wall.cpp OpenSpace.cpp MazeLevel.cpp IntrepidStudent.cpp Instructor.cpp TA.cpp Maze.cpp -o escape 

continual: IntrepidStudent.cpp IntrepidStudent.hpp Instructor.cpp Instructor.hpp TA.cpp TA.hpp Maze.cpp Maze.hpp

clear:
	rm -f escape *.o 
