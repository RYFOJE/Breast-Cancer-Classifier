#include "Breast-Cancer-Classifier.h"
#include <iostream>


#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>



int main() {


	Attributes test_RR (2, 2, 3, 3, 3, 3, 3, 3, 3); // Benign RR
	Attributes test_RLR(2, 2, 3, 3, 3, 4, 3, 3, 3); // Malignant RLR
	Patient testPatient_RR("Ryan Jennings", test_RR);
	Patient testPatient_RLR("Ryan Jennings", test_RLR);


	Classifier classifierClass;

	classifierClass.classify_patient(testPatient_RR);
	classifierClass.classify_patient(testPatient_RLR);

	std::cout << "Patient Classified to: " << testPatient_RR.get_classification() << std::endl;
	std::cout << "Patient Classified to: " << testPatient_RLR.get_classification() << std::endl;

	_CrtDumpMemoryLeaks();

}