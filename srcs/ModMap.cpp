//
// ModMap.cpp for  in /mnt/c/Users/ze/Desktop/gitshit/304pacman
// 
// Made by DESKTOP-FQFT07H
// Login   <maxime.lacroix@epitech.eu>
// 
// Started on  Tue Nov  7 15:38:41 2017 DESKTOP-FQFT07H
// Last update Tue Nov  7 15:57:07 2017 DESKTOP-FQFT07H
//

#include "Main.hpp"

//if Wall or Space is String --------> ERRER ?
void	modMapWallSpace(std::vector<std::string> &map, const char Wall, const char Space)
{
  for (size_t x = 0; x < map.size(); x++)
    {
      for (size_t y = 0; y < map[x].size(); y++)
	{
	  if (map[x][y] == '1')
	    map[x][y] = Wall;
	  else if (map[x][y] == '0')
	    map[x][y] = Space;
	}
    }
}
