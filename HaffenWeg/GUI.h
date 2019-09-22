#pragma once
#include "Graph.h"
#include "Node.h"
#include "Edge.h"
#include "Schiff.h"
#include "Info.h"
#include <vector>

using namespace std;

struct Auftrag {
	Node* startHaffen;
	Node* zielHaffen;
	double TransportMenge;
	Schiff* schiffwahl;


};
class GUI : public Graph
{
public:
	int showMenu();
	void Netzzeigen(); 
	void TransportAuftrag(); 
	void Schiffauswaehlen(); 
	void PlanenundAusfuehren(); 
	vector<Schiff*> getSchiff(){ return alleSchiffe; };
	void setSchiffe(vector<Schiff*> schiffe) { alleSchiffe = schiffe; };
	
	vector <Info> alleTransportListe;
	void TransportListe(); 
	void PositionSchiffe(); 

	

private:
	vector<Schiff*> alleSchiffe;
	vector <Schiff*> geeigneteShiff;
	vector<Auftrag*> auftraege; 
	
	



};



