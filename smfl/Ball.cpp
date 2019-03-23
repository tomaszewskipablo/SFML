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


//Ball::Ball()
//{
//}
//
//
//Ball::~Ball()
//{
//}
