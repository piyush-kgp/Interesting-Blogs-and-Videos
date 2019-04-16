import glob
from PIL import Image
import numpy as np
from sklearn.decomposition import PCA
import matplotlib.pyplot as plt

def create_dataset(img_dir):
    """
    creates dataset of images of shape [M, h*w*c]
    """
    files = glob.glob(img_dir+'*.jpg')
    sample = np.array(Image.open(files[0]))
    h, w, c = sample.shape
    data = np.zeros((len(files), h*w)).astype(np.float32)
    for i, file in enumerate(files):
        img = np.array(Image.open(file))
        img = np.mean(img, axis=-1) #convert color to B/w
        # img = img/127.5 - 1 #scale in -1 to 1 range
        data[i] = img.flatten()
    return data, (h, w)


def get_mean_face(data, shape):
    """
    Gets mean face and saves it as image
    """
    mean_face = np.mean(data, axis=0)
    mean_face = np.reshape(mean_face, shape)
    Image.fromarray(mean_face.astype(np.uint8)).save('save/mean_face.jpg')


def get_eigenfaces(data, shape):
    """
    Gets and saves eigen faces
    """
    pca = PCA(n_components=150, svd_solver='randomized',
              whiten=True)
    pca.fit(data)
    eigenfaces = pca.components_
    # fig, axes = plt.subplots(4, 4)
    # fig.set_figheight(7.2)
    # fig.set_figwidth(9.6)
    fig = plt.figure(figsize=(7.2, 7.2))
    plt.subplots_adjust(bottom=0, left=.01, right=.99, top=.90, hspace=.35)
    for i, face in enumerate(eigenfaces[:12]):
        # r, c = i//4, i%4
        plt.subplot(3, 4, i+1)
        plt.imshow(face.reshape(shape), cmap='gray')
        plt.title('EigenFace %s' %(i+1), size=12)
        plt.xticks(())
        plt.yticks(())
        # Image.fromarray(face.astype(np.uint8)).save('save/eigenface_%s.jpg' %i)
    plt.savefig('save/EIGENFACES.jpg')
    
    fig = plt.figure(figsize=(27, 24))
    plt.subplots_adjust(bottom=0, left=.01, right=.99, top=.90, hspace=.35)
    for i, face in enumerate(eigenfaces):
        # r, c = i//4, i%4
        plt.subplot(10, 15, i+1)
        plt.imshow(face.reshape(shape), cmap='gray')
        plt.title('EigenFace %s' %(i+1), size=12)
        plt.xticks(())
        plt.yticks(())
        # Image.fromarray(face.astype(np.uint8)).save('save/eigenface_%s.jpg' %i)
    plt.savefig('save/EIGENFACES_ALL.jpg')



if __name__=='__main__':
    data, shape = create_dataset(img_dir='images/')
    get_mean_face(data, shape)
    get_eigenfaces(data, shape)
