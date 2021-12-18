#include <iostream>

class Base {
public:
	Base() {
		printf("Base()\n");
	}

	Base(Base* obj) {
		printf("Base(Base* obj)\n");
	}

	Base(Base& obj) {
		printf("Base(Base& obj)\n");
	}

	virtual~Base() {
		printf("~Base()\n");
	}
};

class Desc : public Base {
public:
	Desc() {
		printf("Desc()\n");
	}

	Desc(Base* obj) {
		printf("Desc(Desc* obj)\n");
	}

	Desc(Base& obj) {
		printf("Desc(Desc& obj)\n");
	}

	~Desc() {
		printf("~Desc()\n");
	}
};


void func1(Base obj) {
	printf("void func1(Base obj)\n");
}

void func2(Base* obj) {
	printf("void func2(Base *obj)\n");
}

void func3(Base& obj) {
	printf("void func3(Base& obj)\n");
}

Base func11(Base obj) {
	//printf("Base func1()\n");
	return obj;
}

Base* func22(Base* obj) {
	//printf("Base* func1()\n");
	return obj;
}

Base& func33(Base& obj) {
	//printf("Base& func1()\n");
	return obj;
}

int main()
{
	Base* base = new Base();
	func1(base);
	func2(base);
	func3(*base);
	printf("\n\n");


	Desc* desc = new Desc();
	func1(*desc);
	func2(desc);
	func3(*desc);
	delete desc;
	printf("\n\n");

	func11(*base);
	func22(base);
	func33(*base);
	delete base;
}
