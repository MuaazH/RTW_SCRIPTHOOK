//
// Created by MuaazH (muaaz.h.is@gmail.com) on 2024-02-03.
//

struct PopulationLimits {
    /**
     * Minimum required for this level
     */
    int levelMin;

    /**
     * How many idiot it takes to get to the next level
     */
    int nextLevel;

    /**
     * Population can't be less that this, and will jump to be equal at
     * the end of turn if it becomes smaller
     */
    int absoluteMinimum;

    /**
     * Squalor will increase significantly if this threshold is exceeded
     */
    int overPopulationThreshold;
};