import numpy as np
from matplotlib.ticker import FixedLocator
from numpy import polyfit, poly1d
import matplotlib.pyplot as plt
X = []
Y = []

for i in [1,7,63,511]:
    x = []
    y = []
    for j in range(10,22):
        X.append(2**j)
        with open("cache\\arr\\"+str(i)+'_'+str(2**j),'r') as f:
            t = []
            datas = f.readlines()[5].split()[0]
            print(datas)

            t.append(float(datas.replace("\n","")))
        x.append(2**j)
        y.append(sum(t)/len(t))
    y = poly1d(polyfit(x,y,1))
    x = np.logspace(10,30,21,base=2)
    print(y(x))
    plt.plot(x, y(x),label="Array k="+str(i))
    plt.legend()

for i in [1,7,63,511]:
    x = []
    y = []
    for j in range(10,22):
        X.append(2**j)
        with open("cache\\linked_list\\"+str(i)+'_'+str(2**j),'r') as f:
            t = []
            datas = f.readlines()[5].split()[0]

            t.append(float(datas.replace("\n","")))
        x.append(2**j)
        y.append(sum(t)/len(t))
    y = poly1d(polyfit(x,y,1))
    x = np.logspace(10,30,21,base=2)
    print(y(x))
    plt.plot(x, y(x),label="linked_list k="+str(i),linestyle=':')
    plt.legend()
for i in [1,7,63,511]:
    x = []
    y = []
    for j in range(10,22):
        X.append(2**j)
        with open("cache\\optmized_list\\"+str(i)+'_'+str(2**j),'r') as f:
            t = []
            datas = f.readlines()[5].split()[0]

            t.append(float(datas.replace("\n","")))
        x.append(2**j)
        y.append(sum(t)/len(t))
    y = poly1d(polyfit(x,y,1))
    x = np.logspace(10,30,21,base=2)
    print(y(x))
    plt.plot(x, y(x),label="optmized_list k="+str(i),linestyle='--')
    plt.legend()

plt.xlabel('n', fontsize=12)
plt.ylabel('Cache misses(times)', fontsize=12)
plt.title("Cache misses in different k")
axs = plt.gca()
axs.set_xscale("log", base=2)

plt.show()
