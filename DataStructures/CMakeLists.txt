cmake_minimum_required(VERSION 3.10)

include_directories(include)

project(DataStructures)

set_source_files_properties(common.c PROPERTIES LANGUAGE C)
add_library(CommonLib STATIC common.c)

# Set the C++ standard to C++11
set(CMAKE_CXX_STANDARD 11)

# Set the C standard to C11
set(CMAKE_C_STANDARD 11)


# Add the C++ source files
set(CPP_SOURCES
    
    Graphs/GraphBFS.cpp
    Graphs/GraphDFS.cpp
    Graphs/DAGTraverse.cpp

    Stack/Stack.cpp

    LinkedList/LinkedList.cpp

    Sorting/BubbleSort.cpp  
    Sorting/BucketSort.cpp  
    Sorting/CountSort.cpp 
    Sorting/InsertionSort.cpp 
    Sorting/QuickSort.cpp  
    Sorting/RadixSort.cpp
    Sorting/SelectionSort.cpp

    HeapTrees/CreateHeap.cpp
    HeapTrees/Heapify.cpp
    HeapTrees/HeapSort.cpp
    HeapTrees/InsertHeap.cpp

    HashTables/Chaining.cpp
    HashTables/LinearProbe.cpp
    
    BinarySearchTrees/BST.cpp   
    BinarySearchTrees/RecursiveBST.cpp
    BinarySearchTrees/BSTfromTraversals.cpp

    ArrayADT/ArrayMerge.cpp

    Trees/Octree.cpp
)

set(C_SOURCES
    ArrayADT/ArrayMerge2.C
    ArrayADT/ArrayRev.C
    ArrayADT/GetSet.C
    ArrayADT/SetOps.C
)

# Create executables for C++ source files

foreach(source ${CPP_SOURCES})
    get_filename_component(filename ${source} NAME_WE)
    add_executable(${filename} ${source})
endforeach()


# Link executables to the CommonLib static library
if(FALSE)

foreach(source ${C_SOURCES})
    get_filename_component(filename ${source} NAME_WE)
    add_executable(${filename} ${source})
    target_link_libraries(${filename} CommonLib)
endforeach()

endif()

