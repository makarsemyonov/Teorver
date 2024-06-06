# Θ-calculation
## A simple program that calculates Θ for Gamma-distribution
Consider a two-dimensional array of type int with size M*N. Going through the array cyclically, we fill it in this way: with probability p, the element is assigned the value 1, otherwise 0. 
Next, we count the number of zeros between α adjacent elements. α - is also a param.
The number of zeros between the ones are precisely the desired random variables that form the Gamma-distribution. 
Zeros in this case play the role of the time interval between events.
## Downloading and preparing
```
git clone https://github.com/makarsemyonov/Teorver
cd Teorver/continuous
make
```

## Usage
```
./diceroll <number of arrays> <length of each array> <magic>
```
Probability p = 1/magic

## Output information
After the program finishes, it will print Θ
