.function f
f:
ADJSP 0 
PUSH 1 
CALL @f
PLUS
RETURNV
PUSH 0 
RETURNV
.function main
main:
ADJSP 0 
CALL @f
CALL @print
POPARGS 4 
POP
PUSH 0 
RETURNV
