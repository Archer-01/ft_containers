# ft_containers

## Overview

This is a C++ repository named `ft_containers` that provides a re-implementation of some of the standard C++ Standard Template Library (STL) containers. The implemented containers include:

- `vector`
- `map`
- `stack`

Additionally, the project includes implementations for essential C++11 features and utilities, such as:

- `std::iterator_traits`
- `std::reverse_iterator`
- `std::enable_if` (with the ability to implement in a C++98 manner)
- `std::is_integral`
- `std::equal` and/or `std::lexicographical_compare`
- `std::pair`
- `std::make_pair`

As a bonus, the repository also contains an implementation of the `set` container, requiring a Red-Black tree.

## Container Implementations

### Vector

The `vector` implementation serves as the default underlying container for other containers in this project. It does not require a specialization for `vector<bool>`.

### Map

The `map` container is implemented, providing a key-value associative container.

### Stack

The `stack` container is implemented with compatibility with the `vector` class.

### Set (Bonus)

The `set` container is implemented with a Red-Black tree.

## Utility Implementations

The repository also includes implementations for various C++11 utilities:

- `std::iterator_traits`: Provides traits for iterator types.
- `std::reverse_iterator`: Implements a reverse iterator.
- `std::enable_if`: Enables type-based conditional compilation.
- `std::is_integral`: Checks if a type is integral.
- `std::equal` and/or `std::lexicographical_compare`: Implements equality and lexicographical comparison.
- `std::pair`: Represents a pair of values.
- `std::make_pair`: Constructs a pair from two values.
