## A. Anton and Danik
比较A和D的数量即可。
## B. Anton and Digits
贪心，先凑256，再凑32.
## C. Anton and Making Potions
预处理 first type，用\\(s - d[i]\\)二分查找。
## D. Anton and Chess
用map存下水平、竖直、对角线、反对角线，逐个判断与king之间是否有其他子。
## E. Anton and Tree
先将所有连通的颜色一样的点缩点，然后加入从某一个点开始操作，最少操作即是最大子树深度，如果枚举每一点当作根的情况显然会超时，树形DP即可。
## F. Anton and School
关键在这条公式\\((a\ and\ b) + (a\ or\ b) = (a + b)\\)，将每两个式子想加，可以得到n个含有n个未知数\\(a_1, a_2, ..., a_n\\)的方程，全部相加再逐个减去可以解得\\(2 * n ^ 2 * a_i = 2 * n * (b_i + c_i) - \sum(b_i + c_i)\\)，可以看到这个\\(a_i\\)是唯一的，所以再检查对于每个关于\\(b_i 和 c_i\\)的式子是否符合，检查时对于每一个二进制位检查再乘上权值即可。

