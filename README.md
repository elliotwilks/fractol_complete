*This project has been created as part of the 42 curriculum by elwilks.*

## Description
A fractal renderer built in C using MLX42.
Renders Mandelbrot and Julia sets with interactive zoom and pan.

## Instructions

**Dependencies:** GLFW must be installed on your system.
On Debian/Ubuntu: `sudo apt install libglfw3-dev`

**Compilation:**
```bash
make
```

**Execution:**
```bash
./fractol mandelbrot
./fractol julia <real> <imag>
```

**Example:**
```bash
./fractol julia -0.7 0.27015
```

## Controls
| Input | Action |
|-------|--------|
| Scroll up | Zoom in |
| Scroll down | Zoom out |
| Arrow keys | Pan |
| ESC | Quit |

## Resources
- https://en.wikipedia.org/wiki/Mandelbrot_set
- https://en.wikipedia.org/wiki/Julia_set
- MLX42 docs: https://github.com/codam-coding-college/MLX42

**How AI was used:**
- **Understanding concepts:** Used AI to understand the mathematics behind
  complex number iteration and how the Mandelbrot and Julia sets are computed.
- **Debugging:** Used AI to help interpret compiler errors and understand
  unexpected rendering behaviour during development.
# fractol_complete
