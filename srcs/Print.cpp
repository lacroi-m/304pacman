//
// Print.cpp for  in /home/kopiz/Workplace/MATHS/304pacman/srcs
// 
// Made by Tom Jeammet
// Login   <tom.jeammet@epitech.eu>
// 
// Started on  Thu Nov  9 16:27:32 2017 Tom Jeammet
// Last update Thu Nov  9 16:40:19 2017 Tom Jeammet
//

#include "Print.hpp"

void						printMap(std::vector<std::vector<Cell> > map)
{
  std::vector<std::vector<Cell> >::iterator     it;
  std::vector<Cell>::iterator			jt;
  std::vector<Cell>				tab;
  Cell                                          cell;

  for (it = map.begin(); it != map.end(); it++)
    {
      tab = *it;
      for (jt = tab.begin(); jt != tab.end(); jt++)
	{
	  cell = *jt;
	  std::cout << cell.getLetter();
	}
      std::cout << std::endl;
    }
}
