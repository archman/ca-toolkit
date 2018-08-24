#!/usr/bin/env python3
# -*- coding: utf-8 -*-

"""CA evolving demonstration.
"""

from ca_toolkit import evolve
import numpy as np
import matplotlib.pyplot as plt

CMAP = plt.cm.viridis

M, N = 1080, 1920
a = np.zeros(M * N, dtype=np.int32)
a[int(N/3):M*N:N] = 1
a[int(N/3*2):M*N:N] = 1
opt = {'cmap': CMAP, 'origin': 'lower', 'alpha': 0.8, 'aspect': 'auto'}
fig = plt.figure(dpi=120, figsize=(16,9))
cnt = 0
for i in range(1, 10):
    ax = fig.add_subplot(3, 3, i)
    ax.get_xaxis().set_visible(False)
    ax.get_yaxis().set_visible(False)
    ax.imshow(a.reshape(M, N), **opt)
    ax.set_title('{}'.format(cnt))
    for _ in range(20):
        evolve(a, M, N, a)
        cnt += 1

fig.subplots_adjust(left=0.00001, bottom=0.00001,
                    right=0.99999, top=0.99999,
                    wspace=None, hspace=None)
plt.tight_layout()
plt.show()
