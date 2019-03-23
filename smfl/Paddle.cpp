#include "Paddle.h"
Paddle::Paddle(float t_X, float t_Y)
{
	shape.setPosition(t_X, t_Y);
	shape.setSize({ 20,20 });
	shape.setFillColor(Color::Green);
	shape.setOrigin(paddleWidth / 2.f, paddleHeight / 2.f); // ball center(origin) is deafault set on the top left to move it to the center we add radious on OX and OY
}
void Paddle::draw(RenderTarget& target, RenderStates state)const {
	target.draw(this->shape, state);
}
void Paddle::update()
{
	this->shape.move(this->velocity); // gets vector vector(x,y) 


	if (Keyboard::isKeyPressed(Keyboard::Key::Left) && this->left() > 0)
		velocity.x = -paddleVelocity;
	else if (Keyboard::isKeyPressed(Keyboard::Key::Right) && this->right() < 800)
		velocity.x = paddleVelocity;
	else
		velocity.x = 0;

}
float Paddle::left()
{
	return this->shape.getPosition().x - shape.getSize().x / 2.f;
}
float Paddle::right()
{
	return this->shape.getPosition().x + shape.getSize().x / 2.f;
}
float Paddle::top()
{
	return this->shape.getPosition().y - shape.getSize().y / 2.f;
}
float Paddle::bottom()
{
	return this->shape.getPosition().y + shape.getSize().y / 2.f;
}
