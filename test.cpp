#include "gtest/gtest.h"
#include <cstring>
#include <iostream>
#include "ex00/ft_strcpy.c"
#include "ex01/ft_strncpy.c"
#include "ex02/ft_str_is_alpha.c"
#include "ex03/ft_str_is_numeric.c"
#include "ex04/ft_str_is_lowercase.c"
#include "ex05/ft_str_is_uppercase.c"
#include "ex06/ft_str_is_printable.c"
#include "ex07/ft_strupcase.c"
#include "ex08/ft_lowecase.c"
#include "ex09/ft_strcapitalize.c"


namespace {
	char* lowecase = (char*)"ajhsdf";
	char* uppercase = (char*)"KHGIUSG";
	char* alpha_mix = (char*)"hjdKJH";
	char* numeric   = (char*)"1638264";
	char* alpha_num =(char*) "sjdfh9298";
	char* mixed	=(char*) "87jDg{}][";
	char* nullstr	=(char*) "";
	char* nullstrptr	= nullptr;

	void print_all() {
		std::cout << lowecase << std::endl;
		std::cout << uppercase << std::endl;
		std::cout << alpha_mix << std::endl;
		std::cout << numeric << std::endl;
		std::cout << alpha_num << std::endl;
		std::cout << mixed << std::endl;
	}

	TEST(ex00, ft_strcpy) {
		char dest[7];
		EXPECT_STREQ(lowecase, ft_strcpy(dest, lowecase));
		EXPECT_EQ(0, ft_strcpy(nullstrptr, alpha_num));
	}

	TEST(ex01, ft_strncpy) {
		char bytes3[3];
		char bytes7[7];
		char bytes10[10];

		EXPECT_STREQ(lowecase, ft_strncpy(bytes7, lowecase, 7));
		EXPECT_STREQ("ajhsdf\0\0\0", ft_strncpy(bytes10, lowecase, 10));
		EXPECT_EQ(0, strncmp(ft_strncpy(bytes3, mixed, 3), mixed, 3));
	}

	TEST(ex02, str_is_alpha) {
		EXPECT_EQ(1, ft_str_is_alpha(uppercase));
		EXPECT_EQ(1, ft_str_is_alpha(nullstr));
		EXPECT_EQ(0, ft_str_is_alpha(numeric));
		EXPECT_EQ(0, ft_str_is_alpha(mixed));
		EXPECT_EQ(0, ft_str_is_alpha(nullstrptr));
	}

	TEST(ex03, ft_str_is_numeric) {
		EXPECT_EQ(1, ft_str_is_numeric(numeric));
		EXPECT_EQ(1, ft_str_is_numeric(nullstr));
		EXPECT_EQ(0, ft_str_is_numeric(nullstrptr));
		EXPECT_EQ(0, ft_str_is_numeric(lowecase));
		EXPECT_EQ(0, ft_str_is_numeric(mixed));
	}

	TEST(ex04, ft_str_is_lowecase) {
		EXPECT_EQ(1, ft_str_is_lowercase(lowecase));
		EXPECT_EQ(1, ft_str_is_lowercase(nullstr));
		EXPECT_EQ(0, ft_str_is_lowercase(nullstrptr));
		EXPECT_EQ(0, ft_str_is_lowercase(uppercase));
		EXPECT_EQ(0, ft_str_is_lowercase(mixed));
	}

	TEST(ex05, ft_str_is_uppercase) {
		EXPECT_EQ(1, ft_str_is_uppercase(uppercase));
		EXPECT_EQ(1, ft_str_is_uppercase(nullstr));
		EXPECT_EQ(0, ft_str_is_uppercase(mixed));
		EXPECT_EQ(0, ft_str_is_uppercase(nullstrptr));
	}

	TEST(ex06, ft_str_is_printable) {
		char test[7];
		strncpy(test, lowecase, 7);
		test[3] = 1;

		EXPECT_EQ(1, ft_str_is_printable(lowecase));
		EXPECT_EQ(1, ft_str_is_printable(mixed));
		EXPECT_EQ(0, ft_str_is_printable(test));
	}

	TEST(ex07, ft_strupcase) {
		char tlowcase[7];
		char tnum[8];
		char tmixed[10];

		strncpy(tlowcase, lowecase, 7);
		strncpy(tnum, numeric, 8);
		strncpy(tmixed, mixed, 10);

		EXPECT_STREQ("AJHSDF", ft_strupcase(tlowcase));
		EXPECT_STREQ(numeric, ft_strupcase(tnum));
		EXPECT_STREQ("87JDG{}][", ft_strupcase(tmixed));
	}

	TEST(ex08, ft_lowecase) {
		char tlowcase[7];
		char tnum[8];
		char tmixed[10];

		strncpy(tlowcase, lowecase, 7);
		strncpy(tnum, numeric, 8);
		strncpy(tmixed, mixed, 10);

		EXPECT_STREQ(lowecase, ft_strlowcase(tlowcase));
		EXPECT_STREQ(numeric, ft_strlowcase(tnum));
		EXPECT_STREQ("87jdg{}][", ft_strlowcase(tmixed));
	}

	TEST(ex09, ft_strcapitalize) {
		std::string a = "a new test 46JHJ TkdJ";
		char test[a.size()];
		strncpy(test, a.c_str(), a.size());

		EXPECT_STREQ("A New Test 46jhj Tkdj", ft_strcapitalize(test));
	}
}

int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	return 0;
}
