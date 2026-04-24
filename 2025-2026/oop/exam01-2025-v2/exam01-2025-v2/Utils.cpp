#include "Utils.h"

std::size_t Utils::GetBufferLen(std::istream& is)
{
	std::streampos startPos = is.tellg();
	std::streampos pos = startPos;
	char toRead = '\0';
	size_t len = 0;
	while (!is && toRead != ' ') {
		is >> toRead;
		pos = is.tellg();
		len++;
	}

	is.seekg(startPos);

	// To remove the end of the buffer
	return len - 1;
}
