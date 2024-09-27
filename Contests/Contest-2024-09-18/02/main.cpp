#include <iostream>
#include <vector>
#include <string>


bool is_can_exit_from_maze(std::vector<std::string>maze, int row, int col)
{
	maze[row][col] = '@';
	bool is_empty = true;
	bool find_exit = false;
	while (is_empty)
	{
		is_empty = false;
		for (int r = 0; r < maze.size(); r++) {
			for (int c = 0; c < maze[r].size(); c++) {
				if (maze[r][c] == '@')
				{
					if (maze[r+1][c] == 'E' || maze[r-1][c] == 'E' || maze[r][c+1] == 'E' || maze[r][c-1] == 'E')
					{
						find_exit = true;
						break;
					}
					if (maze[r+1][c] == ' ') {maze[r+1][c] = '@'; is_empty = true;}
					if (maze[r-1][c] == ' ') {maze[r-1][c] = '@'; is_empty = true;}
					if (maze[r][c+1] == ' ') {maze[r][c+1] = '@'; is_empty = true;}
					if (maze[r][c-1] == ' ') {maze[r][c-1] = '@'; is_empty = true;}
				}
			}
		}
	}

	return find_exit;
}


int main(){
    int row, col, rows, cols;
    std::cin >> row >> col >> rows >> cols;
    std::cin.ignore(1); // Игнорируем перевод строки, застрявший в потоке ввода
    
    std::vector<std::string> maze(rows);
    for(auto& line : maze) std::getline(std::cin, line);
    
    std::cout << (is_can_exit_from_maze(maze, row, col) ? "YES" : "NO") << std::endl;
}
