make
echo "\033[1;33m====  OPENING A DIRECTORY  ===="
valgrind --leak-check=full --show-leak-kinds=all --show-reachable=yes --track-origins=yes --tool=memcheck --track-fds=yes ./cub3D maps/folder_test
echo "\033[1;33m====  OPENING A DIRECTORY.cub  ===="
valgrind --leak-check=full --show-leak-kinds=all --show-reachable=yes --track-origins=yes --tool=memcheck --track-fds=yes ./cub3D maps/folder_test.cub
echo "\033[1;33m====  OPENING A FILE.cu  ===="
valgrind --leak-check=full --show-leak-kinds=all --show-reachable=yes --track-origins=yes --tool=memcheck --track-fds=yes ./cub3D maps/map_error01.cu
echo "\033[1;33m====  OPENING A FILE..cub  ===="
valgrind --leak-check=full --show-leak-kinds=all --show-reachable=yes --track-origins=yes --tool=memcheck --track-fds=yes ./cub3D maps/map_error02..cub
echo "\033[1;33m====  OPENING A NAMELESS FILE.cub  ===="
valgrind --leak-check=full --show-leak-kinds=all --show-reachable=yes --track-origins=yes --tool=memcheck --track-fds=yes ./cub3D maps/.cub
echo "\033[1;33m====  OPENING A FILEcub  ===="
valgrind --leak-check=full --show-leak-kinds=all --show-reachable=yes --track-origins=yes --tool=memcheck --track-fds=yes ./cub3D maps/map_error04cub
echo "\033[1;33m====  OPENING A NAMELESS FILEcub.c  ===="
valgrind --leak-check=full --show-leak-kinds=all --show-reachable=yes --track-origins=yes --tool=memcheck --track-fds=yes ./cub3D maps/map_error05cub.c

echo "\033[1;33m====  OPENING EMPTY TEXTURE FILE  ===="
valgrind --leak-check=full --show-leak-kinds=all --show-reachable=yes --track-origins=yes --tool=memcheck --track-fds=yes ./cub3D maps/empty_textures.cub
echo "\033[1;33m====  OPENING EMPTY TXT EA FILE  ===="
valgrind --leak-check=full --show-leak-kinds=all --show-reachable=yes --track-origins=yes --tool=memcheck --track-fds=yes ./cub3D maps/notxtEA.cub
echo "\033[1;33m====  OPENING EMPTY TXT NO FILE  ===="
valgrind --leak-check=full --show-leak-kinds=all --show-reachable=yes --track-origins=yes --tool=memcheck --track-fds=yes ./cub3D maps/notxtNO.cub
echo "\033[1;33m====  OPENING EMPTY TXT WE FILE  ===="
valgrind --leak-check=full --show-leak-kinds=all --show-reachable=yes --track-origins=yes --tool=memcheck --track-fds=yes ./cub3D maps/notxtWE.cub
echo "\033[1;33m====  OPENING EMPTY TXT SO FILE  ===="
valgrind --leak-check=full --show-leak-kinds=all --show-reachable=yes --track-origins=yes --tool=memcheck --track-fds=yes ./cub3D maps/notxtSO.cub

echo "\033[1;33m====  OPENING NO EA FILE  ===="
valgrind --leak-check=full --show-leak-kinds=all --show-reachable=yes --track-origins=yes --tool=memcheck --track-fds=yes ./cub3D maps/maps_noEA.cub
echo "\033[1;33m====  OPENING NO NO FILE  ===="
valgrind --leak-check=full --show-leak-kinds=all --show-reachable=yes --track-origins=yes --tool=memcheck --track-fds=yes ./cub3D maps/maps_noNO.cub
echo "\033[1;33m====  OPENING NO WE FILE  ===="
valgrind --leak-check=full --show-leak-kinds=all --show-reachable=yes --track-origins=yes --tool=memcheck --track-fds=yes ./cub3D maps/maps_noWE.cub
echo "\033[1;33m====  OPENING NO SO FILE  ===="
valgrind --leak-check=full --show-leak-kinds=all --show-reachable=yes --track-origins=yes --tool=memcheck --track-fds=yes ./cub3D maps/maps_noSO.cub
echo "\033[1;33m====  OPENING NO C FILE  ===="
valgrind --leak-check=full --show-leak-kinds=all --show-reachable=yes --track-origins=yes --tool=memcheck --track-fds=yes ./cub3D maps/maps_noC.cub
echo "\033[1;33m====  OPENING NO F FILE  ===="
valgrind --leak-check=full --show-leak-kinds=all --show-reachable=yes --track-origins=yes --tool=memcheck --track-fds=yes ./cub3D maps/maps_noF.cub
echo "\033[1;33m====  TEST FINAL  ===="
valgrind --leak-check=full --show-leak-kinds=all --show-reachable=yes --track-origins=yes --tool=memcheck --track-fds=yes ./cub3D maps/map2.cub



