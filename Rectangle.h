#pragma once
#include <string>
// Classe Retangulo, herdado de Objeto
class Rectangle
{
public:
    int x,y;
    int R,G,B;
    std::string style;
	int Height, Width;
	Rectangle();
	Rectangle(int x, int y, int pHeight, int pWidth,int R,int G,int B);
	void Set(int x, int y, int pHeight, int pWidth,int R,int G,int B);
	~Rectangle();
	void Draw(); // a ser implementado
};

