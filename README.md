# Tiling/Dispatching
Project to tile TGA image files into one as-square-as-possible image and dispatch different image manipulation calls to separate child processes using fork() and exec().

Noteworthy accomplishments:
  
  -use of fork() call to create child processes 
  
  -use of exec() call to execute files within child processes 
  
  -use of BASH to build and run an executable using an entire directory as input parameters
  
  -use of Doxygen to document code with javadoc style comments
  
  -worked with both 1D and 2D Rasters to represent RGB image files
  
NOTE: 
  
    Not all code is mine, some has been provided by my professor.
    Code that is 100% mine:
      -prog4Script.sh
      -dispatcher.c
      -tile.c
