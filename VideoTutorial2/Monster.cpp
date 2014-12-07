#include <iostream>

#include "Monster.h"

Monster::Monster() {
	_name = "NO_NAME";
}
Monster::Monster(string name) {
	_name = name;
}

void Monster::printName() {
	cout << _name << endl;
}