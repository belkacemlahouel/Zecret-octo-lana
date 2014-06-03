#include "Batch.h"

Batch::Batch(Produit* p) {
	// Pas besoin d'allouer de la mémoire au vector ?
	produits.push_back(p);
}

int Batch::size() {
	return produits.size();
}

vector<Produit*> Batch::getProduits() {
	return produits;
}

Client* Batch::getClient() {
	return produits[0]->getClient();
}

void Batch::addProduit(Produit* p) {
	produits.push_back(p);
}

float Batch::dateDueGlobale() {
	int min = produits[0]->getDateDue();
    int i;

    for(i = 1; i < size(); ++i) {
        if(produits[i]->getDateDue() < min){
            min = produits[i]->getDateDue();
        }
    }

    return min;
}

float Batch::coutStockage(int date) {
    int i;
    float cout_stockage_total = 0;

    for (i = 0; i < size(); ++i) {
        cout_stockage_total += produits[i]->coutStockage(date);
    }

    return cout_stockage_total;
}

float Batch::sommeAvancesMin() {
    int i;
    int sum = 0;
    int min = produits[0]->getDateDue();

    for (i = 1; i < size(); ++i) {
        if (min < produits[i]->getDateDue())
            sum += (produits[i]->getDateDue() - min);
        else {
            sum += (min - produits[i]->getDateDue()) * i;
            min = produits[i]->getDateDue();
        }
    }

    return sum;
}

void Batch::printBatch(){
    int j;
    cout << "Batch pour client " << getClient()->getNum() << " :\n";

	for(j = 0; j < size(); ++j) {
		cout << "\tProduit " << produits[j]->getNum() <<
                ", Date due : " << produits[j]->getDateDue() << "\n";
    }

    cout << "\tDate due globale    : " << dateDueGlobale() << "\n";
    cout << "\tSomme des avances   : " << sommeAvancesMin() << "\n\n";
}


