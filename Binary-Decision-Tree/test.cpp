#include "Breast-Cancer-Classifier.h"
#include <iostream>

int main() {

	Attributes test_R(2, 2, 3, 3, 3, 3, 3, 3, 3);
	Patient testPatient_R("Ryan Jennings", test_R);


	Classifier classifierClass;

	classifierClass.classify_patient(testPatient_R);
	
	std::cout << "Patient Classified to: " << testPatient_R.get_classification();

}