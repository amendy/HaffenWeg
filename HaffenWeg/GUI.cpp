#include "GUI.h"
#include "Graph.h"
#include "Connection.h"
#include "Haffen.h"
#include "Schiff.h"
#include "Info.h"
#include "Connection.h"
#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <vector>

using namespace std;

vector<Haffen*> sortedHaffen;
Node* startHaffen = NULL;
Node* zielHaffen = NULL;
int transportMenge = 0;
vector <Schiff*> geeigneteShiff;
double gesamtCost = 0;
double gesamtZeit = 0;
vector <Info> alleTransportListe;
double geschwendigkeit = 0;// to set the speed



int GUI::showMenu()
{
	cout << " Bitte waehlen Sie eine Aktion aus" << endl
		<< "1- Schifffahrtswegenetz ausgeben: " << endl
		<< "2- Transportauftrag erfassen: " << endl
		<< "3- Transport planen und ausfuehren:" << endl
		<< "4- Gesamtliste der ausgefuehrten Transporte ausgeben:" << endl
		<< "5- Positionen der Schiffe ausgeben " << endl
		<< "6- Programm beenden" << endl;

	cout << "Eingabe: ";
	int eingabe;
	cin >> eingabe;
	return eingabe;
}

void GUI::Netzzeigen()
{
	
	list<Node*> sortedNode = this->getNodes();
	list<Edge*> sortedEdge = this->getEdges();
	// Sortieren der Haeffen 
	
	cout << "Alphabetisch: " << endl;
	sortedNode.sort([](const Node* a, const Node* b) {return a->getID() < b->getID(); });
	for (auto tmpIt = sortedNode.begin(); tmpIt != sortedNode.end(); tmpIt++)
	{
		Haffen* tmpHaffen = static_cast<Haffen*> (*tmpIt);
		sortedHaffen.push_back(tmpHaffen);

		cout << tmpHaffen->getID() << " ; Type: " << tmpHaffen->getTypNaame() << endl;
		for (auto tmpEdge = sortedEdge.begin(); tmpEdge != sortedEdge.end(); tmpEdge++)
		{
			Connection* tmpConnection = dynamic_cast<Connection*> (*tmpEdge);
			if (tmpConnection->getSrcNode().getID() == tmpHaffen->getID())
			{
				cout << "	" << tmpConnection->toString() << " ; Distance: "
					<< tmpConnection->getDistance() << endl;
			}

		}
	}


	sortedNode.sort([](Node* a, Node* b) { return
		static_cast<Haffen*>(a)->getTyp() <
		static_cast<Haffen*>(b)->getTyp();

	});
	cout << "Thematisch: " << endl;
	for (auto tmpIt = sortedNode.begin(); tmpIt != sortedNode.end(); tmpIt++)
	{

		Haffen* tmpHaffen = static_cast <Haffen*> (*tmpIt);

		cout << tmpHaffen->getID() << " ; Type: " << tmpHaffen->getTypNaame() << endl;
		for (auto tmpEdge = sortedEdge.begin(); tmpEdge != sortedEdge.end(); tmpEdge++)
		{
			Connection* tmpConnection = dynamic_cast<Connection*> (*tmpEdge);
			if (tmpConnection->getSrcNode().getID() == tmpHaffen->getID())
			{
				cout << "	" << tmpConnection->toString() << " ; Distance: "
					<< tmpConnection->getDistance() << endl;
			}

		}
	}

}
void GUI::TransportAuftrag()
{
	cout << "" << endl;
	for (auto i : this->getNodes())
	{
		cout << "StartHaffen" << i->getID() << endl;

	}
	string eingabe1;
	cout << " Start Haffen: ";
	cin >> eingabe1;
	cout << endl;
	while (this->findNode(eingabe1) == NULL)
	{
		cout << "Haffen nicht gefunden. " << endl;
		cin >> eingabe1;
	}


	string eingabe2;
	cout << " Ziel Haffen: ";
	cin >> eingabe2;
	cout << endl;
	while (this->findNode(eingabe2) == NULL)
	{
		cout << "Haffen nicht gefunden. " << endl;
		cin >> eingabe2;
	}
	double transportmenge;
	cout << "Transportmenge angeben: ";
	cin >> transportmenge;
	while (transportmenge < 100 && transportmenge > 1350)
	{
		cout << "Menge muss zwischen 100 und 1350 liegen" << endl;
		cin >> transportmenge;
	}

	// Wo wird diese Eingabe gespeichert? Sodass HaffenStart jetzt Haffen1- Eingabe1 wird
	Auftrag* auftrag=new Auftrag();
	auftrag->startHaffen = findNode(eingabe1);
	auftrag->zielHaffen = findNode(eingabe2);
	auftrag->TransportMenge = transportmenge;
	this->auftraege.push_back(auftrag);
	for( auto i: this->auftraege)
	{
		cout << "Auftrag Starthaffen " << i->startHaffen->getID();
		
	}
}

void GUI::Schiffauswaehlen()
{
	
	cout << " waehlen Sie aus: " ; 
	string schiffwahl; 
	cin >> schiffwahl; 
	cout << endl; 

	for (auto i : this->getSchiff())
	{
		if (i->getName() == schiffwahl)
		{
			cout << "Schiff" << i->getName() << "Schiffklasse" << i->getTyp() << endl;
			auftraege.at(auftraege.size() - 1)->schiffwahl = i;
		}
	}
	
	// Give the element at the last

}
void GUI::PlanenundAusfuehren()
{
	

	
	
	

	

}
void GUI::TransportListe()
{
	

	

}

void GUI::PositionSchiffe()
{
		vector <Schiff*> geeigneteShiff;
	

		for(auto i : this->getSchiff())
		{
			cout << " Name des Schiffes " << i->getName() << endl
				<< " SchiffsKlasse " << i->getTyp() << endl
				<< " Position des Haffens " << i->getPosition() << endl;
		}
	
}
