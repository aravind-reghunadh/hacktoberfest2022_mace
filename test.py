import numpy as np
import Layer as l
import Activation as ac
		
X = [[1.2, 1.4],
	 [1.7, 0.4]]

l1 = l.Dense(2, 5)
l1.forward(X)
a1 = ac.ReLU()
a1.forward(l1.output)
l2 = l.Dense(5, 1)
l2.forward(a1.output)
a2 = ac.Sigmoid()
a2.forward(l2.output)

print(a2.output)
