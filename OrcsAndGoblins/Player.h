#pragma once
class Actor {
public :
    int x,y; // position on map
    int ch; // ascii code
 
    Actor(int x, int y, int ch);
    void render() const;
};