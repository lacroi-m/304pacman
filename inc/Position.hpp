//
// Position.hpp for  in /home/kopiz/Workplace/MATHS/304pacman/inc
// 
// Made by Tom Jeammet
// Login   <tom.jeammet@epitech.eu>
// 
// Started on  Thu Nov  9 15:46:45 2017 Tom Jeammet
// Last update Thu Nov  9 15:52:39 2017 Tom Jeammet
//

#ifndef __POSITION_HPP__
# define __POSITION_HPP__

class					Position
{
private:
  int					_x;
  int					_y;

public:
  //Ctor
  Position();
  //Dtor
  ~Position();
  //Member
  
  //Getter
  int					getX();
  int					getY();
  //Setter
  void					setX(int);
  void					setY(int);
};

#endif /* ! __POSITION_HPP__ */
