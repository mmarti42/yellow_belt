#include <string>
#include <memory>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

template <class T>
T square(T num) {
	return num * num;
}

class Figure {
public:
	virtual string Name() = 0;
	virtual double Perimeter() = 0;
	virtual double Area() = 0;
};

class Circle : public Figure {
public:
	Circle(unsigned r) : rad(r) {
	}
	string Name() override {
		return "CIRCLE";
	}
	double Perimeter() override {
		return 3.14 * 2 * rad;
	}
	double Area() override {
		return 3.14 * square(rad);
	}
private:
	const unsigned rad;
};

class Rect : public Figure {
public:
	Rect(unsigned width, unsigned height) : width(width), height(height) {
	}
	string Name() override {
		return "RECT";
	}
	double Perimeter() override {
		return (width + height) * 2;
	}
	double Area() override {
		return width * height;
	}
private:
	const unsigned width;
	const unsigned height;
};

class Triangle : public Figure {
public:
	Triangle(unsigned side1, unsigned side2, unsigned side3) :
	side1(side1),
	side2(side2),
	side3(side3) {}

	string Name() override {
		return "TRIANGLE";
	}
	double Perimeter() override {
		return side1 + side2 + side3;
	}
	double Area() override {
		double p = Perimeter() / 2;
		p = p * (p - side1) * (p - side2) * (p - side3);
		return sqrt(p);
	}
private:
	const unsigned side1;
	const unsigned side2;
	const unsigned side3;
};

shared_ptr<Figure> CreateFigure(istringstream& inp) {
	string type;

	inp >> type;
	if (type == "CIRCLE") {
		unsigned r;

		inp >> r;
		return make_shared<Circle>(Circle(r));
	} else if (type == "RECT") {
		unsigned w;
		unsigned h;

		inp >> w >> h;
		return make_shared<Rect>(Rect(w, h));
	} else {
		unsigned s1;
		unsigned s2;
		unsigned s3;

		inp >> s1 >> s2 >> s3;
		return make_shared<Triangle>(Triangle(s1, s2, s3));
	}
}

int main() {
	vector<shared_ptr<Figure>> figures;
	for (string line; getline(cin, line); ) {
		istringstream is(line);

		string command;
		is >> command;
		if (command == "ADD") {
			figures.push_back(CreateFigure(is));
		} else if (command == "PRINT") {
			for (const auto& current_figure : figures) {
				cout << fixed << setprecision(3)
					 << current_figure->Name() << " "
					 << current_figure->Perimeter() << " "
					 << current_figure->Area() << endl;
			}
		}
	}
	return 0;
}