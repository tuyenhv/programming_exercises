/*
0. Check if the transactions has duplication or not
1. Find the duplicate transactions (there can be more than duplicate two entries for a same transaction)
2. Group them in arrays. Each array has all the duplicates of a transaction including first transaction record as well. (Let's call it grouped transactions array). Final output will be an array of these grouped transactions array.
3. Inside each grouped transactions array, all the transactions should be sorted by time at which they were recorded.
4. Final array should contain the grouped transactions arrays sorted by time of their first elements.
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
// Define Transaction with id and name 
struct Transaction {
    uint32_t id;
    string name;
};

// Compares two transactions with the Ids
bool compareTransactionIds(Transaction t1, Transaction t2) {
    return (t1.id < t2.id);
}

bool hadDuplicateIds(vector<Transaction> v){
    sort(v.begin(), v.end(), compareTransactionIds);
    int size = v.size();
    for (int i = 0; i < size-1; ++i) {
        if(v[i].id == v[++i].id)
            return true;
    }
    return false;
}

void findDuplicateIds(vector<Transaction> allTransaction, vector<Transaction> duplicateTransaction){
    sort(allTransaction.begin(), allTransaction.end(), compareTransactionIds);
    int size = v.size();
    for (int i = 0; i < size - 1; ++i) {
        if(allTransaction[i].)
    } 
}

int main()
{
    vector<Transaction> t {{2,"tuyen"},{3,"thang"},{1,"dat"},{8,"quan"}};
    
    if(hadDuplicateIds(t)){
        cout << "have Duplicate Ids";
    } else {
        cout << "DO NOT have Duplicate Ids";
    }
    return 0;
}
