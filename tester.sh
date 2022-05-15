make
echo "\033[1;33m====  OPENING A DIRECTORY  ===="
./cub3D maps/folder_test
echo "\033[1;33m====  OPENING A DIRECTORY.cub  ===="
./cub3D maps/folder_test.cub
echo "\033[1;33m====  OPENING A FILE.cu  ===="
./cub3D maps/map_error01.cu
echo "\033[1;33m====  OPENING A FILE..cub  ===="
./cub3D maps/map_error02..cub
#echo "\033[1;33m====  OPENING A NAMELESS FILE.cub  ===="
#./cub3D maps/.cub
echo "\033[1;33m====  OPENING A FILEcub  ===="
./cub3D maps/map_error04cub
echo "\033[1;33m====  OPENING A NAMELESS FILEcub.c  ===="
./cub3D maps/map_error05cub.c
