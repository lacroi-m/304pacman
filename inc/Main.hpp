//
// Main.hpp for  in /home/ze/304pacman
// 
// Made by ze
// Login   <maxime.lacroix@epitech.eu>
// 
// Started on  Mon Nov  6 13:22:36 2017 ze
// Last update Sun Nov 12 15:40:26 2017 Tom Jeammet
//

#ifndef  __MAIN_HPP__
# define  __MAIN_HPP__

# include <iostream>
# include <string>
# include <cstring>
# include <fstream>
# include <vector>

# include "Exception.hpp"
# include "Cell.hpp"
# include "Map.hpp"

std::vector<std::string>		checks(int ac, char **av);
void					modMapWallSpace(std::vector<std::string> &, const char, const char);

#endif /* ! __MAIN_HPP__ */
