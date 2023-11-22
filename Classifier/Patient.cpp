#include "Patient.hpp"

using namespace PatientInfo;

std::string classification_name(const classifications classification) {

	switch (classification) {

	case unclassified:
		return "unclassified";

	case error:
		return "error";

	case benign:
		return "benign";

	case malignant:
		return "malignant";

	default:
		throw std::invalid_argument("Error at classifcation_name, argument not valid");
		return "";
	}
}

void verify_attribute_struct(const Attributes& attributes) {

	is_valid_attribute(attributes.bare_nuclei_);
	is_valid_attribute(attributes.bland_chromatin_);
	is_valid_attribute(attributes.clump_thickness_);
	is_valid_attribute(attributes.marginal_adhesion_);
	is_valid_attribute(attributes.mitoses_);
	is_valid_attribute(attributes.normal_nucleoli_);
	is_valid_attribute(attributes.shape_uniformity_);
	is_valid_attribute(attributes.single_epithelial_size_);
	is_valid_attribute(attributes.size_uniformity_);

}

void is_valid_attribute(const attribute_t attribute) {

	if (attribute >= MIN_SIZE && attribute <= MAX_SIZE)
		return;

	throw std::invalid_argument("Patient attribute is out of range.");

}