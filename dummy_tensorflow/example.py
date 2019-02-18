
"""
Source: https://medium.com/@d3lm/understand-tensorflow-by-mimicking-its-api-from-scratch-faa55787170d
"""

import tf_api as tf

# create default graph
tf.Graph().as_default()

# construct computational graph by creating some nodes
a = tf.Constant(15)
b = tf.Constant(5)
prod = tf.multiply(a, b)
sum = tf.add(a, b)
res = tf.divide(prod, sum)

# create a session object
session = tf.Session()

# run computational graph to compute the output for 'res'
out = session.run(res)
print(out)
