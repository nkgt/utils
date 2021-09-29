# utils
A collection of classes and functions I end up using often in various projects

## Building
To build the library you need to execute the following commands from the root directory of the repository

```bash
> mkdir build && cd build
> cmake ..
> cmake --build .
```

If you wish to also build the test suite you'll need to install [vcpkg](https://vcpkg.io/) and integrate it directly in CMake by running

```bash
> mkdir build && cd build
> cmake -DCMAKE_TOOLCHAIN_FILE=[path to vcpkg]/scripts/buildsystems/vcpkg.cmake -DNKGT_BUILD_TESTS=On ..
> cmake --build .
```

[Here](https://vcpkg.io/en/getting-started.html) you can find additional information on the vcpkg CMake integration.

Additionally, the library and tests can be built in debug mode with the standard CMake flag `-DCMAKE_BUILD_TYPE=Debug`, but beware that this flag enables sanitizers (on top of all sorts of warnings and `-g -Og`) which have a non-negligible performance impact.
