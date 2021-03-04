/*
 * even numbers are in the form 2k with k in Z = {..., -2, -1, 0, 1, 2, ...}
*/
int nextEven(void) {
    static int lastEvenValue = 0;
    return 2 * lastEvenValue++;
}