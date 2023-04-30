cmake_minimum_required(VERSION 2.8.3)
project(four_wheel_robot)

find_package(catkin REQUIRED)
find_package(gazebo REQUIRED)
include_directories(${catkin_INCLUDE_DIRS})

include_directories(${GAZEBO_INCLUDE_DIRS})
link_directories(${GAZEBO_LIBRARY_DIRS})

add_library(center_of_mass SHARED CenterOfMassPlugin.cc)

target_link_libraries(center_of_mass ${GAZEBO_LIBRARIES})
message("-------------------------CMAKE_INSTALL_PREFIX: " ${CMAKE_INSTALL_PREFIX})

# install(TARGETS center_of_mass DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/gazebo/plugins/)
install(TARGETS center_of_mass DESTINATION /usr/include/gazebo-9/gazebo/plugins/)


install(
  DIRECTORY worlds model plugins
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)

catkin_package()

include_directories()
