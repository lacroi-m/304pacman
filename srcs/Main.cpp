//
// Main.cpp for  in /home/ze/304pacman
// 
// Made by ze
// Login   <maxime.lacroix@epitech.eu>
// 
// Started on  Mon Nov  6 13:22:56 2017 ze
// Last update Tue Nov  7 15:47:27 2017 DESKTOP-FQFT07H
//

#include "Main.hpp"

int	main(int ac, char **av)
{
  try
    {
      std::vector<std::string>	map;
      map = checks(ac, av);
      modMapWallSpace(map, av[2][0], av[3][0]);
      for (size_t x = 0; x < map.size(); x++)
	std::cout << map[x] << std::endl;
    }
  catch (Err &err)
    {
      err.print_msg();
      return (84);
    }
  return (0);
}
