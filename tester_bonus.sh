norminette gnl/*.c gnl/*.h libft/*.c libft/*.h *.h *.c
make bonus
echo "\033[1;33m====  OPENING A DIRECTORY ===\033[0m"
valgrind --leak-check=full --show-leak-kinds=all --show-reachable=yes --track-origins=yes --tool=memcheck ./cub3D_bonus maps/folder_test
echo "\033[1;33m====  OPENING A DIRECTORY.cub ===\033[0m"
valgrind --leak-check=full --show-leak-kinds=all --show-reachable=yes --track-origins=yes --tool=memcheck ./cub3D_bonus maps/folder_test.cub
echo "\033[1;33m====  OPENING A FILE.cu ===\033[0m"
valgrind --leak-check=full --show-leak-kinds=all --show-reachable=yes --track-origins=yes --tool=memcheck ./cub3D_bonus maps/map_error01.cu
echo "\033[1;33m====  OPENING A FILE..cub ===\033[0m"
valgrind --leak-check=full --show-leak-kinds=all --show-reachable=yes --track-origins=yes --tool=memcheck ./cub3D_bonus maps/map_error02..cub
echo "\033[1;33m====  OPENING A NAMELESS FILE.cub ===\033[0m"
valgrind --leak-check=full --show-leak-kinds=all --show-reachable=yes --track-origins=yes --tool=memcheck ./cub3D_bonus maps/.cub
echo "\033[1;33m====  OPENING A FILEcub ===\033[0m"
valgrind --leak-check=full --show-leak-kinds=all --show-reachable=yes --track-origins=yes --tool=memcheck ./cub3D_bonus maps/map_error04cub
echo "\033[1;33m====  OPENING A NAMELESS FILEcub.c ===\033[0m"
valgrind --leak-check=full --show-leak-kinds=all --show-reachable=yes --track-origins=yes --tool=memcheck ./cub3D_bonus maps/map_error05cub.c

echo "\033[1;33m====  OPENING EMPTY TEXTURE FILE EA===\033[0m"
valgrind --leak-check=full --show-leak-kinds=all --show-reachable=yes --track-origins=yes --tool=memcheck ./cub3D_bonus maps/empty_textures_EA.cub
echo "\033[1;33m====  OPENING EMPTY TEXTURE FILE NO===\033[0m"
valgrind --leak-check=full --show-leak-kinds=all --show-reachable=yes --track-origins=yes --tool=memcheck ./cub3D_bonus maps/empty_textures_NO.cub
echo "\033[1;33m====  OPENING EMPTY TEXTURE FILE WE===\033[0m"
valgrind --leak-check=full --show-leak-kinds=all --show-reachable=yes --track-origins=yes --tool=memcheck ./cub3D_bonus maps/empty_textures_WE.cub
echo "\033[1;33m====  OPENING EMPTY TEXTURE FILE SO===\033[0m"
valgrind --leak-check=full --show-leak-kinds=all --show-reachable=yes --track-origins=yes --tool=memcheck ./cub3D_bonus maps/empty_textures_SO.cub
echo "\033[1;33m====  OPENING EMPTY TXT EA FILE ===\033[0m"
valgrind --leak-check=full --show-leak-kinds=all --show-reachable=yes --track-origins=yes --tool=memcheck ./cub3D_bonus maps/notxtEA.cub
echo "\033[1;33m====  OPENING EMPTY TXT NO FILE ===\033[0m"
valgrind --leak-check=full --show-leak-kinds=all --show-reachable=yes --track-origins=yes --tool=memcheck ./cub3D_bonus maps/notxtNO.cub
echo "\033[1;33m====  OPENING EMPTY TXT WE FILE ===\033[0m"
valgrind --leak-check=full --show-leak-kinds=all --show-reachable=yes --track-origins=yes --tool=memcheck ./cub3D_bonus maps/notxtWE.cub
echo "\033[1;33m====  OPENING EMPTY TXT SO FILE ===\033[0m"
valgrind --leak-check=full --show-leak-kinds=all --show-reachable=yes --track-origins=yes --tool=memcheck ./cub3D_bonus maps/notxtSO.cub

echo "\033[1;33m====  OPENING NO EA FILE ===\033[0m"
valgrind --leak-check=full --show-leak-kinds=all --show-reachable=yes --track-origins=yes --tool=memcheck ./cub3D_bonus maps/maps_noEA.cub
echo "\033[1;33m====  OPENING NO NO FILE ===\033[0m"
valgrind --leak-check=full --show-leak-kinds=all --show-reachable=yes --track-origins=yes --tool=memcheck ./cub3D_bonus maps/maps_noNO.cub
echo "\033[1;33m====  OPENING NO WE FILE ===\033[0m"
valgrind --leak-check=full --show-leak-kinds=all --show-reachable=yes --track-origins=yes --tool=memcheck ./cub3D_bonus maps/maps_noWE.cub
echo "\033[1;33m====  OPENING NO SO FILE ===\033[0m"
valgrind --leak-check=full --show-leak-kinds=all --show-reachable=yes --track-origins=yes --tool=memcheck ./cub3D_bonus maps/maps_noSO.cub
echo "\033[1;33m====  OPENING NO C FILE ===\033[0m"
valgrind --leak-check=full --show-leak-kinds=all --show-reachable=yes --track-origins=yes --tool=memcheck ./cub3D_bonus maps/maps_noC.cub
echo "\033[1;33m====  OPENING NO F FILE ===\033[0m"
valgrind --leak-check=full --show-leak-kinds=all --show-reachable=yes --track-origins=yes --tool=memcheck ./cub3D_bonus maps/maps_noF.cub

echo "\033[1;33m====  OPENING LONG LINE ===\033[0m"
valgrind --leak-check=full --show-leak-kinds=all --show-reachable=yes --track-origins=yes --tool=memcheck ./cub3D_bonus maps/map_long_line.cub
echo "\033[1;33m====  OPENING LONG LINE ===\033[0m"
valgrind --leak-check=full --show-leak-kinds=all --show-reachable=yes --track-origins=yes --tool=memcheck ./cub3D_bonus maps/map_long_line2.cub
echo "\033[1;33m====  OPENING LONG LINE ===\033[0m"
valgrind --leak-check=full --show-leak-kinds=all --show-reachable=yes --track-origins=yes --tool=memcheck ./cub3D_bonus maps/map_long_line3.cub
echo "\033[1;33m====  OPENING LONG LINE ===\033[0m"
valgrind --leak-check=full --show-leak-kinds=all --show-reachable=yes --track-origins=yes --tool=memcheck ./cub3D_bonus maps/map_long_line4.cub
echo "\033[1;33m====  OPENING LONG LINE ===\033[0m"
valgrind --leak-check=full --show-leak-kinds=all --show-reachable=yes --track-origins=yes --tool=memcheck ./cub3D_bonus maps/map_long_line5.cub
echo "\033[1;33m====  OPENING LONG LINE ===\033[0m"
valgrind --leak-check=full --show-leak-kinds=all --show-reachable=yes --track-origins=yes --tool=memcheck ./cub3D_bonus maps/map_long_line6.cub


echo "\033[1;33m====  CUT01 ===\033[0m"
valgrind --leak-check=full --show-leak-kinds=all --show-reachable=yes --track-origins=yes --tool=memcheck ./cub3D_bonus maps/maps_cut01.cub
echo "\033[1;33m====  CUT02 ===\033[0m"
valgrind --leak-check=full --show-leak-kinds=all --show-reachable=yes --track-origins=yes --tool=memcheck ./cub3D_bonus maps/maps_cut02.cub
echo "\033[1;33m====  CUT03 ===\033[0m"
valgrind --leak-check=full --show-leak-kinds=all --show-reachable=yes --track-origins=yes --tool=memcheck ./cub3D_bonus maps/maps_cut03.cub

echo "\033[1;33m====  TEST FINAL ===\033[0m"
valgrind --leak-check=full --show-leak-kinds=all --show-reachable=yes --track-origins=yes --tool=memcheck ./cub3D_bonus maps/map2.cub




