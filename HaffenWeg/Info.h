#pragma once
#include"Node.h"

using namespace std;

struct Info
{
	Node* m_StartHafen;
	Node* m_ZielHafen;
	std::string m_nameDesShiffes;
	int m_klasseDesShiffes;
	double m_fahrKost;
	double m_zeitBedarf;
};
