## How To Run:
Pre-req: Java SE 17
  
Once you've cloned the repo follow these steps to compile & run the code.
  1. `mvn clean package -Djacoco.skip=true`
  2. `mvn dependency:build-classpath`  
  3. Copy the classpath
  4. `java -cp target/rokcc-1.jar:<classpath> shrunken.rokcc.sim.Test`

## IMPORTANT NOTE  
As was noted on the webpage linked above, the currently known combat formula does not perfectly predict damage factor for battles with one or more marches above 35,000 troops (approx.). I don't foresee the community combat formula ever matching the true formula used in the game. However, with the balance tweak I made to the community formula, I'm confident that its possible to accurately predict the rough outcome of an entire battle.
 
