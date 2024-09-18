/// <summary>
/// The most broken code ive done so far xD
/// 
/// bejeweled mock
/// </summary>


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
#include <string.h>

const int ROWS = 25;
const int COLUMNS = 25;
const float tileSize = 64.0f;
int m_grid[ROWS][COLUMNS]{};
sf::RectangleShape textures[ROWS][COLUMNS];
sf::Sprite blueGem, redGem, yellowGem, greenGem;
sf::Text scoreScreen;
sf::Texture blueGemText, redGemText, yellowGemText, greenGemText;
sf::Font font;
int score = 0;
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
	else if (index > 0 && index < ROWS && 
		(t_grid[index][jndex] == t_grid[index - 1][jndex] && //    #
		t_grid[index][jndex] == t_grid[index + 1][jndex])  //      X and it isnt out of bounds
 		) ///													   #
	{
		return true;
	}
	else if (index > 1 &&//										X
		t_grid[index][jndex] == t_grid[index - 1][jndex] &&//	#
		t_grid[index][jndex] == t_grid[index - 2][jndex])//		#
	{
		return true;
	}
	else if (index < (ROWS - 1) && t_grid[index][jndex] == t_grid[index + 1][jndex] &&
		t_grid[index][jndex] == t_grid[index + 2][jndex])
	{
		return true;
	}

	else {
		return false;
	}
}

static void update(sf::Vector2i& mousePos) {
	for (int jndex = 0; jndex < COLUMNS; jndex++) //checks columns
	{
		for (int index = 0; index < ROWS; index++) //checks rows
		{
				if (textures[index][jndex].getFillColor() == sf::Color::Black)
				{
					// Move tiles up
					for (int i = jndex; i > 0; i--) {
						if (i - 1 >= 0) { // Ensure the index is in bounds
							m_grid[index][i] = m_grid[index][i - 1];
							textures[index][i].setFillColor(textures[index][i - 1].getFillColor());
						}
					}
				}
			std::cout << m_grid[index][jndex] << " ";
		}
		std::cout << std::endl;
	}

	for (int jndex = 0; jndex < COLUMNS; jndex++) //checks columns
	{
		for (int index = 0; index < ROWS; index++) //checks rows
		{
			if (checkForAdjacentMatch(m_grid, index, jndex)) //if there are 3 or more
			{
				if (textures[index][jndex].getFillColor() != sf::Color::Black)
				{
					textures[index][jndex].setFillColor(sf::Color::Black);
					score = score + 3;
					m_grid[0][jndex] = rand() % 4; // New random tile at the top row
					switch (m_grid[0][jndex]) {
						case 0: textures[index][0].setFillColor(sf::Color::Red); break;
						case 1: textures[index][0].setFillColor(sf::Color::Blue); break;
						case 2: textures[index][0].setFillColor(sf::Color::Yellow); break;
						case 3: textures[index][0].setFillColor(sf::Color(127, 193, 3)); break;
					}
				}
			}
		}
	}

	for (int jndex = 0; jndex < COLUMNS; jndex++) {
		for (int index = 0; index < ROWS; index++) {
			if (textures[index][jndex].getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					// Handle tile selection and swapping logic here
				}
			}
		}
	}
	std::cout << std::endl;
	scoreScreen.setString(std::to_string(score));
}


static void draw(sf::RenderWindow& t_window) {
	t_window.clear(sf::Color::Black);
	for (int jndex = 0; jndex < COLUMNS; jndex++)
	{
		for (int index = 0; index < ROWS; index++)
		{
			t_window.draw(textures[index][jndex]);
		}
	}
	t_window.draw(scoreScreen);
	t_window.display();
}



int main()
{
	srand(time(nullptr));
	sf::RenderWindow window(sf::VideoMode(64.f + (ROWS * tileSize), 64.f + COLUMNS * tileSize, 32), "SFML-STATIC");

	sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	
	
	for (size_t j = 0; j < COLUMNS; j++)
	{
		for (size_t i = 0; i < ROWS; i++)
		{
			textures[i][j].setSize(sf::Vector2f(tileSize, tileSize));
			textures[i][j].setPosition(sf::Vector2f(tileSize * i, tileSize * j));
		}
	}


	for (size_t j = 0; j < COLUMNS; j++)
	{
		for (size_t i = 0; i < ROWS; i++)
		{
			int color = rand() % 4;
			m_grid[i][j] = color;
			switch (color)
			{
			case 0: textures[i][j].setFillColor(sf::Color::Red); break;
			case 1: textures[i][j].setTexture.; break;
			case 2: textures[i][j].setFillColor(sf::Color::Yellow); break;
			case 3:	textures[i][j].setFillColor(sf::Color(127, 193, 3));break;
			default:break;
			}
			std::cout << m_grid[i][j] << " ";
		}
		std::cout << std::endl;
	}

	if (!font.loadFromFile("Nau sea.otf"))
	{

	}
	if (!blueGem.loadFromFile("Blue_gem.png"))
	{

	}
	if (!yellowGem.loadFromFile("Yellow_gem.png"))
	{

	}
	if (!greenGem.loadFromFile("Green_gem.png"))
	{

	}

	scoreScreen.setFillColor(sf::Color::White);
	scoreScreen.setString(std::to_string(score));
	scoreScreen.setFont(font);
	scoreScreen.setCharacterSize(50);
	scoreScreen.setPosition((1 * tileSize) + 1, (ROWS * tileSize) + 1);
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	const float fps{ 10.0f };
	sf::Time timePerFrame = sf::seconds(1.0f / fps); // 60 fps
	sf::Event event;
	
	//////////////////////////////////////////////////
	/// End of initialization
	//////////////////////////////////////////////////

	

	while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                window.close();
            }
			
        }

        // Ensure the game is updated at a fixed frame rate
        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate > timePerFrame) {
            timeSinceLastUpdate -= timePerFrame;
            update(mousePos); // Update game logic
        }

        draw(window); // Draw the grid
    }

    return 0;
}