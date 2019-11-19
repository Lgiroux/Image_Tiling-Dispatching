#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
//
#include "./ImageIO/imageIO_TGA.h"

/**
* @file C:\Users\Logan\Documents\CSC412\prog_04\Prog 03 Solution\Prog 03\tile.c
* @author Logan
* @date 2 Nov 2019
* @copyright 2019 Logan
* @brief <prog_04>
*/


int main(int argc, char *argv[]) {


  /**
  * @brief <this file takes in numImages number of tile images and
  puts them all together inside of one, nearly square composite image>
  * @param [main] <argc, argv> <command line arguments for
  images to be composed into composite image>
  * @return <writes composite image to file>
  * @details <>
  */


  //get dimensions
  int numImages = argc-2; //name of file + output file
  RasterImage image = readTGA(argv[argc-2]);
  int imageWidth = image.numCols;
  int imageHeight = image.numRows;
  deleteRasterImage(&image);


  //store images in array
  RasterImage imageArray [numImages];
  for (int i = 0; i < numImages; i++){
    RasterImage temp = readTGA(argv[i+1]); //because argv[1] is file name
    imageArray[i] = temp;
  }

   int compositeRows = (int) ceil(sqrt(numImages));
   int compositeCols = (int) ceil((float)numImages/compositeRows);

   RasterImage composite = newRasterImage(compositeRows*imageHeight, compositeCols*imageWidth, RGBA32_RASTER);

   int** c2D = (int**) composite.raster2D;

   for(int n = 0; n < numImages; n++){
     int row = n / compositeCols;
     int col = n % compositeCols;
     int** i2D = (int**) imageArray[n].raster2D;

     for(int ii = 0, ic = row*imageHeight; ii < imageHeight; ii++, ic++){
       for(int ji = 0, jc = col*imageWidth; ji < imageWidth; ji++, jc++){
          c2D[ic][jc] = i2D[ii][ji];
         }
       }
     }
   int err = writeTGA(argv[argc-1], &composite);

  return 0;
}
