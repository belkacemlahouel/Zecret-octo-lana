#include "Probleme.h"

Probleme::Probleme(int _capa, float _eta, vector<Client*> _clients,
											vector<Produit*> _produits) {
	capa = _capa;
	eta = _eta;

	clients = _clients;
	produits = _produits;

	buildBatchs();

	dateCourante = 0.0f;
}

// Instance de base, voir sujet
Probleme::Probleme() {
	capa = 5;
	eta = 2;

	// Création des clients
	clients.push_back(new Client(1, 100, 3/2.));
	clients.push_back(new Client(2, 100, 3));
	clients.push_back(new Client(3, 100, 9/2.));
	clients.push_back(new Client(4, 100, 6));

	// Création des produits
	produits.push_back(new Produit(1, 310, clients[0]));
	produits.push_back(new Produit(2, 310, clients[0]));
	produits.push_back(new Produit(3, 300, clients[2]));
	produits.push_back(new Produit(4, 360, clients[2]));
	produits.push_back(new Produit(5, 400, clients[2]));

	// construction des batchs
	buildBatchs();

	// initialisation des évaluations
	evalSol = 99999999;
	evalBestSol = 99999999;

	// initialisation des solutions
	sol = batchs;
	bestSol = batchs;

	cout << "Initialisation instance de test OK\n";
}

// Batchs faits "bêtement" ici...
void Probleme::buildBatchs() {
	// Tri produits à faire
	vector<Produit*> tmpProduits = produits;

	while (tmpProduits.size() > 0) {
		// cout << "Il reste " << tmpProduits.size() << " produits" << endl;

		Batch* tmp = new Batch(tmpProduits[0]);
		tmpProduits.erase(tmpProduits.begin());

		vector<Produit*>::iterator it = tmpProduits.begin();

		while (it != tmpProduits.end()) {
			// cout << "Recherche de produits avec le même client" << endl;
			if ((*it)->getClient()->getNum() == tmp->getClient()->getNum() &&
														tmp->size() < capa) {
				// cout << "Même client trouvé" << endl;
				tmp->addProduit((*it));
				tmpProduits.erase(it);
			} else {
				++it;
			}
		}

		batchs.push_back(tmp);
	}
}

void Probleme::solutionHeuristique() {
	// Nous n'avons plus qu'à dire que la solution heuristique
	// est la liste des batchs ordonnés
	bestSol = batchs;

	cout << "batchs.size() : " << batchs.size() << endl;
	cout << "bestSol.size() : " << bestSol.size() << endl;

	evalBestSol = evaluationSol();
	dateCourante = 0;
	cout << "Solution heuristique OK\n";
}

float Probleme::evaluationSol() {
	evalSol = 0;

	for (int i = 0; i < sol.size(); ++i) {
		evalSol += livraison(sol[i]);
	}

	return evalSol;
}

void Probleme::printBatchs() {
	int i;
	for(i = 0; i < batchs.size(); ++i) {
        batchs[i]->printBatch();
	}
}

void Probleme::printBestSol(){
    int i;
    cout << "______________________________________________________\n";
    cout << "Meilleure solution trouvee :\n\t";
    for (i = 0; i < bestSol.size(); ++i) {
        cout << "0--->" << bestSol[i]->getClient()->getNum() << "--->";
    }
    cout << "0\n\n";	// A la fin, on revient chez le fournisseur
    cout << "Evaluation de cette solution : " << evalBestSol << "\n";
    cout << "______________________________________________________\n";
}

float Probleme::livraison(Batch* b) {
	float rep = b->getClient()->getDist() * 2*eta;
	dateCourante += b->getClient()->getDist();
	rep += b->coutStockage(dateCourante);
	dateCourante += b->getClient()->getDist();
	return rep;
}

float Probleme::annulerLivraison(Batch* b) {
	float rep = b->getClient()->getDist() * 2*eta;
	dateCourante -= b->getClient()->getDist();
	rep += b->coutStockage(dateCourante);
	dateCourante -= b->getClient()->getDist();
	return rep;
}

/* void Probleme::solve() {
	solutionHeuristique();
	solve(0, batchs);
}

void Probleme::solve(int iter, vector<Batch*> reste) {
	
} */

