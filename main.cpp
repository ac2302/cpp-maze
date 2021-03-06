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
	bool hasPreviousNode;
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
	Node grid[height][width];

	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
		{
			if ((imageBuffer[i][j][0] == 0xff) && (imageBuffer[i][j][2] == 0xff) && (imageBuffer[i][j][2] == 0xff))
			{
				// pixel is a normal pixel
				grid[i][j].type = 1;
				grid[i][j].isVisited = false;
				grid[i][j].hasPreviousNode = false;
				grid[i][j].distance = -1;
			}
			else if ((imageBuffer[i][j][0] == 0xff) && (imageBuffer[i][j][2] == 0x00) && (imageBuffer[i][j][2] == 0x00))
			{
				// pixel is a start pixel
				grid[i][j].type = 2;
				grid[i][j].isVisited = false;
				grid[i][j].hasPreviousNode = false;
				grid[i][j].distance = 0;
			}
			else if ((imageBuffer[i][j][0] == 0x00) && (imageBuffer[i][j][2] == 0x00) && (imageBuffer[i][j][2] == 0xff))
			{
				// pixel is an end pixel
				grid[i][j].type = 3;
				grid[i][j].isVisited = false;
				grid[i][j].hasPreviousNode = false;
				grid[i][j].distance = 0;
			}
			else if ((imageBuffer[i][j][0] == 0xff) && (imageBuffer[i][j][2] == 0x00) && (imageBuffer[i][j][2] == 0x00))
			{
				// pixel is a wall pixel
				grid[i][j].type = 0;
			}
		}

	// starting the Djikstra's Shortest Path Algorithm
	unsigned int unvisited = 0;
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			if (grid[i][j].type != 0)
				unvisited++;

	// starting the body of the algorithm
	int current[2];
	int previous[] = {0, 0};
	unsigned int currentDist;
	while (unvisited != 0)
	{
		// finding the unvisited node with the least distance from start
		currentDist = -1;
		for (int i = 0; i < height; i++)
			for (int j = 0; j < width; j++)
				if (!grid[i][j].isVisited)
				{
					if (grid[i][j].distance < currentDist)
					{
						current[0] = i;
						current[1] = j;
						currentDist = grid[i][j].distance;
					}
				}

		// marking the node as visited
		grid[current[0]][current[1]].isVisited = true;
		unvisited--;
		// setting the previous node
		grid[current[0]][current[1]].previousNode[0] = previous[0];
		grid[current[0]][current[1]].previousNode[1] = previous[1];
		// setting previous to current
		previous[0] = current[0];
		previous[1] = current[1];
	}
}