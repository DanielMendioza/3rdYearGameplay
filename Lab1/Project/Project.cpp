#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib")
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 
#include <SFML/Graphics.hpp>
#include <iostream>

const int ROWS = 25;
const int COLUMNS = 25;
const float tileSize = 64.0f;

static void falling(sf::RenderWindow& t_window, sf::RectangleShape& t_gem, int& t_grid) {
	sf::Vector2f currentpos = t_gem.getPosition();
	for (size_t i = 0; i < 60; i++)
	{
		currentpos.y = currentpos.y - 1.66;
		t_window.draw(t_gem);
	}
	
}

static bool checkForAdjacentMatch(int(&t_grid)[ROWS][COLUMNS], int& index, int& jndex) {
	if ((t_grid[index][jndex] == t_grid[index][jndex - 1] &&
		t_grid[index][jndex] == t_grid[index][jndex + 1] &&
		jndex > 0 && jndex < COLUMNS))// # X # and it isnt the first or last
	{
		return true;
	}

	else if (t_grid[index][jndex] == t_grid[index][jndex - 1] &&
		t_grid[index][jndex] == t_grid[index][jndex - 2] &&
		jndex > 1)// # # X and it isnt the first 2
	{
		return true;
	}
	else if (t_grid[index][jndex] == t_grid[index][jndex + 1] &&
		t_grid[index][jndex] == t_grid[index][jndex + 2] &&
		jndex < (COLUMNS - 1)) // X # # and it isnt the last 2
	{
		return true;
	}
	else if ((t_grid[index][jndex] == t_grid[index -1][jndex] &&
			  t_grid[index][jndex] == t_grid[index + 1][jndex]) &&
			  index > 0 && index < ROWS)
	{
		return true;
	}

	else if (t_grid[index][jndex] == t_grid[index - 1][jndex] &&
			 t_grid[index][jndex] == t_grid[index - 2][jndex] &&
			 index > 1)
	{
		return true;
	}
	else if (t_grid[index][jndex] == t_grid[index + 1][jndex] &&
			 t_grid[index][jndex] == t_grid[index + 2][jndex] &&
			 index < (ROWS - 1))
	{
		return true;
	}

	else {
		return false;
	}
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(ROWS * tileSize, COLUMNS * tileSize, 32), "SFML-STATIC");
	////////////////////////
	/// Initialization
	////////////////////////
	int m_grid[ROWS][COLUMNS]{};
	sf::RectangleShape textures[ROWS][COLUMNS];
	int m_gridInt[ROWS][COLUMNS]{};
	bool isMatch = false;
	bool isFalling = false;
	bool isMoving = false;

	sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	////////////////////////
	/// Setup the "Gems"
	////////////////////////
	for (size_t i = 0; i < ROWS; i++)
	{
		for (size_t j = 0; j < COLUMNS; j++)
		{
			textures[i][j].setSize(sf::Vector2f(tileSize, tileSize));
			textures[i][j].setPosition(sf::Vector2f(tileSize * i, tileSize * j));
		}
	}


	for (size_t i = 0; i < ROWS; i++)
	{
		for (size_t j = 0; j < COLUMNS; j++)
		{
			int color = rand() % 4;
			m_grid[i][j] = color;
			switch (color)
			{
			case 0:
				textures[i][j].setFillColor(sf::Color::Red);
				break;
			case 1:
				textures[i][j].setFillColor(sf::Color::Blue);
				break;
			case 2:
				textures[i][j].setFillColor(sf::Color::Yellow);
				break;
			case 3:
				textures[i][j].setFillColor(sf::Color(127, 193, 3));
				break;
			default:
				break;
			}
			std::cout << m_grid[i][j] << " ";
		}
		std::cout << std::endl;
	}

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.close();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}

		window.clear(sf::Color::Black);


		for (size_t i = 0; i < ROWS; i++)
		{
			for (size_t j = 0; j < COLUMNS; j++)
			{
				if (isFalling) {
					falling(window, textures[i][j], m_grid[i][j]);
				}
			}
		}

		for (int index = 0; index < ROWS; index++)
		{
			for (int jndex = 0; jndex < COLUMNS; jndex++)
			{
				window.draw(textures[index][jndex]);
				
			}
		}

		for (int index = 0; index < ROWS; index++)
		{
			for (int jndex = 0; jndex < COLUMNS; jndex++) 
			{
				if (checkForAdjacentMatch(m_grid, index, jndex))
				{
					if (textures[index][jndex].getFillColor() != sf::Color::Black) 
					{
						{
							textures[index][jndex].setFillColor(sf::Color::Black);
						}
					}
				}
			}
		}
		window.display();

	}
		return 0;
}