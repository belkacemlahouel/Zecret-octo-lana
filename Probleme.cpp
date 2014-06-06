#include "Probleme.h"

Probleme::Probleme(int _capa, float _eta, vector<Client*> _clients,
											vector<Produit*> _produits) {
	capa = _capa;
	eta = _eta;

	clients = _clients;
	produits = _produits;

	buildBatchs();

	evalSol = 0;
	evalBestSol = 0;

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

	// Création des produits, dans le désordre exprès
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

	dateCourante = 0;

	cout << "Initialisation instance de test OK\n";
}

Probleme::~Probleme() {
	Tools::viderVector(clients);
	Tools::viderVector(produits);
	Tools::viderVector(batchs);
}

// --> tools
// template<class T> void Probleme::viderVector(vector<T> vect) {
// 	while (vect.size() > 0) {
// 		delete vect[0];
// 		vect.erase(vect.begin());
// 	}
// }

// Fonctions statiques de comparaison
bool comparatorProduitPtrDateDue(Produit* p1, Produit* p2) {
	// cout << "produitptr comparator" << endl;
	return p1->dateDue() < p2->dateDue();
}

bool comparatorBatchPtrDateDue(Batch* b1, Batch* b2) {
	// cout << "batchptr comparator" << endl;
	return b1->dateDueGlobale() < b2->dateDueGlobale();
}

// Batchs faits "bêtement" ici...
void Probleme::buildBatchs() {
	// Tri produits à faire sur les produits
	cout << "Avant tri" << endl;
	printProduits();
	sort(produits.begin(), produits.end(), comparatorProduitPtrDateDue);
	cout << "Après tri" << endl;
	printProduits();

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
	sort(batchs.begin(), batchs.end(), comparatorBatchPtrDateDue);
	sol = batchs;

	// cout << "batchs.size() : " << batchs.size() << endl;
	// cout << "bestSol.size() : " << bestSol.size() << endl;

	evalBestSol = 0;
	for (int i = 0; i < sol.size(); ++i) {
		evalBestSol += livraison(sol[i]);
	}

	evalSol = 0;
	bestSol = sol;

	dateCourante = 0;
	// cout << "Solution heuristique OK\n";
}

void Probleme::printBatchs() {
	int i;
	for(i = 0; i < batchs.size(); ++i) {
        batchs[i]->printBatch();
	}
}

void Probleme::printProduits() {
	cout << "Liste des produits à livrer :" << endl;
	for (int i = 0; i < produits.size(); ++i) {
		produits[i]->printProduit();
	}
	cout << endl;
}

void Probleme::printBestSol() {
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

void Probleme::printSol(int niveau) {
	int i;
    cout << "______________________________________________________\n";
    cout << "Solution courante trouvee :\n\t";
    for (i = 0; i <= niveau; ++i) {
        cout << "0--->" << sol[i]->getClient()->getNum() << "--->";
    }
    cout << "0\n\n";	// A la fin, on revient chez le fournisseur
    cout << "Evaluation de cette solution : " << evalSol << "\n";
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
	// Appel des autres heuristiques et ne garder que la meilleure solution
	solutionHeuristique();

	printBestSol();
	cout << endl;

	dateCourante = 0;
	cout << "Lancement résolution" << endl;
	solve(0, batchs);

	/*dateCourante = 0;
	cout << "Est-ce que livraison/annulerLivraison fonctionnent ?" << endl;
	cout << "Date avant : " << dateCourante << endl;
	cout << "livraison : " << livraison(batchs[0]) << endl;
	cout << "annulerLivraison : " << annulerLivraison(batchs[0]) << endl;
	cout << "Date après : " << dateCourante << endl;
	cout << "Est-ce qu'elles fonctionnent ? :: OUI" << endl;*/
}

void Probleme::solve(int iter, vector<Batch*> reste) {
	// cout << "reste.size() : " << reste.size() << endl;
	if (evalSol < evalBestSol && encorePossible(reste)) {
		if (iter == batchs.size()-1 && reste.size() == 1) {
			sol[iter] = reste[0];
			evalSol += livraison(reste[0]);

			if (evalSol < evalBestSol) {
				cout << "Une meilleure solution est trouvée" << endl;
				evalBestSol = evalSol;
				bestSol = sol;
			}
			evalSol -= annulerLivraison(reste[0]);
		} else {
			for (int i = 0; i < reste.size(); ++i) {
				// cout << "iter : " << iter << ", " << i << endl;

				sol[iter] = reste[i];
				evalSol += livraison(reste[i]);

				printSol(iter);

				vector<Batch*> reste2 = reste;
				reste2.erase(reste2.begin() + i);
				solve(iter+1, reste2);

				evalSol -= annulerLivraison(reste[i]);
			}
		}
	} else {
		cout << "STOP : ";

		if (evalSol >= evalBestSol) {
			cout << "evalSol=" << evalSol << " >= evalBestSol=" << evalBestSol;
			cout << endl;
		}

		if (!encorePossible(reste)) {
			cout << "Ce chemin mène vers une impasse" << endl;
		}
	}
}

bool Probleme::encorePossible(vector<Batch*> reste) {
	for (int i = 0; i < reste.size(); ++i) {
		if (reste[i]->dateDueGlobale() < // dateCourante) {
						dateCourante + reste[i]->getClient()->getDist()) {
			
			return false;
		}
	}
	return true;
}

