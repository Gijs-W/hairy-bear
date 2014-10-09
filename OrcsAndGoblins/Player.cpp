#include "stdafx.h"
#include "Player.h"
#include <iostream>

Actor::Actor(int x, int y, int ch) :
    x(x),y(y),ch(ch) {
}
 
void Actor::render() const {
	printf("@");
}
