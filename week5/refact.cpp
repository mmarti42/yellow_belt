#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Human {
public:
	Human(const string& name, const string& type) : Name(name), type(type) {
	}

	virtual void Walk(const string& destination) const {
		cout << type << ": " << Name << " walks to: " << destination << endl;
	}
public:
	const string type;
	const string Name;
};

class Student : public Human{
public:

	Student(const string& name, const string& favouriteSong) : Human(name, "Student") {
		FavouriteSong = favouriteSong;
	}

	void Learn() const {
		cout << "Student: " << Name << " learns" << endl;
	}

	void Walk(const string& destination) const override {
		cout << "Student: " << Name << " walks to: " << destination << endl;
		SingSong();
	}

	void SingSong() const {
		cout << "Student: " << Name << " sings a song: " << FavouriteSong << endl;
	}

public:
	string FavouriteSong;
};


class Teacher : public Human {
public:
	Teacher(const string& name, const string& subject) : Human(name, "Teacher"), Subject(subject) {
	}
	void Teach() const {
		cout << "Teacher: " << Name << " teaches: " << Subject << endl;
	}

public:
	const string Subject;
};


class Policeman : public Human {
public:
	Policeman(const string& name) : Human(name, "Policeman") {
	}

	void Check(const Human& h) const {
		cout << "Policeman: " << Name << " checks " << h.type <<". " << h.type << "'s" << " name is: " << h.Name << endl;
	}
};


void VisitPlaces(const Human& h, const vector<string>& places) {
	for (const auto& p : places) {
		h.Walk(p);
	}
}

int main() {
	Teacher t("Jim", "Math");
	Student s("Ann", "We will rock you");
	Policeman p("Bob");

	VisitPlaces(t, {"Moscow", "London"});
	p.Check(s);
	VisitPlaces(s, {"Moscow", "London"});
	return 0;
}