# C++ Matrix DLL

## Description
There is simple example of creating DLL and writing Unit tests for it.

## Requiremets
* [Visual Studio 2015 IDE](https://www.visualstudio.com/en-us/downloads/download-visual-studio-vs.aspx)

## How to get it
1. Download/Clone this repository
2. Open solution file `.sln`
3. Build the solution

## How to create your own DLL and Unit tests for it
1. Open [Visual Studio 2015 IDE](https://www.visualstudio.com/en-us/downloads/download-visual-studio-vs.aspx)
2. Start project wizard

        File->New->Project
3. Select Visual C++ Console Application

        Visual C++->Win32->Win32 Console Application
and set the checkpoint on `Create directory for solution`
4. In wizard's `Application Settings` tab choose

        Appliction type: DLL
        Additional options: Export symbols; Precompiled header; Security Development Lifecycle (SDL) checks
5. Add new project in solution

        Solution->Add->New Project
6. Select Unit test

        Visual C++->Test->Native Unit Test Project
7. Go to solution properties

        Solution->Properties
8. Select `Project Dependencies` tab
9. Select Unit test project and set checkbox on DLL project
10. Go to Unit test project properties
11. Go to `C/C++->General` tab
12. Add path to DLL project `../ConsoleApplication` into `Additional Include Directories`
13. Go to `Linker->General` tab
14. Add `..\$(Configuration)` into `Additional Library Directories`
13. Go to `Linker->Input` tab
14. Add lib name `ConsoleApplication.lib` into `Additional Dependencies`
15. Build solution and run with tests

        Test->Run->All tests