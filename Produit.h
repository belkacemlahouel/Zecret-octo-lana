#ifndef __PRODUIT__
#define __PRODUIT__

#include "Client.h"
#include <iostream>

using namespace std;

class Produit {
	private:
		int i;				// N° du job
		float date;			// Date due du job i
		Client* client;		// Client qui demande le job i

	public:
		Produit(int i_, float _date, Client* _client);
		float dateDue();
		Client* getClient();
		int getNum();
		float coutStockage(int _date);
		void printProduit();
		// bool operator< (Produit);
		// bool operator() (Produit);
		static bool compare(const Produit& p1, const Produit& p2);
};

#endif // __PRODUIT__
