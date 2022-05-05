cmake_minimum_required(VERSION 3.19)
project(Labo4_RIver)

set(CMAKE_CXX_STANDARD 14)

add_executable(Labo4_RIver main.cpp Controller.cpp Controller.h Person/Person.cpp Person/Person.h Person/Cop.cpp Person/Cop.h Person/Parent.cpp Person/Parent.h Person/Mother.cpp Person/Mother.hpp Person/Father.cpp Person/Father.hpp Person/Son.cpp Person/Son.hpp Person/Daughter.cpp Person/Daughter.hpp Person/Robber.cpp Person/Robber.hpp Container/Container.cpp Container/Container.h Container/Boat.cpp Container/Boat.h constraints/Constraint.cpp constraints/Constraint.h)