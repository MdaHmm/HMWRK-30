#include <iostream>
#include <string>
#include <fstream>

bool overwrite( const std::string path, const  std::string str);

int main() {
	setlocale(LC_ALL, "Russian");
	
	std::cout << "������ 1.\n\n";

	std::ofstream out;

	out.open("file.ramm", std::ios::app);
	if (out.is_open()) {
		std::string input;
		do {
			std::cout << "������� ������: ";
			std::getline(std::cin, input);
			out << input << "\n";
		} while (input != "end");
		out.close();
	
	}
	else
		std::cout << "������ �������� �����\n";

	std::ifstream in;
	in.open("file.ramm");

	if (in.is_open()) {
		std::string str;
		while (std::getline(in, str)) {
			std::cout << str << std::endl;
		}
	}
	else
		std::cout << "������ �������� �����.\n";

	in.close();
	remove("file.ramm");
	

	std::cout << "������ 2.\n\n";

	std::ofstream file;
	std::string path = "file2.ramm";
	
	file.open(path);

	if (file.is_open()) {
		std::cout << "���� ������ ��� ������. ������� ����� -> ";
		std::string text;
		std::getline(std::cin, text);
		file << text << "\n";
		std::cout << std::endl;
	}
	else
		std::cout << "������ �������� �����.\n\n";
	file.close();

	std::cout << "������� ������ ��� ������ � ����� -> ";
	std::string text2;
	std::getline(std::cin, text2);

	if (overwrite(path, text2))
		std::cout << "������ ���������.";
	else
		std::cout << "������ �������� �����.";

	return 0;
}
bool overwrite(const std::string path, const  std::string str) {
	std::ifstream file;
	file.open(path);
	if (!file.is_open()) {
		file.close();
		return false;
	}
	file.close();
	std::ofstream file2;
	file2.open(path);
	if (!file2.is_open()) {
		file2.close();
		return false;
	}
	file2 << str << '\n';
	file2.close();
	return true;
}
