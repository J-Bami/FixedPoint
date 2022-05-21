FILE(GLOB FixedHeaders *.h)

add_library(FixedPoint INTERFACE)
target_include_directories(FixedPoint INTERFACE .)