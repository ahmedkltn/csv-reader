# CSV Manager

A simple C program to read, manipulate and manage CSV files with support for custom delimiters.

## Features

- Read and write CSV files
- Custom delimiter support
- Interactive command interface
- Search functionality
- Add/Delete records
- Memory-safe implementation

## Building

```bash
make
```

## Usage

```bash
./program <csv_file> [delimiter]
# Example with default delimiter (;)
./program data.csv
# Example with custom delimiter (,)
./program data.csv ,
```

### Available Commands

- `[L]` Look - View specific lines
  - Prompts for start and end line numbers
  - Always shows header row
- `[S]` Search - Find records
  - Format: Column=Value
  - Example: name=John
- `[A]` Add - Insert new record
  - Prompts for each column value
- `[D]` Delete - Remove records
  - Format: Column=Value
  - Example: id=123
- `[B]` Break - Exit program

## Project Structure

```
csv_manager/
├── include/         # Header files
│   ├── csv.h       # CSV structure and main functions
│   └── utils.h     # Utility functions
├── src/            # Source files
│   ├── main.c      # Main program
│   ├── csv.c       # CSV operations
│   └── utils.c     # String manipulation
└── Makefile        # Build configuration
```

## Memory Management

- Automatic memory cleanup on exit
- Dynamic memory allocation for rows
- Memory-safe string operations
