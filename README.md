# fillit
A bin-packing program to fit between 1  and 26 tetromino pieces into the smallest possible square. A tetromino is a shape created from four square cells as is found in the game Tetris:

![alt text](https://github.com/robertnowell/fillit/blob/master/tetriminos.png "Tetromino")

This program takes a file as parameter which contains a list of Tetriminos and arranges them to create the smallest square possible. The main goal is to find this smallest square in the minimal amount of time, despite a exponentially growing number of possibilities each time a piece is added. The most significant challenge of the implementation was being careful about data structures and our solving algorithm in order to solve the packing problem efficiently.

See fillit.en.pdf for additional project information.

## Implementation

This project was implemented in C through an iterative backtracking algorithm. Allowed functions: malloc, write, and free.

## Detail and Code Examples

Our implementation relies on a custom data structure which we entitled "t_map" which holds three pairs of x and y variables, in addition to our current map size (this is the square filled with tetromino pieces) and how many tetriminos remain to be placed. The following is the main function for our program:

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
### Retrieving and Formatting Tetrimino Data

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
get_data() is our central function for:  
1. Accessing data stored in the file given to the program as a parameter
2. Checking to ensure that the file contains valid information (according to specifications in the fillit.en.pdf)  
3. Filling our three dimensional array with formatted data about the tetrominos contained in the file. Each element of the three dimensional array is a tetrimino, four arrays of four characters (essentially a 2-d matrix) with "." for empty spaces and "#" for tetrimino spaces.
If the file is valid, get_data() returns the filled in array.

Again in the main function, we will call create_map() to initialize a two dimensional array of map_size elements (to start, a two by two mapsize.)

### The Solving Algorithm

From our main function, we run a continuous loop for our solving function. The solver() returns zero if there is no possible way to fit the tetrominos in the current map size. In this case, we increase the map size, recreate the map, and again call the solver function:

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

Within our solver() function, we reset our map x and y variables, then proceed to our attempt to fit all tetrominos within the current square map. We do this one tetromino at a time. The process is as follows:  
  
1.  Check if our current tetromino will fit starting from our current position in the map (i.e. map[x_point][y_point]).
2.  If the piece will fit:
    1. Edit the map to reflect this positioning of the tetromino (put the piece on the map)
    2. If that was the final tetromino, return 1 to indicate success.
    3. If that was not the final tetromino, find the next open spot on the map and return to the start of the loop to try to fit.
3. If the piece will not fit:
    1. Check if there is another open space on the map. If not, a bigger map is needed, so return 0.
    2. If there is another open space, then that means there is more space on the map but our piece won't fit, so we need to backtrack. Delete the most recent tetromino, and return to the start of the map to try to place it in the next available location.  
  
  
This algorithm will run until either:

1.  All pieces are successfully placed in the current map. In this case solver() returns 1 and the successfully filled-in map is printed.  
2.  No more backtracking is possible (the program is attempting to place the first tetromino), and there are no more additional open spaces on the current map (the program is attempting to place the tetromino in the final possible map location, i.e. the bottom left position of the map). In this case solver() returns 0, a bigger map is created, and solver() tries again on the bigger map.  
  
  
The program continues until a map is found that will contain all of the tetrominos. This is quite quick for collections of less than seven pieces (less than one one hundredth of a second), and has been tested for collections of tetrominos as high as twenty pieces, and twenty pieces takes a good amount of time.  

## Authors

* **Robert Nowell** (https://github.com/robertnowell)
* **Netanel Weizman** 
## Acknowledgments

* This project was completed at School 42, Fremont
