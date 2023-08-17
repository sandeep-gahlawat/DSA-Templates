
//inbuild sort function takes nlogn time =>uses introsort (hybrid of quicksort,heapsort,insertion sort)
// sort(address of first element,address of element that is next to last)

//e.g for vector
//sort(v.begin(),v.end())=>in increasing order
//sort(v.begin(),v.end(),greater<int>())=>in decreasing order


//we can also sort using our own comparator function
//sort(v.begin(),v.end(),mycmp);


//stable sorting algorithm
// 1->insertion sort


//unstable algorithm
// 1=>selection sort

//inplace sorting algorithms
//1->insertion sort