import matplotlib.pyplot as plt
import numpy as np

def readData(fileName):
    with open(fileName) as f:
        global x
        global y
        lines = f.readlines()
        x = [line.split()[0] for line in lines]
        y = [line.split()[1] for line in lines]

        x = [int(i) for i in x]
        y = [float(i) for i in y]

readData('bubbleSort.data')

plt.title("Sortowanie")

plt.plot(x, y, label="Bubble Sort")
plt.plot(x, 1.25*(np.power(x,2)), "--", label="1,25*n^2")

readData('mergeSort.data')

plt.plot(x, y, label="Merge Sort")
plt.plot(x, 5.5*(x*(np.log(x))), "--", label="5,5*nlog(n)")

plt.legend()
plt.show()