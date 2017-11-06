//
// Main.cpp for  in /home/ze/304pacman
// 
// Made by ze
// Login   <maxime.lacroix@epitech.eu>
// 
// Started on  Mon Nov  6 13:22:56 2017 ze
// Last update Mon Nov  6 14:34:41 2017 ze
//

#include "Main.hpp"

int	main(int ac, char **av)
{
  try
    {
      std::vector<std::string>	map;
      map = checks(ac, av);
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
