## My libft (42 C Library)

***This is my custom libft that I use in 42 projects!***

It contains all of the functions in the *mandatory and bonus* parts of the libft project, as well as my ft_printf/ft_fprintf and my implementation of *get_next_line*. It also now has a (kind of) *garbage collector*!

### Included Standard C Libraries

- unistd: Unix standard functions; includes system calls like "write".
- stdlib: Standard C library.
- stdio: Standard I/O.
- stdarg: Contains useful argument utils such as "va_arg".
- stdint: Useful number related macros and typedefs such as "uint32".
- stdbool: Boolean definition instead of using an integer.
- limits: Useful defines related to numeric limits such as "INT_MIN"
- fcntl: File manipulation such as "open".
- math: The C math library with constant like "PI" and tons of operations.

### Functions
**!**: _Functions with this indicator allocate memory but do not free it for you, therefore they are integrated with the garbage collector._
- Memory manipulation:
	- ft_bzero: Zeros out specified memory
	- ft_memchr: Locates and returns the adress of the character `c` in string `s`
	- ft_memcmp: Returns the difference in ascii between two given points in memory
	- ft_memcpy: Copies the value of `src` into the adress of `dst`
	- ft_memmove: Copies `len` bytes from `src` to `dst`
	- ft_memset: Like *ft_bzero*, but sets specified range in memory to value `c`
	- ft_calloc: Allocates memory for an array of `count` items each of `size` bytes
- String manipulation:
	- ft_strchr: Returns a string poiting to the first appereace of the character `c` in string `s`
	- ft_strrchr: Reversed version of *ft_strchr*
	- ft_strnstr: Returns `haystack` pointing to the first occurance of `needle` in it up to the length `len`
	- ft_substr **!**: Copies a specified substring from a string into a new one with *ft_strdup*
	- ft_strtrim **!**: Trims `set` string off the start and end of string `s1`
	- ft_strcpy: Compies the contents of string `s1` and replaces `s2` with it, then returns `s2`
	- ft_strlcpy: Returns the resultant length of copying `src` to `dst`, truncated by `dstsize`
	- ft_strcat: Resturns the resultant concatenation of `dst` with `src`, adding on it `dst`
	- ft_strlcat: Returns the resultant length of concatenating `dst` with `src`, truncated by `dstsize`
	- ft_strdup **!**: Dupclicates a string by allocating memory to a new one and copying to said address
	- ft_strjoin **!**: Uses concatenation to add a string onto the end of another
	- ft_strncmp: Returns the differnce in ascii between the first differing charater of `s1` and `s2`, up to `n`
	- ft_strlen: Returns the length of a given string
	- ft_split **!**: Splits string `str` by delimiter character `c` (not including) and returns an array of the split strings
	- ft_striteri: Applies a function `f` passed as a parameter to string `s` 
	- ft_strmapi: Identical to *ft_striteri* but returns the string after the function is applied to it
- Conversion functions:
	- ft_atoi: Converts a string to its integer form, ignoring invalid input
	- ft_atof: Converts a string to its float form, ignoring invalid input
	- ft_itoa: Convers an integer to its string form, returning `0` if input is invalid
	- ft_tolower: Converts an alphabetic character to its lower-case form
	- ft_toupper: Converts an alphabetic character to its upper-case form
- Character booleans:
	- ft_isalnum: Returns true if the given character is alphanumeric
	- ft_isalpha: Returns true if the given character is alphanbetical
	- ft_isascii: Returns true if the given character is valid ascii
	- ft_isdigit: Returns true if the given character is a digit
	- ft_isprint: Returns true if the given character is a printable character
- Linked list utils:
	- ft_lstnew: Creates a new linked list
	- ft_lstsize: Returns the size of a linked list
	- ft_lstclear: Clears a linked list fully
	- ft_lstdelone: Deletes a node from a linked list
	- ft_lstadd_front: Adds a node to the front of a linked list
	- ft_lstadd_back: Adds a node to the back of a linked list
	- ft_lstiter: Applies a function `f` passed as a parameter to all nodes in a linked list
	- ft_lstmap: Creates a new linked list by applying a function `f` to each node's content of an existing linked list. If the allocation of a new node fails, it deletes the content and clears the new list.
- Writing functions:
	- ft_putchar_fd: Writes a character `c` to `fd`
	- ft_putstr_fd: Writes a string `str` to `fd`
	- ft_putendl_fd: Writes a character `c` to `fd`, terminating with a newline character
	- ft_putnbr_fd: Writes a number `nbr` to `fd`
- Sub-Project functions: 
	- ft_fprintf: Custom reimplementation of fprintf made from my ft_printf project, prints formated string to `fd`
	- get_next_line **!**: My get_next_line project (very improvable), returns the next line read from `fd`
	- gc_malloc: Calls malloc and adds a node with a reference to the allocated pointer to the garbage collector list
	- gc_free: Frees the specified pointer and removes its node from the garbage collector list
	- gc_collect: Frees all remaining allocations in the garbage collector list

### Garbage Collector
This libft constains a garbage collection system which replaces and malloc and free functions and uses a linked list to keep track of pointers to allocated memory. The `gc_collect()` function then frees everything off. The list functions like a stack, with a first-in-last-out logic.

### Linked Lists
All structs related to linked lists are also included so that they can easily be created. Will add more linked list related utils in the future!
