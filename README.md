# About
LibThinkGear is a library to handling ThinkGear. 
The code is based on ofxThinkGear from [BrainwaveOSC](https://github.com/trentbrooks/BrainWaveOSC) by [trentbrooks](https://github.com/trentbrooks).
The goal of this project is make independent of frameworks

# Build
In square parenthesis is a option to build example projects to test or find own inspiration for own projects.
Type:
```
cd LibThinkGear
mkdir build
cd build
cmake .. [-DCOMPILE_PROJECTS=1]
cmake --build .
cmake --install .
```

# Usage
To use this library, you can add to CMakeLists.txt
```
find_package(thinkgear)
```
and
```
target_link_libraries(${PROJECT_NAME} PUBLIC thinkgear)
```

In Makefile add to CFLAGS or CXXFLAGS ```-lthinkgear```

# TODO
Implement cpp class to receive and send ThinkGear messages (class ThinkGearReceiver will be moved to main library).

# Contact
To contact me, please use my [contact form](https://freeshell.de/~arturwro/contact.php?lang=en)
