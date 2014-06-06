#ifndef __PARSER__
#define __PARSER__

#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <list>
#include "Probleme.h"

using namespace std;

class Parser {

	private:
		int n; // nb produits
		int m;
		float eta;
		int c; // capacite transporteur

		vector<Client*> clients;
		vector<Produit*> produits;

        void parseFile(string name);
        void removeSpaces(string &str);

	public:
		Parser(string filename);
		~Parser(){} // TODO
		void printProduits();

		float getEta();
		int getCapa();
		vector<Client*> getClients();
		vector<Produit*> getProduits();
};

#endif // __PARSER__
