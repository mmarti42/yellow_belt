#pragma once

#include <memory>
#include "date.h"

using namespace std;

enum class LogicalOperation {
	And,
	Or
};

enum class Comparison {
	Less,
	LessOrEqual,
	Greater,
	GreaterOrEqual,
	Equal,
	NotEqual
};

class Node {
public:
	virtual bool Evaluate(const Date& date, const string& event) = 0;
};

class EmptyNode : public Node{
public:
	bool Evaluate(const Date& date, const string& event) override ;
};

class DateComparisonNode : public Node {
public:
	DateComparisonNode(const Comparison& comp, const Date& d) : d_(d), comp_(comp) {};

	bool Evaluate(const Date& date, const string& event) override ;
private:
	const Date d_;
	const Comparison comp_;
};

class EventComparisonNode : public Node {
public:
	EventComparisonNode(const Comparison& comp, const string& event) : comp_(comp), event_(event) {};

	bool Evaluate(const Date& date, const string& event) override ;
private:
	const Comparison comp_;
	const string event_;
};

class LogicalOperationNode : public Node {
public:
	LogicalOperationNode(const LogicalOperation& op, const shared_ptr<Node>& left, const shared_ptr<Node>& right) :
	left_(left), right_(right),  op_(op){}

	bool Evaluate(const Date& date, const string& event) override ;

private:
	const LogicalOperation op_;
	const shared_ptr<Node> left_;
	const shared_ptr<Node> right_;
};
