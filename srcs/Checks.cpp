//
// Checks.cpp for  in /home/ze/304pacman/srcs
// 
// Made by ze
// Login   <maxime.lacroix@epitech.eu>
// 
// Started on  Mon Nov  6 14:30:38 2017 ze
// Last update Mon Nov  6 14:32:33 2017 ze
//


#include "Main.hpp"


bool is_map(char c)
{
  if (c == '0' || c == '1' || c == 'F' || c == 'P')
    return (true);
  return (false);
}

void	check_line(std::string &tmp)
{
  int	i = -1;
  const char	*line;
  
  line = tmp.c_str();
  while (line[++i] != 0)
    if (is_map(line[i]) == false)
      throw(Err("Error in map !\nUnexpected format line:\n'" + (std::string)line + "'"));
}

std::vector<std::string> check_map(std::fstream &file)
{
  std::string			tmp;
  std::vector<std::string>	map;
  
  while (std::getline(file, tmp))
    {
      map.push_back(tmp);
      check_line(tmp);
    }
  return (map);
}


std::vector<std::string> checks(int ac, char **av)
{
  std::fstream		   file;

  if (ac != 4)
    throw (Err("Usage:\n\t./304pacman file c1 c2"));
  file.open(av[1]);
  if (file.fail())
    throw (Err("Error: " + (std::string)av[1] + " no such file"));
  return (check_map(file));
}
