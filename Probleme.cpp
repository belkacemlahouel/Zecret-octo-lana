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
	evalSol = 0;
	evalBestSol = 0;

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
	sol = batchs;

	// cout << "batchs.size() : " << batchs.size() << endl;
	// cout << "bestSol.size() : " << bestSol.size() << endl;

	evalBestSol = evaluationSol();
	bestSol = sol;

	dateCourante = 0;
	evalSol = 0;
	// cout << "Solution heuristique OK\n";
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

void Probleme::solve() {
	cout << "Lancement heuristique" << endl;
	solutionHeuristique();
	printBestSol();
	cout << endl;

	cout << "Lancement résolution" << endl;
	solve(0, batchs);
}

void Probleme::solve(int iter, vector<Batch*> reste) {
	if (evalSol < evalBestSol) { // && encorePossible(...)
		cout << "On peut continuer" << endl;
		if (iter == batchs.size()) { // && reste.size() == 1
			cout << "On peut terminer la solution, elle est bonne (?)" << endl;
			// sol[iter] = reste[0];
			// evalSol += livraison(reste[0]);
			if (evalSol < evagitlBestSol) {
				evalBestSol = evalSol;
				bestSol = sol;
			}
			// evalSol -= annulerLivraison(reste[0]);
		} else {
			cout << "On ne peut pas encore construire, on doit avancer" << endl;
			for (int i = 0; i < reste.size(); ++i) {
				sol[iter] = reste[i];
				evalSol += livraison(reste[i]);

				vector<Batch*> reste2 = reste;
				reste2.erase(reste.begin() + i);
				solve(iter+1, reste2);

				evalSol -= livraison(reste[i]);
			}
		}
	} else {
		cout << "Impasse, on s'arrête là" << endl;
	}
}

