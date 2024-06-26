#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <istream>
#include <fstream>
using namespace std;
/*������ � ��������� ������� �������� (������� ������ ����� ������ ������), ������� �� � ���,
������� ���� �� �����. ���������� ��� ��������� ����� ��������, �� � � �����. ������� ���������� ��������,
�������� �������� ������� �������� � ���������.
4.	�� ��������� ��������� STL ���������� � ���������� ����� ������� �������� �� ������� ��������� ��������
(������� ������ ������ ������ ������� �������), �ᒺ������ �� � ������ ���������, ������� �� �����.
������ ���������� ����� �������� ��������� ��������. ������� ��� ����������� �������� (� ��������� ���������
������� ������ ��������). �������� ������� �������� � ����� �������� �� ������ �����, ���������� ��������� ���������.
(10 ����)
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
