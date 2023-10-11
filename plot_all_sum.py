import numpy as np
from matplotlib.ticker import FixedLocator
from numpy import polyfit, poly1d
import matplotlib.pyplot as plt
X = []
Y = []
for i in [1,7,63,511]:
    x = []
    y = []
    print("array:")
    print("k=",i)
    for j in range(10,24):
        X.append(2**j)
        with open("array\\"+str(i)+'_'+str(2**j)+"_initial",'r') as f:
            t = []
            datas = f.readlines()
            for data in datas:
                t.append(float(data.replace("\n","")))
        x.append(2**j)
        y.append(sum(t)/len(t))
        print("n=",j," t=",round(y[-1],1),sep="")
    y = poly1d(polyfit(x,y,1))
    x = np.logspace(10,30,21,base=2)
    for j in range(24,31):
        print("n=",j," t=",round(y(2**j),1),sep="")

    plt.plot(x, y(x),label="Array k="+str(i))
    plt.legend()

for i in [1,7,63,511]:
    x = []
    y = []
    print("list:")
    print("k=",i)
    for j in range(10,24):
        X.append(2**j)
        with open("linked_list\\"+str(i)+'_'+str(2**j)+"_initial",'r') as f:
            t = []
            datas = f.readlines()
            for data in datas:
                t.append(float(data.replace("\n","")))
        x.append(2**j)
        y.append(sum(t)/len(t))
        print("n=",j," t=",round(y[-1],1),sep="")
    y = poly1d(polyfit(x,y,1))
    x = np.logspace(10,30,21,base=2)
    for j in range(24,31):
        print("n=",j," t=",round(y(2**j),1),sep="")
    plt.plot(x, y(x),label="Linked_list k="+str(i),linestyle='--')
    plt.legend()
for i in [1,7,63,511]:
    x = []
    y = []
    print("list:")
    print("k=",i)
    for j in range(10,24):
        X.append(2**j)
        with open("optmized_linked_list\\"+str(i)+'_'+str(2**j)+"_initial",'r') as f:
            t = []
            datas = f.readlines()
            for data in datas:
                t.append(float(data.replace("\n","")))
        x.append(2**j)
        y.append(sum(t)/len(t))
        print("n=",j," t=",round(y[-1],1),sep="")
    y = poly1d(polyfit(x,y,1))
    x = np.logspace(10,30,21,base=2)
    for j in range(24,31):
        print("n=",j," t=",round(y(2**j),1),sep="")
    plt.plot(x, y(x),label="optmized_Linked_list k="+str(i),linestyle=':')
    plt.legend()
plt.xlabel('n', fontsize=12)
plt.ylabel('time(s)', fontsize=12)
plt.title("Sum time in different k")
axs = plt.gca()
axs.set_xscale("log", base=2)

plt.show()
