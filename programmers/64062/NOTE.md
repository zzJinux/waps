Methods
- (my method) remove stones in order of decreasing values and manage ranges of removed stones
  - union-find
  - unordered_map
- binary search
- calc the maxmium value for each k-sized sliding window, and take the minimum of those maxmium values
  - If the maximum value of stones[i:i+k] is Q=stones[q], Q guys can cross the section of [i,i+1,...,i+k-1]
    by stepping onto one of stones of the section. The last guy touches the stones[q]; all stones are invalidated.
