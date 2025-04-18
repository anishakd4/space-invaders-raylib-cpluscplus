# Step 1: Generate build files

mkdir build && cd build
cmake ..

# Compile

cmake --build .

# Run

./raylib_app

# OR YOU can use g++ directly

`RAYLIB_PATH=$(brew --prefix raylib)`

```
g++ main.cpp -o rayapp \
 -I"$RAYLIB_PATH/include" \
  -L"$RAYLIB_PATH/lib" \
 -lraylib -framework OpenGL -framework Cocoa -framework IOKit -framework CoreAudio
```
