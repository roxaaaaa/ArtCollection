#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <istream>
#include <fstream>
using namespace std;
/*Введіть з клавіатури декілька колекцій (вартість задано малим дійсним числом), помістіть їх у дек,
виведіть його на екран. Надрукуйте без повторень жанри колекцій, що є у декові. Знайдіть найдешевшу колекцію,
обчисліть загальну кількість предметів у колекціях.
4.	За допомогою алгоритмів STL прочитайте з текстового файлу декілька колекцій та декілька унікальних колекцій
(вартість задано дійсним числом подвійної точності), об’єднайте їх в одному контейнері, виведіть на екран.
Окремо надрукуйте імена власників унікальних колекцій. Знайдіть три найвартісніші колекції (з найбільшою середньою
вартістю одного предмету). Збільшіть кількість предметів у кожній колекції на задане число, надрукуйте отриманий контейнер.
(10 балів)
*/
class Collection {
protected:
	float price;
	int amount;
	string name;
public:
	Collection();
	Collection(const Collection& c);
	Collection(float price,
		int amount,
		string name);
	virtual void print() const;
	virtual float price_per_item() const;
	string get_name() const;
	void add_price(int n);
	void add_item(int n);
	bool operator>(Collection& t);
	void compare_price(Collection& t);
	virtual void create();
	virtual float price2() const;
	virtual int amount2() const;
	friend istream& operator>>(istream& is, Collection& f);
};

class Unique : public Collection {
private:
	string uname;
	float uprice;
	string owner;
public:
	Unique();
	Unique(const Unique& u);
	Unique(float price,
		int amount,
		string name,
		string uname,
		float uprice, string owner);

	float price2() const override;
	int amount2() const override;
	void print() const override;
	float price_per_item() const override;
	void change_price(float n);
	void create() override;
	friend istream& operator>>(istream& is, Unique& u);
};
