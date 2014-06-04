#include "Probleme.h"

int main(int argc, char** argv) {
	cout << "----- Hello World! -----" << endl;
	Probleme p;
	p.printBatchs();
	p.solve();
	p.printBestSol();
	cout << "------ Bye World! ------" << endl;
	return 0;
}


