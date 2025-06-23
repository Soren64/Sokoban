#include "Sokoban.h"
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

Sokoban::Sokoban()
{
  width = 0;
  height = 0;
  playerX = 0;
  playerY = 0;
  playerDir = direction::DOWN;
  numBoxes = 0;
  numGoals = 0;
} 


bool Sokoban::IsValidMove(direction moveDir) {
  switch (moveDir)
  {
    case(direction::UP): {
      if (Map[playerX - 1][playerY] == '#') {
        return false;
      }
      else if (playerX - 1 < 0) {
        return false;
      }
      else if (playerX - 2 < 0 && Map[playerX - 1][playerY] == 'A') {
        return false;
      }
      else if (Map[playerX - 1][playerY] == 'A' && Map[playerX - 2][playerY] == 'A') {
        return false;
      }
      else if (Map[playerX - 1][playerY] == 'A' && Map[playerX - 2][playerY] == '#') {
        return false;
      }
      else if (Map[playerX - 1][playerY] == '1' && Map[playerX - 2][playerY] == '1') {
        return false;
      }
      else if (Map[playerX - 1][playerY] == '1' && Map[playerX - 2][playerY] == '#') {
        return false;
      }
      else if (Map[playerX - 1][playerY] == '1' && Map[playerX - 2][playerY] == 'A') {
        return false;
      }
      else if (Map[playerX - 1][playerY] == 'A' && Map[playerX - 2][playerY] == '1') {
        return false;
      }
      else {
        return true;
      }
      break;
    }
    case(direction::DOWN): {
      if (Map[playerX + 1][playerY] == '#') {
        return false;
      }
        else if (playerX + 1 > (height - 1)) {
          return false;
      }
      else if (playerX + 2 > (height - 1) && Map[playerX + 1][playerY] == 'A') {
        return false;
      }
      else if (Map[playerX + 1][playerY] == 'A' && Map[playerX + 2][playerY] == 'A') {
        return false;
      }
      else if (Map[playerX + 1][playerY] == 'A' && Map[playerX + 2][playerY] == '#') {
        return false;
      }
      else if (Map[playerX + 1][playerY] == '1' && Map[playerX + 2][playerY] == '1') {
        return false;
      }
      else if (Map[playerX + 1][playerY] == '1' && Map[playerX + 2][playerY] == '#') {
        return false;
      }
      else if (Map[playerX + 1][playerY] == '1' && Map[playerX + 2][playerY] == 'A') {
        return false;
      }
      else if (Map[playerX + 1][playerY] == 'A' && Map[playerX + 2][playerY] == '1') {
        return false;
      }
      else {
        return true;
      }
      break;
    }
    case(direction::LEFT): {
      if (Map[playerX][playerY - 1] == '#') {
        return false;
      }
      else if (playerY - 1 < 0) {
        return false;
      }
      else if (playerY - 2 < 0 && Map[playerX][playerY - 1] == 'A') {
        return false;
      }
      else if (Map[playerX][playerY - 1] == 'A' && Map[playerX][playerY - 2] == 'A') {
        return false;
      }
      else if (Map[playerX][playerY - 1] == 'A' && Map[playerX][playerY - 2] == '#') {
        return false;
      }
      else if (Map[playerX][playerY - 1] == '1' && Map[playerX][playerY - 2] == '1') {
        return false;
      }
      else if (Map[playerX][playerY - 1] == '1' && Map[playerX][playerY - 2] == '#') {
        return false;
      }
      else if (Map[playerX][playerY - 1] == '1' && Map[playerX][playerY - 2] == 'A') {
        return false;
      }
      else if (Map[playerX][playerY - 1] == 'A' && Map[playerX][playerY - 2] == '1') {
        return false;
      }
      else {
        return true;
      }
      break;
    }
    case(direction::RIGHT): {
      if (Map[playerX][playerY + 1] == '#') {
        return false;
      }
      else if (playerY + 1 > (width - 1)) {
        return false;
      }
      else if (playerY + 2 > (width - 1) && Map[playerX][playerY + 1] == 'A') {
        return false;
      }
      else if (Map[playerX][playerY + 1] == 'A' && Map[playerX][playerY + 2] == '@') {
        return false;
      }
      else if (Map[playerX][playerY + 1] == 'A' && Map[playerX][playerY + 2] == '#') {
        return false;
      }
      else if (Map[playerX][playerY + 1] == '1' && Map[playerX][playerY + 2] == '1') {
        return false;
      }
      else if (Map[playerX][playerY + 1] == '1' && Map[playerX][playerY + 2] == '#') {
        return false;
      }
      else if (Map[playerX][playerY + 1] == '1' && Map[playerX][playerY + 2] == 'A') {
        return false;
      }
      else if (Map[playerX][playerY + 1] == 'A' && Map[playerX][playerY + 2] == '1') {
        return false;
      }
      else {
        return true;
      }
      break;
    }
    default:
      break;
    }
    return false;
}


