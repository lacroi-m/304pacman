//
// Checks.cpp for  in /home/ze/304pacman/srcs
// 
// Made by ze
// Login   <maxime.lacroix@epitech.eu>
// 
// Started on  Mon Nov  6 14:30:38 2017 ze
// Last update Tue Nov  7 15:35:37 2017 DESKTOP-FQFT07H
//

#include "Main.hpp"

bool is_map(char c)
{
  if (c >= 7 || c <= 13)
    return (true);
  if (c == '0' || c == '1' || c == 'F' || c == 'P')
    return (true);
  return (false);
}

void	check_line(std::string tmp)
{
  int	i = -1;
  const char	*line = tmp.c_str();
  while (line[++i])
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
