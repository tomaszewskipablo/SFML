#pragma once
#include<SFML/Graphics.hpp>

using namespace sf;
class Ball: public Drawable // Drawable makes possible to use window.draw(Ball)
{
private:
	CircleShape shape;
	const float ballRadius{ 10.0f };
	void draw(RenderTarget& target, RenderStates state) const override; // to use window.draw(Ball)
public:
	Ball(float t_X, float t_Y);
	Ball() = delete;;
	~Ball()= default;
	
};