void Sokoban::movePlayer(direction moveDir) { 
  if (IsValidMove(moveDir)) {
    if (Map[playerX][playerY] == '2') {  
      Map[playerX][playerY] = 'a';
    }
    else {
      Map[playerX][playerY] = '.';
    }

    switch (moveDir) {
      case(direction::UP): {
        playerDir = direction::UP;
        if (Map[playerX - 1][playerY] == 'A' || Map[playerX - 1][playerY] == '1') {
          moveBox(moveDir);
        }
        else if (Map[playerX - 1][playerY] == 'a') {
          Map[playerX - 1][playerY] = '2';
        }
        else {
          Map[playerX - 1][playerY] = '@';
        }
          playerX = playerX - 1;
          break;
        }
      case(direction::DOWN): {
        playerDir = direction::DOWN;
        if (Map[playerX + 1][playerY] == 'A' || Map[playerX + 1][playerY] == '1') {
          moveBox(moveDir);
        }
        else if (Map[playerX + 1][playerY] == 'a') {
          Map[playerX + 1][playerY] = '2';
        }
        else {
          Map[playerX + 1][playerY] = '@';
        }
          playerX = playerX + 1;
          break;
        }
      case(direction::LEFT): {
        playerDir = direction::LEFT;
        if (Map[playerX][playerY - 1] == 'A' || Map[playerX][playerY - 1] == '1') {
          moveBox(moveDir);
        }
        else if (Map[playerX][playerY - 1] == 'a') {
          Map[playerX][playerY - 1] = '2';
        }
        else {
          Map[playerX][playerY - 1] = '@';
        }
          playerY = playerY - 1;
          break;
        }
      case(direction::RIGHT): {
         playerDir = direction::RIGHT;
         if (Map[playerX][playerY+1] == 'A' || Map[playerX][playerY+1] == '1') {
           moveBox(moveDir);
         }
         else if (Map[playerX][playerY+1] == 'a') {
           Map[playerX][playerY+1] = '2';
         }
         else {
           Map[playerX][playerY+1] = '@';
         }
           playerY = playerY + 1;
           break;
        }
      }
    }
}

