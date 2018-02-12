cmake_minimum_required(VERSION 3.6)
project(small_world)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Map.cpp Map.h Region.cpp Region.h Race/Race.h Race/Race.cpp dice.h dice.cpp Race/Amazons.h Race/Amazons.cpp Race/Dwarves.h Race/Dwarves.cpp twoPlayer.map Race/Elves.cpp Race/Elves.h Race/Ghouls.cpp Race/Ghouls.h Race/Giants.cpp Race/Giants.h Race/Halflings.cpp Race/Halflings.h Race/Humans.cpp Race/Humans.h Race/Orcs.cpp Race/Orcs.h Race/Ratmen.cpp Race/Ratmen.h Race/Skeletons.cpp Race/Skeletons.h Race/Sorcerers.cpp Race/Sorcerers.h Race/Tritons.cpp Race/Tritons.h Race/Trolls.cpp Race/Trolls.h Race/Wizards.cpp Race/Wizards.h)
add_executable(small_world ${SOURCE_FILES} Race/Elves.cpp Race/Elves.h Race/Ghouls.cpp Race/Ghouls.h Race/Giants.cpp Race/Giants.h Race/Halflings.cpp Race/Halflings.h Race/Humans.cpp Race/Humans.h Race/Orcs.cpp Race/Orcs.h Race/Ratmen.cpp Race/Ratmen.h Race/Skeletons.cpp Race/Skeletons.h Race/Sorcerers.cpp Race/Sorcerers.h Race/Tritons.cpp Race/Tritons.h Race/Trolls.cpp Race/Trolls.h Race/Wizards.cpp Race/Wizards.h)

