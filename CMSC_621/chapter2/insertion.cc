#include <iostream>
#include <vector>

/*
* Loop invariance proof
*
* The time complexity of this algorithm is calculated by counting the 
* number of loops required to fully sort an array of size n. The time 
* complexity of this algorithm is O(n). Proof below
*
* Initialization: We get the number of times the loop has ran by
* counting the variable tIter. Upon the init of the loop tIter == 1.
* Therefore the subarray A[0 : i] is by definition sorted because 
* it can only contain a single element. 
*
* Maintenance: Next the logic within the for loop works by obtaining the 
* key at the position A[i] and copying it into a temp variable. Then it works
* by shifting the any values in A[0 : i - 1] to the right until we find
* find the index for the key. Since the values of A[0 : i - 1] have been established to 
* be sorted already we can shift them cleanly to the right thereby preserving their order
* until we find a value in that subarray such that it is less than the key or we are at index
* 0 of the subarray. We then insert the key into this position. The loop then increments i 
* and the subarray A[0 : i -1] is sorted and we have arrived back at our assumption.
* 
* Termination: The loop will terminate once i > n which is the size of the array. Therefore
* we can conlude based on our previous two steps that once i > n, A[0 : i - 1] elements are sorted
* and therefore A[0 : n] elements are sorted in the array. 
* 
*/


/**
 * @brief Insertion sort impl
 *
 * @param[out] aVector is a std::vector of ints
*/
void sortVector(std::vector<int> &aVector)
{
    if (aVector.size() <= 1)
    {
        return aVector;
    }
    else
    {
        for (std::size_t tIter = 1; i < aVector.size(); ++i)
        {
            // Save the key
            int tKey = aVector.at(tIter);
            // get value to the left
            int tLeftIndex = tIter - 1;


            while (tLeftIndex >= 0 && aVector.at(tLeftIndex) > tKey)
            {
                // shift left value right
                aVector.at(tLeftIndex + 1) = aVector.(tLeftIndex);

                // move left to continue the search
                --tLeftIndex;
            }

            // we found the position for the key
            aVector.at(tLeftIndex + 1) = tKey;
        }
    }
    return aVector;
}



int main()
{
    std::vector<int> tTest{10, 4, 8, 3, 1, 7};

    auto tFinal = sortVector(tTest);

    for (const int tInt : tFinal)
    {
        std::cout << tInt << "\n";
    }

    return 0;
}