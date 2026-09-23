#include <iostream>
#include <vector>

/**
 * @brief Sorts two sorted subarrays of a vector
 *
 * @details Takes two sorted subarrays A[aLeftIndex : aMidIndex] and
 * A[aMidIndex + 1 : aRightIndex] and combines them back into another
 * vector by iterating through each vector and comparing their values
 * at the index and placing the lower value into the new array. 
 *
 * @param[out] aVector is a vector in memory to sort values into
 *
 * @param[in] aLeftIndex is a real valid index into aVector signafying the left index
 * of the subarray
 *
 * @param[in] aMidIndex is a real valid index into aVector signafying the middle index
 * of the subarray
 *
 * @param[in] aRightIndex is a real valid index into aVector signafying the right index
 * of the subarray
 */
void merge(std::vector<int> &aVector, 
           std::size_t aLeftIndex,
           std::size_t aMidIndex,
           std::size_t aRightIndex)
{
    std::size_t tLeftLength = aMidIndex - aLeftIndex + 1;
    std::size_t tRightLength = aRightIndex - aMidIndex;

    std::vector<int> tLeftVector{}, tRightVector{};

    for (std::size_t tIter = 0; tIter < tLeftLength; ++tIter)
    {
        tLeftVector.push_back(aVector.at(aLeftIndex + tIter));
    }

    for (std::size_t tIter = 0; tIter < tRightLength; ++tIter)
    {
        tRightVector.push_back(aVector.at(aMidIndex + 1 + tIter));
    }

    std::size_t tLeftIter = 0;
    std::size_t tRightIter = 0;
    std::size_t tInsertIndex = aLeftIndex;

    while (tLeftIter < tLeftLength && tRightIter < tRightLength)
    {
        if (tLeftVector.at(tLeftIter) <= tRightVector.at(tRightIter))
        {
            aVector.at(tInsertIndex) = tLeftVector.at(tLeftIter);
            ++tLeftIter;
        }
        else 
        {
            aVector.at(tInsertIndex) = tRightVector.at(tRightIter);
            ++tRightIter;
        }

        ++tInsertIndex;
    }

    while (tLeftIter < tLeftLength)
    {
        aVector.at(tInsertIndex) = tLeftVector.at(tLeftIter);
        ++tLeftIter;
        ++tInsertIndex;
    }

    while (tRightIter < tRightLength)
    {
        aVector.at(tInsertIndex) = tRightVector.at(tRightIter);
        ++tRightIter;
        ++tInsertIndex;
    }
}

/**
 * @brief Merge sort impl
 *
 * @details Takes in a std::vector<int>& and recursively splits the vector into
 * left and right components until each subarray consists of a single element and calls
 * merge to sort each subarray into a fully sorted array
 *
 * @param[out] aVector is a std::vector to sort
 *
 * @param[in] aLeftIndex is the left bound of subarray
 *
 * @param[in] aRightIndex is the right bound of subarray
*/
void mergeSort(std::vector<int> &aVector, 
               std::size_t aLeftIndex, 
               std::size_t aRightIndex)
{
    if (aLeftIndex < aRightIndex)
    {
        std::size_t tMid = aLeftIndex + (aRightIndex - aLeftIndex) / 2;
        mergeSort(aVector, aLeftIndex, tMid);
        mergeSort(aVector, tMid + 1, aRightIndex);
        merge(aVector, aLeftIndex, tMid, aRightIndex);
    }
}

int main()
{
    std::vector<int> tVector{2, 7, 5, 11, 8, 3};

    mergeSort(tVector, 0, tVector.size() - 1);
    
    for (auto tIter = tVector.begin(); tIter != tVector.end(); ++tIter)
    {
        std::cout << *tIter << ' ';    
    }

    return 0;
}