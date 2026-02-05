# Visu: simple sorting algorithm visualization for C programming language

Visu is a simple library to visualize sorting algorithms in C directly on the terminal.

## Usage

Currently, visu supports visualization for in-place sorting algorithms. To use define your sorting function as follows:

```C
void my_sorting_function(int* array_to_sort, int array_length);

```

Visu requires your sorting function to swap values in the array with the function ```swap(int* array, int a, int b)``` to swap the value in index ```a``` with the value in index ```b```.

With your sorting function done simply call the function with the function:

```C
visu(my_sorting_function, "Name of my sorting function");
```

Visu will create an array of length 30, shuffle it and sort it with your sorting function.


## Dependencies 

Currently visu works on windows and unix systems. For unix systems it is necessary to install xterm:

### Linux
```
$ sudo apt install xterm
```

### Mac
```
% brew install xterm
```


## TODO
[ ] Add statistics
[ ] Add bounds checking
[ ] Style changes
[ ] Add correctness checking
[ ] Add time measure
[ ] Add support to non in-place sorting algorithms
[ ] Add options to the user