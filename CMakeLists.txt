cmake_minimum_required(VERSION 3.6)
project(small_world)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Map.cpp Map.h Region.cpp Region.h Race.h Race.cpp dice.h dice.cpp Amazons.h Amazons.cpp Dwarves.h Dwarves.cpp twoPlayer.map Elves.cpp Elves.h Player.cpp Player.h Power/Power.cpp Power/Power.h Power/Alchemist.cpp Power/Alchemist.h Power/Berserk.cpp Power/Berserk.h Power/Bivouacking.cpp Power/Bivouacking.h Power/Diplomat.cpp Power/Diplomat.h Power/DragonMaster.cpp Power/DragonMaster.h Power/Flying.cpp Power/Flying.h Power/Forest.cpp Power/Forest.h Power/Fortified.cpp Power/Fortified.h Power/Heroic.cpp Power/Heroic.h Power/Hill.cpp Power/Hill.h Power/Merchant.cpp Power/Merchant.h Power/Mounted.cpp Power/Mounted.h Power/Pillaging.cpp Power/Pillaging.h Power/Seafaring.cpp Power/Seafaring.h Power/Shuffler.cpp Power/Shuffler.h Power/Spirit.cpp Power/Spirit.h Power/Stout.cpp Power/Stout.h Power/Swamp.cpp Power/Swamp.h Power/Underworld.cpp Power/Underworld.h Power/Wealthy.cpp Power/Wealthy.h Power/Commando.cpp Power/Commando.h)
add_executable(small_world ${SOURCE_FILES} Elves.cpp Elves.h)

