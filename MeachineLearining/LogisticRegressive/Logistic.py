# -*- coding: utf-8 -*-

import numpy as np
import matplotlib.pyplot as plt
import random
import math

class LogisticExpression(object):
    def __init__(self, exp11=5, exp12=5, exp21=15, exp22=15, var=3, size=100):
        self.size = int(size)
        self.G1X = np.random.normal(exp11, var, size=self.size//2)
        self.G1Y = np.random.normal(exp12, var, size=self.size//2)
        self.G2X = np.random.normal(exp21, var, size=self.size//2)
        self.G2Y = np.random.normal(exp22, var, size=self.size//2)

    def getDataFromFile(self, filePath):
        self.size = 0
        self.G1X = []
        self.G1Y = []
        self.G2X = []
        self.G2Y = []
        with open(filePath, 'r', encoding='utf-8') as dataFile:
            for line in dataFile.readlines():
                if line == '\n':
                    continue
                self.size += 1
                # 对于从文件读取数据的情况, 设置一个缓存数据的list
                tempLineDataList = line.split()
                if int(tempLineDataList[2]) == 0:
                    self.G1X.append(float(tempLineDataList[0]))
                    self.G1Y.append(float(tempLineDataList[1]))
                else:
                    self.G2X.append(float(tempLineDataList[0]))
                    self.G2Y.append(float(tempLineDataList[1]))

    def generateMarixAndVector(self):
        self.dataMatrix = []
        self.labelVector = []
        for i in range(len(self.G1X)): 
            self.dataMatrix.append([1.0, self.G1X[i], self.G1Y[i]])
            self.labelVector.append(int(0))
        for i in range(len(self.G2X)):
            self.dataMatrix.append([1.0, self.G2X[i], self.G2Y[i]])
            self.labelVector.append(int(1))

    # 梯度上升法求解最佳回归系数
    def gradAscent(self, alpha=0.001, cycleTimes=500, epslion=0.0000000000001):
        self.dataMatrix = np.mat(self.dataMatrix) # 将数组转为矩阵
        labelVectorT = np.mat(self.labelVector).T
        m, n = np.shape(self.dataMatrix)      # 返回矩阵的行和列
        weights = np.ones((n, 1)) # 初始化最佳回归系数
        for i in range(cycleTimes):
            h = sigmoid(self.dataMatrix * weights)
            change = labelVectorT - h
            if max(change) < epslion:
                break
            weights = weights + alpha * self.dataMatrix.T * change
        self.weightsOfGradAscent = weights

    # 带有Loss的梯度上升法求解最佳回归系数
    def gradAscentWithLoss(self, alpha=0.001, cycleTimes=500, epslion=0.0000000000001, Lambda=0.5):
        self.dataMatrix = np.mat(self.dataMatrix) # 将数组转为矩阵
        labelVectorT = np.mat(self.labelVector).T
        m, n = np.shape(self.dataMatrix)      # 返回矩阵的行和列
        weights = np.ones((n, 1)) # 初始化最佳回归系数
        for i in range(cycleTimes):
            h = sigmoid(self.dataMatrix * weights)
            change = labelVectorT - h
            if max(change) < epslion:
                break
            weights = weights + alpha * self.dataMatrix.T * change
            weights = weights - Lambda * alpha * weights
        self.weightsOfGradAscentWithLoss = weights

    # 牛顿法求解最佳回归系数
    def newton(self, cycleTimes=10):
        m, n = np.shape(self.dataMatrix)
        weights = [0.0] * n
        for i in range(cycleTimes):
            gradSum = [0.0] * n
            hessianMatrixSum = [[0.0] * n] * n
            for i in range(m):
                hypothesis = sigmoid(getVectorInnerProduct(self.dataMatrix[i], weights))
                change = self.labelVector[i] - hypothesis
                gradient = getVectorMultiX(self.dataMatrix[i], change/m)
                gradSum = getVectorSum(gradSum, gradient)
                hessian = computeHessianMatrix(self.dataMatrix[i], hypothesis/m)
                for j in range(n):
                    hessianMatrixSum[j] = getVectorSum(hessianMatrixSum[j], hessian[j])
            hessianMatInv = np.mat(hessianMatrixSum).I.tolist()
            for i in range(n):
                weights[i] -= getVectorInnerProduct(hessianMatInv[i], gradSum)
        lst = []
        for w in weights:
            lst.append([w])
        self.weightsOfNewton = np.matrix(lst)
            
    def painting(self):
        # 不带损失函数的梯度上升法得到的分类图
        plt.subplot(2, 2, 1)
        plt.title('Gradient Ascent')
        plt.scatter(self.G1X, self.G1Y, marker='o', color='red')
        plt.scatter(self.G2X, self.G2Y, marker='x', color='blue')
        lineX = []
        lineX.append(min(min(self.G1X), min(self.G2X)))
        lineX.append(max(max(self.G1X), max(self.G2X)))
        weights = self.weightsOfGradAscent.tolist()
        lineY = []
        for i in range(len(lineX)):
            lineY.append(-(lineX[i] * weights[1][0] + weights[0][0]) / weights[2][0])
        plt.plot(lineX, lineY, color='green')
        # 带损失函数的梯度上升法得到的分类图
        plt.subplot(2, 2, 2)
        plt.title('Gradient Ascent with Loss')
        plt.scatter(self.G1X, self.G1Y, marker='o', color='red')
        plt.scatter(self.G2X, self.G2Y, marker='x', color='blue')
        lineX = []
        lineX.append(min(min(self.G1X), min(self.G2X)))
        lineX.append(max(max(self.G1X), max(self.G2X)))
        weights = self.weightsOfGradAscentWithLoss.tolist()
        lineY = []
        for i in range(len(lineX)):
            lineY.append(-(lineX[i] * weights[1][0] + weights[0][0]) / weights[2][0])
        plt.plot(lineX, lineY, color='green')
        # 牛顿法得到的分类图
        plt.subplot(2, 2, 3)
        plt.title('Newton')
        plt.scatter(self.G1X, self.G1Y, marker='o', color='red')
        plt.scatter(self.G2X, self.G2Y, marker='x', color='blue')
        lineX = []
        lineX.append(min(min(self.G1X), min(self.G2X)))
        lineX.append(max(max(self.G1X), max(self.G2X)))
        weights = self.weightsOfNewton.tolist()
        lineY = []
        for i in range(len(lineX)):
            lineY.append(-(lineX[i] * weights[1][0] + weights[0][0]) / weights[2][0])
        plt.plot(lineX, lineY, color='green')
        plt.show()

'''
计算海森矩阵(Hessian Matrix):
data: list类型(长度为n)
hypothesis: 实数类型
Return: n维方阵
'''
def computeHessianMatrix(data, hypothesis):
    hessianMatrix = []
    n = len(data)
    for i in range(n):
        row = []
        for j in range(n):
            row.append(-data[i]*data[j]*(1-hypothesis)*hypothesis)
        hessianMatrix.append(row)
    return hessianMatrix

'''
Sigmoid函数:
val: 实数类型
Return: 实数类型
'''
def sigmoid(val):
    return 1.0 / (1 + np.exp(-val))

'''
计算两个向量的内积:
vectorA: list类型
vectorB: list类型
Return: list类型/False
'''
def getVectorInnerProduct(vectorA, vectorB):
    if len(vectorA) != len(vectorB):
        return False
    innerProduct = 0
    for i in range(len(vectorA)):
        innerProduct += vectorA[i] * vectorB[i]
    return innerProduct

'''
计算两个向量的和(逐维相加):
vectorA: list类型
vectorB: list类型
Return: list类型/False
'''
def getVectorSum(vectorA, vectorB):
    if len(vectorA) != len(vectorB):
        return False
    vectorSum = []
    for i in range(len(vectorA)):
        vectorSum.append(vectorA[i] + vectorB[i])
    return vectorSum

'''
计算某个向量与x的乘积(逐位相乘):
vector: list类型
x: 某个实数
'''
def getVectorMultiX(vector, x):
    ans = []
    for i in range(len(vector)):
        ans.append(x * vector[i])
    return ans

def main():
    temp = LogisticExpression()
    temp.getDataFromFile('data.txt')
    temp.generateMarixAndVector()
    temp.newton()
    temp.gradAscent()
    temp.gradAscentWithLoss()
    temp.painting()

if __name__ == '__main__':
    main()
