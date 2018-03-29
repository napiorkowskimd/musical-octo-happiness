cmake_minimum_required(VERSION 2.8)

project(musicalo-octo-happiness)

find_package(OpenCV)
if (NOT OpenCV_FOUND)
	message("Could not find OpenCV, will try ${PROJECT_SOURCE_DIR}/opencv/build")
	set(OpenCV_DIR "${PROJECT_SOURCE_DIR}/opencv/build")
	find_package(OpenCV)
	if (NOT OpenCV_FOUND)
		message("Still no luck with OpenCV, maybe C:/opencv/build ??")
		set(OpenCV_DIR "C:/opencv/build")
		find_package(OpenCV)
		if (NOT OpenCV_FOUND)
			message("No OpenCV there, last chance, maybe C:/opencv/opencv/build ??")
			set(OpenCV_DIR "C:/opencv/opencv/build")
			find_package(OpenCV)
		endif()
	endif()
endif()

if (NOT OpenCV_FOUND)
	message("OpenCV autodetection failed, will set manually to ${PROJECT_SOURCE_DIR}/opencv")
	set(OpenCV_LIBS "${PROJECT_SOURCE_DIR}/opencv/build/x64/vc15/lib/opencv_world341d.lib")
	set(OpenCV_INCLUDE_DIRS "${PROJECT_SOURCE_DIR}/opencv/build/include/")
	include_directories(SYSTEM ${OpenCV_INCLUDE_DIRS})
endif()

add_executable(musicalo-octo-happiness main.cpp)
target_link_libraries(musicalo-octo-happiness ${OpenCV_LIBS})

set_target_properties(musicalo-octo-happiness PROPERTIES
                      RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/build")

add_custom_command(TARGET musicalo-octo-happiness PRE_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                       ${CMAKE_SOURCE_DIR}/resources "${PROJECT_SOURCE_DIR}/build/resources")

find_library(OPENCV_DLL_FOUND "opencv_world341d.dll" REQUIRED)
if(NOT OPENCV_DLL_FOUND)
	message("nooooooooooo, opencv_world341d.dll not found. I will copy that for you... XD")
	add_custom_command(TARGET musicalo-octo-happiness POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_if_different
                       "${OpenCV_DIR}/x64/vc15/bin/opencv_world341d.dll" "${PROJECT_SOURCE_DIR}/build/")
endif()