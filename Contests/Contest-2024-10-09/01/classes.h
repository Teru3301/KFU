#pragma once

class Cat
{
	public:
		bool is_alive();
		void ChangeAlive();

	private:
		bool alive;

};

class Box
{
	public:
		Cat open();

	private:
		Cat cat;
		void ChangeAlive();
		bool is_not_opend = true;
};


bool Cat::is_alive()
{
	return this->alive;
}

void Cat::ChangeAlive ()
{
	this->alive = (rand() % 2);
}

Cat Box::open()
{
	if (is_not_opend) this->cat.ChangeAlive();
	this->is_not_opend = false;
	return cat;
}


