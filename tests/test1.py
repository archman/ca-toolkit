#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from ca_toolkit import evolve
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation

CMAP = plt.cm.viridis

def animate():
    n_frame = 800
    M, N = 1080, 1920
    a = np.zeros(M*N, dtype=np.int32)
    a[int(N/3):M*N:N] = 1
    a[int(N/3*2):M*N:N] = 1
    opt = {'cmap': CMAP, 'origin': 'lower', 'alpha': 0.8, 'aspect': 'auto'}
    fig = plt.figure(dpi=120, figsize=(16,9))
    ax1 = fig.add_subplot(111)
    ax1.get_xaxis().set_visible(False)
    ax1.get_yaxis().set_visible(False)
    ims = [[ax1.imshow(a.reshape(M, N), **opt)]]
    plt.tight_layout()
    fig.subplots_adjust(left=0.00001, bottom=0.00001,
                        right=0.99999, top=0.99999,
                        wspace=None, hspace=None)
    for i in range(n_frame):
        evolve(a, M, N, a)
        ims.append([ax1.imshow(a.reshape(M, N), **opt)])

    ani = animation.ArtistAnimation(fig, ims,
                                    interval=50,
                                    repeat_delay=1000,
                                    blit=True)

    ani.save('{}x{}.mp4'.format(M, N), metadata={'author':'Tong'})
    #plt.show()


if __name__ == "__main__":
    animate()
