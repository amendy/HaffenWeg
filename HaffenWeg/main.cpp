#include "Graph.h"
#include "GUI.h"
#include "Connection.h"
#include "Haffen.h"
#include "Schiff.h"
#include "Info.h"
#include <iostream>
#include <string>
#include <algorithm>


// Funktion to make tow way Edge.
void makeReversedConnection(Graph *ptrG, Node& rSrc, Node& rDes, double distance)
{
	ptrG->addEdge(new Connection(rSrc, rDes, distance));
	ptrG->addEdge(new Connection(rDes, rSrc, distance));
}

using namespace std;


int main()
{
	GUI gui; 
	Node& rWittenberge = gui.addNode(new Haffen("Wittenberge", 1));
	Node& rBrandenburg = gui.addNode(new Haffen("Brandenburg", 1));
	Node& rRathenaw = gui.addNode(new Haffen("Rathenaw", 1));
	Node& rHavelPortBerlin = gui.addNode(new Haffen("Havel Port Berlin", 1));
	Node& rVelten = gui.addNode(new Haffen("Velten", 1));
	Node& rWestHafenBerlin = gui.addNode(new Haffen("WestHafen Berlin", 1));
	Node& rSpandau = gui.addNode(new Haffen("Spandau", 2));
	Node& rEberswalde = gui.addNode(new Haffen("Eberswalde", 1));
	Node& rRuedersdorf = gui.addNode(new Haffen("Ruedersdorf", 1));
	Node& rWoltersdorf = gui.addNode(new Haffen("Woltersdorf", 2));
	Node& rKoenigWusterhausen = gui.addNode(new Haffen("Koenig Wusterhausen", 1));
	Node& rEisenhuettenstadt = gui.addNode(new Haffen("Eisenhuettenstadt", 1));
	Node& rSchwedet = gui.addNode(new Haffen("Schwedet", 1));
	Node& rNordEnde = gui.addNode(new Haffen("Nord Ende", 3));
	Node& rSudEnde = gui.addNode(new Haffen("Sud Ende", 3));

	makeReversedConnection(&gui, rWittenberge, rRathenaw, 80);
	makeReversedConnection(&gui, rBrandenburg, rRathenaw, 40);
	makeReversedConnection(&gui, rBrandenburg, rHavelPortBerlin, 40);
	makeReversedConnection(&gui, rHavelPortBerlin, rVelten, 40);
	makeReversedConnection(&gui, rHavelPortBerlin, rSpandau, 15);
	makeReversedConnection(&gui, rHavelPortBerlin, rSudEnde, 70);

	makeReversedConnection(&gui, rVelten, rEberswalde, 60);
	makeReversedConnection(&gui, rVelten, rWestHafenBerlin, 30);
	makeReversedConnection(&gui, rWestHafenBerlin, rSudEnde, 40);
	makeReversedConnection(&gui, rWestHafenBerlin, rSpandau, 15);

	makeReversedConnection(&gui, rEberswalde, rNordEnde, 40);
	makeReversedConnection(&gui, rSchwedet, rNordEnde, 40);
	makeReversedConnection(&gui, rEisenhuettenstadt, rSudEnde, 90);
	makeReversedConnection(&gui, rEisenhuettenstadt, rNordEnde, 120);

	makeReversedConnection(&gui, rRuedersdorf, rWoltersdorf, 10);
	makeReversedConnection(&gui, rWoltersdorf, rSudEnde, 10);
	makeReversedConnection(&gui, rKoenigWusterhausen, rSudEnde, 10);

	Schiff* rBerlin = new Schiff("Berlin", 3, static_cast<Haffen*>(&rEisenhuettenstadt));
	Schiff* rSachsen = new Schiff("Sachsen", 4, static_cast<Haffen*>(&rVelten));
	Schiff* rCottbus = new Schiff("Cottbus", 3, static_cast<Haffen*>(&rSchwedet));
	Schiff* rDonau = new Schiff("Donau", 1, static_cast<Haffen*>(&rWestHafenBerlin));
	Schiff* rElbe = new Schiff("Elbe", 1, static_cast<Haffen*>(&rRuedersdorf));

	vector<Schiff*> alleSchiffe;
	alleSchiffe.push_back(rBerlin);
	alleSchiffe.push_back(rCottbus);
	alleSchiffe.push_back(rSachsen);
	alleSchiffe.push_back(rDonau);
	alleSchiffe.push_back(rElbe);
	gui.setSchiffe(alleSchiffe);


	bool bRunning = true;

	// Endlosschleife, bis bRunning auf 'false' gesetzt wird
	while (bRunning)
	{
		int menuEntry = gui.showMenu();

		// Hinweis: Die Fallunterscheidung geht auch mit Switch-Case (siehe C-Programmierung)



		switch (menuEntry)
		{
		case 1:
			gui.Netzzeigen(); 
			break;

		case 2:
			gui.TransportAuftrag(); 
			break;
		case 3:
			gui.PlanenundAusfuehren();
			break;
		case 4:
			gui.TransportListe();
			break;
		case 5: 
			gui.PositionSchiffe();
			break;
		case 6:
			bRunning = false;
			break;

		default:
			break;
		}
	}
	system("pause");
	return 0;
}