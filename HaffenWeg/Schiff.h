#pragma once
#include"Haffen.h"

using namespace std;

class Schiff {
public:
	Schiff(std::string name, int typ, Haffen* position) : m_name(name), m_typ(typ), m_position(position) {
		if (typ == 1) {
			m_capacity = 300;
			m_speed = 14.5;
			m_cost = 0.06;
		}
		else if (typ == 3) {
			m_capacity = 650;
			m_speed = 12;
			m_cost = 0.05;
		}
		else if (typ == 4) {
			m_capacity = 1350;
			m_speed = 10;
			m_cost = 0.03;
		}
		else {
			m_capacity = 0;
			m_speed = 0;
			m_cost = 0;
		}
	}

	string getName() { return m_name; }
	int getTyp() { return m_typ; }
	Haffen* getPosition() { return m_position; }
	double getSpeed() { return m_speed; }
	double getCapacity() { return m_capacity; }
	double getCost() { return m_cost; }

	void setPosition(Haffen* newPosition) { m_position = newPosition; }

private:
	std::string m_name;
	int m_typ;
	Haffen* m_position;
	double m_speed, m_capacity, m_cost;
};
