// Nicholas Matsuda

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include "Sokoban.h"

int main(int argc, char* argv[]) {

  // Verrify argument: Level
  if (argc < 1) { 
    std::cerr << "Usage: LEVEL-NAME (e.g. level1.lvl)" << std::endl;
    return 1;
  }
    	
  // LevelName
  std::string LevelName = argv[1];
  //std::cout << "Level name is: " << LevelName << std::endl;

  // Create game object
  Sokoban GAME = Sokoban();
  //std::cout << "Made default game object." << std::endl;
	
  std::ifstream inputFile;
  inputFile.open(LevelName); 

  if (!inputFile) {
    std::cerr << "Unable to open file\n"; 
    return 1;
  }
    	
    	
  // Initialize Game State from input level file
  inputFile >> GAME;
  std::cout << "Initialized Gamestate." << std::endl;
    	
  sf::RenderWindow window(sf::VideoMode(64 * GAME.getWidth(), 64 * GAME.getHeight()), "Sokoban");
  window.setFramerateLimit(60);
    
  // Draw Loop
  while (window.isOpen())
  {
  sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
        window.close();
      // Keyboard Input  
      if (event.type == sf::Event::KeyPressed) {
        
        if ((event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::W) && !GAME.isWon()) {        
          GAME.movePlayer(direction::UP);
        }
        
        if ((event.key.code == sf::Keyboard::Down || event.key.code == sf::Keyboard::S) && !GAME.isWon()) {
	  GAME.movePlayer(direction::DOWN);
        }
        
        if((event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::A) && !GAME.isWon()) {
          GAME.movePlayer(direction::LEFT);
        }
        
        if ((event.key.code == sf::Keyboard::Right || event.key.code == sf::Keyboard::D) && !GAME.isWon()) {
          GAME.movePlayer(direction::RIGHT);
        }
        
        // Restart: Reinitialize game state, close & reopen inputFile (reset stream postion) reread inputFile
        if(event.key.code == sf::Keyboard::R) {
          std::cout << "Command: Reset Game." << std::endl;
          GAME = Sokoban();
          inputFile.close();
          inputFile.open(LevelName); 
          inputFile >> GAME;
        }
        
      }
      
    }
    
    
	  	
    window.clear();
    GAME.draw(window);
    if (GAME.isWon()) {
      //std::cout << "Game won." << std::endl;
      sf::Text text;
      sf::Font font;
      font.loadFromFile("SuperMario256.ttf");
      text.setString("You won!");
      text.setCharacterSize(48);
      text.setFont(font);
      text.setFillColor(sf::Color::White);
      text.setPosition(20 * GAME.getWidth(), 28 * GAME.getHeight());
      window.draw(text);
    }
    window.display();

  }

	return 0;
}
