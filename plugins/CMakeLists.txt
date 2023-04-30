cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

# Build the CenterOfMass plugin
add_library(center_of_mass SHARED CenterOfMassPlugin.cc)
target_link_libraries(center_of_mass ${GAZEBO_LIBRARIES})
install(TARGETS center_of_mass LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION})

