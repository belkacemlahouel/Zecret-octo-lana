#include "Produit.h"

Produit::Produit(int _i, float _date, Client* _client) {
	i = _i;
	date = _date;
	client = _client;
}

float Produit::dateDue() {
	return date;
}

Client* Produit::getClient() {
	return client;
}

int Produit::getNum() {
	return i;
}

// Comment implémenter les coûts si retard ...P?
float Produit::coutStockage(int t) {
	return (date-t) * client->coutUnitaireStockage();
}

// Surcharge de l'opérateur de comparaison <
/*bool Produit::operator< (Produit p) {
	cout << "Entrée opérateur <" << endl;
	if (dateDue() < p.dateDue())
		return true;
	return false;
}*/

/*bool Produit::operator() (Produit p) {
	cout << "Entrée opérateur ()" << endl;
	if (dateDue() < p.dateDue())
		return true;
	return false;
}*/

void Produit::printProduit() {
	cout << "\tProduit " << getNum() << ", Date due : " << dateDue() << "\n";
}

static bool Produit::compare(const Produit& p1, const Produit& p2) {
	return p1.dateDue() < p2.dateDue();
}

