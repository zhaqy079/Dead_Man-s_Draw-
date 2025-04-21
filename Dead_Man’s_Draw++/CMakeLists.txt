# CMakeList.txt : CMake project for Dead_Man’s_Draw++, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (CMakeTarget "Dead_Man’s_Draw++.cpp" "Dead_Man’s_Draw++.h" "Card.h" "Game.h" "Player.h"  "Cards/CannonCard.h" "Cards/ChestCard.h" "Cards/KeyCard.h" "Cards/SwordCard.h" "Cards/HookCard.h" "Cards/OracleCard.h" "Cards/MapCard.h"  "Cards/KrakenCard.h"  "Cards/MermaidCard.h" "Player.cpp" "Game.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CMakeTarget PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
