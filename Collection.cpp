#include "Collection.h"

Collection::Collection()
{
	price = 1.0;
	amount = 1;
	name = "art";
}

Collection::Collection( const Collection& c)
{

	price = c.price;
	amount = c.amount;
	name = c.name;
}

Collection::Collection(float price, int amount, string name) :
	price(price), amount(amount), name(name) {}

void Collection::print() const
{
	cout << "------Collection------" << endl;
	cout << "name:" << name << endl;
	cout << "price:" << price << endl;
	cout << "amount:" << amount << endl;
}

float Collection::price_per_item() const
{
	return price / amount;
}

string Collection::get_name() const
{
	return name;
}

void Collection::add_price(int n)
{
	price += n;
}

void Collection::add_item(int n)
{
	amount += n;
}

bool Collection::operator>(Collection& t)
{
	return price > t.price;
}

void Collection::compare_price(Collection& t)
{
	if (price > t.price) cout << name << "is more expencier than " << t.name << endl;
	else if (price < t.price) cout << t.name << "is more expencier than " << name << endl;
	else if (price == t.price) cout << name << " and " << t.name << "have the same price " << endl;
}

void Collection::create()
{
	cout << "------Creating Collection------" << endl;
	cout << "name:";
	cin >> name;
	cout << "price:";
	cin >> price;
	cout << "amount:";
	cin >> amount;
}

float Collection::price2() const
{
	return price;
}

int Collection::amount2() const
{
	return amount;
}

istream& operator>>(istream& is, Collection& f)
{
	is >> f.name >> f.price >> f.amount;
	return is;
}

Unique::Unique() : Collection()
{
	uname = " ";
	uprice = 0.0;
	owner = " ";
}

Unique::Unique(const Unique& u) : Collection(u)
{
	uname = u.uname;
	uprice = u.uprice;
	owner = u.owner;
}

Unique::Unique(float price, int amount, string name, string uname, float uprice, string owner) :
	Collection(price, amount, name), uname(uname), uprice(uprice), owner(owner) {}

float Unique::price2() const
{
	return this->price + uprice;
}
int Unique::amount2() const
{
	return this->amount + 1;
}
void Unique::print() const
{
	cout << "------Unique Collection------" << endl;
	cout << "name:" << this->name << endl;
	cout << "price:" << this->price << endl;
	cout << "amount:" << this->amount << endl;
	cout << "unique name:" << uname << endl;
	cout << "unique price:" << uprice << endl;
	cout << "owner:" << owner << endl;
	cout << "collection price: " << price2() << endl;
	cout << "collection amount: " << this->amount + 1 << endl;
}

float Unique::price_per_item() const
{
	float pr = ((uprice + this->price) / this->amount + 1);
	return pr;
}

void Unique::change_price(float n)
{
	uprice = n;
}

void Unique::create()
{
	cout << "------Creating Unique Collection------" << endl;
	cout << "name:";
	cin >> this->name;
	cout << "price:";
	cin >> this->price;
	cout << "amount:";
	cin >> this->amount;
	cout << "unique name:";
	cin >> uname;
	cout << "unique price:";
	cin >> uprice;
	cout << "owner:";
	cin >> owner;
}

istream& operator>>(istream& is, Unique& u)
{
	is >> u.name >> u.price >> u.amount >> u.uname >> u.uprice >> u.owner;
	return is;
}
