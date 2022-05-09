# CMakeList.txt : projet CMake pour ivra, incluez la source et définissez
# la logique spécifique au projet ici.

cmake_minimum_required (VERSION 3.8)

# Ajoutez une source à l'exécutable de ce projet.
add_executable (ivra "ivra.cpp" "ivra.h" "core.cpp" "parser.cpp" "interpreter.cpp" "tool.cpp")