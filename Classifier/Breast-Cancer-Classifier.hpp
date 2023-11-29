#pragma once

#include "Binary-Decision-Tree.hpp"
#include "Patient.hpp"

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

		/** LINKING THE NODES **/

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


		// CREATING ALL NODES FOR LEFT SIDE OF THE TREE

		Node_t* Node_L = new Node_t(
			[](Patient& patient) {return patient.get_shape_uniformity() <= 2; }
		);

		Node_t* Node_LR = new Node_t(
			[](Patient& patient) {return patient.get_clump_thickness() <= 5; }
		);

		Node_t* Node_LL = new Node_t(
			[](Patient& patient) {return patient.get_size_uniformity() <= 4; }
		);

		Leaf_t* Node_LRR = new Leaf_t(
			[](Patient& patient) {patient.set_classification(benign); return false; }
		);

		Leaf_t* Node_LRL = new Leaf_t(
			[](Patient& patient) {patient.set_classification(malignant); return true; }
		);

		Node_t* Node_LLR = new Node_t(
			[](Patient& patient) {return patient.get_bare_nuclei() <= 2; }
		);

		Leaf_t* Node_LLL = new Leaf_t(
			[](Patient& patient) {patient.set_classification(malignant); return true; }
		);

		Node_t* Node_LLRR = new Node_t(
			[](Patient& patient) {return patient.get_marginal_adhesion() <= 3; }
		);

		Node_t* Node_LLRL = new Node_t(
			[](Patient& patient) {return patient.get_clump_thickness() <= 6; }
		);

		Leaf_t* Node_LLRRR = new Leaf_t(
			[](Patient& patient) {patient.set_classification(benign); return false; }
		);

		Leaf_t* Node_LLRRL = new Leaf_t(
			[](Patient& patient) {patient.set_classification(malignant); return true; }
		);

		Node_t* Node_LLRLR = new Node_t(
			[](Patient& patient) {return patient.get_size_uniformity() <= 3; }
		);

		Leaf_t* Node_LLRLRR = new Leaf_t(
			[](Patient& patient) {patient.set_classification(malignant); return true; }
		);

		Node_t* Node_LLRLRL = new Node_t(
			[](Patient& patient) {return patient.get_marginal_adhesion() <= 5; }
		);

		Leaf_t* Node_LLRLRLR = new Leaf_t(
			[](Patient& patient) {patient.set_classification(benign); return false; }
		);

		Leaf_t* Node_LLRLRLL = new Leaf_t(
			[](Patient& patient) {patient.set_classification(malignant); return true; }
		);

		Leaf_t* Node_LLRLL = new Leaf_t(
			[](Patient& patient) {patient.set_classification(malignant); return true; }
		);


		root->set_left_node(Node_L);				// Decision
		Node_L->set_right_node(Node_LR);			// Decision
		Node_L->set_left_node(Node_LL);				// Decision
		Node_LR->set_right_node(Node_LRR);			// Leaf
		Node_LR->set_left_node(Node_LRL);			// Leaf

		Node_LL->set_right_node(Node_LLR);			// Decision
		Node_LL->set_left_node(Node_LLL);			// Leaf

		Node_LLR->set_right_node(Node_LLRR);		// Decision
		Node_LLR->set_left_node(Node_LLRL);			// Decision

		Node_LLRR->set_right_node(Node_LLRRR);		// Leaf
		Node_LLRR->set_left_node(Node_LLRRL);		// Leaf

		Node_LLRL->set_right_node(Node_LLRLR);		// Decision
		Node_LLRL->set_left_node(Node_LLRLL);		// Leaf

		Node_LLRLR->set_right_node(Node_LLRLRR);	// Leaf
		Node_LLRLR->set_left_node(Node_LLRLRL);		// Decision

		Node_LLRLRL->set_right_node(Node_LLRLRLR);	// Leaf
		Node_LLRLRL->set_left_node(Node_LLRLRLL);	// Leaf

		/** DONE BUILDING LEFT SIDE OF TREE **/
		/** DONE BUILDING TREE **/

	};

	~Classifier() {
		delete root;
	}

	bool classify_patient(Patient& patient) {
		return root->process(patient);
	}

	bool verify_tree() {
		return root->recursive_verify_tree();
	}

};
