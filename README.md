# Basic Information #

Store the code of online contest.
* Codeforces
* Topcoder

# TODO list #

* the rest unsolved problems

# Record #

### 2016.08.07 CF366 Div.1 ###
    - WA and TLE on A: lack caution manipulating the **pointer**, when the chain is empty,
    make the tail pointer point to -1 and keep head pointer unchange.
### 2016.08.04 CF365 Div.2 ###
    - RE on B: insufficient **size of array**.
    - TLS on B: not realize the **property of** distribution on multiplication in **the problem**.
    - WA on C: stupid mistake, forgot to **set the precision in special cases**.
    - D: calc the sum of identical elements in intervals.
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