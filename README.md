# fillit
A bin-packing program to fit between 1  and 26 tetromino pieces into the smallest possible square. A tetromino is a shape created from four square cells as is found in the game Tetris:

![alt text](https://github.com/robertnowell/fillit/blob/master/tetriminos.png "Tetromino")

This program takes a file as parameter which contains a list of Tetriminos and arranges them to create the smallest square possible. The main goal is to find this smallest square in the minimal amount of time, despite a exponentially growing number of possibilities each time a piece is added. The most significant challenge of the implementation was being careful about data structures and our solving algorithm in order to solve the packing problem efficiently.

See fillit.en.pdf for additional project information.

## Implementation

This project was implemented in C through an iterative backtracking algorithm. Allowed functions: malloc, write, and free.

## Detail and Code Examples

Our implementation relies on a custom data structure which we entitled "t_map" which holds three pairs of x and y variables, in addition to our current square size and how many tetriminos remain to be placed. The following is the main function for our program:

```
int	main(int argc, char *argv[])
{
	t_map		*settings;
	char		**map;
	char		***array;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit filename\n");
		return (0);
	}
	settings = init_settings();
	array = get_data(argv[1], settings);
	map = create_map(settings->map_size);
	if (!map || !settings || !array)
		return (0);
	while (1)
	{
		if (solver(map, settings, array, 0))
			break ;
		settings->map_size += 1;
		free(map);
		if (!(map = create_map(settings->map_size)))
			return (0);
	}
	print_map(map, settings);
	return (0);
}
```
## Retrieving and Formatting Tetrimino Data

The first step is to initialize the variables of this struct and then read in data about our tetromino pieces from a file. We store the data read from file in three dimensional (char \*\*\*) array. We call get_data() from the main function:

```
char	***get_data(char *str, t_map *settings)
{
	char	*s;
	char	*pieces;
	char	***array;

	pieces = (char *)malloc(sizeof(char) * 27);
	if (!(s = ft_read(str)))
		return (0);
	if (ft_s_error(s, 0, 0, 0))
	{
		ft_putendl("error");
		return (0);
	}
	array = ft_pieces_array(s);
	ft_fill_array(array, s, 0, 0);
	if (!(*(pieces = ft_analyze(s))))
	{
		ft_putendl("error");
		return (0);
	}
	if (ft_find(pieces, 'z'))
		return (0);
	settings->pieces_count = ft_count_pieces(s);
	return (array);
}
```
get_data() is our central function for  
1. Accessing data stored in the file given to the program as a parameter  
2. Checking to ensure that the file contains valid information (according to specifications in the fillit.en.pdf)
3. Filling our three dimensional array with formatted data about the tetrominos contained in the file. Each element of the three dimensional array is a tetrimino, four arrays of four characters (essentially a 2-d matrix) with "." for empty spaces and "#" for tetrimino spaces.
If the file is valid, get_data() returns the filled in array.

Again in the main function, we will call create_map() to initialize a two dimensional array of map_size elements (to start, a two by two mapsize.)

### The Solving Algorithm

From our main function, we run a continuous loop for our solving function. The solver() returns zero if there is no possible way to fit the tetrominos in the current map size. In this case, we increase the map size, recreate the map, and call the solver function again:

```
bool	solver(char **map, t_map *settings, char ***array, int location)
{
	settings->x_point = 0;
	settings->y_point = 0;
	while (1)
	{
		if (fit_possibility(map, settings, array, location))
		{
			put_tetriminos(map, settings, array, location);
			if (location == settings->pieces_count - 1)
				return (1);
			X_POINT = -1;
			Y_POINT = 0;
			update_next_point(settings, map);
			location++;
		}
		else
		{
			if (update_next_point(settings, map))
				continue ;
			else if (!location)
				return (0);
			delete_last_tetriminos(map, settings, location - 1, 0);
			update_next_point(settings, map);
			location--;
		}
	}
}
```
## Authors

* **Robert Nowell** (https://github.com/robertnowell)
* **Netanel Weizman** 
## Acknowledgments

* This project was completed at School 42, Fremont
