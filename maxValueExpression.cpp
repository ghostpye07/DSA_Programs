e=input()
e_length=len(e)
n=[]
op=[]
temp=""

for i in range(e_length):
    if e[i]=="+" or e[i]=="*":
        op.append(e[i])
        n.append(int(temp))
        temp=""
    else:
        temp+=e[i]
    
n.append(int(temp))
nl=len(n)
max_val=[[0 for j in range(nl)] for i in range(nl)]
    
for i in range(nl):
    for j in range(nl):
        if i==j:
            max_val[i][j]=n[i]
                
                
for k in range(2,nl+1):
    for i in range(nl-k+1):
        j=i+k-1
        for h in range(i,j):
            max_temp=0
            if op[h]=="*":
                max_temp=max_val[i][h]*max_val[h+1][j]
            elif op[h]=="+":
                max_temp=max_val[i][h]+max_val[h+1][j]
                    
            if (max_temp>max_val[i][j]):
                max_val[i][j]=max_temp
    
print(max_val[0][nl-1])
