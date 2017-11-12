//
// Map.hpp for  in /home/kopiz/Workplace/MATHS/304pacman/inc
// 
// Made by Tom Jeammet
// Login   <tom.jeammet@epitech.eu>
// 
// Started on  Fri Nov 10 12:24:04 2017 Tom Jeammet
// Last update Sun Nov 12 15:40:09 2017 Tom Jeammet
//

#ifndef __MAP_HPP__
# define __MAP_HPP__

# include <iostream>
# include <vector>
# include <string>

# include "Cell.hpp"

class					Map
{
private:
  std::vector<std::vector<Cell> >	_map;
  std::vector<Position>			toCheck;
  int					size_x;
  int					size_y;
  bool					founded;

public:
  //Ctor
  Map(std::vector<std::string>);
  //Dtor
  ~Map();
  //Member
  void					printMap();
  Position				checkOnePos(Position, int, char);
  void					search(char);
  Position				findChar(char);
  //Getter
  std::vector<std::vector<Cell> >	getMap();
  std::vector<Position>			getToCheck();
  int					getSizeX();
  int					getSizeY();
  bool					getFounded();
  //Setter
  void					setMap(std::vector<std::vector<Cell> >);
  void					setToCheck(std::vector<Position>);
  void					setSizeX(int);
  void					setSizeY(int);
  void					setFounded(bool);
};

#endif /* ! __MAP_HPP__ */
