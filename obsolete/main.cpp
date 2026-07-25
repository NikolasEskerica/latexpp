#include "latex.hpp"
#include <iostream>
#include <cstdio>
#include <string>

int main(int argc, const char* argv[])
{
	Latex latex;

	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	printf("Automated latexpp - A LateX Generator for C++ (Win x64 edition)\nTo exit the program, type 'q'.\n\n");

	std::string equation = "";
	uint32_t counter = 0;

	while (1)
	{
		printf("Insert the equation you wish to create as a .png file: ");
        std::getline(std::cin, equation);
		if (equation == "q") break;
		//const std::string equation = "\frac{1}{2} + \pi \cdot 2";

		std::string path = "equation" + std::to_string(counter);
		latex.to_png(equation, "results/" + path + ".png");

		counter++;
		equation.clear();
		printf("\n");
	}

	printf("Total amount of generated images: %i \n", counter);
	std::system("pause");

}