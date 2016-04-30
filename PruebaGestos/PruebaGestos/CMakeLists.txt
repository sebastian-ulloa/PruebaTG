cmake_minimum_required(VERSION 2.8)
 
PROJECT(PruebaGestos)
 
include_directories("C:/Program Files/Microsoft SDKs/Kinect/v1.8/inc")
link_directories("C:/Program Files/Microsoft SDKs/Kinect/v1.8/lib/amd64")
 
find_package(ITK REQUIRED)
include(${ITK_USE_FILE})
if (ITKVtkGlue_LOADED)
  find_package(VTK REQUIRED)
  include(${VTK_USE_FILE})
endif()

file(GLOB MY_SRCS 
"*.h" 
"*.cpp"
"Vista/*.cpp"
"Vista/*.h"
"Modelo/*.cpp"
"Modelo/*.h"
"Controlador/*.cpp"
"Controlador/*.h"
)

find_package(VTK REQUIRED)
include(${VTK_USE_FILE})

add_executable(PruebaGestos MACOSX_BUNDLE main ${MY_SRCS})

if(VTK_LIBRARIES)
  target_link_libraries(PruebaGestos ${VTK_LIBRARIES})
else()
  target_link_libraries(PruebaGestos vtkHybrid vtkWidgets)
endif()

if( "${ITK_VERSION_MAJOR}" LESS 4 )
  target_link_libraries(PruebaGestos ITKReview ${ITK_LIBRARIES})
else( "${ITK_VERSION_MAJOR}" LESS 4 )
  target_link_libraries(PruebaGestos ${ITK_LIBRARIES})
endif( "${ITK_VERSION_MAJOR}" LESS 4 )