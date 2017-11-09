//
// Checks.cpp for  in /home/ze/304pacman/srcs
// 
// Made by ze
// Login   <maxime.lacroix@epitech.eu>
// 
// Started on  Mon Nov  6 14:30:38 2017 ze
// Last update Thu Nov  9 15:45:54 2017 Tom Jeammet
//

#include "Main.hpp"

bool					is_map(char c)
{
  if (c >= 7 || c <= 13)
    return (true);
  if (c == '0' || c == '1' || c == 'F' || c == 'P')
    return (true);
  return (false);
}

void					check_line(std::string tmp)
{
  const char				*line = tmp.c_str();
  int					i;

  i = - 1;
  while (line[++i])
    if (is_map(line[i]) == false)
      throw(Err("Error in map !\nUnexpected format line:\n'" + (std::string)line + "'"));
}

int					isAF(std::string str)
{
  int					nb_f;
  int					i;

  i = 0;
  nb_f = 0;
  while (i < (int)str.size())
    {
      if (str.at(i) == 'F')
	nb_f = nb_f + 1;
      i = i + 1;
    }
  return (nb_f);
}

int					isAP(std::string str)
{
  int					nb_p;
  int					i;

  i = 0;
  nb_p = 0;
  while (i < (int)str.size())
    {
      if (str.at(i) == 'P')
	nb_p = nb_p + 1;
      i = i + 1;
    }
  return (nb_p);
}

std::vector<std::string>		check_map(std::fstream &file)
{
  std::vector<std::string>		map;
  std::string				tmp;
  int					nb_f;
  int					nb_p;

  nb_f = 0;
  nb_p = 0;
  while (std::getline(file, tmp))
    {
      map.push_back(tmp);
      check_line(tmp);
      nb_f = nb_f + isAF(tmp);
      nb_p = nb_p + isAP(tmp);
    }
  if (nb_f != 1 || nb_p != 1)
    throw (Err("Wrong number of F and P in map, should be one"));
  return (map);
}


std::vector<std::string>		checks(int ac, char **av)
{
  std::fstream				file;

  if (ac != 4)
    throw (Err("Usage:\n\t./304pacman file c1 c2"));
  file.open(av[1]);
  if (file.fail())
    throw (Err("Error: " + (std::string)av[1] + " no such file"));
  return (check_map(file));
}
