#pragma once
#include<SFML/Graphics.hpp>

using namespace sf;
class Ball : public Drawable // Drawable makes possible to use window.draw(Ball)
{
private:
	CircleShape shape;
	const float ballRadius{ 10.0f };
	const float ballVelocity{ 5.0f };
	Vector2f velocity{ ballVelocity, ballVelocity };
	void draw(RenderTarget& target, RenderStates state) const override; // to use window.draw(Ball)
public:
	Ball(float t_X, float t_Y);
	Ball() = delete;;
	~Ball() = default;

	Vector2f getPosition();

	void update();

	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();

	float left();
	float right();
	float top();
	float bottom();

};

