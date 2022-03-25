# Algorithm-design-and-analysis
计算机算法的学习和练习
Karatsuba算法
原大整数乘法代码的相乘部分代码是根据公式![image](https://user-images.githubusercontent.com/77910684/160176776-b4fc0ec5-1680-4d74-abed-c68faaf60d02.png)
进行计算的，需要进行四次乘法，其时间复杂度为![image](https://user-images.githubusercontent.com/77910684/160176842-6a1a477a-a12e-4312-bc50-0e6b2142f09b.png)
。而公式![image](https://user-images.githubusercontent.com/77910684/160176892-0a8c5483-7715-4453-9480-732bcbe565d4.png)
根据实际观察和验算发现可以变形为![image](https://user-images.githubusercontent.com/77910684/160176908-55302f60-21c4-4225-9ef7-cb18e5771fa8.png)
，可以观察到变形后的式子中只需要三次乘法，其时间复杂度为![image](https://user-images.githubusercontent.com/77910684/160176950-85ccf339-19de-4fc4-b59a-565072f33a3b.png)
，算法的时间复杂度得到了降低。

原大整数乘法的代码只支持正数的大整数进行相乘，当相乘的大整数中有负数时，结果并不是我们想要的。考虑到根据上述变形后的公式中三个主要的部分没有出现负数的情况，即大整数乘法的过程中主要部分都是正数，因此可以在最初输入大整数时获取大整数的符号，推断出结果的符号后，仅仅使用两个大整数的数值部分进行计算。最终输出的大整数相乘结果是一个字符串，用最先推断出的符号再连接相乘的结果，即可得到最终的真正结果。
