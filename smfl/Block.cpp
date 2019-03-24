#include "Block.h"

Block::Block(float t_X, float t_Y)
{
	shape.setPosition(t_X, t_Y);
	shape.setSize({ 80,30 });
	shape.setFillColor(Color::Yellow);
	shape.setOrigin(Width / 2.f, Height / 2.f);
}
void Block::draw(RenderTarget& target, RenderStates state)const {
	target.draw(this->shape, state);
}

Vector2f Block::getPosition()
{
	return shape.getPosition();
}


void Block::update()
{
//	~Block();
	;
}

float Block::left()
{
	return this->shape.getPosition().x - shape.getSize().x / 2.f;
}
float Block::right()
{
	return this->shape.getPosition().x + shape.getSize().x / 2.f;
}
float Block::top()
{
	return this->shape.getPosition().y - shape.getSize().y / 2.f;
}
float Block::bottom()
{
	return this->shape.getPosition().y + shape.getSize().y / 2.f;
}

void Block::destroy()
{
	this->Destroy = true;
}
bool Block::isDestroyed()
{
	return this->Destroy;
}