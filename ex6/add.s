.global add
add:
ADD x1,x1,x0
SUB x0,x0,#1
CMP x0,#0
BNE add
MOV x0,x1
RET