void Sokoban::moveBox(direction moveDir) {
  switch (moveDir)
  {
    case(direction::UP): {
      if (Map[playerX - 1][playerY]== 'A') {
        Map[playerX - 1][playerY] = '@';
        if (Map[playerX - 2][playerY] == 'a') {
          Map[playerX - 2][playerY] = '1';
        }
        else {
           Map[playerX - 2][playerY] = 'A';
        }
      }
      else {
        Map[playerX - 1][playerY] = '2';
        if (Map[playerX - 2][playerY] == 'a') {
          Map[playerX - 2][playerY] = '1';
        }
        else {
          Map[playerX - 2][playerY] = 'A';
        }
      }
      break;
    }
    case(direction::DOWN): {
      if (Map[playerX + 1][playerY] == 'A') {
        Map[playerX + 1][playerY] = '@';
            if (Map[playerX + 2][playerY] == 'a') {
                Map[playerX + 2][playerY] = '1';
            }
            else {
                Map[playerX + 2][playerY] = 'A';
            }
        }
        else {
          Map[playerX + 1][playerY] = '2';
          if (Map[playerX + 2][playerY] == 'a') {
            Map[playerX + 2][playerY] = '1';
        }
        else {
          Map[playerX + 2][playerY] = 'A';
        }
      }
      break;
    }
    case(direction::LEFT): {
        if (Map[playerX][playerY - 1] == 'A') {
            Map[playerX][playerY - 1] = '@';
            if (Map[playerX][playerY - 2] == 'a') {
                Map[playerX][playerY - 2] = '1';
            }
            else {
                Map[playerX][playerY - 2] = 'A';
            }
        }
        else {
            Map[playerX][playerY - 1] = '2';
            if (Map[playerX][playerY - 2] == 'a') {
                Map[playerX][playerY - 2] = '1';
            }
            else {
                Map[playerX][playerY - 2] = 'A';
            }
        }
        break;
    }
    case(direction::RIGHT): {
      if (Map[playerX][playerY + 1] == 'A') {
        Map[playerX][playerY + 1] = '@';
            if (Map[playerX][playerY + 2] == 'a') {
                Map[playerX][playerY + 2] = '1';
            }
            else {
                Map[playerX][playerY + 2] = 'A';
            }
        }
        else {
          Map[playerX][playerY + 1] = '2';
          if (Map[playerX][playerY + 2] == 'a') {
            Map[playerX][playerY + 2] = '1';
          }
          else {
            Map[playerX][playerY + 2] = 'A';
          }
        }
      break;
    }
    default:
      break;
    }
}


const bool Sokoban::isWon()
{
  int W = width;
  int H = height; 

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (((Map[i][j] == 'a' || Map[i][j] == '2') && numBoxes >= numGoals) || (Map[i][j] == 'A' && numBoxes <= numGoals)) { // Win if there are no empty goals that can be filled
        return false;
      }
    }
  }
  return true;
}


std::istream& operator>> (std::istream& inStream, Sokoban& Game)
{
  inStream >> Game.height >> Game.width;
	
  std::cout << "Width is: " << Game.width << std::endl;
  std::cout << "Height is: " << Game.height << std::endl; 
	
  // Sets up reading point in the instream for reading level tiles
  // Not used: discarded
  char filter[5];
  inStream.getline(filter, 5);
	
  //char str[Game.getWidth()];
  std::string str;
  for (int i = 0; i < Game.getHeight(); i++) {
    //inStream.getline(str, Game.getWidth()+1);
    std::getline(inStream, str);
    std::cout << str << std::endl;
    Game.Map.push_back(str);
  }
  
  // Initialize player x & y
  // Initialize number of boxes & goals
  for (int i = 0; i < Game.getHeight(); i++) {
    for (int j = 0; j < Game.getWidth(); j++) {
      if (Game.Map[i][j] == '@') {
        Game.playerY = j;
        Game.playerX = i;
      }     
      if (Game.Map[i][j] == 'a') {
        Game.numGoals += 1;
      }
      if (Game.Map[i][j] == 'A') {
        Game.numBoxes += 1;
      }
    }
  }
  
  std::cout << "Player X is: " << Game.playerX << std::endl;
  std::cout << "Player Y is: " << Game.playerY << std::endl;
 
  std::cout << "Number of goals is: " << Game.numGoals << std::endl;
  std::cout << "Number of boxes is: " << Game.numBoxes << std::endl;
   	
  return inStream;
}

