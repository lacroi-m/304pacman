//
// Exception.cpp for  in /home/ze/304pacman
// 
// Made by ze
// Login   <maxime.lacroix@epitech.eu>
// 
// Started on  Mon Nov  6 13:22:46 2017 ze
// Last update Mon Nov  6 13:22:47 2017 ze
//

#include "Exception.hpp"

//Ctor
Err::Err(std::string msg)
{
  this->set_msg(msg);
}

//Dtor
Err::~Err(void) throw ()
{
  
}

//Setter
void					Err::set_msg(std::string msg)
{
  this->_msg = msg;
}

//Getter
std::string				Err::get_msg(void)
{
  return (this->_msg);
}

//Member
void					Err::print_msg(void)
{
  if (this->_msg != "")
    std::cerr << this->_msg << std::endl;
}
