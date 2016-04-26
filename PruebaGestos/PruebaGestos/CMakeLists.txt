cmake_minimum_required(VERSION 2.8)
 
PROJECT(PruebaGestos)
 
include_directories("C:/Program Files/Microsoft SDKs/Kinect/v1.8/inc")
link_directories("C:/Program Files/Microsoft SDKs/Kinect/v1.8/lib/amd64")

file(GLOB MY_SRCS 
"*.h" 
"*.cpp"
)
add_executable(PruebaGestos MACOSX_BUNDLE main ${MY_SRCS})