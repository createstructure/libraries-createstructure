/**
 * input.hpp
 *
 * Library to manage inputs gived by the user.
 *
 * @author Davide Castellani (@DavideC03)
 */

#ifndef INPUTS
// If not imported yet
#define INPUTS

// Dependencies
#include <string>
#include <map>
#include "json.hpp"

// using ...
using namespace std;
using json = nlohmann::json;

class Inputs
{
private:
	map<string, string> convertion = {
		{"-h", "--help"},
		{"-v", "--version"},
		{"-l", "--login"},
		{"-u", "--username"},
		{"-p", "--password"},
		{"-t", "--token"},
		{"-sn", "--server-name"},
		{"-sp", "--server-password"},
		{"-r", "--repo-info"}};
	map<string, string> m;

	string longVersion(string s);

public:
	Inputs();
	Inputs(int argc, char *argv[]);

	bool exist(string key);
	string getValue(string key);

	static bool exist(int argc, char *argv[], string key);
	static string getValue(int argc, char *argv[], string key);
};

#endif
