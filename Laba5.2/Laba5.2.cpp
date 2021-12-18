#include <iostream>

using namespace std;

class Rectangle {
private:
	int square;
protected:
	int coordX;
	int coordY;
public:

	Rectangle() {
		//printf("Вызвался конструктор по умолчанию класса Rectangle\n");
		coordX = 1;
		coordY = 1;
	}

	Rectangle(int coordX, int coordY) {
		//printf("Вызвался конструктор с параметрами класса Rectangle\n");
		this->coordX = coordX;
		this->coordY = coordY;
	}

	Rectangle(Rectangle& rtg) {
		//printf("Вызвался конструктор копирования класса Rectangle\n");
		coordX = rtg.coordX;
		coordY = rtg.coordY;
	}

	virtual string ClassName() {
		return "Rectangle";
	}

	virtual bool IsClass(string className) {
		return (className == "Rectangle");
	}

	virtual void ShowCoords() {
		printf("X:%d Y:%d\n", coordX, coordY);
	}

	int FindRectangle() {
		square = coordX * coordY;
		return square;
	}

	void ResetRectangle();

	virtual ~Rectangle() {
		//printf("Вызвался деструктор класса Rectangle\n");
		//printf("Стороны прямоугольника = %d %d\n\n", coordX, coordY);
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
		//printf("Вызвался конструктор по умолчанию класса Parallelepiped\n");
		coordZ = 1;
	}

	Parallelepiped(int coordX, int coordY, int CoordZ) : Rectangle(coordX, coordY) {
		//printf("Вызвался конструктор с параметрами класса Parallelepiped\n");
		this->coordZ = CoordZ;
	}

	Parallelepiped(Parallelepiped& parallelepiped) {
		//printf("Вызвался конструктор копирования класса Parallelepiped\n");
		coordZ = parallelepiped.coordZ;
		coordX = parallelepiped.coordX;
		coordY = parallelepiped.coordY;
	}

	string ClassName() {
		return "Parallelepiped";
	}

	bool IsClass(string className) {
		return (className == "Parallelepiped");
	}

	virtual void ShowCoords() {
		printf("X:%d Y:%d Z:%d\n", coordX, coordY, coordZ);
	}

	int FindParallelepiped() {
		return FindRectangle() * coordZ;
	}

	~Parallelepiped() {
		//printf("Вызвался деструктор класса Parallelepiped\n");
		//printf("Стороны параллелепипеда = %d %d %d\n\n", coordX, coordY, coordZ);
	}
};

class Cube : public Rectangle {
protected:
	int coordZ;
public:

	Cube() : Rectangle() {
		//printf("Вызвался конструктор по умолчанию класса Cube\n");
		coordZ = 1;
	}

	Cube(int coordX, int coordY, int CoordZ) : Rectangle(coordX, coordY) {
		//printf("Вызвался конструктор с параметрами класса Cube\n");
		this->coordZ = CoordZ;
	}

	Cube(Cube& cube) {
		//printf("Вызвался конструктор копирования класса Cube\n");
		coordZ = cube.coordZ;
		coordX = cube.coordX;
		coordY = cube.coordY;
	}

	string ClassName() {
		return "Cube";
	}

	bool IsClass(string className) {
		return (className == "Cube");
	}

	virtual void ShowCoords() {
		printf("X:%d Y:%d Z:%d\n", coordX, coordY, coordZ);
	}

	int FindCube() {
		if (IsClass("Cube"))
			printf("cube == class Cube\n");
		return FindRectangle() * coordZ;
	}

	~Cube() {
		//printf("Вызвался деструктор класса Cube\n");
		//printf("Стороны куба = %d %d %d\n\n", coordX, coordY, coordZ);
	}
};
void foo(Rectangle* rtg) {							
	Parallelepiped* prl = dynamic_cast<Parallelepiped*>(rtg);
	if (rtg->IsClass("Parallelepiped")) {						
		printf("Parallelepiped\n");					
	}

	Cube* cube = dynamic_cast<Cube*>(rtg);
	if (rtg->IsClass("Cube")) {
		printf("Cube\n");
	}
}

int main()
{
	setlocale(LC_ALL, "rus");

	//создание динамического объекта класса предка
	Rectangle* rtg = new Parallelepiped();

	if(rtg->ClassName() == "Parallelepiped")
		printf("rtg class == Parallelepiped\n");
	else 
		printf("rtg class == Rectangle\n");

	if (rtg->IsClass("Parallelepiped"))
		printf("rtg class == Parallelepiped\n");
	else
		printf("rtg class != Parallelepiped\n");

	//опасное приведение типов
	printf("FindCube == %d\n", ((Cube*)rtg)->FindCube());

	//безопасное приведение типов
	Parallelepiped prl;
	foo(&prl);

	Cube cube;
	foo(&cube);

	//delete rtg;
	//delete prl;
}