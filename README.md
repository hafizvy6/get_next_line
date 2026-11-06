*This project has been created as part of the 42 curriculum by mhafiz*

# get_next_line

## Description

`get_next_line` reads a file descriptor and returns **one line per call**, until the
file is reached the end. A line is everything up to and including its `'\n'`; a last line
without `'\n'` is returned as it is.

```c
char	*get_next_line(int fd);
```

`"Hello\nWorld\n"` → call 1: `"Hello\n"`, call 2: `"World\n"`, call 3: `NULL`.

The goal is to learn how to keep state between calls with a **static variable**, and to
manage memory that the function cannot free for the caller. The function must work for
any `BUFFER_SIZE` (1, 42, 9999, or none given), on files, on stdin and on pipes, without
leaking.

## Instructions

Compile it together with your own `main`:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
   get_next_line.c get_next_line_utils.c main.c -o gnl

cc -Wall -Wextra -Werror \
   get_next_line.c get_next_line_utils.c main.c -o gnl      # default from the header
```

`BUFFER_SIZE` is never left undefined: `get_next_line.h` provides a default value.

```bash
./gnl test.txt          # a file
./gnl < test.txt        # stdin
cat test.txt | ./gnl    # a pipe
```

Files of the submission: `get_next_line.c`, `get_next_line_utils.c`, `get_next_line.h`
and the three Bonus: `get_next_line_bonus.c`, `get_next_line_utils_bonus.c`, `get_next_line_bonus.h`.

## Algorithm

Four steps:

1. **`read_file`** — a `static char *stash` survives between calls. While the stash has
   no `'\n'`, read `BUFFER_SIZE` bytes into a buffer of `BUFFER_SIZE + 1` (the extra byte
   is for the `'\0'`, which `read` does not write) and append them to the stash.
2. **`extract_line`** — copy everything up to and including the first `'\n'`, or to the
   end of the stash if there is none.
3. **`recover_extra`** — keep the bytes after that `'\n'` as the new stash, and free the
   old one.
4. Return the copy.

The invariant, true before every call: *the stash holds exactly the bytes that were read
from `fd` but not yet returned.* Two consequences: a call whose stash already contains a
`'\n'` does **zero** reads, and a stash may hold several lines while one call returns
only the first.

## Bonus

Several file descriptors at the same time, still with a **single static variable**:

```c
static char	*stash[GNL_MAX_FD];
```

`get_next_line` returns `NULL` for `fd >= GNL_MAX_FD` instead of writing out of bounds.

## Resources

- [Linux man pages](Official documentation for libc functions (`man 3 read`, `man 3 open`, `man 3 close`, etc.))
- [Static Variables]((https://www.geeksforgeeks.org/c/static-variables-in-c/) — Concept and Syntax of Static Variables.)
- [Thinking Guides](Generated thinking guide using LLMS.)

### AI usage

AI was used as a study and review aid, never to write the submitted code.

- **Thinking Guide** — used LLMS to Generate thinking guides and exercises to study the concept.
- **Testing** — helped me build a harness (several files, `BUFFER_SIZE` 1 / 42 / 9999,
  stdin) with a reference output made by `tr`, and how to read a valgrind report.