//void Sokoban::draw(sf::RenderTarget& target, sf::RenderStates states) const
void Sokoban::draw(sf::RenderWindow& w) const
{
  //-----=<  Textures  >=-----
	
  //   All images are 64x64 pixels
    	
  // Wall
  sf::Texture WALL_TEXTURE;
  WALL_TEXTURE.loadFromFile("block_06.png");
     	
  // Ground
  sf::Texture GROUND_TEXTURE;
  GROUND_TEXTURE.loadFromFile("ground_01.png");
    	 	
  // Goal
  sf::Texture GOAL_TEXTURE;
  GOAL_TEXTURE.loadFromFile("ground_04.png");
    	 	
  // Box
  sf::Texture BOX_TEXTURE;
  BOX_TEXTURE.loadFromFile("crate_03.png");
    	    	
  // Player (Down)
  sf::Texture PLAYER_DOWN_TEXTURE;
  PLAYER_DOWN_TEXTURE.loadFromFile("player_05.png");
    	 	
  // Player (Up)
  sf::Texture PLAYER_UP_TEXTURE;
  PLAYER_UP_TEXTURE.loadFromFile("player_08.png");
    	 	
  // Player (Left)
  sf::Texture PLAYER_LEFT_TEXTURE;
  PLAYER_LEFT_TEXTURE.loadFromFile("player_20.png");
    	
  // Player (Right)
  sf::Texture PLAYER_RIGHT_TEXTURE;
  PLAYER_RIGHT_TEXTURE.loadFromFile("player_17.png");
    	
  //-----=<++++++++++>=-----
    	
    	
  int W = width;
  int H = height; 
    	
  int TileX = 0;
  int TileY = 0;
  sf::Sprite tile; // tile to be drawn
  sf::Sprite tileGround; // tile ground (drawn under tile)
       
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
    
      if (Map[i][j] == '#') {
        tileGround.setTexture(GROUND_TEXTURE);
      	tileGround.setPosition(TileX, TileY); 
        tile.setTexture(WALL_TEXTURE);
        tile.setPosition(TileX, TileY);
        w.draw(tileGround);
        w.draw(tile);
      }
      
      else if (Map[i][j] == '.') {
        tile.setTexture(GROUND_TEXTURE);
        tile.setPosition(TileX, TileY);
        w.draw(tile);
      }
      
      else if (Map[i][j] == 'A') {
        tileGround.setTexture(GROUND_TEXTURE);
      	tileGround.setPosition(TileX, TileY);  
        tile.setTexture(BOX_TEXTURE);
        tile.setPosition(TileX, TileY);
        w.draw(tileGround);
        w.draw(tile);
      }
      
      else if (Map[i][j] == '@') {
        switch (playerDir) {
      	  case(direction::UP): {
      	    tile.setTexture(PLAYER_UP_TEXTURE);
      	    break;
      	  }
      	  case(direction::DOWN): {
      	    tile.setTexture(PLAYER_DOWN_TEXTURE);
      	    break;
      	  }
      	  case(direction::LEFT): {
      	    tile.setTexture(PLAYER_LEFT_TEXTURE);
      	    break;
      	  }
      	  case(direction::RIGHT): {
      	    tile.setTexture(PLAYER_RIGHT_TEXTURE);
      	    break;
      	  }
      	}
      	tileGround.setTexture(GROUND_TEXTURE);
      	tileGround.setPosition(TileX, TileY);
        tile.setPosition(TileX, TileY);
        w.draw(tileGround);
        w.draw(tile);
      }
      
      else if (Map[i][j] == 'a') {
        tile.setTexture(GOAL_TEXTURE);
        tile.setPosition(TileX, TileY);
        w.draw(tile);
      }
      // Player on goal
      else if (Map[i][j] == '2') {
      switch (playerDir) {
      	  case(direction::UP): {
      	    tile.setTexture(PLAYER_UP_TEXTURE);
      	    break;
      	  }
      	  case(direction::DOWN): {
      	    tile.setTexture(PLAYER_DOWN_TEXTURE);
      	    break;
      	  }
      	  case(direction::LEFT): {
      	    tile.setTexture(PLAYER_LEFT_TEXTURE);
      	    break;
      	  }
      	  case(direction::RIGHT): {
      	    tile.setTexture(PLAYER_RIGHT_TEXTURE);
      	    break;
      	  }
      	}
        tileGround.setTexture(GOAL_TEXTURE);
      	tileGround.setPosition(TileX, TileY);
        tile.setPosition(TileX, TileY);
        w.draw(tileGround);
        w.draw(tile);
      }
      else if (Map[i][j] == '1') {
        tileGround.setTexture(GOAL_TEXTURE);
      	tileGround.setPosition(TileX, TileY);
        tile.setTexture(BOX_TEXTURE);
        tile.setPosition(TileX, TileY);
        w.draw(tileGround);
        w.draw(tile);
      }
    			
      TileX += 64; // increment tile position in row
    }
    		
    TileY += 64; // increment tile postion in column
    TileX = 0;
    
  }    		
}
