## How To Run:
My development environment: CMake v3.10+, GCC/G++ v9.4+, Ubuntu 22.04 LTS  
  
Once you've cloned the repo follow these steps to compile & run the code.
  1. `mkdir build` (If "build" folder already exists, remove it.)   
  2. `cd build`  
  3. `cmake ..`  
  4. `make` or `cmake --build` (makes no difference)  
  5. `cd ..`  
  6. `bin/ROKC`  
  
## Future Plans
  - Expand beyond 1 vs. 1 into 1 vs. 2+
  - Create and then pull from database containing legendary commander skill & talent info  
    
## IMPORTANT NOTE  
As was noted on the webpage linked above, the currently known combat formula does not perfectly predict damage factor for battles with one or more marches above 35,000 troops (approx.). I don't foresee the community combat formula ever matching the true formula used in the game. However, with the balance tweak I made to the community formula, I'm confident that its possible to accurately predict the rough outcome of an entire battle.
 
