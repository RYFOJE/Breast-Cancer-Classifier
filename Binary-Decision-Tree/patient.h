#pragma once

#include <string>
#include <stdexcept>

namespace PatientInfo {
	
	// Typedefs
	typedef unsigned int attribute_t;

	// Attribute acceptable range
	const attribute_t MIN_SIZE = 1;
	const attribute_t MAX_SIZE = 10;

	// Struct to hold patients values
	struct Attributes {
		attribute_t clump_thickness_;
		attribute_t size_uniformity_;
		attribute_t shape_uniformity_;
		attribute_t marginal_adhesion_;
		attribute_t single_epithelial_size_;
		attribute_t bare_nuclei_;
		attribute_t bland_chromatin_;
		attribute_t normal_nucleoli_;
		attribute_t mitoses_;
	};



	// Helper methods for class

	void is_valid_attribute(const attribute_t attribute) {

		if (attribute >= MIN_SIZE && attribute <= MAX_SIZE)
			return;

		throw std::invalid_argument("Patient attribute is out of range.");

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


	class Patient {

	private:

		const std::string patientID_;
		int classification_;
		const Attributes patientAttributes;

	public:

		Patient(const std::string patientID, Attributes values) : patientID_(patientID), patientAttributes(values) {
			verify_attribute_struct(values);
		};

	};
}