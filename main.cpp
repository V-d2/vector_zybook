#include "Vector.h"
using namespace Vector;

int main()
{
	vector<string> v1(20);	// 20 elements, each initialized to 0
	std::cout << "Size of v1: " << v1.size() << std::endl;

	vector<string> v2;
	v2.push_back("a");
	v2.push_back("b");
	v2.push_back("c");
	v2.push_back("d");
	v2.push_back("e");
	std::cout << v2 << std::endl;

	vector<string> v3 = v2; 	// what happens here?
	vector<string> v4;
	v4 = v2;					// what happens here?
	v2[0] = "Test2";
	v3[0] = "Test3";
	v4[4] = "Test4";
	std::cout << "Independent copies: " << v2[0] << " " << v3[0] << " " << v4[0] << std::endl;

	string d;

	vector<string> v5(3);
	std::string s;
	std::cout << "Input 3 strings: ";
	for (int i = 0; i < 3; i++)
	{
		std::cin >> s;
		v5.at(i) = s;
	}
	v5.push_back("Hello");
	v5.resize(100);  //will fill the rest with empty strings ""
	std::cout << v5 << std::endl;

	vector<int> v6;
	try {
		for (int i = 0; i < 5; ++i) v6.push_back(i);
		for (size_t i = 0; i <= v6.size(); ++i)
			std::cout << "v[" << i << "]==" << v6.at(i) << '\n';
	}
	catch (out_of_range_) {		// we’ll get here (why?)
		std::cout << "out of range error" << std::endl;
	}
	std::cout << v6 << std::endl;

	vector<double> v7;
	v7.push_back(3.14);
	const vector<double> v8 = v7;
	double d1 = v8[7];	// call the const version of [ ]
	double d2 = v7[7];	// call the non-const version of [ ]
	//v8[7] = 9;		// error: call the const version of [ ]
	v7[7] = 9;		// call the non-const version of [ ]: ok 

	std::cout << "Press any key then enter to exit: ";
	std::cin >> d;

	return 0;
}//in visual studio put a breakpoint here to see destructors