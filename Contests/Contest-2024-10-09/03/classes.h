#pragma once

class Water
{
	public:
		Water();
		Water(int t);
		void AddTemperature(int temperature);
		int GetTemperature();

	private:
		int temperature;

};

Water::Water ()
{
	temperature = 0;
}

Water::Water (int temperature)
{
	this->temperature = temperature;
}

void Water::AddTemperature (int temperature)
{
	this->temperature += temperature;
}

int Water::GetTemperature ()
{
	return this->temperature;
}


class Teapot
{
	public:
		Teapot(Water water);
		void heat_up(int temperature);
		bool is_boiling();

	private:
		Water water;

};

Teapot::Teapot(Water water)
{
	this->water = water;
}

void Teapot::heat_up(int temperature)
{
	this->water.AddTemperature(temperature);
}

bool Teapot::is_boiling()
{
	return this->water.GetTemperature() >= 100;
}
