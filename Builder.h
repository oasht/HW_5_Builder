#include <iostream>
#include <vector>
#include <windows.h>


using namespace std;
class Foundation
{
public:
	void build() { cout << "foundation" << endl; }
};
class Walls
{
public:
	void build() { cout << "walls" << endl; }
};
class Roof
{
public:
	void build() { cout << "Roof" << endl; }
};
class Windows
{
public:
	void build() { cout << "Windows" << endl; }
};
class Doors
{
public:
	void build() { cout << "doors" << endl; }
};


class Pool
{
public:
	void build() { cout << "pool" << endl; }
};


class Garden
{
public:
	void build() { cout << "garden" << endl; }
};

class House
{
public:
	vector<Foundation> vfoundation;
	vector<Walls> vwall;
	vector<Roof> vroof;
	vector<Windows> vwind;
	vector<Doors> vdoor;
	vector<Pool> vpool;
	vector<Garden> vgarden;

	void build()
	{
		int i;
		for (i = 0; i < vfoundation.size(); ++i)  vfoundation[i].build();
		for (i = 0; i < vwall.size(); ++i)  vwall[i].build();
		for (i = 0; i < vroof.size(); ++i)  vroof[i].build();
		for (i = 0; i < vwind.size(); ++i)  vwind[i].build();
		for (i = 0; i < vdoor.size(); ++i)  vdoor[i].build();
		for (i = 0; i < vpool.size(); ++i)  vpool[i].build();
		for (i = 0; i < vgarden.size(); ++i)  vgarden[i].build();
	}
};


class HouseBuilder
{
protected:
	House* p;
public:
	HouseBuilder() : p(0) {}
	virtual ~HouseBuilder() {}
	virtual void create_HouseBuilder() {}
	virtual void build_Foundation() {}
	virtual void build_Walls() {}
	virtual void build_Roof() {}
	virtual void build_Windows() {}
	virtual void build_Doors() {}
	virtual void build_Home_decoration() {}

	virtual void build_Pool() {}
	virtual void build_Lounge_area() {}
	virtual void build_Garden() {}
	virtual House* getHouseBuilder() { return p; }
};


class House_1 : public HouseBuilder
{
public:
	void create_HouseBuilder() { p = new House; }
	void build_Walls() { p->vwall.push_back(Walls()); }
	void build_Foundation() { p->vfoundation.push_back(Foundation()); }
	void build_Roof() { p->vroof.push_back(Roof()); }
	void build_Windows() { p->vwind.push_back(Windows()); }
	void build_Doors() { p->vdoor.push_back(Doors()); }
	void build_Pool() { p->vpool.push_back(Pool()); }
};


class House_2 : public HouseBuilder
{
public:
	void create_HouseBuilder() { p = new House; }
	void build_Foundation() { p->vfoundation.push_back(Foundation()); }
	void build_Walls() { p->vwall.push_back(Walls()); }
	void build_Roof() { p->vroof.push_back(Roof()); }
	void build_Windows() { p->vwind.push_back(Windows()); }
	void build_Doors() { p->vdoor.push_back(Doors()); }
	void build_Pool() { p->vgarden.push_back(Garden()); }

};

class House_3 : public HouseBuilder
{
public:
	void create_HouseBuilder() { p = new House; }
	void build_Foundation() { p->vfoundation.push_back(Foundation()); }
	void build_Walls() { p->vwall.push_back(Walls()); }
	void build_Roof() { p->vroof.push_back(Roof()); }
	void build_Windows() { p->vwind.push_back(Windows()); }
	void build_Doors() { p->vdoor.push_back(Doors()); }

};


class Director
{
public:
	House* createHouseBuilder(HouseBuilder& builder)
	{
		builder.create_HouseBuilder();
		builder.build_Walls();
		builder.build_Foundation();
		builder.build_Roof();
		builder.build_Windows();
		builder.build_Doors();
		builder.build_Garden();
		builder.build_Pool();
		return(builder.getHouseBuilder());
	}
};
