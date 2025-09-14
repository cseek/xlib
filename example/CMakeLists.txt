set(EXE ${PROJECT_NAME})
add_executable(
    ${EXE}
    main.cpp
)
target_link_libraries(
    ${EXE} PRIVATE 
    ${PROJECT_NAME}_shared
)
target_include_directories(
    ${PROJECT_NAME} PRIVATE
    ${TOP}/include
)
