01.
start   #   L   s1
        *   R   start

s1  1   P0,L    s2
    0   P1,L    s5

s2  1   P0      delete
    0   P1,L      s4

delete  #   R   s3
        *   L   delete

s3      0   P#,R    s3
        1   H       accept

s4  0   P0,L    s4
    1   P0      delete

s5  1   P1,L    s6
    0   L       s4

s6  0   P1,L    s6
    1   P0      delete
