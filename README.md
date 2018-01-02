# FaceMorphing
Face Morphing by Delaunay Triangulation using OpenCV and C++


## Please visit [HERE](https://devendrapratapyadav.github.io/FaceMorphing) for detailed analysis of code and experiment results.


We manually mark sets of tie points for images, compute the Delaunay Triangulation for them, and morph the images using alpha blending.

Code is present in 'code' directory. FaceMorph.cpp implements the main program. Other files contain the images and predefined tie points.

### HOW TO RUN : 
NOTE: Cmake and GNU make are required for compilation along with OpenCV.

1) Compile the program by entering the following command :
```sh
   cmake .
   make
 ```
 2) Run using:
 ```sh
   ./lab4
 ```
 
 The program provides three options via a menu:
1. Mark points on images and find Delaunay Triangulation 
2. Morph two images: '1.jpg' to '2.jpg'
3. Morph three images: '1.jpg' to '2.jpg' to '3.jpg'

Note: for now, the filenames are fixed. Code will be updated later to allow input for filenames.
