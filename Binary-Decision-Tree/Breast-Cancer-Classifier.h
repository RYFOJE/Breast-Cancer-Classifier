#pragma once

#include "Binary-Decision-Tree.h"
#include "patient.h"

class Classifier {

private:
	Node<Patient>* root;

public:

	Classifier() {
		root = new RootNode<Patient>();
	};

};
