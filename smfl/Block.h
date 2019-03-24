#pragma once
#include<SFML/Graphics.hpp>

using namespace sf;
class Block : public Drawable // Drawable makes possible to use window.draw(Ball)
{
private:
	RectangleShape shape;
	const float Width{ 80.0f };
	const float Height{ 20.0f };
	bool Destroy=false;
	void draw(RenderTarget& target, RenderStates state) const override; // to use window.draw(Ball)
public:
	Block(float t_X, float t_Y);
	Block() = delete;;
	~Block() = default;

	Vector2f getPosition();


	void update();

	float left();
	float right();
	float top();
	float bottom();

	void destroy();
	bool isDestroyed();
};

