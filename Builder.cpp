#include "Builder.h"


void main()
{
	Director dir;
	House_1 h1;
	House_2 h2;
	House_3 h3;

	House* p_h1 = dir.createHouseBuilder(h1);
	House* p_h2 = dir.createHouseBuilder(h2);
	House* p_h3 = dir.createHouseBuilder(h3);

	cout << "House numer one consists of" << endl;
	p_h1->build();
	cout << "\nHouse number two consists of:" << endl;
	p_h2->build();
	cout << "\nHouse number three consists of:" << endl;
	p_h3->build();
	
}
