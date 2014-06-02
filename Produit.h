#ifndef __PRODUIT__
#define __PRODUIT__

#include "Client.h"

class Produit {
	private:
		int i;				// N° du job
		float date;			// Date due du job i
		Client* client;		// Client qui demande le job i

	public:
		Produit(int i_, float _date, Client* _client);
		float getDateDue();
		Client* getClient();
		int getNum();
		float coutStockage(int _date);
};

#endif // __PRODUIT__