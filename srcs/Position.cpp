//
// Position.cpp for  in /home/kopiz/Workplace/MATHS/304pacman/srcs
// 
// Made by Tom Jeammet
// Login   <tom.jeammet@epitech.eu>
// 
// Started on  Thu Nov  9 15:46:47 2017 Tom Jeammet
// Last update Sat Nov 11 18:17:57 2017 Tom Jeammet
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
bool					Position::isGoodPos()
{
  if ((getX() == - 1) || (getY() == - 1))
    return (false);
  return (true);
}

void					Position::printPos()
{
  std::cout << "x : " << getX() << " y : " << getY() << std::endl;
}

void					Position::setUp(Position pos)
{
  setX(pos.getX() - 1);
  setY(pos.getY());
}

void					Position::setRight(Position pos)
{
  setX(pos.getX());
  setY(pos.getY() + 1);
}

void					Position::setDown(Position pos)
{
  setX(pos.getX() + 1);
  setY(pos.getY());
}

void					Position::setLeft(Position pos)
{
  setX(pos.getX());
  setY(pos.getY() - 1);
}

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
