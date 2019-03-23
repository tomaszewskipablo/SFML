#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>

#include"Ball.h"
#include"Paddle.h"

using namespace sf;
using namespace std;

int main()
{
	Ball ball(400, 300);
	Paddle paddle(400, 500);
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
		ball.update();
		paddle.update();
		window.draw(paddle);
		window.draw(ball);
		window.display();
	}

	return 0;
}