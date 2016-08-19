# Basic Information #

Store the code of online contest.
* Codeforces
* Topcoder

# TODO list #

* CF367 Div.2 D binary search
* the rest unsolved problems

# Record #

### 2016.08.011 TC697 Div.1 ###

* A: given vector b, check if there exist vector a satisfies p[i] | a[i] ^ b[i] for every i in the range of b size. p[i] is equal to the product of all the elements in vector a but a[i];
    - solution:
        + for concenience, we can assume that a[i] contains only 2 as prime divisor, because every prime divisor can be considered separately.
        + so a[i] can be represented by the power of 2, mark as m[i]
        + then we have the equation: forall i in size, b[i] * m[i] >= sigma(m[j]) (j <> i)
        + the equation can be transformed into: (b[i] + 1) * m[i] >= sum
        + the equation above can be interpreted as portion of each m[i] in the sum of all the m[i]
        + so the problem becomes check whether sum of all 1 / (b[i] + 1) is less than 1
        + trick: if the result is exactly equal to 1, it means that the 1 / (b[i] + 1) is exactly the portion of m[i], so than we check if there exist any two elements are the same (because the restriction state that the vector a can only contain distinct elements).

### 2016.08.011 CF367 Div.2 ###

* D: find an element
    - solution:
        + consider the problem bit by bit
        + the higher bits always have more effect on answer than the lower bits
        + so we try to find an element with every bit opposite by given value from high bit to low bit
        + as we can see, the desired elements form a continuous interval
        + so the first consideration is to record the left and right bound of the interval
        + but it may lead to TLE
        + but, we only need to know that is there exist some elements with certain bit set (or not)
        + so we can just record the tmp result and continue to add lower bits and check existance by using lower_bound function
    - trick: we can simply check that if the result of lower_bound function is larger than the desire value add one more current bit
    - TLE: lower\_bound(it1, it2, val) is much slower than the s.lower\_bound(val)
    - WA: consider empty set

### 2016.08.07 CF366 Div.1 ###

* WA and TLE on A: lack caution manipulating the **pointer**, when the chain is empty, make the tail pointer point to -1 and keep head pointer unchange.

### 2016.08.04 CF365 Div.2 ###

* RE on B: insufficient **size of array**.
* TLS on B: not realize the **property of** distribution on multiplication in **the problem**.
* WA on C: stupid mistake, forgot to **set the precision in special cases**.
* D: calc the sum of identical elements in intervals.
    - solution:
        1. sort the query by right point
        2. deal the element one by one
        3. record the last position of element
        4. everytime, remove the element from the last position (if exists)
        5. add the element at current position
        6. calc the interval (for every quaries with currentposition as right point) sum using segment tree
    - TLE on D:
        1. sort the pair vector costs lots of time. If want to sort intervals by one point, use **vector** to store **links on each point** is a good choice.
        2. **cin, cout** should **NOT** be used in large data amount situation
* E: find minimum elements whose product is multiple of a given number
    - solution:
        + DP: dp\[i\]\[j\] record the optimal result of the first i elements with gcd j with given number k
        + if the i-th element is selected, the state can be update from dp\[i - 1\]\[j / gcd(a[i], j)\]
    - TLE
        + we should use the gcd(k, a[i]) as a replacement of a[i] at first, cause the time cost of gcd is not that little to neglect.
        + we can use a pair to record the state with two key value as minimum number of elements and the minimum sum under first constraint.