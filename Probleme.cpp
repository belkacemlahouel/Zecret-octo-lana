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

	cout << "Initialisation instance de test OK\n";
}

// Batchs faits "bêtement" ici...
// Dans l'ordre, car tri, du plus urgent au moins urgent
void Probleme::buildBatchs() {
	// Tri des produits... voir comment ça fonctionne avec la STL

	vector<Produit*>::iterator it;
	vector<Produit*> tmpProduits = produits;

	while (tmpProduits.size() > 0) {
		Batch tmp(tmpProduits[0]);

		// Parcours de la liste en reprenant tous ceux du même client :
		// Jusqu'à ce que ce batch soit plein					X
		// 		Ou tmpProduits vide								X
		// 		Ou qu'on soit arrivés à la fin de tmpProduits	X

		it = tmpProduits.begin();
		tmpProduits.erase(it);
		
		while (it != tmpProduits.end() && tmp.size() < capa) {
			if ((*it)->getClient()->getNum() == tmp.getClient()->getNum()) {
				// Ajout de ce produit au batch temporaire
				tmp.addProduit((*it));

				// Suppression de ce produit de tmpProduits
				tmpProduits.erase(it);
			}
			++it;
		}
		// Et on ajoute ce batch temporaire à batchs
		batchs.push_back(&tmp);
	}
}

void Probleme::solutionHeuristique() {
	// Nous n'avons plus qu'à dire que la solution heuristique
	// est la liste des batchs ordonnés
	sol = batchs;
	evalSol = evaluationSol();
	dateCourante = 0;
}

float Probleme::evaluationSol() {
	// Evalue la solution courante sol
	return 0.;
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
    for (i = 0; i < bestSol.size()-1; ++i) {
        cout << bestSol[i] << "--->";
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

void Probleme::solve() {
	solutionHeuristique();
	solve(0, batchs);
}

void Probleme::solve(int iter, vector<Batch*> reste) {

}

