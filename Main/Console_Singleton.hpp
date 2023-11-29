
#pragma once

#include "Breast-Cancer-Classifier.hpp"

#include <filesystem>
#include <vector>
#include <iostream>
#include <fstream>

namespace Console {

	namespace fs = std::filesystem;
	typedef std::vector<Patient> Patients_t;
	const fs::path OUTPUT_PATH = fs::path("results.csv");

	/**
	 * @brief 	Singleton class for the main program
	*/
	class MainProgram {

		Patients_t patients_ = std::vector<Patient>();
		Classifier classifier_ = Classifier();

		unsigned int num_benign_ = 0;
		unsigned int num_malignant_ = 0;
		unsigned int num_invalid_ = 0;


	public:

		// Get the instance of the MainProgram
		static MainProgram& getInstance() {
			static MainProgram instance;
			return instance;
		}

	private:

		// Constructor
		MainProgram();

		/**
		 * @brief	Asks the user for the path to the input file
		 * @return	The path to the input file
		*/
		const fs::path get_input_path();
		
		/**
		 * @brief				Gets the patients from the input file
		 * @param input_path	The path to the input file
		 * @param patients		The vector to store the patients in
		*/
		void get_patients(std::filesystem::path const& input_path, Patients_t& patients);
		
		/**
		 * @brief				Classifies the patients
		 * @param patients		The vector of patients to classify
		*/
		void classify_patients(Patients_t& patients);
		
		/**
		 * @brief				Prints the results of the classification
		 * @param patients		The vector of patients to print the results of
		*/
		void print_results(const Patients_t& patients);

		void output_all() const;

		// Private copy constructor and assignment operator to prevent copying therefore making it a singleton
		MainProgram(const MainProgram&) = delete;
		MainProgram& operator=(const MainProgram&) = delete;

	};

}