//
// Main.cpp for  in /home/ze/304pacman
// 
// Made by ze
// Login   <maxime.lacroix@epitech.eu>
// 
// Started on  Mon Nov  6 13:22:56 2017 ze
// Last update Mon Nov  6 13:34:01 2017 ze
//

#include "Main.hpp"

void checks(int ac, char **av)
{
  std::fstream	file;
  (void)ac;
  if (ac < 2)
    throw (Err("Usage:\n\t./304pacman file c1 c2"));
  file.open(av[1]);
  if (file.fail())
    throw (Err("Error: " + (std::string)av[1] + " no such file"));
}

int	main(int ac, char **av)
{
  try
    {
      checks(ac, av);
    }
  catch (Err &err)
    {
      err.print_msg();
      return (84);
    }
  return (0);
}
