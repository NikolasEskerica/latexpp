#include "AutoLateX.h"

void AutoLateX::fRun() {

	while (1)
	{
		printf("Insert the equation you wish to create as a .png file: ");
		std::getline(std::cin, equation);
		if (equation == "q") break;

		std::string path = "equation" + std::to_string(counter);
		latex.to_png(equation, "results/" + path + ".png");

		counter++;
		equation.clear();
		printf("\n");
	}

	printf("Total amount of generated images: %i \n", counter);
	return;
}