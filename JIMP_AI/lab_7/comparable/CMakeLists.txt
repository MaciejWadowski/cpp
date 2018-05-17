
project(comparable)

set(HEDEAR_FILES Comparable.h Student.h StudyYear.h)
set(SOURCE_FILES Comparable.cpp Student.cpp StudyYear.cpp)

add_library(libcomparable STATIC ${SOURCE_FILES})
target_include_directories(libcomparable PUBLIC .)

add_executable(comparable ${SOURCE_FILES} main.cpp)

target_link_libraries(comparable libcomparable)
