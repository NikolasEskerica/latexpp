Github repositories
Revival program – C++
Original project: latexcpp - (https://github.com/goldsborough/latexpp)

Written by: Nikolas Eškerica
Date: 24/07/2026

Licensed by MIT

This is a modified fork of Peter Goldsborough's "latexcpp" project that is adapted for VS2022+ (Debug x64 /MTd) exclusively. 

The project is outdated (10+ years) and no longer compatible with modern versions of its dependencies, so I downgraded and adjusted them completely to make the author's code runnable again for future C++ projects.

The dependency versions that have been utilized are as follows:

- V8 Javascript Engine - 4.5.103.35
- wkhtmltox library - 0.12.2.4 (mocked)
- Boost library - removed

Additionally, ImageMagick has been added to allow cropping and other editing for generated .png Latex-based images, offering an improvement in results. The project does not require it to work.

For simpler use, the solution is standalone/ready-to-build and does not need any configurations beforehand. However, due to the large size of some of the files, I have made a release which needs to be extracted into the project before launching it. Separate pre-compiled output files are in x64/Debug/.