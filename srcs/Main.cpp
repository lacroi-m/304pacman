//
// Main.cpp for  in /home/ze/304pacman
// 
// Made by ze
// Login   <maxime.lacroix@epitech.eu>
// 
// Started on  Mon Nov  6 13:22:56 2017 ze
// Last update Thu Nov  9 16:40:43 2017 Tom Jeammet
//

#include "Main.hpp"

std::vector<std::vector<Cell> >			createCells(std::vector<std::vector<Cell> > map, std::vector<std::string> map_str)
{
  std::vector<std::string>::iterator		it;
  std::vector<Cell>				line;
  std::string					tmp;
  Position					pos;
  Cell						cell;
  int						i;
  int						j;

  i = 0;
  for (it = map_str.begin(); it != map_str.end(); it++)
    {
      j = 0;
      tmp = *it;
      line.clear();
      while (j < (int)tmp.size())
	{
	  pos.setX(i);
	  pos.setY(j);
	  cell.setLetter(tmp.at(j));
	  cell.setPos(pos);
	  line.push_back(cell);
	  j = j + 1;
	}
      map.push_back(line);
      i = i + 1;
    }
  return (map);
}

int						main(int ac, char **av)
{
  std::vector<std::vector<Cell> >		map;
  std::vector<std::string>			map_str;
  size_t					x;
  
  try
    {
      map_str = checks(ac, av);
      modMapWallSpace(map_str, av[2][0], av[3][0]);
      map = createCells(map, map_str);
      //printMap(map);
    }
  catch (Err &err)
    {
      err.print_msg();
      return (84);
    }
  return (0);
}
