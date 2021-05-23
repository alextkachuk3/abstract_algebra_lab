project(Large_Number)

set(HEADER_FILES
        Large_Number.h
        )

set(SOURCE_FILES
        Large_Number.cpp
        )

add_library(Large_Number STATIC ${SOURCE_FILES} ${HEADER_FILES})