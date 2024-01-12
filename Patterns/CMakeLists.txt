cmake_minimum_required(VERSION 3.10)

# Set the project name
project(Patterns)

# Set the C++ standard to C++14
set(CMAKE_CXX_STANDARD 14)

message("Starting to configure Patterns project")

# Add all the source files
set(SOURCE_FILES
    FastSlowPointers/HappyNumbers.cpp
    FastSlowPointers/LLCycle.cpp
    FastSlowPointers/StartLL.cpp

    InPlaceLL/ReverseLL.cpp
    InPlaceLL/ReverseSubLL.cpp

    SlidingWindow/LongestSubstringK.cpp
    SlidingWindow/MaxSumSubArray.cpp
    SlidingWindow/MaxWindowValue.cpp
    SlidingWindow/SmallestSubArray.cpp
    SlidingWindow/StringSubsequence.cpp
    SlidingWindow/averageSubArray.cpp

    Subsets/DistinctSubsets.cpp
    Subsets/Permutations.cpp
    Subsets/SubsetsWDuplicates.cpp

    TreeBFS/LevelAverage.cpp
    TreeBFS/LevelOrder.cpp
    TreeBFS/ReverseLevelOrder.cpp
    TreeBFS/ZigZagTraversal.cpp

    TreeDFS/DFSAllPaths.cpp
    TreeDFS/DFSPathSum.cpp
    TreeDFS/DFSTraversals.cpp
    TreeDFS/DFSMaxDepth.cpp
    TreeDFS/FindSimilarLeaves.cpp
    TreeDFS/CountGoodNodes.cpp
    TreeDFS/PathSumAnyPath.cpp

    GraphDFS/NumOfCities.cpp
    GraphDFS/VisitAllRooms.cpp

    HeapTrees/KthLargest.cpp

    BinarySearch/SearchBST.cpp

    TwoPointers/PairWithTarget.cpp
    TwoPointers/RemoveDuplicates.cpp
    TwoPointers/RemoveKey.cpp
    TwoPointers/ReverseString.cpp
    TwoPointers/SquareSortedArray.cpp
    TwoPointers/TripletSum.cpp
    TwoPointers/ValidPalindrome.cpp
    TwoPointers/ValidPalindromeII.cpp
)


# Create an executable for each source file
foreach(SOURCE_FILE ${SOURCE_FILES})
    # Get the filename without the extension
    get_filename_component(FILENAME ${SOURCE_FILE} NAME_WE)

    # Add an executable for the file
    add_executable(${FILENAME} ${SOURCE_FILE})
endforeach()



message("Patterns configuration complete")
