# CSV Manager

A simple C program to read, manipulate and manage CSV files.

## Features

- Read CSV files
- Display CSV content with head command
- Support for different delimiters (currently semicolon)
- Memory-safe implementation

## Building

```bash
make
```

## Usage

```bash
./program <csv_file>
```

### Available Commands

- `[H]` - Show first N lines of the CSV file
- `[S]` - Search in CSV file (coming soon)
- `[A]` - Add new entry (coming soon)
- `[D]` - Delete entry (coming soon)
- `[B]` - Exit program

## Project Structure

- `src/` - Source files
- `include/` - Header files
- `Makefile` - Build configuration

## Memory Management

The program handles memory allocation and deallocation carefully to prevent memory leaks.
