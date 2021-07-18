/* createstructure_inputs library
 * By Castellani Davide (@DavideC03)
 */

#ifndef CREATESTRUCTURE_INPUTS
// If not imported yet
#define CREATESTRUCTURE_INPUTS

// Dependencies
#include <bits/stdc++.h>
#include "json.hpp"

// using ...
using namespace std;
using json = nlohmann::json;

// Definitions
// #define DEBUG

// Classes prototipe(s)
class inputs
{
/* Inputs: the class to store the CLI inputs
 */
private:
    map<string, string> m;

public:
    inputs(int argc, char *argv[]);
    string to_string();
    bool exist(string key);
    string getValue(string key);
};

// Function(s)
inputs::inputs(int argc, char *argv[])
{
    /* Inputs Constructor: the constructor of the inputs class
	 *
	 * inputs:
	 * 	- argc: the number of command-line arguments
	 *	- argv: an array containing all command-line arguments
	 */
    for (size_t i = 1; i < argc; ++i)
    {
        string tmp(argv[i]);
        if (tmp.rfind("-", 0) == 0 && i + 1 < argc && string(argv[i + 1]).rfind("-", 0) != 0)
        {
            string tmp2(argv[++i]);
            m[tmp] = tmp2;
        }
        else
        {
            if (tmp.rfind("-", 0) == 0)
                m[tmp] = "1"; // true
        }
    }
}

string inputs::to_string()
{
    /* Inputs to String: the instance printer
     *
	 * output:
	 *	- the instance string
	 */
    string s("inputs{\n");

    for (auto &elem : m)
    {
        s += "\t\"" + elem.first + "\": \"" + elem.second + "\"," + "\n";
    }

    s += "}";

    return s;
}

bool inputs::exist(string key)
{
    /* Inputs Exist: check if exist the asked key
	 *
	 * inputs:
	 * 	- key: the asked key
 	 *
	 * output:
	 *	- if the key exist in the inputs or not
	 */
    return m.find(key) != m.end();
}

string inputs::getValue(string key)
{
    /* Inputs Get Value: get the value related to the selected key
	 *
	 * inputs:
	 * 	- key: the asked key
 	 *
	 * output:
	 *	- the key value
	 */
    assert(exist(key));
    return m[key];
}

#endif
