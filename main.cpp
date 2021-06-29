#include <iostream>

struct Node
{
	/*
		type = 0 // wall
		type = 1 // normal cell
		type = 2 // start pixel
		type = 3 // end pixel 
	 */
	int type;

	bool isVisited;
	unsigned int distance;
	int previousNode[2];
};

int main()
{
	// geting image size from header
	int width, height;
	std::string line;
	getline(std::cin, line);
	std::cin >> width >> height;
	getline(std::cin, line);
	getline(std::cin, line);

	// allocating image buffer and populating it
	char imageBuffer[height][width][3];
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			for (int k = 0; k < 3; k++)
			{
				// std::cin.read(&imageBuffer[i][j][k], sizeof(char));
				scanf("%c", &imageBuffer[i][j][k]);
			}

	// generating grid
}