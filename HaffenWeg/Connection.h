#pragma once
#include "Edge.h"

extern double geschwendigkeit; 

class Connection : public Edge
{
public:
	Connection(Node& rSrc, Node& rDst, double distance) : Edge(rSrc, rDst), m_distance(distance) {}

	virtual double getWeight() { return m_distance / geschwendigkeit; }
	double getDistance() { return m_distance; }

private:
	double m_distance;
};
