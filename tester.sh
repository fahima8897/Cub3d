make
echo "\033[1;33m====  OPENING A DIRECTORY  ===="
valgrind --leak-check=full --show-leak-kinds=all ./cub3D maps/folder_test
echo "\033[1;33m====  OPENING A DIRECTORY.cub  ===="
valgrind --leak-check=full --show-leak-kinds=all ./cub3D maps/folder_test.cub
echo "\033[1;33m====  OPENING A FILE.cu  ===="
valgrind --leak-check=full --show-leak-kinds=all ./cub3D maps/map_error01.cu
echo "\033[1;33m====  OPENING A FILE..cub  ===="
valgrind --leak-check=full --show-leak-kinds=all ./cub3D maps/map_error02..cub
echo "\033[1;33m====  OPENING A NAMELESS FILE.cub  ===="
valgrind --leak-check=full --show-leak-kinds=all ./cub3D maps/.cub
echo "\033[1;33m====  OPENING A FILEcub  ===="
valgrind --leak-check=full --show-leak-kinds=all ./cub3D maps/map_error04cub
echo "\033[1;33m====  OPENING A NAMELESS FILEcub.c  ===="
valgrind --leak-check=full --show-leak-kinds=all ./cub3D maps/map_error05cub.c
echo "\033[1;33m====  OPENING EMPTY TEXTURE FILE  ===="
valgrind --leak-check=full --show-leak-kinds=all ./cub3D maps/empty_textures.cub
