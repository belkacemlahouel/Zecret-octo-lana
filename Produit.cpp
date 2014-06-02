#include "Produit.h"

Produit::Produit(int _i, float _date, Client* _client) {
	i = _i;
	date = _date;
	client = _client;
}

float Produit::getDateDue() {
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
