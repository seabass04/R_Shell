CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
add_subdirectory(googletest)
SET(CMAKE_CXX_STANDARD 11)
#SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")



set(Boost_USE_STATIC_LIBS OFF) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF) 
find_package(Boost 1.45.0 COMPONENTS filesystem regex) 

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS}) 
    ADD_EXECUTABLE(rshell
    src/rshell.cpp
	src/rshellHelper.cpp
	src/parser.cpp
	src/separate.cpp
	src/Tokenizer.cpp
	src/testCommand.cpp
	src/execute.cpp
	src/Tree.cpp
)
    target_link_libraries(rshell ${Boost_LIBRARIES})
endif()



#####################################################################################
#ADD_EXECUTABLE(rshell
#    src/rshell.cpp
#	src/parser.cpp
#	src/separate.cpp
#	src/Tokenizer.cpp
#)

#####################################################################################

#####################################################################################
ADD_EXECUTABLE(test 
	src/Tree.cpp
	src/rshellHelper.cpp
	src/parser.cpp
	src/separate.cpp
	src/Tokenizer.cpp
	src/rshellHelper.cpp
	src/testCommand.cpp
	src/execute.cpp	
    unit_tests/parsing_input.cpp
	unit_tests/redirection_test.cpp
	unit_tests/pipe_test.cpp
	integration_tests/parsing_and_separate.cpp
	integration_tests/pipe_integration.cpp
	unit_tests/tokenize.cpp
	unit_tests/shunting_input.cpp
	integration_tests/shunting_parsing_separate_tokenize.cpp
	integration_tests/parsing_seperate_tokenize.cpp
	unit_tests/testcommand_test.cpp
	integration_tests/test_literal_tests.cpp
	integration_tests/test_symbolic_tests.cpp
)
TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
