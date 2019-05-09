# -*- coding: utf-8 -*-

import numpy as np
import matplotlib.pyplot as plt
import math

class PolyExpression(object):
    def __init__(self, row, col):
        self.row = row # 定义行数
        self.col = col # 定义列数

    def generate_X(self):
        self.x = np.arange(0, 1, 1/self.row)
        self.X = np.ones((self.row, self.col+1))
        for i in range(self.row):
            for j in range(self.col+1):
                self.X[i, j] = math.pow(self.x[i], j)

    def generate_Y(self):
        self.y = np.sin(self.x * 2 * math.pi) + np.random.normal(0, scale=0.1, size=self.row)
        self.Y = self.y.reshape(self.row, 1)

    def show_X(self):
        for i in range(self.row):
            for j in range(self.col+1):
                print('%.2f ' % self.X[i, j], end='')
            print()

    def generate_A(self):
        self.A = np.linalg.inv(np.dot(self.X.T, self.X)).dot(self.X.T).dot(self.Y)
        print('最小二乘法得到的系数向量解:\n', self.A)

    def loss_without_regular(self):                         # 不带有正则项的损失函数
        loss = 0.0
        E = np.dot(self.X, self.A) - self.Y
        for i in range(len(E)):
            loss += math.pow(E[i], 2)
        return loss / 2

    def loss_with_regular(self, Lambda=0.00000001):         # 带有正则项的损失函数
        loss = Lambda * np.dot(self.A.T, self.A) / 2
        loss += self.loss_without_regular()
        I = np.eye(self.col + 1)
        self.AwithLoss = np.dot(np.linalg.inv(np.dot(self.X.T, self.X) + Lambda * I).dot(self.X.T), self.Y)
        print('加入正则项之后的系数向量解: \n', self.AwithLoss)
        return loss

    def grads_down(self, alpha=0.005, Lambda=0.0000000001):
        epsilon = alpha * 0.00001
        self.W = self.A
        tempVector = (1 / self.row) * (np.dot(self.X.T, self.X).dot(self.W) - np.dot(self.X.T, self.Y) + Lambda * self.W)
        judgeVal = np.max(np.abs(tempVector)) * alpha
        while judgeVal >= epsilon:
            self.W = self.W - alpha * tempVector;
            tempVector = (1 / self.row) * (np.dot(self.X.T, self.X).dot(self.W) - np.dot(self.X.T, self.Y) + Lambda * self.W)
            judgeVal = np.max(np.abs(tempVector)) * alpha
        return self.W

    def conjugate_grads(self, alpha=0.00001, Lambda=0.0001, epsilon=0.00001):
        A = np.dot(self.X.T, self.X) + Lambda * np.eye(self.col + 1)
        b = np.dot(self.X.T, self.Y)
        self.CG = np.zeros((self.col + 1, 1))
        r = b - np.dot(A, self.CG)
        P = r
        while True:
            r1 = r
            a = np.dot(r.T, r) / np.dot(P.T, np.dot(A, P))
            self.CG = self.CG + a * P
            r = r - a * np.dot(A, P)
            q = np.linalg.norm(r) ** 2
            if q < epsilon:
                print('共轭梯度法得到的系数矩阵为:\n', self.CG)
                return self.CG
            else:
                beta = np.linalg.norm(r) ** 2 / np.linalg.norm(r1) ** 2
                P = r + beta * P

    def exchange(self, tempX, choiceVector):
        tempX = np.arange(0, 1, 0.001)
        tempY = []
        for x in tempX:
            tempListX = []
            for i in range(self.col+1):
                tempListX.append(math.pow(x, i))
            tempY.append(np.dot(tempListX, choiceVector))
        return tempY

def main():
    expression = PolyExpression(10, 9)
    expression.generate_X()
    expression.generate_Y()
    expression.generate_A()
    X = np.arange(0, 1, 0.001) 
    Y = np.sin(X * 2 * math.pi)
    # 初次拟合，未添加任何修正
    plt.subplot(2, 2, 1)
    plt.title('Fitting without Anything')
    plt.plot(2 * math.pi * X, Y, color='black', linewidth=2.0, linestyle='-')
    plt.xlim(-1.0, 7.0)
    plt.ylim(-1.25, 1.25)
    tempX = np.arange(0, 1, 0.001)
    tempY1 = expression.exchange(tempX, expression.A)
    plt.plot(2 * math.pi * tempX, tempY1, color='red', linewidth=2.0, linestyle='-')
    print('Expression\'loss without regular: %.10f' % expression.loss_without_regular())
    print('Expression\'loss with regular: %.10f' % expression.loss_with_regular(0.00000001522998))
    # 加入正则项后的修正
    plt.subplot(2, 2, 2)
    plt.title('Fitting with Regular')
    plt.plot(2 * math.pi * X, Y, color='black', linewidth=2.0, linestyle='-')
    tempY2 = expression.exchange(tempX, expression.AwithLoss)
    plt.plot(2 * math.pi * tempX, tempY2, color='red', linewidth=2.0, linestyle='-')
    plt.xlim(-1.0, 7.0)
    plt.ylim(-1.25, 1.25)
    # 使用“梯度下降法”得到的修正
    plt.subplot(2, 2, 3)
    plt.title('Fitting with DownGrads')
    plt.plot(2 * math.pi * X, Y, color='black', linewidth=2.0, linestyle='-')
    tempW = expression.grads_down()
    print('梯度下降法: \n', tempW)
    tempY3 = expression.exchange(tempX, tempW)
    plt.plot(2 * math.pi * tempX, tempY3, color='red', linewidth=2.0, linestyle='-')
    plt.xlim(-1.0, 7.0)
    plt.ylim(-1.25, 1.25)
    # 使用“共轭梯度下降法”得到的修正
    plt.subplot(2, 2, 4)
    plt.title('Fitting with ConjugateGrads')
    plt.plot(2 * math.pi * X, Y, color='black', linewidth=2.0, linestyle='-')
    tempCG = expression.conjugate_grads()
    tempY4 = expression.exchange(tempX, tempCG)
    plt.plot(2 * math.pi * tempX, tempY4, color='red', linewidth=2.0, linestyle='-')
    plt.show()

if __name__ == '__main__':
    main()
