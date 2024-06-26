#include "Collection.h"
#include <iostream>
#include <vector>
#include <algorithm>
vector<string> names;


void add(Collection* x) {
	int n;
	cout << "enter n";
	cin >> n;
	x->add_item(n);
}
bool byprm(Collection* c, Collection* f) {
	return c->price_per_item() > f->price_per_item();
}
int main()
{
	vector<Collection*> c;
	ifstream file("file.txt");
	char x;
	while (file >> x) {
		switch (x)
		{
		case '1': {
			Collection* f = new Collection();
			file >> *f;
			f->print();
			c.push_back(f);
			break;
		}case '2': {
			Unique* f = new Unique();
			file >> *f;
			f->print();
			names.push_back(f->get_name());
			c.push_back(f);
			break;
		}
		default:
			break;
		}
	}


	for_each(c.begin(), c.end(), add);
	for (const auto& i : c) {
		i->print();
	}
	cout << endl << endl;
	sort(c.begin(), c.end(), byprm);
	for ( int i = 0; i <3 ; ++i) {
		c[i]->print();
	}
};

