#include "latex.hpp"
#include <iostream>
#include <cstdio>
#include <string>

class AutoLateX
{
	Latex latex;
	std::string equation;
	uint32_t counter;

public:

	AutoLateX() : equation(""), counter(0) {
		std::ios::sync_with_stdio(false);
		std::cin.tie(nullptr);

		printf("Automated latexpp - A LateX Generator for C++ (Win x64 edition)\nTo exit the program, type 'q'.\n\n");

	}

	void fRun();

};

