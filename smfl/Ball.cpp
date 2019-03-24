#include "Ball.h"
Ball::Ball(float t_X, float t_Y)
{
	shape.setPosition(t_X, t_Y);
	shape.setRadius(this->ballRadius);
	shape.setFillColor(Color::White);
	shape.setOrigin(this->ballRadius, this->ballRadius); // ball center(origin) is deafault set on the top left to move it to the center we add radious on OX and OY
}
void Ball::draw(RenderTarget& target, RenderStates state)const {
	target.draw(this->shape, state);
}
Vector2f Ball::getPosition()
{
	return shape.getPosition();
}

void Ball::update()
{
	shape.move(this->velocity); // gets vector vector(x,y) 

	if (this->left() < 0)
		velocity.x = ballVelocity;
	else if(this->right() > 800)
		velocity.x = -ballVelocity;
	if (this->top() < 0)
		velocity.y = ballVelocity;
	else if (this->bottom()> 600)
		velocity.y = -ballVelocity;
}
void Ball::moveUp(){
	velocity.y = -ballVelocity;
}
void Ball::moveDown(){
	velocity.y = ballVelocity;
}
void Ball::moveLeft() {
	velocity.x = -ballVelocity;
}
void Ball::moveRight() {
	velocity.x = ballVelocity;
}

float Ball::left()
{
	return this->shape.getPosition().x - shape.getRadius();
}
float Ball::right()
{
	return this->shape.getPosition().x + shape.getRadius();
}
float Ball::top()
{
	return this->shape.getPosition().y - shape.getRadius();
}
float Ball::bottom()
{
	return this->shape.getPosition().y + shape.getRadius();
}
