01acX.
start   *   L   contor

contor  *   Pa,R    start1

start1  #   L   s1
        X   L   s1
        *   R   start1

s1  0   PX  write(0)
    1   PX  write(1)
    a   PX  s2

write(c)    #   Pc  start1
            *   L   write(c)  

s2  #   L   s3
    X   R   s2

s3  X   P#  accept
