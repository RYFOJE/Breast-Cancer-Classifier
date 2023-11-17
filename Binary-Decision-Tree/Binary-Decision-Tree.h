#pragma once

#include <functional>

template <typename T>
class Node {

protected:
	Node* leftNode;		/** IF CONDITION EVALUATES TO FALSE **/
	Node* rightNode;	/** IF CONDITION EVALUATES TO TRUE  **/

	const std::function<bool(T)> condition;	/** CONDITION FOR EVALUATION **/

	/**
	 * @brief	Make decision based on condition
	 * @param	T the value used to make the decision
	 * @return	bool the decision made based on the condition (false -> leftNode, true -> rightNode)
	*/
	virtual bool make_decision(const T &val) const {

		if (!condition(T)) {
			return leftNode->make_decision(val);
		}
		else {
			return rightNode->make_decision(val);
		}

	};
	
public:

	void set_condition(const std::function<bool(T)> &func) {	/** SET CONDITION FOR EVALUATION **/
		condition = func;
	};

};

template <typename T>
class RootNode : public Node<T> {

public:
	
	bool process(const T &val) const {
		return Node<T>::make_decision(val);
	}
	
};

template <typename T>
class LeafNode : public Node<T> {

protected:
	
	virtual bool make_decision(T val) override const{

		return Node<T>::condition(val);

	};
};