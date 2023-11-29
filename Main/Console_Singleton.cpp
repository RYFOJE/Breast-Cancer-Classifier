#include "Console_Singleton.hpp"

namespace Console {
	
	MainProgram::MainProgram() {

		fs::path input_path = get_input_path();

		get_patients(input_path, patients_);

		classify_patients(patients_);
		print_results(patients_);

	}

	const fs::path get_filepath() {

		std::string str_fp;

		// Get the file path
		getline(std::cin, str_fp);

		fs::path path(str_fp);

		// If the file exists and can be opened
		if (fs::exists(path) && fs::is_regular_file(path)) {
			return path;
		}

		// If the file is not found
		throw std::invalid_argument("File does not exist.");

	}

	void clear_screen() {
		// Clear the screen
		std::cout << "\033[2J\033[1;1H";
	}

	void wait_for_enter(std::string const message) {

		if (!message.empty()) {
			std::cout << message << std::endl;
		}

		std::cout << "Press Enter to Return...";

		std::string temp = "";
		getline(std::cin, temp);
		clear_screen();
		return;

	}

	Patient process_patient_line(const std::string patientStr) {

		try {

			std::istringstream iss(patientStr);

			// Read the patient ID
			std::string patientID = "";
			getline(iss, patientID, ',');

			std::string temp;
			getline(iss, temp, ','); // Read Clump Thickness
			attribute_t clump_thickness = std::stoi(temp);
			
			getline(iss, temp, ','); // Read Uniformity of Cell Size
			attribute_t size_uniformity = std::stoi(temp);

			getline(iss, temp, ','); // Read Uniformity of Cell Shape
			attribute_t shape_uniformity = std::stoi(temp);

			getline(iss, temp, ','); // Read Marginal Adhesion
			attribute_t marginal_adhesion = std::stoi(temp);

			getline(iss, temp, ','); // Read Single Epithelial Cell Size
			attribute_t single_epithelial_size = std::stoi(temp);

			getline(iss, temp, ','); // Read Bare Nuclei
			attribute_t bare_nuclei = std::stoi(temp);

			getline(iss, temp, ','); // Read Bland Chromatin
			attribute_t bland_chromatin = std::stoi(temp);
			
			getline(iss, temp, ','); // Read Normal Nucleoli
			attribute_t normal_nucleoli = std::stoi(temp);
			
			getline(iss, temp, ','); // Read Mitoses
			attribute_t mitoses = std::stoi(temp);
			
			PatientInfo::Attributes attributes( clump_thickness, size_uniformity, shape_uniformity,
				marginal_adhesion, single_epithelial_size, bare_nuclei, bland_chromatin, normal_nucleoli, mitoses );

			return Patient(patientID, attributes);

		}
		catch (const std::invalid_argument& e) {
			throw std::invalid_argument(e.what());
		} 

		catch (const std::exception&) {
			throw std::invalid_argument("Error at process_patient, arguments not valid");
		}


	}

	const fs::path MainProgram::get_input_path() {

		while (true) {
			
			try
			{
				std::cout << "Please enter the path to the input file: ";
				return get_filepath();
			}
			catch (const std::exception&)
			{
				wait_for_enter("File does not exist.");
			}

		}

	}

	void MainProgram::classify_patients(Patients_t& patients) {
		
		for (auto& patient : patients) {
			
			bool isMalignant = classifier_.classify_patient(patient);
		
			if (isMalignant) {
				num_malignant_++;
			}
			else
				num_benign_++; {
			}
		
		}

	}

	void MainProgram::print_results(const Patients_t& patients) {
		clear_screen();
		std::cout << "Benign Patient Count: " << num_benign_ << std::endl;
		std::cout << "Malignant Patient Count: " << num_malignant_ << std::endl;
		std::cout << "Invalid Count: " << num_invalid_ <<std::endl;
	}

	void MainProgram::get_patients(std::filesystem::path const &input_path, Patients_t& patients) {

		std::ifstream file(input_path);

		if (!file.is_open()) {
			throw std::invalid_argument("File not opened");
		}

		std::string currLine;

		while (getline(file, currLine)) {

			try
			{
				patients.push_back(process_patient_line(currLine));
			}
			catch (const std::exception& e)
			{
				num_invalid_++;
				std::cout << e.what() << std::endl;
			}

		}

	}

}