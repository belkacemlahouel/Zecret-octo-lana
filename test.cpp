#include <vector>
#include <iostream>
#include <algorithm>
#include "Produit.h"
#include "Client.h"

using namespace std;

/*struct foncteurDateDue {
	bool operator() (const Produit& p1, const Produit& p2) const {
		return p1.dateDue() < p2.dateDue();
	}
};

bool compareProduits(Produit& p1, Produit& p2) {
	return p1.dateDue() < p2.dateDue();
}*/

int main(int argc, char** argv) {
	vector<int> vect;
	vect.push_back(3);
	vect.push_back(2);
	vect.push_back(1);
	for (int i = 0; i < 3; ++i)
		cout << vect[i] << " ";
	cout << endl;
	sort(vect.begin(), vect.end());
	for (int i = 0; i < 3; ++i)
		cout << vect[i] << " ";
	cout << endl;

	cout << endl;
	cout << endl;

	Client* clt = new Client(1, 1, 1);
	vector<Produit*> produits;
	produits.push_back(new Produit(1, 310, clt));
	produits.push_back(new Produit(2, 310, clt));
	produits.push_back(new Produit(3, 300, clt));
	produits.push_back(new Produit(4, 360, clt));
	produits.push_back(new Produit(5, 400, clt));
	for (int i = 0; i < 5; ++i)
		produits[i]->printProduit();
	cout << endl;
	sort(produits.begin(), produits.end());
	for (int i = 0; i < 5; ++i)
		produits[i]->printProduit();
	cout << endl;

	cout << endl;
	cout << endl;

	produits[4]->printProduit();
	if (*produits[4] < *produits[0]) {
		cout << " < ";
	} else {
		cout << " > ";
	}
	produits[0]->printProduit();

	return 0;
}

