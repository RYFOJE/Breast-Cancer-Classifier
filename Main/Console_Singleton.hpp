#pragma once

class MainProgram {

public:

	// Get the instance of the MainProgram
	static MainProgram& getInstance() {
		static MainProgram instance;
		return instance;
	}

private:

	
	// Private copy constructor and assignment operator to prevent copying therefore making it a singleton
	MainProgram(const MainProgram&) = delete;
	MainProgram& operator=(const MainProgram&) = delete;

};