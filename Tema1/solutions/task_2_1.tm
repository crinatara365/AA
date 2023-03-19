01acX.
start   #   Pa,L    s1
        *   R       start

s1  #   R   s2
    X   R   s2
    *   L   s1

s2  a   PX      s4
    0   PX,R    s3(0)
    1   PX,R    s3(1)

s3(c)   #   Pc  s1
        *   R   s3(c)

s4  #   R   s5
    *   L   s4

s5  *   P#  accept
