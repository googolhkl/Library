function y = test()
load('datax.txt')
load('datay.txt')
plot3(datax(:,2),datax(:,3),datay)
hold on;
gradient(datax,datay)
