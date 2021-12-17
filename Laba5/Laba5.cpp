#include <iostream>

class Rectangle {
private:
	int square;
protected:
	int coordX;
	int coordY;
public:

	Rectangle() {
		printf("Вызвался конструктор по умолчанию класса Rectangle\n");
		coordX = 1;
		coordY = 1;
	}

	Rectangle(int coordX, int coordY) {
		printf("Вызвался конструктор с параметрами класса Rectangle\n");
		this->coordX = coordX;
		this->coordY = coordY;
	}

	Rectangle(Rectangle& rtg) {
		printf("Вызвался конструктор копирования класса Rectangle\n");
		coordX = rtg.coordX;
		coordY = rtg.coordY;
	}

	void ShowClassName() {
		printf("My class is Rectangle\n");
	}

	virtual void ShowCoords() {
		printf("X:%d Y:%d\n", coordX, coordY);
	}

	int FindRectangle() {
		square = coordX * coordY;
		return square;
	}

	void ResetRectangle();

	~Rectangle() {
		printf("Вызвался деструктор класса Rectangle\n");
		printf("Стороны прямоугольника = %d %d\n\n", coordX, coordY);
	}
};

void Rectangle::ResetRectangle() {
	coordX = 1;
	coordY = 1;
}

class Parallelepiped : public Rectangle {
protected:
	int coordZ;
public:

	Parallelepiped() : Rectangle() {
		printf("Вызвался конструктор по умолчанию класса Parallelepiped\n");
		coordZ = 1;
	}

	Parallelepiped(int coordX, int coordY, int CoordZ) : Rectangle(coordX, coordY) {
		printf("Вызвался конструктор с параметрами класса Parallelepiped\n");
		this->coordZ = CoordZ;
	}

	Parallelepiped(Parallelepiped& parallelepiped) {
		printf("Вызвался конструктор копирования класса Parallelepiped\n");
		coordZ = parallelepiped.coordZ;
		coordX = parallelepiped.coordX;
		coordY = parallelepiped.coordY;
	}

	void ShowClassName() {
		printf("My class is Parallelepiped\n");
	}

	virtual void ShowCoords() {
		printf("X:%d Y:%d Z:%d\n", coordX, coordY, coordZ);
	}

	int FindParallelepiped() {
		return FindRectangle() * coordZ;
	}

	~Parallelepiped() {
		printf("Вызвался деструктор класса Parallelepiped\n");
		printf("Стороны параллелепипеда = %d %d %d\n\n", coordX, coordY, coordZ);
	}
};

int main()
{
	setlocale(LC_ALL, "rus");

	//создание динамического объекта класса потомка
	Rectangle* rtg = new Rectangle();

	//создание динамического объекта класса наследника
	Parallelepiped* prl = new Parallelepiped(6, 4, 5);

	//вызов перекрываемого метода
	rtg->ShowClassName();
	prl->ShowClassName();

	//вызов виртуального метода
	rtg->ShowCoords();
	prl->ShowCoords();

	delete rtg;
	delete prl;
}