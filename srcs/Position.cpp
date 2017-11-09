//
// Position.cpp for  in /home/kopiz/Workplace/MATHS/304pacman/srcs
// 
// Made by Tom Jeammet
// Login   <tom.jeammet@epitech.eu>
// 
// Started on  Thu Nov  9 15:46:47 2017 Tom Jeammet
// Last update Thu Nov  9 15:52:37 2017 Tom Jeammet
//

#include "Position.hpp"

//Ctor
Position::Position()
{

}

//Dtor
Position::~Position()
{

}

//Member

//Getter
int					Position::getX()
{
  return (_x);
}

int					Position::getY()
{
  return (_y);
}

//Setter
void					Position::setX(int x)
{
  _x = x;
}

void					Position::setY(int y)
{
  _y = y;
}
