cmake_minimum_required(VERSION 2.8.3)
project(mesh_map)
add_definitions(-Wall -std=c++11 -Werror=return-type ${PCL_DEFINITIONS})
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake)

find_package(cmake_modules REQUIRED)
find_package(catkin REQUIRED COMPONENTS roscpp sensor_msgs image_transport cv_bridge tf pcl_ros)
find_package(Eigen REQUIRED)


catkin_package(CATKIN_DEPENDS roscpp sensor_msgs image_transport cv_bridge tf)

set(MESH_SOURCE_FILES
                src/mesh_map_main.cpp

)

#set(MESH_VISUALIZER  src/vio_visualizer.cpp)

set(MESH_HEADER_FILES  
                include/mesh_map/mesh_map.h

)

find_package(OpenCV REQUIRED)
include_directories(
  include ${catkin_INCLUDE_DIRS} ${Boost_INCLUDE_DIRS}
  ${OpenCV_INCLUDE_DIRS}
  ${Eigen_INCLUDE_DIRS}
  ${PCL_INCLUDE_DIRS}
#  LIBRARIES imu_3dm_gx3
#  CATKIN_DEPENDS other_catkin_pkg
#  DEPENDS system_lib
)

link_directories(${PCL_LIBRARY_DIRS})
###########
## Build ##
###########
#set(VIO_LIBRARIES cvd lapack blas agast)
add_executable(mesh_map ${VIO_HEADER_FILES} ${MESH_SOURCE_FILES})
target_link_libraries(mesh_map ${OpenCV_LIBS} ${catkin_LIBRARIES})


