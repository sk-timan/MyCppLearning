#pragma once

#include <iostream>

#define MacroTest( Macro_1_parameter, Macro_2_parameter ) \
	MacroTest_1( Macro_1_parameter ) \
	MacroTest_2( Macro_2_parameter ) \
	std::cout << "Yeap_1!"<< endl; \
	std::cout << "Yeap_2!"<< endl;std::cout << "Yeap!"<< endl;

#define MacroTest_1( Macro_1_parameter ) \
	struct MyStruct	\
	{ \
		MyStruct() \
		{ \
			CombineTime( Macro_1_parameter, 2 ); \
		} \
	} MyMacroTest_1;

#define MacroTest_2( Macro_2_parameter ) \
	std::cout << "Yeap!"<< endl;
	


#define A B C D;
#define B int a = 1;std::cout << a + a; 
#define C 2;
#define D 3;

void CombineTime(int a, int b);

static int MyInt = 56;