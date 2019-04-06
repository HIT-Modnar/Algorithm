# -*- coding: utf-8 -*-

import numpy as np
import matplotlib.pyplot as plt
import math
import random
from mpl_toolkits.mplot3d import Axes3D

class expression(object):
    # 设置数据集内样本个数、样本的维度
    def __init__(self, dataNumber, dimension=3):
        self.dataNumber = dataNumber
        self.dimension = dimension

    def getDataFromFile(self, filePath):
        self.dataX = []
        lineNumber = 0
        with open(filePath, 'r', encoding='utf-8') as dataFile:
            for line in dataFile.readlines():
                lineNumber += 1
                dataList = [float(dataStr) for dataStr in line.split()]
                self.dataX.append(dataList)
            self.dataNumber = lineNumber

    def PCA(self, aimDimension=1):
        self.miuList = [] # 存储数据集中每个维度的样本均值
        self.newDataX = [] # 存储样本数据中心化之后的新样本数据集
        if self.dataNumber == 0:
            print('Error! The number of the dataX is zero!')
            exit(1)
        for i in range(self.dataNumber):
            self.newDataX.append([])
        for i in range(self.dimension):
            sumValue = 0.0
            for j in range(self.dataNumber):
                sumValue += self.dataX[j][i]
            averageValue = sumValue / self.dataNumber # 计算样本每个维度的平均值
            self.miuList.append(averageValue)
            for j in range(self.dataNumber):
                # 得到新的中心化之后的样本数据集
                self.newDataX[j].append(self.dataX[j][i] - averageValue) 
        self.sigma = np.dot(np.array(self.newDataX).T, np.array(self.newDataX))
        eigenvalue, eigenvector = np.linalg.eig(self.sigma)
        ansEigenvector = eigenvector.T # 取其转置矩阵, 得到对应的特征向量
        tempList = []
        tempW = []
        for i in range(len(eigenvalue)):
            tempList.append((eigenvalue[i].real, ansEigenvector[i].real))
#        print('TempList:', tempList[0][1])
        tempList = sorted(tempList, key=lambda x:x[0], reverse=True)
        for i in range(aimDimension):
            tempW.append(tempList[i])
        self.W = []
        for i in range(len(tempW)):
            self.W.append(tempW[i][1])
        self.ansX = np.array(self.W).dot(np.array(self.newDataX).T)
#        print('ansX\n', self.ansX)

#        print('value', eigenvalue)
#        print('vector', eigenvector)

    def painting(self):
        fig = plt.figure()
        ax = fig.add_subplot(111, projection='3d')
        X, Y, Z = [], [], []
        # 将投影面上的顶点映射到三维空间中, 在三维空间中的点集为paintPointSet
        paintPointSet = np.array(self.newDataX).dot(np.array(self.W).T).dot(np.array(self.W))
        # 绘制样本点
        for i in range(self.dataNumber):
            X.append(self.newDataX[i][0])
            Y.append(self.newDataX[i][1])
            Z.append(self.newDataX[i][2])
        ax.scatter(X, Y, Z, color='green', marker='*')
        # 绘制投影面上的样本投影点
        X.clear()
        Y.clear()
        Z.clear()
        for i in range(self.dataNumber):
            X.append(paintPointSet[i][0])
            Y.append(paintPointSet[i][1])
            Z.append(paintPointSet[i][2])
        ax.scatter(X, Y, Z, color='red', marker='o')
        # 绘制投影面
        Xindex, Yindex, Zindex = 0.0, 0.0, 0.0
        for samplePoint in paintPointSet:
            Xindex += samplePoint[0]
            Yindex += samplePoint[1]
            Zindex += samplePoint[2]
        point = (Xindex/len(paintPointSet), Yindex/len(paintPointSet), Zindex/len(paintPointSet)) 
        vecA = self.W[0]
        vecB = self.W[1]
        normVecotr = (vecA[1]*vecB[2]-vecA[2]*vecB[1], 
            -vecA[0]*vecB[2]+vecA[2]*vecB[0], 
            vecA[0]*vecB[1]-vecA[1]*vecB[0])
        print('normVecotr:', normVecotr)
        X.clear()
        Y.clear()
        Z.clear()
        X = np.arange(point[0]-20.0, point[0]+20.0, 4.0)
        Y = np.arange(point[1]-20.0, point[1]+20.0, 4.0)
        X, Y = np.meshgrid(X, Y)
        Z = func(X, Y, normVecotr, point)
        ax.plot_surface(X, Y, Z, rstride=1, cstride=1, cmap=plt.cm.jet, alpha=0.5)
        # 绘制投影面基向量
        X = np.arange(point[0]-20.0, point[0]+20.0, 4.0)
        Y = vecA[1] / vecA[0] * X
        Z = vecA[2] / vecA[0] * X
        ax.plot(X, Y, Z, label='W0', color='black')
        Y = vecB[1] / vecB[0] * X
        Z = vecB[2] / vecB[0] * X
        ax.plot(X, Y, Z, label='W1', color='black')

#        Y = normVecotr[1] / normVecotr[0] * X
#        Z = normVecotr[2] / normVecotr[0] * X
#        ax.plot(X, Y, Z, label='W2', color='red')
#        print('normVecotr:', normVecotr)

        # 设置坐标轴标签
        ax.set_xlabel('X Label', color='red')
        ax.set_ylabel('Y Label', color='green')
        ax.set_zlabel('Z Label', color='blue')
#        X, Y = np.meshgrid(X, Y)
#        print(X)
#        ax.plot_surface(X, Y, Z, rstride=1, cstride=1, cmap=plt.cm.coolwarm)
        plt.show()

#    normVecotr = (vecA[1]*vecB[2]-vecA[2]*vecB[1], 
#        vecA[0]*vecB[2]-vecA[2]*vecB[0], 
#        vecA[0]*vecB[1]-vecA[1]*vecB[0])
#    X = np.arange(-2.0, 2.0, 0.1)
#    Y = np.arange(-2.0, 2.0, 0.1)
#    X, Y = np.meshgrid(X, Y)
#    Z = func(X, Y, normVecotr, point)
#    ax.plot_surface(X, Y, Z, rstride=1, cstride=1, cmap=plt.cm.jet)
#    ax.set_xlabel('X Label', color='red')
#    ax.set_ylabel('Y Label', color='green')
#    ax.set_zlabel('Z Label', color='blue')

def func(x, y, normVecotr, point):
    x0 = point[0]
    y0 = point[1]
    z0 = point[2]
    return z0-(normVecotr[0]*(x-x0) + normVecotr[1]*(y-y0))/normVecotr[2]

def main():
#    generateDataToFile('data.txt')
    pca = expression(30, 3)
    pca.getDataFromFile('data.txt')
#    print(np.array(pca.dataX))
    pca.PCA(2)
    pca.painting()
#    print('self.W', pca.W)
#    print(np.array(pca.miuList))
#    print(np.array(pca.newDataX))
#    print(np.array(pca.sigma))

if __name__ == '__main__':
    main()
