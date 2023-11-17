# ncube

https://github.com/ivan-guerra/ncube/assets/13009513/bf5ad5b2-f188-461d-b2de-99b6dfd6cb87

`ncube` is a Linux only application that renders a cube in your terminal. You
can rotate the cube in 3D space using the arrow keys. The "n" in `ncube` comes
from the fact that the application uses [ncurses][1] to create its UI.

### Building

To build the project locally, you will need the following libraries and tools
installed:

* CMake3.16+
* C++ compiler supporting C++20 features
* [Doxygen][2]
* Ncurses Developer Libs

To build, change directory to `scripts/linux` and run `build.sh`.

After a successful build, you will find the binary installed to `ncube/bin/`.

### Program Usage

Below is the program usage message that can be seen by running `ncube --help`:

```text
usage: ncube [OPTION]...
ncurses rendering of a cube
	-f, --fov-angle-deg	FOV angle in degrees
	-c, --camera-dist	distance of the camera from the center of the cube
	-n, --num-edge-points	number of points per edge
	-h, --help		print this help page
```

### Doxygen Docs

This project is documented using Doxygen. Doxygen docs are built automatically
by the Linux build script. Docs can be found under `ncube/docs/ncube/`.

[1]: https://tldp.org/HOWTO/NCURSES-Programming-HOWTO/intro.html
[2]: https://www.doxygen.nl/
