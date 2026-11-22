_This activity has been created as part of the 42 curriculum by kmarguir._

# ft_printf

## Description

`ft_printf` is a re-implementation of the C library function `printf()`, delivered as a static library, `libftprintf.a`.

The goal of the project is to learn how **variadic functions** work in C (`stdarg.h`: `va_start`, `va_arg`, `va_end`) and to write small, reusable output functions on top of the `write()` system call.

```c
int ft_printf(const char *, ...);
```

It handles the following conversions:

| Conversion  | Argument read with `va_arg` | Prints                                                   | Example                 | Output           |
| ----------- | --------------------------- | -------------------------------------------------------- | ----------------------- | ---------------- |
| `%c`        | `int` (a promoted `char`)   | one character                                            | `ft_printf("%c", 'a')`  | `a`              |
| `%s`        | `char *`                    | a string, `(null)` if the pointer is NULL                | `ft_printf("%s", "42")` | `42`             |
| `%p`        | `void *`                    | the address in lowercase hexadecimal, prefixed with `0x` | `ft_printf("%p", &x)`   | `0x7ffd5e8c1a2c` |
| `%d` / `%i` | `int`                       | a signed decimal number                                  | `ft_printf("%d", -42)`  | `-42`            |
| `%u`        | `unsigned int`              | an unsigned decimal number                               | `ft_printf("%u", -1)`   | `4294967295`     |
| `%x`        | `unsigned int`              | lowercase hexadecimal                                    | `ft_printf("%x", 255)`  | `ff`             |
| `%X`        | `unsigned int`              | uppercase hexadecimal                                    | `ft_printf("%X", 255)`  | `FF`             |
| `%%`        | nothing                     | a percent sign                                           | `ft_printf("%%")`       | `%`              |

Like `printf()`, it returns the number of characters printed.

Behaviour details:

- **No buffer.** As the subject requires, there is no buffer management. Every character is sent immediately with `write(1, ..., 1)`.
- **Write errors.** If `write()` fails (for example when standard output is closed, or the disk is full), `ft_printf` stops and returns `-1`, like the man page says `printf` does on an output error.
- **NULL format.** `ft_printf(NULL)` returns `-1`.
- **NULL pointer with `%p`.** The real `printf` prints `(nil)` on Linux (glibc) and `0x0` on macOS. `ft_printf` prints the same thing as the system it is compiled on (macro `PTR_NULL` in `ft_printf.h`).
- **Not handled.** Flags, width and precision (`%-5d`, `%.3s`, …) are not part of the mandatory part. An unknown conversion prints nothing, and a lone `%` at the end of the format is ignored. Both cases are undefined behaviour for the real `printf`.

## Instructions

### Build the library

```sh
make          # builds libftprintf.a
make clean    # removes the object files (.o)
make fclean   # removes the object files and libftprintf.a
make re       # fclean then make
```

The Makefile compiles with `cc -Wall -Wextra -Werror`, creates the library with `ar rcs` and does not relink when nothing has changed.

### Use it in a program

```c
#include "ft_printf.h"

int	main(void)
{
	int	n;

	n = ft_printf("Hello %s, the answer is %d (%x in hex)\n", "world", 42, 42);
	ft_printf("%d characters were printed\n", n);
	return (0);
}
```

```sh
make
cc -Wall -Wextra -Werror main.c -L. -lftprintf -o demo
./demo
```

## Algorithm and data structure

### Files

| File                   | Role                                                                                                |
| ---------------------- | --------------------------------------------------------------------------------------------------- |
| `ft_printf.c`          | `ft_printf` reads the format; `ft_conversion` (static) picks the right function for each conversion |
| `ft_putchar.c`         | writes one character, returns `1` or `-1`                                                           |
| `ft_putstr.c`          | writes a string, or `(null)`                                                                        |
| `ft_putnbr.c`          | `%d` / `%i`, with `ft_nbrlen` (static) to count the characters                                      |
| `ft_unsigned_putnbr.c` | `%u`, with `ft_unsigned_length` (static)                                                            |
| `ft_putnbase.c`        | writes a number in any valid base: used for `%x`, `%X` and `%p`                                     |
| `ft_putptr.c`          | `%p`: `0x` followed by the address in base 16                                                       |
| `ft_isspace.c`         | helper used to reject whitespace in a base                                                          |

### One pass over the format string

`ft_printf` walks the format string once, from left to right, with an index `i`:

1. A normal character goes straight to `ft_putchar`.
2. A `%` followed by a character: `i` moves to that character and `ft_conversion` is called. It compares the letter with each supported conversion (a simple chain of `if`), reads **one** argument with `va_arg` and calls the matching output function.
3. Each function returns how many characters it printed, and `ft_printf` adds it to its counter. If one of them returns `-1`, the loop stops, `va_end` is called and `ft_printf` returns `-1`.

The argument list is read through a `va_list` **passed by pointer** (`&ap`) to `ft_conversion`. That way `ft_printf` and `ft_conversion` move the same cursor. Passing a `va_list` by value is not portable: depending on the platform, the caller's cursor may not move, and the next conversion would read the same argument again (this happens on macOS arm64).

### Printing numbers: recursion instead of a buffer

To print a number in a base of size `n`:

- `nbr / n` is the number without its last digit,
- `nbr % n` is the last digit (its index in the base string).

`ft_putnbase_recursive` first calls itself with `nbr / n`, then writes `base[nbr % n]`. The calls go down to the first digit, and the digits are written on the way back up, in the right order. Example with `300` in hexadecimal: `300 → 18 → 1`, then it writes `1`, `2`, `c`.

Why this choice:

- **No memory allocation and no temporary array.** The only "data structure" is the call stack. Nothing can leak and there is nothing to free.
- **Small, bounded depth.** An `unsigned long` (64 bits) has at most 16 hexadecimal digits and 20 decimal digits, so the recursion never goes deeper than 20 calls.
- **One generic function for several conversions.** `ft_putnbase` is reused by `%x`, `%X` and `%p`, just by changing the base string. It first checks that the base is valid: at least 2 symbols, no duplicates, no `+`, `-` or whitespace. A base of size 1 would make the recursion endless (`nbr / 1 == nbr`).
- **`INT_MIN`.** `ft_putnbr` copies the `int` into a `long` before changing its sign, because `-(-2147483648)` does not fit in an `int`.

## Resources

- `man 3 printf`, `man 3 stdarg`, `man 2 write`
- cppreference, printf family: https://en.cppreference.com/w/c/io/fprintf
- cppreference, variadic functions: https://en.cppreference.com/w/c/variadic
- The 42 Norm and its checker, norminette: https://github.com/42School/norminette

### How AI was used

I used Claude (Anthropic) as a reviewer:

- **Code review.** Claude pointed out bugs: `%u` was missing, `%p` printed the value pointed to instead of the address, and my test `main` was inside the library. I fixed `%u` and `%p` myself.
- **This README.** A first draft, which I reviewed.
