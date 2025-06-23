#ifndef SOKOBAN_H
#define SOKOBAN_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

//typedef Direction 
enum class direction { UP, DOWN, LEFT, RIGHT };

class Sokoban
{
public:
Sokoban();
int getWidth() { return width; };
int getHeight() { return height; };
int getPlayerX() { return playerX; }; 
int getPlayerY() { return playerY; };
void movePlayer(direction moveDir);
void moveBox(direction moveDir);
const bool isWon(); // Checks for win condtion
bool IsValidMove(direction moveDir);
friend std::istream& operator>> (std::istream& inStream, Sokoban& game); // Reads level from instream
//private:
//virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
//virtual 
void draw(sf::RenderWindow& w) const;
protected:
  int width;	// Level Width
  int height;	// Level Height
  int playerX;
  int playerY;
  int numBoxes;
  int numGoals;
  direction playerDir;
  std::vector<std::string> Map;  // Map data
};
#endif
