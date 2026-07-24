#include "latex.hpp"

#include <iostream>


int main(int argc, const char* argv[])
{
	Latex latex;
	
	std::cout << latex.to_html("\\frac{1}{2} + \\pi \\cdot 2") << std::endl;

	//const std::string equation = "\\sum_{i=1}^{n} i = \\frac{n(n + 1)}{2}";
	const std::string equation = "\\int_{-\\infty}^{+\\infty} \\frac{1}{\\sigma \\sqrt{2\\pi}} e^{-\\frac{1}{2}\\left(\\frac{x-\\mu}{\\sigma}\\right)^2} dx = 1";

	latex.to_png(equation, "results/equation.png");

	std::string html = latex.to_html(equation);

	std::cout << html << std::endl;
	
}