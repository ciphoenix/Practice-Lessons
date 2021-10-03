#include <iostream>
#include <algorithm>


// Define is_palindrome() here:
bool is_palindrome(std::string text)
{
	std::string alt_text;
	for (int i = text.length() - 1; i >= 0; i--)
	{
		//concatenate characters to the reverse
		alt_text = alt_text + text[i];
	}

	if (text.compare(alt_text) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{

	std::cout << is_palindrome("madam") << "\n";
	std::cout << is_palindrome("ada") << "\n";
	std::cout << is_palindrome("lovelace") << "\n";

}