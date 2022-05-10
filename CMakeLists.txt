cmake_minimum_required(VERSION 3.19)
project(Labo4_RIver)

set(CMAKE_CXX_STANDARD 14)

set(PROJECT_FILES Controller.cpp Controller.h persons/Person.cpp
        persons/Person.hpp persons/Cop.cpp persons/Cop.hpp persons/Parent.cpp
        persons/Parent.hpp persons/Mother.cpp persons/Mother.hpp persons/Father.cpp
        persons/Father.hpp persons/Son.cpp persons/Son.hpp persons/Daughter.cpp
        persons/Daughter.hpp persons/Robber.cpp persons/Robber.hpp Container/Container.cpp
        Container/Container.h Container/Boat.cpp Container/Boat.h
        Container/Bank.h Container/Bank.cpp persons/Child.cpp persons/Child.hpp)

add_executable(Labo4_RIver main.cpp ${PROJECT_FILES})

add_library(Catch2 tests/catch.hpp)
set_target_properties(Catch2 PROPERTIES LINKER_LANGUAGE CXX)
add_executable(Test ${PROJECT_FILES} tests/SonTest.cpp
        tests/DaughterTest.cpp tests/RobberTest.cpp tests/FatherTest.cpp tests/MotherTest.cpp tests/test.cpp tests/BoatTest.cpp)

target_link_libraries(Test Catch2)