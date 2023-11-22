#pragma once

#include <string>
#include <stdexcept>

namespace PatientInfo {

	// Typedefs
	typedef unsigned int attribute_t;

	// Attribute acceptable range
	const attribute_t MIN_SIZE = 1;
	const attribute_t MAX_SIZE = 10;

	/** STRUCTS **/

	/**
	 * @brief Helps hold all patient values
	*/
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

		Attributes(attribute_t c_t, attribute_t si_u, attribute_t sh_u,
			attribute_t m_a, attribute_t s_e_s, attribute_t b_n,
			attribute_t b_c, attribute_t n_n, attribute_t m) :
			clump_thickness_(c_t), size_uniformity_(si_u), shape_uniformity_(sh_u),
			marginal_adhesion_(m_a), single_epithelial_size_(s_e_s), bare_nuclei_(b_n),
			bland_chromatin_(b_c), normal_nucleoli_(n_n), mitoses_(m) {};

	};


	/** ENUMS **/

	enum classifications { unclassified = 0, error = -1, benign = 2, malignant = 4 };

	std::string classification_name(const classifications classification);



	/** HELPER FUNCTIONS **/

	void is_valid_attribute(const attribute_t attribute);

	void verify_attribute_struct(const Attributes& attributes);

	/** CLASSES **/

	class Patient {

	private:

		const std::string patientID_;
		classifications classification_;
		const Attributes patientAttributes;

	public:

		/** CONSTRUCTOR **/

		Patient(const std::string patientID, Attributes values) :
			patientID_(patientID), patientAttributes(values), classification_(unclassified) {

			verify_attribute_struct(values);
		};
		/**


		attribute_t clump_thickness_;
		attribute_t size_uniformity_;
		attribute_t shape_uniformity_;
		attribute_t marginal_adhesion_;
		attribute_t single_epithelial_size_;
		attribute_t bare_nuclei_;
		attribute_t bland_chromatin_;
		attribute_t normal_nucleoli_;
		attribute_t mitoses_;

		*/

		attribute_t get_clump_thickness() const {
			return patientAttributes.clump_thickness_;
		}

		attribute_t get_size_uniformity() const {
			return patientAttributes.size_uniformity_;
		}

		attribute_t get_shape_uniformity() const {
			return patientAttributes.shape_uniformity_;
		}

		attribute_t get_marginal_adhesion() const {
			return patientAttributes.marginal_adhesion_;
		}

		attribute_t get_single_epithelial_size() const {
			return patientAttributes.single_epithelial_size_;
		}

		attribute_t get_bare_nuclei() const {
			return patientAttributes.bare_nuclei_;
		}

		attribute_t get_bland_chromatin() const {
			return patientAttributes.bland_chromatin_;
		}

		attribute_t get_normal_nucleoli() const {
			return patientAttributes.normal_nucleoli_;
		}

		attribute_t get_mitoses() const {
			return patientAttributes.mitoses_;
		}

		std::string get_patient_id() const {
			return patientID_;
		}

		classifications get_classification() const {
			return classification_;
		}

		void set_classification(classifications classification) {
			classification_ = classification;
		}



	};
}