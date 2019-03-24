#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>

#include"Ball.h"
#include"Paddle.h"
#include"Block.h"

using namespace sf;
using namespace std;

template<class T1, class T2> bool isIntersecting(T1& A, T2& B)
{
	return A.right() >= B.left() && A.left() <= B.right()
		&& A.bottom() >= B.top() && A.top() <= B.bottom();
}

void collisionTestBlockBall(Block & block, Ball& ball)
{
	if (isIntersecting(block, ball))
		block.destroy();
}
bool collisionTest(Paddle& paddle, Ball& ball)
{
	if (!isIntersecting(paddle, ball))
		return false;

	ball.moveUp();

	if (ball.getPosition().x < paddle.getPosition().x)
		ball.moveLeft();
	else if (ball.getPosition().x > paddle.getPosition().x)
		ball.moveRight();
}

int main()
{
	Ball ball(400, 300);
	Paddle paddle(400, 500);
	Block block(100, 100);
	Block block1(200, 100);

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
		collisionTest(paddle, ball);
		collisionTestBlockBall(block, ball);
		collisionTestBlockBall(block1, ball);

		//collisionTest(paddle, ball);

		window.draw(paddle);
		window.draw(ball);
		if (!block.isDestroyed())
			window.draw(block);
		if (!block1.isDestroyed())
			window.draw(block1);
		window.display();

	}

	return 0;
}