#pragma once
#include<SFML/Graphics.hpp>

using namespace sf;
class Paddle : public Drawable // Drawable makes possible to use window.draw(Ball)
{
private:
	RectangleShape shape;
	const float paddleWidth{ 80.0f };
	const float paddleHeight{ 20.0f };
	const float paddleVelocity{ 6.0f };
	Vector2f velocity{ paddleVelocity, 0.f };
	void draw(RenderTarget& target, RenderStates state) const override; // to use window.draw(Ball)
public:
	Paddle(float t_X, float t_Y);
	Paddle() = delete;;
	~Paddle() = default;

	void update();

	float left();
	float right();
	float top();
	float bottom();

};

