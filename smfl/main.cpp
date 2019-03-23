#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>

#include"Ball.h"

using namespace sf;
using namespace std;

int main()
{
	Ball ball(400, 300);
	RenderWindow window{ VideoMode{800,600},"my window" };
	window.setFramerateLimit(60);
	
	Event event;
	while (true)
	{
		window.clear(Color::Black);
		window.pollEvent(event);

		if (event.type == Event::Closed)
		{
			window.close();
			break;
		}
		window.draw(ball);
		window.display();
	}

	return 0;
}