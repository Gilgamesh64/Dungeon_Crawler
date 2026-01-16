# Dungeon_Crawler
911250 Alvise Berti
909172 Tommaso Roncato
909132 Christian Torli

MANUALLY COMPILE
gcc src/*.c -Iinclude -Iexternal/dirent -std=c99 -o dungeon_crawler

CMAKE:
mkdir build
cd build
mkdir savings
cmake ..
cmake --build .
./DC (Dungeon_Crawler)