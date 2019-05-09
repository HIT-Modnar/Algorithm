# -*- coding: utf-8 -*-

import numpy as np
import matplotlib.pyplot as plt
import math
import random

class expression(object):
    def __init__(self):
        pass

    def generate_data(self):
        self.G1X = np.random.normal(2.0, 2.0, 100)
        self.G1Y = np.random.normal(2.0, 2.0, 100)
        self.G2X = np.random.normal(8.0, 2.0, 100)
        self.G2Y = np.random.normal(2.0, 2.0, 100)
        self.G3X = np.random.normal(5.0, 2.0, 100)
        self.G3Y = np.random.normal(8.0, 2.0, 100)
        self.K1 = (self.G1X[0], self.G1Y[0])
        self.K2 = (self.G1X[1], self.G1Y[1])
        self.K3 = (self.G1X[2], self.G1Y[2])
        self.C1 = []
        self.C2 = []
        self.C3 = []

    def painting(self):
        plt.subplot(1, 1, 1)
        plt.title('K-Means')
        plt.scatter(self.G1X, self.G1Y, marker='*', color='white')
        plt.scatter(self.G2X, self.G2Y, marker='*', color='white')
        plt.scatter(self.G3X, self.G3Y, marker='*', color='white')
        plt.show()
    
    def finalPainting(self):
        plt.subplot(1, 1, 1)
        plt.title('K-Means')
        lineX = []
        lineY = []
        for i in range(len(self.C1)):
            lineX.append(self.C1[i][0])
            lineY.append(self.C1[i][1])
        plt.scatter(lineX, lineY, marker='*', color='red')
        lineX.clear()
        lineY.clear()
        for i in range(len(self.C2)):
            lineX.append(self.C2[i][0])
            lineY.append(self.C2[i][1])
        plt.scatter(lineX, lineY, marker='*', color='blue')
        lineX.clear()
        lineY.clear()
        for i in range(len(self.C3)):
            lineX.append(self.C3[i][0])
            lineY.append(self.C3[i][1])
        plt.scatter(lineX, lineY, marker='*', color='green')
        plt.scatter(self.K1[0], self.K1[1], marker='D', color='blue') # Around should be red
        plt.scatter(self.K2[0], self.K2[1], marker='D', color='green') # Around should be blue
        plt.scatter(self.K3[0], self.K3[1], marker='D', color='red') # Around should be green
        plt.show()

    def init_Class(self):
        pass

    def classify(self):
        self.C1.clear()
        self.C2.clear()
        self.C3.clear()
        for i in range(len(self.G1X)):
            classFlag = 1
            point = (self.G1X[i], self.G1Y[i])
            distance = get_distance(self.K1, point)
            cmpDistance = get_distance(self.K2, point)
            if distance > cmpDistance:
                distance = cmpDistance
                classFlag = 2
            cmpDistance = get_distance(self.K3, point)
            if distance > cmpDistance:
                distance = cmpDistance
                classFlag = 3
            if classFlag == 1:
                self.C1.append(point)
            elif classFlag == 2:
                self.C2.append(point)
            else:
                self.C3.append(point)
        for i in range(len(self.G2X)):
            classFlag = 1
            point = (self.G2X[i], self.G2Y[i])
            distance = get_distance(self.K1, point)
            cmpDistance = get_distance(self.K2, point)
            if distance > cmpDistance:
                distance = cmpDistance
                classFlag = 2
            cmpDistance = get_distance(self.K3, point)
            if distance > cmpDistance:
                distance = cmpDistance
                classFlag = 3
            if classFlag == 1:
                self.C1.append(point)
            elif classFlag == 2:
                self.C2.append(point)
            else:
                self.C3.append(point)
        for i in range(len(self.G3X)):
            classFlag = 1
            point = (self.G3X[i], self.G3Y[i])
            distance = get_distance(self.K1, point)
            cmpDistance = get_distance(self.K2, point)
            if distance > cmpDistance:
                distance = cmpDistance
                classFlag = 2
            cmpDistance = get_distance(self.K3, point)
            if distance > cmpDistance:
                distance = cmpDistance
                classFlag = 3
            if classFlag == 1:
                self.C1.append(point)
            elif classFlag == 2:
                self.C2.append(point)
            else:
                self.C3.append(point)
        self.finalPainting()

    def finalClassify(self):
        size1, size2, size3 = 1, 1, 1
        while size1 != len(self.C1) or size2 != len(self.C2) or size3 != len(self.C3):
            size1 = len(self.C1)
            size2 = len(self.C2)
            size3 = len(self.C3)
            self.classify()
            self.compute_Ker()

    def compute_Ker(self):
        self.K1 = get_average(self.C1)
        self.K2 = get_average(self.C2)
        self.K3 = get_average(self.C3)

# 计算平均值, 返回一个二元组
def get_average(tempList): # tempList内为二元组元素
    LENGTH = len(tempList)
    if LENGTH == 0:
        return False
    ansX, ansY = 0.0, 0.0
    for i in range(LENGTH):
        ansX += tempList[i][0]
        ansY += tempList[i][1]
    return (ansX / LENGTH, ansY / LENGTH)

def get_distance(point1, point2):
#    print(point1, point2)
    return (point1[0] - point2[0]) * (point1[0] - point2[0]) + \
           (point1[1] - point2[1]) * (point1[1] - point2[1])

def main():
    exp = expression()
    exp.generate_data()
    print('Classifying...')
    exp.finalClassify()
    exp.finalPainting()
    print('Done.')

if __name__ == '__main__':
    main()
