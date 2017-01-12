# fillit
A bin-packing program to fit between 1  and 26 tetromino pieces into the smallest possible square. A tetromino is a shape created from four square cells as is found in the game Tetris:

![alt text](https://github.com/robertnowell/fillit/blob/master/tetriminos.png "Tetromino")

This program takes a file as parameter which contains a list of Tetriminos and arranges them to create the smallest square possible. The main goal is to find this smallest square in the minimal amount of time, despite a exponentially growing number of possibilities each time a piece is added. The most significant challenge of the implementation was being careful about data structures and our solving algorithm in order to solve the packing problem efficiently.

See fillit.en.pdf for additional project information.

## Implementation

This project was implemented in C through an iterative backtracking algorithm. Allowed functions: malloc, write, and free.

### Detail and Code Examples

Our implementation relies on a custom data structure which we entitled "t_map" which holds three pairs of x and y variables, in addition to our current square size and how many tetriminos remain to be placed. 

The first step is to initialize the variables of this struct and then read in data about our tetromino pieces from a file. We store the data read from file in three dimensional (char \*\*\*) array:
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


## Authors

* **Robert Nowell** (https://github.com/robertnowell)
* **Netanel Weizman** 
## Acknowledgments

* This project was completed at School 42, Fremont
