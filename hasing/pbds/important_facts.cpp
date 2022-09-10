// Common file
#include <ext/pb_ds/assoc_container.hpp>
// Including tree_order_statistics_node_update
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
// Additional functions in the ordered set other than the set

// Along with the previous operations of the set, it supports two main important operations

// find_by_order(k): It returns to an iterator to the kth element (counting from zero) in the set in O(logn) time.To find the first element k must be zero.
// Let us assume we have a set s : {1, 5, 6, 17, 88}, then :
// *(s.find_by_order(2)) : 3rd element in the set i.e. 6
// *(s.find_by_order(4)) : 5th element in the set i.e. 88
// order_of_key(k) : It returns to the number of items that are strictly smaller than our item k in O(logn) time.
// Let us assume we have a set s : {1, 5, 6, 17, 88}, then :
// s.order_of_key(6) : Count of elements strictly smaller than 6 is 2.
// s.order_of_key(25) : Count of elements strictly smaller than 25 is 4.

// also we can convert it into multiset ,map,multimap by changing less<int>comapartor function

//into multiset = > change it to less_equal<int>
//e.g
// typedef tree<
//     int,
//     null_type,
//     less_equal<int>,
//     rb_tree_tag,
//     tree_order_statistics_node_update> ordered_set;


//into map=> change it to every where replace int to pair
//e.g
// typedef tree<
// pair<int, int>,
// null_type,
// less<pair<int, int>>,
// rb_tree_tag,
// tree_order_statistics_node_update> ordered_set;