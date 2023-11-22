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