import numpy as np

class ReLU:
	def forward(self, inputs):
		self.output = np.maximum(0, inputs)

class Sigmoid:
	def forward(self, inputs):
		self.output = 1 / (1 + np.exp(-inputs))
