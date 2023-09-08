package shrunken.rokcc.sim;

import java.util.Arrays;
import java.util.List;
import joinery.DataFrame;

public class Test {
    public static void main(final String[] args) {
        // Initialize a new DataFrame with the specified columns
        DataFrame<Object> df = new DataFrame<>("damage_dealt", "troop_cnt", "rage_cnt");

        // Append two rows of arbitrary data
        df = df.append(Arrays.asList(150, 5, 2));  // 150 damage, 5 troops, 2 rage
        df = df.append(Arrays.asList(220, 3, 1));  // 220 damage, 3 troops, 1 rage

        // Display the DataFrame
        System.out.println(df);
    }
}