#include <iostream>
#include <fstream>

int main()
{
	std::string s;
	std::ifstream ReadFile("in.txt");
	std::ofstream OutFile("out.sublime-macro");

	OutFile << '[';

	bool comma = false;
	while (getline(ReadFile, s))
	{
		if (comma) OutFile << ',';
		else comma = true;

		OutFile << '\n';

		OutFile << "\t" << '{' << '\n';
		OutFile << "\t\t" << "\"args\":" << '\n';
		OutFile << "\t\t" << '{' << '\n';
		OutFile << "\t\t\t" << "\"characters\": " << "\"" << s << "\\n" << "\"" << '\n';
		OutFile << "\t\t" << "}," << '\n';
		OutFile << "\t\t" << "\"command\": \"insert\"" << '\n';
		OutFile << "\t" << '}';
	}

	OutFile << '\n';
	OutFile << ']';
	OutFile << '\n';

	return 0;
}