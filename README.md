# 📜 Get Next Line – Read a File Line by Line

Get Next Line is a function that reads a file line by line efficiently. It is implemented using dynamic memory allocation and file descriptors, ensuring smooth handling of large files.

## 🚀 Features
- Reads a file line by line without storing the whole file in memory.
- Uses a buffer-based approach to optimize performance.
- Works with any valid file descriptor, including standard input.

## 🛠 Installation & Compilation

First, compile the library:

```sh
make
```
This will generate get_next_line.a, a static library that can be used in your C projects.

To compile a C file using get_next_line.a, use:

```c
gcc -Wall -Wextra -Werror your_file.c -L. -lgnl -o your_program
```

Or explicitly link the library:
```c
gcc -Wall -Wextra -Werror your_file.c get_next_line.a -I./ -o your_program
```

📜 Usage Example
```c
#include "get_next_line.h"
#include <fcntl.h>

int main(void)
{
    int fd = open("file.txt", O_RDONLY);
    char *line;
    while ((line = get_next_line(fd)))
    {
        printf("%s\n", line);
        free(line);
    }
    close(fd);
    return 0;
}
```

🏆 Learning Outcomes

✅ Working with file descriptors

✅ Efficient memory management with malloc & free

✅ Optimized buffered reading
