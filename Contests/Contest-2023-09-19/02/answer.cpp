#define debug false

void way(std::vector<std::string> &maze, int y, int x)
{
    if (maze[y][x] == '2') maze[y][x] = '3';
    if (maze[y][x] == '1') maze[y][x] = '2';
    if (maze[y][x] == ' ') maze[y][x] = '1';
}

bool is_can_exit_from_maze(std::vector<std::string> maze, int y, int x)
{
    bool fnd = false; //поиск символа E
    for (int i = 0; i < maze.size(); i++)
    {
        if (maze[i].find('E') != 18446744073709551615)
        {
            fnd = true;
            break;
        }
    }
    if (!fnd) return fnd;

    int route = 0;
    while (true)
    {
        if (debug)
        {
            for (int i = 0; i < maze.size(); i++)
            {
                std::cout << maze[i] << std::endl;
            }
            std::cout << std::endl;
        }

        if (maze[y][x] == '3') return false;
        if (maze[y][x] == 'E') return true;
        switch (route)
        {
        case 0:
            if (maze[y][x + 1] == '#')
            {
                if (maze[y - 1][x] != '#')
                {
                    y--;
                    way(maze, y, x);
                    continue;
                }
                route++;
                continue;
            }
            
            x++;
            way(maze, y, x);
            continue;

        case 1:
            if (maze[y - 1][x] == '#')
            {
                if (maze[y][x - 1] != '#')
                {
                    x--;
                    way(maze, y, x);
                    continue;
                }
                route++;
                continue;
            }
            
            y--;
            way(maze, y, x);
            continue;

        case 2:
            if (maze[y][x - 1] == '#')
            {
                if (maze[y + 1][x] != '#')
                {
                    y++;
                    way(maze, y, x);
                    continue;
                }
                route++;
                continue;
            }
            
            x--;
            way(maze, y, x);
            continue;

        case 3:
            if (maze[y + 1][x] == '#')
            {
                if (maze[y][x + 1] != '#')
                {
                    x++;
                    way(maze, y, x);
                    continue;
                }
                route = 0;
                continue;
            }
            
            y++;
            way(maze, y, x);
            continue;
        }
    }
}
