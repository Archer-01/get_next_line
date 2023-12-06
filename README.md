# Get Next Line

*Reading a line on a <a href="https://en.wikipedia.org/wiki/File_descriptor" target="_blank">file descriptor</a> is way too tedious*

## Normal Version

### Description
* A function that reads a line from a file descriptor on each call.
* Behaviour is undefined when using this function on different file descriptors

### Prototype

```h
char	*get_next_line(int fd);
```

### Usage

```sh
git clone https://github.com/Archer-01/get_next_line.git
cd get_next_line
touch main.c
```
```c
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("file.txt", O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "Couldn't open file.txt");
		exit(EXIT_FAILURE);
	}

	while (line != NULL)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
	}
	return (0);
}
```
```sh
gcc -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c
./a.out
```

## Bonus version

### Description

* Behaves just like the normal version but also handles multiple file descriptors at once (Up to 10240 file)

### Prototype

```h
char	*get_next_line(int fd);
```

### Usage

```sh
git clone https://github.com/Archer-01/GetNextLine.git
cd GetNextLine
touch main.c
```
```c
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "get_next_line_bonus.h"

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("file.txt", O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "Couldn't open file.txt");
		exit(EXIT_FAILURE);
	}

	while (line != NULL)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
	}
	return (0);
}
```
```sh
gcc -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c main.c
./a.out
```

[![forthebadge](https://forthebadge.com/images/badges/made-with-c.svg)](https://forthebadge.com)
