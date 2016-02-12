# nano_magnetic
=================

Numerical modeling the properties of dense clusters of magnetic nanoparticles.

## Source structure

* `src/nano_magnetic` contains whole the implementation into `*.h` and `*.cc` files and the example into `main.cc`;
* `src/test` contains Google C++ Testing Framework tests.

## Build

Use CMake:

```
> mkdir build
> cd build
> cmake ..
> make
> ./nano_magnetic
...
```

## Tests

For testing purposes this project uses Google C++ Testing Framework. To enable tests you should define `ENABLE_TESTS=ON` variable:

```
> cmake -DENABLE_TESTS=ON ..
> make
> ./nano_magnetic_test
...
```
