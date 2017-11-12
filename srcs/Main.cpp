//
// Main.cpp for  in /home/ze/304pacman
// 
// Made by ze
// Login   <maxime.lacroix@epitech.eu>
// 
// Started on  Mon Nov  6 13:22:56 2017 ze
// Last update Sun Nov 12 15:41:48 2017 Tom Jeammet
//

#include "Main.hpp"

int						main(int ac, char **av)
{
  std::vector<std::string>			map_str;
  
  try
    {
      map_str = checks(ac, av);
      modMapWallSpace(map_str, av[2][0], av[3][0]);
      Map *map = new Map(map_str);
      map->search(av[3][0]);
      map->printMap();
    }
  catch (Err &err)
    {
      err.print_msg();
      return (84);
    }
  return (0);
}
