#include <vector>
#include <algorithm>
#include "Nono.h"

using namespace std;

int main(int argc, char** argv) {
	cout << endl;

	vector<Nono*> nonos;
	nonos.push_back(new Nono(1));
	nonos.push_back(new Nono(2));
	nonos.push_back(new Nono(4));
	nonos.push_back(new Nono(5));
	nonos.push_back(new Nono(3));

	for (int i = 0; i < 5; ++i)
		nonos[i]->print();
	cout << endl;

	// --------------------------------
	sort(nonos.begin(), nonos.end());
	// --------------------------------

	for (int i = 0; i < 5; ++i)
		nonos[i]->print();
	cout << endl;

	cout << endl;
	cout << endl;

	// Test opérateur seul
	nonos[4]->print();
	if (*nonos[4] < *nonos[0]) {
		cout << " < ";
	} else {
		cout << " > ";
	}
	nonos[0]->print();

	return 0;
}

