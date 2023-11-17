#pragma once

#include "Binary-Decision-Tree.h"
#include "patient.h"

class Classifier {

private:

	// Create typedefs for Nodes as they will be often re-written
	typedef Node<PatientInfo::Patient> Node_t;
	typedef LeafNode<PatientInfo::Patient> LeafNode_t;

	Node_t* root;

public:

	Classifier() {
		using namespace PatientInfo;
		root = new Node<Patient>([](Patient patient) {return false; });

	};

};
