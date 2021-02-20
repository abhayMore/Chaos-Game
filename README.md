# Chaos-Game
```
Creating Fractals using Chaos Game, written in C++ and SFML
```

## Summary

[Chaos Game](https://en.wikipedia.org/wiki/Chaos_game) is a method of creating Fractals, using polygons and an intial random point inside it. A random vertex is chosen and the starting/initial point is moved in that direction in some fraction knowns as distance factor(like 1/3, 1/2 etc). <br /> 
Taking this new position as current and choosing random vertex again and moving towards it depending on the distance factor, doing this iteratively produces a fractal.


## This code focuses on n-flake or Sierpinski n-gon theory

This code shows fractals related to [n-flake](https://en.wikipedia.org/wiki/N-flake) thoery, where n is the number of vertices and if the necessary distance factor is given produces a nice fractal flake.

## How to Run (only for Linux)

Install [SFML](https://www.sfml-dev.org/tutorials/2.5/start-linux.php) <br />
Install make (command : ```sudo apt install make``` ) <br />
Run command : ```make F1=main.cpp```

```The program expects two inputs``` <br />
1. The number of vertices
2. The distance factor


## Output

This is a Sierpinski Triangle, it is an n-flake, where n is 3 and the distance factor is 1/2 or 0.5.

![output](https://raw.githubusercontent.com/abhayMore/Chaos-Game/master/Triangle.gif)



