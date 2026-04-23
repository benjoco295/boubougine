apt install build-essential cmake libsfml-dev libglm-dev libglew-dev libpng-dev libsndfile1-dev  
mkdir build && cd build  
cmake ..  
make -j$(nproc)  
./mini3d  
