# 42 _ fdf


This project is about creating a simplified 3D graphic representation of a relief landscape.

## Compiling
> Made for OS X only

Run `Make`

## Usage
#### The map format
```
$> cat maps/42.fdf
0 0  0  0  0  0  0  0 0 0 0  0  0  0  0  0  0 0 0
0 0  0  0  0  0  0  0 0 0 0  0  0  0  0  0  0 0 0
0 0 10 10  0  0 10 10 0 0 0 10 10 10 10 10  0 0 0
0 0 10 10  0  0 10 10 0 0 0  0  0  0  0 10 10 0 0
0 0 10 10  0  0 10 10 0 0 0  0  0  0  0 10 10 0 0
0 0 10 10 10 10 10 10 0 0 0  0 10 10 10 10  0 0 0
0 0  0 10 10 10 10 10 0 0 0 10 10  0  0  0  0 0 0
0 0  0  0  0  0 10 10 0 0 0 10 10  0  0  0  0 0 0
0 0  0  0  0  0 10 10 0 0 0 10 10 10 10 10 10 0 0
```
> You have test map in the `maps` folder

Each number corresponds to a point in space:
* The horizontal position corresponds to its axis.
* The vertical position corresponds to its ordinate.
* The value corresponds to its altitude.


#### Runing
```
./fdf map [width height]
```
###### Example
```
./fdf maps/mars.fdf 800 800
```

## Commands

| Key  | Action       |
| ---- |:-------------:|
| wasd | move sideways |
| arrow| move camera   |
| esc  | quit          |

## Exemple
![julia](../assets/julia.png)
![mars](../assets/mars.png)
![t2](../assets/t2.png)
