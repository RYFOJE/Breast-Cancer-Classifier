#pragma once

#include "Binary-Decision-Tree.h"
#include "patient.h"

using namespace PatientInfo;

class Classifier {
	
private:

	// Create typedefs for Nodes as they will be often re-written
	typedef Node<Patient> Node_t;
	typedef LeafNode<Patient> Leaf_t;
	typedef RootNode<Patient> Root_t;

	Root_t* root;

public:

	Classifier() {
		
		root = new Root_t(
			[](Patient& patient) {return patient.get_size_uniformity() <= 2; }
		);
		
		// CREATING ALL NODES FOR RIGHT SIDE OF THE TREE

		// Uniformity of cell size is <= 2
		Node_t* Node_R = new Node_t(
			[](Patient& patient) {return patient.get_bare_nuclei() <= 3; }
		);
		
		Leaf_t* Node_RR = new Leaf_t(
			[](Patient& patient) {patient.set_classification(benign); return false; }
		);

		Node_t* Node_RL = new Node_t(
			[](Patient& patient) {return patient.get_clump_thickness() <= 3; }
		);

		Leaf_t* Node_RLR = new Leaf_t(
			[](Patient& patient) {patient.set_classification(malignant); return true; }
		);

		Node_t* Node_RLL = new Node_t(
			[](Patient& patient) {return patient.get_bland_chromatin() <= 2; }
		);

		Node_t* Node_RLLR = new Node_t(
			[](Patient& patient) {return patient.get_marginal_adhesion() <= 3; }
		);

		Leaf_t* Node_RLLL = new Leaf_t(
			[](Patient& patient) {patient.set_classification(malignant); return true; }
		);

		Leaf_t* Node_RLLRR = new Leaf_t(
			[](Patient& patient) {patient.set_classification(malignant); return true; }
		);

		Leaf_t* Node_RLLRL = new Leaf_t(
			[](Patient& patient) {patient.set_classification(benign); return false; }
		);

		root->set_right_node(Node_R);
		Node_R->set_left_node(Node_RL);
		Node_R->set_right_node(Node_RR);
		Node_RL->set_left_node(Node_RLL);
		Node_RL->set_right_node(Node_RLR);
		Node_RLL->set_left_node(Node_RLLL);
		Node_RLL->set_right_node(Node_RLLR);
		Node_RLLR->set_left_node(Node_RLLRL);
		Node_RLLR->set_right_node(Node_RLLRR);

		/** RIGHT SIDE OF THE TREE HAS BEEN BUILT **/



	};

	~Classifier() {
		delete root;
	}

	void classify_patient(Patient& patient) {
		root->process(patient);
	}

};
