#pragma once
#pragma once
#include"Node.h"
using namespace std;

class Haffen : public Node
{
public:
	Haffen(string name, int type = 0) : Node(name), m_type(type)
	{
		if (type == 1)
		{
			m_typeName = "Haffen";
			m_zuzatsZeit = 0;
			m_zuzatsKost = 0;
		}
		else if (type = 2)
		{
			m_typeName = "Schleuse";
			m_zuzatsZeit = 30;
			m_zuzatsKost = 10;

		}
		else
		{
			m_typeName = "Complex";
			m_zuzatsZeit = 0;
			m_zuzatsKost = 0;

		}
	}

	string getTypNaame() { return m_typeName; }
	int getTyp() { return m_type; }
	double getZusatsZeit() { return m_zuzatsZeit; }
	double getZusatsKost() { return m_zuzatsKost; }

private:
	int m_type;
	string m_typeName;
	double m_zuzatsZeit;
	double m_zuzatsKost;
};



