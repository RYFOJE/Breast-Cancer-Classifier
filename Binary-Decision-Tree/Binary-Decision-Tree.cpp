#include <functional>

template <typename T>
class Node {

protected:
	Node* leftNode;		/** IF CONDITION EVALUATES TO FALSE **/
	Node* rightNode;	/** IF CONDITION EVALUATES TO TRUE  **/
	
	const std::function<bool(T)> condition;	/** CONDITION FOR EVALUATION **/

public:
	virtual bool make_decision(T) = 0;
	
	void set_condition(const std::function<bool(T)>& func);
	
};

template <typename T>
class RootNode : public Node<T> {

};

template <typename T>
class LeafNode : public Node<T> {


protected:
	
};

template <typename T>
class DecisionNode : public Node<T> {

};