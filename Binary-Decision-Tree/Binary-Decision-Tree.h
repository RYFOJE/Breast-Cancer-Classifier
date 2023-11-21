#pragma once

#include <functional>
#include <iostream>



template <typename T>
class Node {

protected:
	const Node* leftNode;		/** IF CONDITION EVALUATES TO FALSE **/
	const Node* rightNode;	/** IF CONDITION EVALUATES TO TRUE  **/

	const std::function<bool(T&)> condition;	/** CONDITION USED FOR EVALUATION **/

	/**
	 * @brief	Make decision based on condition
	 * @param	T the value used to make the decision
	 * @return	bool the decision made based on the condition (false -> leftNode, true -> rightNode)
	*/
	virtual bool make_decision(T &val) const {

		if (!condition(val)) {
			std::cout << "L";
			return leftNode->make_decision(val);
		}
		else {
			std::cout << "R";
			return rightNode->make_decision(val);
		}
	};
	
public:

	/** CONSTRUCTOR **/
	Node(const std::function<bool(T&)>& func) : condition(func), leftNode(nullptr), rightNode(nullptr) {};

	/** DESTRUCTOR **/

	/**
	 * @brief Destructor for Node objects, will iterate to all attached nodes and subsequently
	 *		deletes them
	*/
	~Node() {

		if (leftNode != nullptr) {
			delete leftNode;
		}

		if (rightNode != nullptr) {
			delete rightNode;
		}

	}

	/** GETTERS AND SETTERS **/

	/**
	 * @brief		Set the Node to the left of this Node
	 * @param node	The node to be set
	*/
	void set_left_node(const Node* node) {
		leftNode = node;
	}

	/**
	 * @brief		Set the Node to the right of this Node
	 * @param node	The node to be set
	*/
	void set_right_node(const Node* node) {
		rightNode = node;
	}

};

template <typename T>
class RootNode : public Node<T> {

public:
	
	/** CONSTRUCTOR **/
	RootNode(const std::function<bool(T&)>& func) : Node<T>(func) {};

	/**
	 * @brief		Acts as an entry point into the decision tree for processing data.
	 * @param val	The value to be processed by the tree.
	 * @return		Returns the calculated value of the tree
	*/
	bool process(T &val) const{
		return Node<T>::make_decision(val);
	}
	
};

template <typename T>
class LeafNode : public Node<T> {

protected:
	
	virtual bool make_decision(T& val) const override{
		std::cout << std::endl;
		return Node<T>::condition(val);
	};

public:

	/** CONSTRUCTOR **/
	LeafNode(const std::function<bool(T&)>& func) : Node<T>(func) {};
};