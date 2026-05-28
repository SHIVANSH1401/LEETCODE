vector<int> nextGreaterPermutation(vector<int> &A) {

    int ind = -1;
    int n = A.size();

   
    for(int i = n - 2; i >= 0; i--) {  // Step 1: Find breakpoint

        if(A[i] < A[i + 1]) {
            ind = i;
            break;
        }
    }

  
    if(ind == -1) {  // If no breakpoint exists, reverse the array and return
        reverse(A.begin(), A.end());
        return A;
    }

    
    for(int i = n - 1; i > ind; i--) {// Step 2: Find next greater element and swap

        if(A[i] > A[ind]) {
            swap(A[i], A[ind]);
            break;
        }
    }

 
    reverse(A.begin() + ind + 1, A.end());   // Step 3: Reverse remaining part to get the next permutation

    return A;
}