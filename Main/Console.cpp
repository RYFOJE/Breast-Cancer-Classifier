#include "Console_Singleton.hpp"

namespace Console {
	
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

	MainProgram::MainProgram() {
		
		fs::path input_path = get_input_path();
		patients = get_patients(input_path);
		
		output_patients(patients);
		print_results(patients);

	}

	const fs::path MainProgram::get_input_path() {

		std::cout << "Please enter the path to the input file: ";

		while (true) {
			
			try
			{
				return get_filepath();
			}
			catch (const std::exception&)
			{

			}

		}
		
		return get_filepath();

	}

	Patients_t MainProgram::get_patients(const fs::path& input_path) {
		

	}

	void MainProgram::output_patients(const Patients_t& patients) {
		

	}

	void MainProgram::print_results(const Patients_t& patients) {
		
		
	}

}