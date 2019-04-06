# -*- coding: utf-8 -*-

import numpy as np
import matplotlib.pyplot as plt
import math
import random

class expression(object):
    def __init__(self, classNumber=3):
        self.classNumber = classNumber
        self.miuList = []
        self.dataX = []
        self.alphaList = []
        for i in range(3):
            self.alphaList.append(1.0/3.0)
        self.gammaX = []
        self.sigmaList = []
        sigma = [[1.0, 0.0], [0.0, 1.0]]
        for i in range(3):
            self.sigmaList.append(sigma)

    def getDataFromFile(self, filePath):
        with open(filePath, 'r', encoding='utf-8') as dataFile:
            for line in dataFile.readlines():
                lst = line.split()
                self.dataX.append((float(lst[0]), float(lst[1])))
        temp = range(len(self.dataX)) # 随机选择初始均值向量
        random.shuffle(list(temp))
        for i in range(self.classNumber):
            self.miuList.append(self.dataX[temp[i]])

    def getDataFromRandom(self, dataNumber):
        tempMiuList = [(2.0, 2.0), (8.0, 2.0), (5.0, 8.0)]
        tempCov = 2.0
        randomVector = []
        highLimit = 1.0 # 设置每次迭代生成时概率上限
        i = 0
        while i < self.classNumber - 1:
            prob = random.uniform(0.0, highLimit)
            if prob == 0.0:
                continue
            randomVector.append(prob)
            highLimit -= prob
            i += 1
        randomVector.append(highLimit)
        for i in range(self.classNumber-1):
            group_number = int(dataNumber * randomVector[i])
            X1 = np.random.normal(tempMiuList[i][0], tempCov, group_number)
            X2 = np.random.normal(tempMiuList[i][1], tempCov, group_number)
            for j in range(group_number):
                self.dataX.append((X1[j], X2[j]))
        group_number = dataNumber - len(self.dataX)
        print(tempMiuList[self.classNumber-1][0])
        print(tempCov)
        print(group_number)
        X1 = np.random.normal(tempMiuList[self.classNumber-1][0], tempCov, group_number)
        X2 = np.random.normal(tempMiuList[self.classNumber-1][1], tempCov, group_number)
        for j in range(group_number):
            self.dataX.append((X1[j], X2[j]))
        temp = range(len(self.dataX))
        random.shuffle(list(temp))
        for i in range(self.classNumber):
            self.miuList.append(self.dataX[temp[i]])

    def GMM(self, cycleTimes):
        for i in range(cycleTimes):
            if len(self.dataX) == 0:
                print('No data!')
                exit(0)
            self.gammaX.clear()
            for vectorX in self.dataX:
                self.gammaX.append(gamma(self.alphaList, self.miuList, self.sigmaList, vectorX))
            self.miuList.clear()
            self.sigmaList = []
            self.alphaList.clear()
            for i in range(3):
                Sum = 0.0
                factor = np.array([0.0, 0.0])
                for j in range(len(self.gammaX)):
                    Sum += self.gammaX[j][i]
                    factor += self.gammaX[j][i] * np.array(f(self.dataX[j]))
                miu = (factor/Sum).tolist()
                self.miuList.append((miu[0], miu[1])) # 计算新均值向量

                factor = np.array([[0.0, 0.0], [0.0, 0.0]])
                for j in range(len(self.gammaX)):
                    tempVector = np.array(self.dataX[j]) - np.array(miu)
                    tempVector = np.matrix(tempVector)
                    factor += self.gammaX[j][i] * (tempVector.T.dot(tempVector))
                self.sigmaList.append(factor/Sum) # 计算新协方差矩阵

                self.alphaList.append(Sum/len(self.gammaX)) # 计算新Alpha混合系数
                    
#            print('MiuMatrix', self.miuList)
#            print('SigmaMatrix', self.sigmaList)
#            print('AlphaList', self.alphaList)

    def classify(self):
        self.Cla = []
        for i in range(self.classNumber):
            self.Cla.append([])
        for i in range(len(self.gammaX)):
            cla = 0
            if self.gammaX[i][cla] < self.gammaX[i][1]:
                cla = 1
            if self.gammaX[i][cla] < self.gammaX[i][2]:
                cla = 2
            self.Cla[cla].append(self.dataX[i])

    def painting(self):
        plt.subplot(1, 1, 1)
        plt.title('GMM')
        X, Y = [], []
        for item in self.Cla[0]:
            X.append(item[0])
            Y.append(item[1])
        plt.scatter(X, Y, marker='*', color='red')
        X.clear()
        Y.clear()
        for item in self.Cla[1]:
            X.append(item[0])
            Y.append(item[1])
        plt.scatter(X, Y, marker='*', color='blue')
        X.clear()
        Y.clear()
        for item in self.Cla[2]:
            X.append(item[0])
            Y.append(item[1])
        plt.scatter(X, Y, marker='*', color='green')
        for i in range(3):
            plt.scatter(self.miuList[i][0], self.miuList[i][1], marker='D', color='black')
        plt.show()

def f(a):
    return [a[0], a[1]]

'''
计算某个样本的后验概率，返回一个样本Xj的所有高斯混合成分生成的后验概率
'''
def gamma(alphaList, miuList, covList, vectorX, classNumber=3):
    prob = []
    ans = []
    for i in range(classNumber):
        prob.append(gaussia(miuList[i], covList[i], vectorX))
    Sum = 0.0
    for i in range(classNumber):
        Sum += alphaList[i] * prob[i]
    if Sum == 0.0:
        print('Alpha', len(alphaList), alphaList)
        print('Gaussian', len(prob), prob) 
        print('CovList', covList)
        print('Vector', vectorX)
        print('Miulist', miuList)
        exit(0)
    for i in range(classNumber):
        ans.append(alphaList[i] * prob[i] / Sum)
    return ans

def gaussia(tempMiu, tempCov, tempVectorX):
    miu = np.array(f(tempMiu))
    vectorX = np.array(f(tempVectorX))
    formatCov = np.array(tempCov)
    index = -0.5 * (vectorX - miu).dot(np.linalg.inv(formatCov)).dot((vectorX - miu).T)
    return 1.0 / (2 * math.pi * math.sqrt(np.linalg.det(formatCov))) * math.exp(index)

def main():
    gmm = expression()
#    gmm.getDataFromFile('data.txt')
    gmm.getDataFromRandom(100)
    gmm.GMM(50)
#    print(gmm.sigmaList)
    gmm.classify()
    gmm.painting()

if __name__ == '__main__':
    main()
