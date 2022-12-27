/**
 * emoji.hpp
 * 
 * Library for handling emoji.
 * 
 * @author Castellani Davide (@DavideC03)
 */

#ifndef EMOJI
// If not imported yet
#define EMOJI

// Dependencies
#include <string>
#include <map>

// using ...
using namespace std;

class Emoji
{
private:
	static map<string, string> emoji_map;

public:
	static string getEmoji(string emoji_name);
};

#endif
