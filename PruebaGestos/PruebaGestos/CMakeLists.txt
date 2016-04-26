cmake_minimum_required(VERSION 2.8)
 
PROJECT(PruebaGestos)
 
include_directories("C:/Program Files/Microsoft SDKs/Kinect/v1.8/inc")
link_directories("C:/Program Files/Microsoft SDKs/Kinect/v1.8/lib/amd64")

file(GLOB MY_SRCS 
"*.h" 
"*.cpp"
)

find_package(VTK REQUIRED)
include(${VTK_USE_FILE})

add_executable(PruebaGestos MACOSX_BUNDLE main ${MY_SRCS})

if(VTK_LIBRARIES)
  target_link_libraries(PruebaGestos ${VTK_LIBRARIES})
else()
  target_link_libraries(PruebaGestos vtkHybrid vtkWidgets)
endif()