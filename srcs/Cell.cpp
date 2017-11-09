//
// Cell.cpp for  in /home/kopiz/Workplace/MATHS/304pacman/srcs
// 
// Made by Tom Jeammet
// Login   <tom.jeammet@epitech.eu>
// 
// Started on  Thu Nov  9 15:34:19 2017 Tom Jeammet
// Last update Thu Nov  9 15:45:19 2017 Tom Jeammet
//

#include "Cell.hpp"

//Ctor
Cell::Cell()
{
  
}

//Dtor
Cell::~Cell()
{

}

//Member

//Getter
Position				Cell::getPos()
{
  return (_pos);
}

char					Cell::getLetter()
{
  return (_letter);
}

//Setter
void					Cell::setPos(Position pos)
{
  _pos = pos;
}

void					Cell::setLetter(char letter)
{
  _letter = letter;
}
