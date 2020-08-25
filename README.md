This is a BSQ generator and a BSQ solver.

Change RANDOM value in generator.c to 0 if you want to disable random map on each generation. (It will always put a fixed random map)

start generator with:

  sh gen.sh
  
start solver with:

  make
  ./bsq [file1] (file2) (filen)
 
exemple:

  ./bsq 5kx5kx_50%_file
  ./bsq main.c
  ./bsq 10kx10kx_50%_file 10kx10kx_10%_file 10kx10kx_1%_file
  
  
gen.sh is really easy to modifie, to have anymap you want.
This gen only generate squared maps
