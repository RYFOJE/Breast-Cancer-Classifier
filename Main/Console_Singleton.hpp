#pragma once

#include "Breast-Cancer-Classifier.hpp"

#include <filesystem>
#include <vector>

namespace Console {

	namespace fs = std::filesystem;
	typedef std::vector<Patient> Patients_t;
	const fs::path OUTPUT_PATH = fs::path("results.csv");

	class MainProgram {

		Patients_t patients_;

	public:

		// Get the instance of the MainProgram
		static MainProgram& getInstance() {
			static MainProgram instance;
			return instance;
		}

	private:

		// Constructor
		MainProgram();

		const fs::path get_input_path();
		Patients_t get_patients(const fs::path& input_path);
		void output_patients(const Patients_t& patients);
		void print_results(const Patients_t& patients);

		// Private copy constructor and assignment operator to prevent copying therefore making it a singleton
		MainProgram(const MainProgram&) = delete;
		MainProgram& operator=(const MainProgram&) = delete;

	};

}