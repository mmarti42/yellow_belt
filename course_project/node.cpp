#include "node.h"

bool EmptyNode::Evaluate(const Date &date, const string &event) {
	return false;
}

bool DateComparisonNode::Evaluate(const Date& date, const string& event) {
	if (comp_ == Comparison::Less) {
		return date < d_;
	} else if (comp_ == Comparison::LessOrEqual) {
		return date < d_ || date == d_;
	} else if (comp_ == Comparison::Equal) {
		return date == d_;
	} else if (comp_ == Comparison::Greater) {
		return !(date < d_ || date == d_);
	} else if (comp_ == Comparison::GreaterOrEqual) {
		return !(date < d_);
	} else {
		return !(date == d_);
	}
}

bool EventComparisonNode::Evaluate(const Date& date, const string& event) {
	if (comp_ == Comparison::Less) {
		return event < event_;
	} else if (comp_ == Comparison::LessOrEqual) {
		return event <= event_;
	} else if (comp_ == Comparison::Equal) {
		return event == event_;
	} else if (comp_ == Comparison::Greater) {
		return event > event_;
	} else if (comp_ == Comparison::GreaterOrEqual) {
		return event >= event_;
	} else {
		return event != event_;
	}
}

bool LogicalOperationNode::Evaluate(const Date& date, const string& event) {
	if (op_ == LogicalOperation::And)
		return left_->Evaluate(date, event) && right_->Evaluate(date, event);
	else
		return left_->Evaluate(date, event) || right_->Evaluate(date, event);
}